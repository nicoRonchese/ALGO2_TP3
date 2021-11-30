#include "Aserradero.h"

Aserradero::Aserradero(int jugador) : EdificioColocable(jugador) {
    nombre = ASERRADERO;
    signo_mapa = SIGNO_ASERRADERO;
    vida = VIDA_EDIFICIO_DEBIL;
}

void Aserradero::mostrar(){
 cout << "Soy un Aserradero y me encuentro en el casillero consultado." << endl;
 cout << "Tengo " << vida << " de vida y mi propietario es el jugador " << propietario + 1 << endl;
}

void Aserradero::recolectar(DatosMateriales* materiales){
    cout << "un Aserradero produjo 25 de madera" << endl;
}

Aserradero::~Aserradero(){}
