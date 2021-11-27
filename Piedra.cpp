#include "Piedra.h"

Piedra::Piedra(){
    this->nombre = NOMBRE_PIEDRA;
    this->signo_mapa = SIGNO_PIEDRA;
}

void Piedra::mostrar(){
    cout << "Soy un material del tipo Piedra y estoy en el casillero consultado" << endl;
}

void Piedra::mostrar_en_mapa(){
    cout << signo_mapa << endl;
}

Piedra::~Piedra(){}