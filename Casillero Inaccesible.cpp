#include "Casillero Inaccesible.h"

CasilleroInaccesible::CasilleroInaccesible(string tipo_terreno) : Casillero(tipo_terreno) {
  tipo_casillero = INACCESIBLE;
  this->tipo_terreno = tipo_terreno;
}

void CasilleroInaccesible:: mostrar(){
  cout << "Soy un casillero inaccesible";
  if (comprobar_jugador_colocado()){
     cout << " y no me encuentro vacio" <<endl;
     cout << "Soy el jugador " << (*jugador_colocado) <<" y me encuentro en el casillero consultado" << endl;
  }
  else
     cout << " y me encuentro vacio" << endl;
}

void CasilleroInaccesible:: mostrar_en_mapa(){
  string signo;
  if(comprobar_jugador_colocado()){
    signo = *jugador_colocado;
  } else {
    signo = VACIO;
  }

  cout << COLOR_LAGO << signo << END_COLOR;
}



