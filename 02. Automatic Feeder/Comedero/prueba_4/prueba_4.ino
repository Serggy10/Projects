#define IN1  11
#define IN2  10
#define IN3  9
#define IN4  8
int Direction = 0;
int n_s=512;
int Steps = 0;
int num_vueltas=8;
void setup(void)
   {
    pinMode(IN1, OUTPUT); 
    pinMode(IN2, OUTPUT); 
    pinMode(IN3, OUTPUT); 
    pinMode(IN4, OUTPUT);   
    Serial.begin(9600);
    }
    
    
void loop(void)
{
      for (int contador=0;contador<num_vueltas;contador++){
      motor(n_s);  
      }
      delay(1000);
      Serial.println("Vuelta");
}



void motor(double nbStep){
if(nbStep>=0){
Direction=1;
}else{
Direction=0;
nbStep=-nbStep;
}
for (int x=0;x<nbStep*8;x++){
switch(Steps){
case 0:
digitalWrite(IN1, LOW); 
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH);
break; 
case 1:
digitalWrite(IN1, LOW); 
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, HIGH);
break; 
case 2:
digitalWrite(IN1, LOW); 
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
break; 
case 3:
digitalWrite(IN1, LOW); 
digitalWrite(IN2, HIGH);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
break; 
case 4:
digitalWrite(IN1, LOW); 
digitalWrite(IN2, HIGH);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
break; 
case 5:
digitalWrite(IN1, HIGH); 
digitalWrite(IN2, HIGH);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
break; 
case 6:
digitalWrite(IN1, HIGH); 
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
break; 
case 7:
digitalWrite(IN1, HIGH); 
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH);
break; 
default:
digitalWrite(IN1, LOW); 
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
break; 
}
delayMicroseconds(1000);
if(Direction==1){ Steps++;}
if(Direction==0){ Steps--; }
if(Steps>7){Steps=0;}
if(Steps<0){Steps=7; }
digitalWrite(IN1, LOW); 
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
} 
}
