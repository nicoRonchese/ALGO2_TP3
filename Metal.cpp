#include "Metal.h"

Metal::Metal(){
    this->nombre = NOMBRE_METAL;
    this->signo_mapa = SIGNO_METAL;
}

void Metal::mostrar(){
    cout << "Soy un material del tipo metal y estoy en el casillero consultado" << endl;
}

void Metal::mostrar_en_mapa(){
    cout << signo_mapa << endl;
}

Metal::~Metal(){}