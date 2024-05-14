#include <Servo.h>

#define pinoSE A4
#define pinoSD A5

#define motorD 5
#define motorE 6

Servo motord;
Servo motore;

int sensorD;
int sensorE;

int vsensor = 450; //valor x lido pelo sensor. leu >x = preto, <x = branco

void setup() {
  motord.attach(motorD);
  motore.attach(motorE);
  Serial.begin(9600);

}


void loop() {
  sensorD = analogRead(pinoSD);
  sensorE = analogRead(pinoSE);

  if((sensorD<vsensor)&&(sensorE<vsensor)){ //ambos sensores detectam branco, então ele anda pra frente
    motord.write(0);
    motore.write(180);
  }
  if((sensorD>vsensor)&&(sensorE<vsensor)){ //só o sensor direito detecta preto, então ele vira para a direita(roda direita para)
    motord.write(90);
    motore.write(180);
  }
   if((sensorD<vsensor)&&(sensorE>vsensor)){ //só o sensor esquerdo detecta preto, então ele vira para a esquerda(roda esquerda para)
    motord.write(45);
    motore.write(90);
  }
  if((sensorD>vsensor)&&(sensorE>vsensor)){ //ambos detectam preto, ambas as rodas param
    motord.write(90);
    motore.write(90);
  }

}
