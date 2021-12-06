#include "Casillero Inaccesible.h"

CasilleroInaccesible::CasilleroInaccesible(string tipo_terreno) : Casillero(tipo_terreno) {
 tipo_casillero = INACCESIBLE;
 this->tipo_terreno = tipo_terreno;
}

void CasilleroInaccesible:: mostrar(){
 cout<<"Soy un casillero inaccesible"<<endl;
}

void CasilleroInaccesible:: mostrar_en_mapa(){
  string signo;
  if(comprobar_jugador_colocado())
    signo = *jugador_colocado;
  else
    signo = VACIO;
  cout << COLOR_LAGO << signo << END_COLOR;
}



