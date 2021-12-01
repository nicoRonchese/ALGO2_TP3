#include "Casillero Inaccesible.h"

CasilleroInaccesible::CasilleroInaccesible(string tipo_terreno) : Casillero(tipo_terreno) {
 tipo_casillero = INACCESIBLE;
 this->tipo_terreno = tipo_terreno;
}

void CasilleroInaccesible:: mostrar(){
 cout<<"Soy un casillero inaccesible"<<endl;
}

void CasilleroInaccesible:: mostrar_en_mapa(){
  if (comprobar_jugador_colocado())
    cout<<*jugador_colocado;
  else
    cout<<"V";

}



