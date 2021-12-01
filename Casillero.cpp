#include "Casillero.h"


Casillero :: Casillero(string tipo_terreno) {
 jugador_colocado = nullptr;
}

void Casillero :: colocar_jugador(int jugador){
 jugador_colocado = new string;
 *jugador_colocado = to_string(jugador+1);
}

void Casillero :: sacar_jugador(){
 delete jugador_colocado;
 jugador_colocado = nullptr;
}

bool Casillero :: comprobar_jugador_colocado(){
 return (jugador_colocado != nullptr);
}

void Casillero :: mostrar(){}

void Casillero :: mostrar_en_mapa() {}

bool Casillero:: comprobar_vacio(){
 return 0;
}

bool Casillero:: comprobar_propietario(int jugador){
 return false;
}

void Casillero :: colocar_edificio(string edificio, int jugador) {}

void Casillero:: colocar_material(string material){}

string Casillero:: devolver_tipo_casillero(){
 return tipo_casillero;
}

string Casillero :: demoler_edificio(){
 return "";
}

void Casillero :: atacar_edificio(){}

void Casillero :: reparar_edificio(){}

string Casillero :: devolver_elemento_colocable(){
 return "";
}

int Casillero :: devolver_propietario(){
 return 0;
}

void Casillero :: recoleccion(DatosMateriales* materiales, int jugador){}

void Casillero :: recolectar_material(DatosMateriales* materiales, int jugador){}

Casillero :: ~Casillero(){}
