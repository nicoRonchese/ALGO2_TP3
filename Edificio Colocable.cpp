#include "Edificio Colocable.h"

EdificioColocable::EdificioColocable(int jugador){
 propietario = jugador;
}

void EdificioColocable::mostrar(){}

string EdificioColocable::nombre_edificio(){
 return nombre;
}

bool EdificioColocable::comprobar_propietario(int propietario){
 return (this->propietario==propietario);
}

int EdificioColocable::devolver_vida(){
 return vida;
}

void EdificioColocable::recibir_bomba(){
 vida -= 50;
}

void EdificioColocable::reparar_edificio(){
  vida += 50;
}


void EdificioColocable::recolectar(DatosMateriales* materiales){}

void EdificioColocable::mostrar_en_mapa(){
  cout<<signo_mapa<<" ";
}

EdificioColocable::~EdificioColocable(){
}
