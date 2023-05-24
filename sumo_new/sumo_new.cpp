/*

sumo_new.h

Autor: Alberto Zilio
Abril 2023

*/

#include "Arduino.h"
#include "sumo_new.h"

sumo_n::sumo_n(bool rWhite, bool lWhite, int dist, int distAttack, int tpRecover, int tpSearch)

{
_rWhite       = rWhite;
_lWhite       = lWhite;
_dist         = dist;
_distAttack   = distAttack;
_tpRecover    = tpRecover;
_tpSearch     = tpSearch;



//estados do Sumo

//Estado de ataque;
//Estado de recuperação
//Estado de procura

 // Em caso de detecção do oponente

if ((_dist<=_distAttack) &&  (!_rWhite) && (!_lWhite)  &&  (_index != 5) && (_index != 6) &&  (_index != 15)){
   _atTime = millis();     //Registro do tempo atual do arduino    
  _index = 5;             //ataque
}


 // Procura pelo oponente
//&& (_dist<20)

if ((_dist>_distAttack)  &&  (!_rWhite) && (!_lWhite)  &&  (_index != 10)  &&  (_index != 5)  &&  (_index != 6) && (_index != 15)){
  _atTime = millis();     //Registro do tempo atual do arduino    
  _index = 10;             //search
}


//Caso sensor da direita ou esquerda tenham detectado linha branca

if (((_rWhite) || (_lWhite)) &&  (_index != 15)) {
_atTime = millis();     //Registro do tempo atual do arduino    
_index = 15;             //retorna com velocidades iguais nas rodas
 };




//********************************** Swich case  *************************************************

switch (_index)

{
 
case 5: //ataque

if ((_dist<=_distAttack)  &&  (!_rWhite) && (!_lWhite)){
_RSpeed = 255; //255
_LSpeed = 255; // 255

}


if ((_dist>_distAttack)  &&  (!_rWhite) && (!_lWhite)){
  _index =6;
}

 break;

 case 6: //retonra um pouco para atacar
_RSpeed = 100; //255
_LSpeed = -100; // 255
if ((_dist<=_distAttack)  &&  (!_rWhite) && (!_lWhite)){
  _index =5;
}
 break;
 
  case 10: //search  --> girando rápido para direita
_RSpeed = -130;
_LSpeed = 130;

break;

 case 15: //Recuperação das linhas brancas
_RSpeed = -255;
_LSpeed = -255;
if ((millis()>=(_atTime+tpRecover)) && (!_rWhite && (!_lWhite))){
   _atTime = millis();     //Registro do tempo atual do arduino  
  _index =10;
}

 break;


  default:
_RSpeed = 0;
_LSpeed = 0;
 break;
}


};

int sumo_n::getRSpeed()              //valor retornado de de velocidade para motor direita
{

return _RSpeed;

}
int sumo_n::getLSpeed()            //valor retornado de de velocidade para motor esquerda
{
return _LSpeed;
}

int sumo_n::getIndex()
{
  return _index;
}

