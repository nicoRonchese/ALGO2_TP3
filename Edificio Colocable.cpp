#include "Edificio Colocable.h"

EdificioColocable::EdificioColocable(int jugador){
 propietario = jugador;
}

void EdificioColocable::mostrar(){}

int EdificioColocable::propietario_edificio(){
 return propietario;
}

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

void EdificioColocable::recolectar(){}

void EdificioColocable::mostrar_en_mapa(){
  cout<<signo_mapa<<" ";
}

string EdificioColocable::mostrar_signo(){
  return this->signo_mapa;
}

EdificioColocable::~EdificioColocable(){
}
