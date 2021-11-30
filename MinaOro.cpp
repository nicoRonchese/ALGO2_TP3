#include "MinaOro.h"

MinaOro::MinaOro(int jugador) : EdificioColocable(jugador) {
    nombre = MINA_ORO;
    signo_mapa = SIGNO_MINA_ORO;
    vida = VIDA_EDIFICIO_FUERTE;
}

void MinaOro::mostrar(){
 cout << "Soy una Mina de Oro y me encuentro en el casillero consultado." << endl;
 cout << "Tengo " << vida << " de vida y mi propietario es el jugador " << propietario + 1 << endl;
}

void MinaOro::recolectar(DatosMateriales* materiales){
    cout << "Una Mina de Oro recolecto 15 Andycoins" << endl;
}

MinaOro::~MinaOro(){}
