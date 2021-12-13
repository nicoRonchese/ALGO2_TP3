#include "Escuela.h"

Escuela::Escuela(int jugador) : EdificioColocable(jugador) {
    nombre = ESCUELA;
    signo_mapa = SIGNO_ESCUELA;
    vida = VIDA_EDIFICIO_DEBIL;
}

void Escuela::mostrar(){
    cout << "Soy una Escuela y me encuentro en el casillero consultado" << endl;
    cout << "Tengo  "<< vida <<" de vida y mi propietario es jugador " << propietario + 1 << endl;
}

Escuela::~Escuela(){}
