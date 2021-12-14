#include "Planta Electrica.h"

PlantaElectrica::PlantaElectrica(int jugador) : EdificioColocable(jugador) {
    nombre = PLANTA_ELECTRICA;
    signo_mapa = SIGNO_PLANTA_ELECTRICA;
    vida = VIDA_EDIFICIO_DEBIL;
}

void PlantaElectrica::mostrar(){
 cout << "Soy una Planta Electrica y me encuentro en el casillero consultado." << endl;
 cout << "Tengo " << vida << " de vida y mi propietario es el jugador " << propietario + 1 << endl;
}

void PlantaElectrica::recolectar(DatosMateriales* materiales, int* energia){
 energia[propietario] += PRODUCCION_PLANTA_ELECTRICA_CANTIDAD;
 cout << nombre << " produjo " << PRODUCCION_PLANTA_ELECTRICA_CANTIDAD << " de energia" << endl;
}

PlantaElectrica::~PlantaElectrica(){}
