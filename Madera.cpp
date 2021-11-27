#include "Madera.h"

Madera::Madera(){
    this->nombre = NOMBRE_MADERA;
    this->signo_mapa = SIGNO_MADERA;
}

void Madera::mostrar(){
    cout << "Soy un material del tipo Madera y estoy en el casillero consultado" << endl;
}

void Madera::mostrar_en_mapa(){
    cout << signo_mapa << endl;
}

Madera::~Madera(){}