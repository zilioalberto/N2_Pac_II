// Programa teste parada por tempo quando encontrar linha branca na direita e na esquerda;

#include <Arduino.h>
#include <bridgeH_new.h>
#include <qtr_new.h>
#include <sumo_new.h>
#include <sharp_new.h>


int speedD=0;
int speedE=0;
int distance;
int distanceQtrD;
int distanceQtrE;
bool corBrancaD;
bool corBrancaE;


sharp_n sharp1(A0);   //Definição do pino conectado ao sharp
qtr_n qtrD(A1, 400);
qtr_n qtrE(A2, 400);


void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);

  Serial.println("Sumo Luta");
}


void loop() {

//Bloco de controle da ponte H 

bridgeH_n bridgeH_D(3,4,5,speedD);
bridgeH_n bridgeH_E(7,8,6,speedE);


distance = sharp1.getDistance();
distanceQtrD= qtrD.getValue();
distanceQtrE= qtrE.getValue();

corBrancaD =qtrD.getcolorWhite();
corBrancaE =qtrE.getcolorWhite();

// Construtor Sumo
//sumo_n sumoV1(corBrancaD,corBrancaE,distance,30,500,800);

sumo_n sumoV1(corBrancaD,corBrancaE,distance,55,200,800);

speedD = sumoV1.getRSpeed();
speedE = sumoV1.getLSpeed();



  Serial.print(distance);
  Serial.print("  ");
  Serial.print(sumoV1.getIndex());
  Serial.print("  ");
  Serial.println(sharp1.getDistance());
   
}

