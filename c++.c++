#include <Servo.h>
#include <SoftwareSerial.h>


SoftwareSerial ArduinoMaster(2, 3);
String msg;

Servo servo1;
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
char com;


void setup()
{
//Define os pinos como saida
servo1.attach(9);
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
servo1.write(95);
Serial.begin(9600);
ArduinoMaster.begin(9600);

}
void frente(){
  servo1.write(95);
 //Gira o Motor A no sentido horario
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
//Gira o Motor B no sentido horario
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW); 
delay(100);
}
void traz(){
  servo1.write(95);
  //Gira o Motor A no sentido anti-horario
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);
//Gira o Motor B no sentido anti-horario
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH);
delay(100);
}
void direita(){
  servo1.write(125);
}
void esquerda(){
  servo1.write(65);
}
void parar(){
  //Para o motor A
digitalWrite(IN1, HIGH);
digitalWrite(IN2, HIGH);
//Para o motor B
digitalWrite(IN3, HIGH);
digitalWrite(IN4, HIGH);
}
void loop()
{
  if (ArduinoMaster.available() > 0) {
      char c = ArduinoMaster.read();  //gets one byte from serial buffer
      msg = c; //makes the string readString
          if(msg == 'w'){
          frente();
        }
        if(msg == 's'){
          traz();
        }
        if(msg == 'd'){
          direita();
        }
        if(msg == 'a'){
          esquerda();
        }
        if(msg = 'p'){
          parar();
        }
      }
  }