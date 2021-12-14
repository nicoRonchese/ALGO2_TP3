#include "Edificio Colocable.h"

EdificioColocable::EdificioColocable(int jugador){
  propietario = jugador;
}

void EdificioColocable::mostrar(){}

int EdificioColocable::propietario_edificio(){
  return propietario;
}

string EdificioColocable::devolver_nombre(){
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

string EdificioColocable::devolver_signo(){
  return this->signo_mapa;
}

void EdificioColocable::recolectar(DatosMateriales* materiales, int* energia){}

EdificioColocable::~EdificioColocable(){}
