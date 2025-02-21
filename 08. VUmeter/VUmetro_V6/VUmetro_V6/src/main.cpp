#include <Arduino.h>
#include <driver/i2s.h>
#include <Adafruit_NeoPixel.h>
#define I2S_WS 11
#define I2S_SD 10
#define I2S_SCK 12
#define I2S_PORT I2S_NUM_0
#define bufferLen 64

#define NUM_LEDS 1
#define PIN_LED 38
#define umbral 100
int brillo = 0;
Adafruit_NeoPixel pixels(1, 38, NEO_RGB);
void i2s_install();
void i2s_setpin();
void TaskTiraLed(void *Pvparameters);

int16_t sBuffer[bufferLen];
void setup()
{
  Serial.begin(115200);
  Serial.println("Setup I2S ...");

  delay(1000);
  i2s_install();
  i2s_setpin();
  i2s_start(I2S_PORT);
  delay(500);

  xTaskCreatePinnedToCore(
      TaskTiraLed,
      "TaskTiraLed",
      10000,
      NULL,
      1,
      NULL,
      1);
}

void loop()
{

  size_t bytesIn = 0;
  esp_err_t result = i2s_read(I2S_PORT, &sBuffer, bufferLen, &bytesIn, portMAX_DELAY);
  if (result == ESP_OK)
  {
    int samples_read = bytesIn / 8;
    if (samples_read > 0)
    {
      float mean = 0;
      for (int i = 0; i < samples_read; ++i)
      {
        mean += (sBuffer[i]);
      }
      mean /= samples_read;
      Serial.println(">Media: " + String(mean));
      Serial.println(">Umbral: " + String(umbral));
      Serial.println(">-Umbral: " + String(-umbral));
      if (abs(mean) > umbral)
      {
        Serial.println(">pulso: " + String(1));
        brillo = 255;
      }
      else
        Serial.println(">pulso: " + String(0));
    }
  }
}

void i2s_install()
{
  const i2s_config_t i2s_config = {
      .mode = i2s_mode_t(I2S_MODE_MASTER | I2S_MODE_RX),
      .sample_rate = 44100,
      .bits_per_sample = i2s_bits_per_sample_t(16),
      .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
      .communication_format = i2s_comm_format_t(I2S_COMM_FORMAT_STAND_I2S),
      .intr_alloc_flags = 0, // default interrupt priority
      .dma_buf_count = 8,
      .dma_buf_len = bufferLen,
      .use_apll = false};

  i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL);
}

void i2s_setpin()
{
  const i2s_pin_config_t pin_config = {
      .bck_io_num = I2S_SCK,
      .ws_io_num = I2S_WS,
      .data_out_num = -1,
      .data_in_num = I2S_SD};

  i2s_set_pin(I2S_PORT, &pin_config);
}

void TaskTiraLed(void *Pvparameters)
{
  pixels.begin();
  pixels.clear();
  pixels.show();
  for (;;)
  {
    if (brillo > 0) // Solo ejecuta si hay brillo
    {
      Serial.println(">Brillo: " + String(brillo));
      pixels.setPixelColor(0, pixels.Color(brillo, brillo, brillo));
      pixels.show();
      brillo--;
    }
    else
    {
      pixels.setPixelColor(0, 0);
      pixels.show();
    }
    vTaskDelay(10 / portMAX_DELAY);
  }
}