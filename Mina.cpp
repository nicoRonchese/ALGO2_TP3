#include "Mina.h"

Mina::Mina(int jugador) : EdificioColocable(jugador) {
    nombre = MINA;
    signo_mapa = SIGNO_MINA;
    vida = VIDA_EDIFICIO_FUERTE;
}

void Mina::mostrar(){
 cout << "Soy una Mina y me encuentro en el casillero consultado." << endl;
 cout << "Tengo " << vida << " de vida y mi propietario es el jugador " << propietario + 1 << endl;
}

void Mina::recolectar(){
    cout << "una Mina produjo 15 de piedra" << endl;
}

Mina::~Mina(){}