#include "ComederoWiFi.h"
// Callback: send style sheet
void onCSSRequest(AsyncWebServerRequest *request)
{
    IPAddress remote_ip = request->client()->remoteIP();
    Serial.println("[" + remote_ip.toString() +
                   "] HTTP GET request of " + request->url());
    request->send(SPIFFS, "/style.css", "text/css");
}

void ComederoWiFi::IniciaWiFi()
{
    // Iniciar el modo AP y STA
    WiFi.mode(WIFI_AP_STA);
    WiFi.softAP(ssid, password);
    dnsServer.start(53, "*", WiFi.softAPIP());
    if (ssidRouter.isEmpty() || passwordRouter.isEmpty())
    {
        Serial.println("SSID o contrasena del router no estan configurados. No se iniciara el modo estacion.");
    }
    else
        conectadoWifi = IniciaWifiStation(ssidRouter, passwordRouter);
    IPAddress AP_IP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(AP_IP);

    // Iniciar SPIFFS
    if (!SPIFFS.begin(true))
    {
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }

    // Servir el archivo HTML principal
    server.on("/", HTTP_GET, [this](AsyncWebServerRequest *request)
              {
            IPAddress remote_ip = request->client()->remoteIP();
            Serial.println("[" + remote_ip.toString() + "] HTTP GET request of " + request->url());
            // Si se accede desde AP
            if ((remote_ip.toString()).indexOf("192.168.4.") != -1 || WiFi.localIP().toString().equals(remote_ip.toString())) {
                request->send(SPIFFS, "/paginaWeb.html", "text/html");
            }
            // Si se accede desde WiFi 
            else if ((remote_ip.toString()).indexOf("192.168.1.") != -1 || WiFi.localIP().toString().equals(remote_ip.toString())) {
                request->send(SPIFFS, "/paginaWeb.html", "text/html");
            }
            // Si no error.
            else {
                request->send(404, "text/plain", "File Not Found");
            } });
    server.on("/Insignia.ico", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(SPIFFS, "/Insignia.ico", "text/html"); });
    server.on("/style.css", HTTP_GET, onCSSRequest);
    server.addHandler(new CaptiveRequestHandler()).setFilter(ON_AP_FILTER); // only when requested from AP

    // Iniciar el servidor web
    server.begin();
    Serial.println("HTTP server started");

    // Iniciar el servidor WebSocket y asignar el callback
    webSocket.begin();
    webSocket.onEvent([this](uint8_t client_num, WStype_t type, uint8_t *payload, size_t length)
                      { onWebSocketEvent(client_num, type, payload, length); });
}

bool ComederoWiFi::IniciaWifiStation(String ssid, String password)
{
    Serial.println("Intentando conectar a " + ssid);

    WiFi.begin(ssid, password);
    long int tiempo = millis();
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
        if (millis() > tiempo + 10000)
        {
            Serial.println("\nTiempo de espera de conexion Wifi superado");
            return false;
        }
    }

    Serial.println("WiFi conectada.");
    Serial.print("STA dirección IP: ");
    Serial.println(WiFi.localIP());
    IPSTA = WiFi.localIP();
    return true;
}

void ComederoWiFi::onWebSocketEvent(uint8_t client_num, WStype_t type, uint8_t *payload, size_t length)
{
    // Manejo de eventos WebSocket
    String str((char *)payload);
    switch (type)
    {
    case WStype_DISCONNECTED:
        Serial.printf("[%u] Disconnected!\n", client_num);
        clienteConectado = false;
        rotarHorario = false;
        rotarAntihorario = false;
        break;

    case WStype_CONNECTED:
    {
        IPAddress ip = webSocket.remoteIP(client_num);
        Serial.printf("[%u] Connection from ", client_num);
        Serial.println(ip.toString());
        clienteConectado = true;

        StaticJsonDocument<1024> doc;
        doc["numDoses"] = numDosis;
        doc["IP"] = IPSTA;

        JsonArray dosesArray = doc.createNestedArray("doses");
        for (const Dosis &dose : dosis)
        {
            JsonObject doseObj = dosesArray.createNestedObject();
            doseObj["hour"] = dose.hour;
            doseObj["minute"] = dose.minute;
            doseObj["quantity"] = dose.quantity;
        }
        doc["wifiConnected"] = conectadoWifi;
        doc["Hora"] = currentHour;
        doc["Minuto"] = currentMinute;
        String jsonString;
        serializeJson(doc, jsonString);

        // Send JSON string to the newly connected client
        webSocket.sendTXT(client_num, jsonString);
        break;
    }

    case WStype_TEXT:
        // Serial.printf("[%u] Received text: %s\n", client_num, payload);
        HandleTextMessage(client_num, str);
        break;
    default:
        break;
    }
}

String ComederoWiFi::processor(const String &var)
{
    Serial.println(var);
    if (var == "DIRIP")
    {
        String dirIp = WiFi.localIP().toString();
        Serial.println("Processor modo estacion");
        Serial.println(dirIp);
        return dirIp;
    }
    else
    {
        Serial.println("Dir ip no encontrada devuelvo 192.168.4.1");
        return "192.168.4.1";
    }
}

void ComederoWiFi::GuardarParametros()
{
    datos.begin("datos", false);
    if (datos.getShort("numDosis") != numDosis)
        datos.putShort("numDosis", numDosis);
    if (datos.getFloat("valCalibBas") != valorCalibBascula)
        datos.putFloat("valCalibBas", valorCalibBascula);
    if (datos.getFloat("valMinBas") != valorMinBascula)
        datos.putFloat("valMinBas", valorMinBascula);
    if (datos.getFloat("pesoRef") != numDosis)
        datos.putFloat("pesoRef", pesoReferencia);
    if (conectadoWifi)
    {
        if (datos.getString("ssidRouter") != ssidRouter)
            datos.putString("ssidRouter", ssidRouter);
        if (datos.getString("passRouter") != passwordRouter)
            datos.putString("passRouter", passwordRouter);
    }
    if (husoHorario != datos.getInt("husoHorario"))
        datos.putInt("husoHorario", husoHorario);

    StaticJsonDocument<1024> doc;
    doc["numDoses"] = numDosis;

    JsonArray dosesArray = doc.createNestedArray("doses");
    for (const Dosis &dose : dosis)
    {
        JsonObject doseObj = dosesArray.createNestedObject();
        doseObj["hour"] = dose.hour;
        doseObj["minute"] = dose.minute;
        doseObj["quantity"] = dose.quantity;
    }

    String jsonString;
    serializeJson(doc, jsonString);

    if (datos.getString("doses") != jsonString)
        datos.putString("doses", jsonString); // Guarda la cadena JSON

    datos.end(); // Cierra el espacio de nombres

    Serial.println("Datos de dosis guardados correctamente.");
}

void ComederoWiFi::CargarParametros()
{
    datos.begin("datos", true);
    numDosis = datos.getShort("numDosis", 4);
    ssidRouter = datos.getString("ssidRouter", "");
    passwordRouter = datos.getString("passRouter", "");
    valorCalibBascula = datos.getFloat("valCalibBas", 1);
    valorMinBascula = datos.getFloat("valMinBas", 0);
    pesoReferencia = datos.getFloat("pesoRef", 10);
    husoHorario = datos.getInt("husoHorario", 7200);

    String jsonString = datos.getString("doses", ""); // Lee la cadena JSON
    datos.end();                                      // Cierra el espacio de nombres

    if (jsonString.isEmpty())
    {
        Serial.println("No se encontraron datos de dosis.");
    }
    else
    {

        StaticJsonDocument<1024> doc;
        DeserializationError error = deserializeJson(doc, jsonString);

        if (error)
        {
            Serial.printf("Error al deserializar JSON: %s\n", error.c_str());
        }
        else
        {

            numDosis = doc["numDoses"].as<int>();
            JsonArray dosesArray = doc["doses"].as<JsonArray>();

            dosis.clear();
            dosis.reserve(numDosis);

            for (JsonObject doseObj : dosesArray)
            {
                Dosis dose;
                dose.hour = doseObj["hour"].as<int>();
                dose.minute = doseObj["minute"].as<int>();
                dose.quantity = doseObj["quantity"].as<int>();
                dosis.push_back(dose);
                Serial.printf("Dose - Hour: %d, Minute: %d, Quantity: %d g\n", dose.hour, dose.minute, dose.quantity);
            }
            Serial.println("Datos de dosis cargados correctamente.");
        }
    }

    Serial.printf("Número de dosis: %d\n", numDosis);
    Serial.printf("SSID del router: %s\n", ssidRouter.c_str());
    Serial.printf("Contraseña del router: %s\n", passwordRouter.c_str());
    Serial.println("valorCalibBascula: " + String(valorCalibBascula));
    Serial.println("valorMinBascula: " + String(valorMinBascula));
    Serial.println("pesoReferencia: " + String(pesoReferencia));
}

void ComederoWiFi::HandleTextMessage(uint8_t client_num, const String &message)
{
    // Serial.println("Handling text message...");
    Serial.printf("Message received: %s\n", message.c_str());

    StaticJsonDocument<1024> doc; // Aumentar el tamaño del documento si es necesario
    DeserializationError error = deserializeJson(doc, message);

    if (error)
    {
        Serial.printf("deserializeJson() failed: %s\n", error.c_str());
        return;
    }

    // Serial.println("Deserialization successful.");

    bool commandHandled = false; // Flag to check if command is handled

    if (doc.containsKey("ssid") && doc.containsKey("password"))
    {
        ssidRouter = doc["ssid"].as<String>();
        passwordRouter = doc["password"].as<String>();
        Serial.printf("SSID: %s\n", ssidRouter.c_str());
        Serial.printf("Password: %s\n", passwordRouter.c_str());
        commandHandled = true;
        conectadoWifi = IniciaWifiStation(ssidRouter, passwordRouter);
        GuardarParametros();
    }

    if (doc.containsKey("rotateClockwise"))
    {
        rotarHorario = doc["rotateClockwise"].as<bool>();
        Serial.printf("rotarHorario: %s\n", rotarHorario ? "true" : "false");
        commandHandled = true;
    }

    if (doc.containsKey("rotateAnticlockwise"))
    {
        rotarAntihorario = doc["rotateAnticlockwise"].as<bool>();
        Serial.printf("rotarAntihorario: %s\n", rotarAntihorario ? "true" : "false");
        commandHandled = true;
    }

    // Manejo de comandos de configuración de dosis
    if (doc.containsKey("action") && doc["action"] == "tarar")
    {
        Serial.println("Action received: tarar");
        Tarar();
        commandHandled = true;
    }

    // Manejo del SSID y contraseña
    if (doc.containsKey("action") && doc["action"] == "calibrar")
    {
        if (doc.containsKey("peso"))
        {
            float pesoConocido = doc["peso"].as<float>();
            pesoReferencia = pesoConocido;
            Serial.printf("Calibrate action received: calibrar with weight %f\n", pesoConocido);
            Calibrar(pesoConocido);
            commandHandled = true;
        }
        else
        {
            Serial.println("Calibrate action received: calibrar but no weight provided.");
        }
    }

    if (doc.containsKey("numDoses") && doc.containsKey("doses"))
    {
        numDosis = doc["numDoses"].as<int>();
        JsonArray dosesArray = doc["doses"].as<JsonArray>();
        dosis.clear();
        dosis.reserve(numDosis);
        Serial.printf("Received %d doses:\n", numDosis);
        for (JsonObject dose : dosesArray)
        {
            Dosis newDose;
            newDose.hour = dose["hour"].as<int>();
            newDose.minute = dose["minute"].as<int>();
            newDose.quantity = dose["quantity"].as<int>();
            dosis.push_back(newDose);
            Serial.printf("Dose - Hour: %d, Minute: %d, Quantity: %d g\n", newDose.hour, newDose.minute, newDose.quantity);
        }
        GuardarParametros();
        commandHandled = true;
    }

    // Manejo de comandos "menos" y "mas"
    if (doc.containsKey("command"))
    {
        String command = doc["command"].as<String>();
        if (command == "menos")
        {
            Serial.println("Command received: menos");
            husoHorario -= 3600;
            timeClient.setTimeOffset(husoHorario);
            GuardarParametros();
            commandHandled = true;
        }
        else if (command == "mas")
        {
            Serial.println("Command received: mas");
            husoHorario += 3600;
            timeClient.setTimeOffset(husoHorario);
            GuardarParametros();
            commandHandled = true;
        }
    }

    if (!commandHandled)
    {
        Serial.println("Unknown command received.");
    }
}

void ComederoWiFi::Tarar()
{
    valorMinBascula = bascula.read_average(10);
}

void ComederoWiFi::Calibrar(int pesoConocido)
{
    valorCalibBascula = bascula.read_average(10);
    GuardarParametros();
}

void ComederoWiFi::ComprobarHora()
{

    static int lastCheckedMinute = -1; // Variable estática para almacenar el último minuto comprobado

    tiempoActual = millis();
    // Obtener la hora y minuto actual
    timeClient.update();
    currentHour = timeClient.getHours();
    currentMinute = timeClient.getMinutes();

    // Serial.printf("Hora actual: %02d:%02d\n", currentHour, currentMinute);

    // Si el minuto ha cambiado, restablecer la bandera
    if (currentMinute != lastCheckedMinute)
    {
        lastCheckedMinute = currentMinute;

        // Comparar con las dosis programadas
        for (const auto &dose : dosis)
        {
            if (dose.hour == currentHour && dose.minute == currentMinute)
            {
                Serial.printf("¡Hora de la dosis! %02d:%02d - Cantidad: %d g\n", dose.hour, dose.minute, dose.quantity);
                DarDosis(dose.quantity);
            }
        }
    }
}

void ComederoWiFi::DarDosis(int dosis)
{
    rotarHorario = true;
    while (peso < dosis)
    {
        CalculaPeso();
        MoverMotor();
    }
    rotarHorario = false;
}

void ComederoWiFi::MandarPeso()
{
    if (millis() > tiempoActualizarPeso + 500)
    {
        tiempoActualizarPeso = millis();
        CalculaPeso();
        // Serial.println(peso);
        StaticJsonDocument<200> jsonDoc;
        jsonDoc["weight"] = peso;
        jsonDoc["hora"] = currentHour;
        jsonDoc["minuto"] = currentMinute;
        String jsonString;
        serializeJson(jsonDoc, jsonString);
        webSocket.broadcastTXT(jsonString);
    }
}

void ComederoWiFi::MoverMotor()
{
    // Controlar el motor según los valores de horario y antihorario
    if (rotarHorario && !rotarAntihorario)
    {
        // Girar en sentido horario (ajustar el valor según tu servomotor)
        servo.write(93); // Valor alto para girar en sentido horario
    }
    else if (!rotarHorario && rotarAntihorario)
    {
        // Girar en sentido antihorario (ajustar el valor según tu servomotor)
        servo.write(80); // Valor bajo para girar en sentido antihorario
    }
    else
    {
        // Detener el motor
        servo.write(90); // Valor neutral para detener el servomotor
    }
}

// TODO revisar el offset de la comida.