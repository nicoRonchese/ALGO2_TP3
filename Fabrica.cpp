#include "Fabrica.h"

Fabrica::Fabrica(int jugador) : EdificioColocable(jugador) {
 nombre = FABRICA;
 signo_mapa = SIGNO_FABRICA;
 vida = VIDA_EDIFICIO_FUERTE;
}

void Fabrica::mostrar(){
 cout << "Soy una Fabrica y me encuentro en el casillero consultado" << endl;
 cout << "Tengo "<<vida<<" de vida y mi propietario es el jugador "<<propietario+1<< endl;
}

void Fabrica::recolectar(){
    cout<<"una Fabrica produjo 40 de metal"<<endl;
}

Fabrica::~Fabrica(){}
