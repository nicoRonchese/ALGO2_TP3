#include "Casillero Inaccesible.h"

CasilleroInaccesible::CasilleroInaccesible(string tipo_terreno) : Casillero(tipo_terreno) {
 tipo_casillero = INACCESIBLE;
 this->tipo_terreno = tipo_terreno;
}

void CasilleroInaccesible:: mostrar(){
 cout<<"Soy un casillero inaccesible"<<endl;
}

void CasilleroInaccesible:: mostrar_en_mapa(){
  cout<<tipo_casillero<<endl;
}



