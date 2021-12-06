#include "PlantaElectrica.h"

PlantaElectrica::PlantaElectrica(int jugador) : EdificioColocable(jugador) {
    nombre = PLANTA_ELECTRICA;
    signo_mapa = SIGNO_PLANTA_ELECTRICA;
    vida = VIDA_EDIFICIO_DEBIL;
}

void PlantaElectrica::mostrar(){
 cout << "Soy una Planta Electrica y me encuentro en el casillero consultado." << endl;
 cout << "Tengo " << vida << " de vida y mi propietario es el jugador " << propietario + 1 << endl;
}

PlantaElectrica::~PlantaElectrica(){}
