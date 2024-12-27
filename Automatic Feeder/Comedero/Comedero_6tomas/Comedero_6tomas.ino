#include <TimerOne.h>
#define IN1  11
#define IN2  10
#define IN3  9
#define IN4  8
#define L1  4
#define L2 5
#define L3  6
#define L4  7
#define BOTON 2
long int TiempoDia =14400000;
int Steps = 0;
int Direction = 0;
int n_s=512*0.75;//= 2048/4
int contador=1;

void setup(void)
   {
    pinMode(IN1, OUTPUT); 
    pinMode(IN2, OUTPUT); 
    pinMode(IN3, OUTPUT); 
    pinMode(IN4, OUTPUT);
    pinMode(L1, OUTPUT);
    pinMode(L2, OUTPUT);
    pinMode(L3, OUTPUT);
    pinMode(L4, OUTPUT);
    pinMode(BOTON,INPUT);
       Timer1.initialize(100000);      
       Timer1.attachInterrupt(manual); 
       Serial.begin(9600);
   }
void loop(void)
{
      motor(n_s/14);
      motor(-n_s*24/28);
  switch(contador)
  {
    case 1:
    digitalWrite(L1,HIGH);
    digitalWrite(L2,LOW);
    digitalWrite(L3,LOW);
    digitalWrite(L4,LOW);
    delay(TiempoDia);
    contador++;
    break;
    case 2:
    digitalWrite(L1,LOW);
    digitalWrite(L2,HIGH);
    delay(TiempoDia);
    contador++;
    break;
    case 3:
    digitalWrite(L1,HIGH);
    delay(TiempoDia);
    contador++;
    break; 
    case 4:
    digitalWrite(L1,LOW);
    digitalWrite(L2,LOW);
    digitalWrite(L3,HIGH);
    delay(TiempoDia);
    contador++;
    case 5:
    digitalWrite(L1,HIGH);
    delay(TiempoDia);
    contador++;
    break; 
    case 6:
    digitalWrite(L1,LOW);
    digitalWrite(L2,HIGH);
    delay(TiempoDia);
    contador=1;
    break; 
  }
  }
   void manual()
   {   
    if(digitalRead(BOTON)==HIGH){
      //motor(n_s/6);
      //motor(-n_s*7/6);
    }
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
