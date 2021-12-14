#include "Casillero Construible.h"



CasilleroConstruible::CasilleroConstruible(string tipo_terreno) : Casillero(tipo_terreno) {
   edificio = nullptr;
   tipo_casillero = CONSTRUIBLE;
   this->tipo_terreno = tipo_terreno;
}

void CasilleroConstruible:: colocar_edificio(EdificioColocable* edificio){
   this->edificio = edificio;
}

bool CasilleroConstruible:: comprobar_vacio(){
   return (edificio == nullptr);
}

bool CasilleroConstruible:: comprobar_propietario(int jugador){
   return (this->edificio->comprobar_propietario(jugador));
}

void CasilleroConstruible:: mostrar(){
   cout<< "Soy un casillero construible";
   if (comprobar_jugador_colocado()) {
      cout<< " y no me encuentro vacio" << endl;
      cout<< "Soy el jugador " << (*jugador_colocado) << " y me encuentro en el casillero consultado" << endl;
   } else if (comprobar_vacio()){
      cout<< " y me encuentro vacio" << endl;
   } else {
      cout<< " y no me encuentro vacio" << endl;
      edificio->mostrar();
 }

}

string CasilleroConstruible::devolver_signo_mapa(){
   string signo;
   if (comprobar_jugador_colocado()){
      signo = *jugador_colocado;
   }else if (comprobar_vacio()){
      signo = VACIO;
   }else{
      signo = edificio->devolver_signo();
   }

   return signo;
}

void CasilleroConstruible:: mostrar_en_mapa(){
   string signo = devolver_signo_mapa();
   cout << COLOR_TERRENO << signo << END_COLOR;
}

void CasilleroConstruible::recolectar_producido(DatosMateriales* materiales, int* energia){
   edificio->recolectar(materiales, energia);
}


string CasilleroConstruible::demoler_edificio(){
   string nombre_edificio = edificio->devolver_nombre();
   delete edificio;
   edificio = nullptr;
   return (nombre_edificio);
}

void CasilleroConstruible::atacar_edificio(ContadorEdificios** edificios_construidos){
   edificio->recibir_bomba();
   cout << edificio->devolver_nombre() << " fue atacado/a con exito y";
   if (edificio->devolver_vida() == 0){
      edificios_construidos[edificio->propietario_edificio()]->restar_edificio(edificio->devolver_nombre());
      delete edificio;
      edificio = nullptr;
      cout<< " se ha destruido" << endl;
   } else {
    cout<< " se encuentra en malas condiciones" << endl;
   }
}

bool CasilleroConstruible::consultar_vida(){
   bool vida_maxima = false;
   if (edificio->devolver_nombre() == MINA && edificio->devolver_vida() == VIDA_EDIFICIO_FUERTE){
      vida_maxima = true;
   }else if (edificio->devolver_nombre() == FABRICA && edificio->devolver_vida() == VIDA_EDIFICIO_FUERTE){
      vida_maxima = true;
   }else if (edificio->devolver_vida() == VIDA_EDIFICIO_DEBIL){
      vida_maxima = true;
   }

   return vida_maxima;
}

void CasilleroConstruible::reparar_edificio(){
   edificio->reparar_edificio();
}

int CasilleroConstruible::devolver_propietario(){
   return (edificio->propietario_edificio());
}

string CasilleroConstruible::devolver_elemento_colocable(){
   return (edificio->devolver_nombre());
}

CasilleroConstruible::~CasilleroConstruible(){
   delete edificio;
}
