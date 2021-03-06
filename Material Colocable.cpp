#include "Material Colocable.h"

MaterialColocable::MaterialColocable(string nombre){
  if (nombre == NOMBRE_PIEDRA){
      this->nombre = nombre;
      this->signo_mapa = SIGNO_PIEDRA;
      this->cantidad = CANTIDAD_PIEDRA;
   } else if (nombre == NOMBRE_MADERA){
      this->nombre = nombre;
      this->signo_mapa = SIGNO_MADERA;
      this->cantidad = CANTIDAD_MADERA;
   } else if (nombre == NOMBRE_METAL){
      this->nombre = nombre;
      this->signo_mapa = SIGNO_METAL;
      this->cantidad = CANTIDAD_METAL;
   } else if (nombre == NOMBRE_ANDYCOIN){
      this->nombre = nombre;
      this->signo_mapa = SIGNO_ANDYCOIN;
      this->cantidad = CANTIDAD_ANDYCOIN;
   }
  }

void MaterialColocable::mostrar(){
  cout << "Soy un material del tipo "<<nombre<<" y me encuentro en el casillero consultado" << endl;
}

string MaterialColocable::devolver_signo(){
  return this->signo_mapa;
}

string MaterialColocable::devolver_nombre(){
  return nombre;
}

MaterialColocable::~MaterialColocable(){}
