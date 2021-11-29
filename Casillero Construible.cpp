#include "Casillero Construible.h"
#include "Escuela.cpp"
#include "Fabrica.cpp"
#include "Aserradero.cpp"
#include "Mina.cpp"
#include "MinaOro.cpp"
#include "PlantaElectrica.cpp"
#include "Edificio Colocable.cpp"


CasilleroConstruible::CasilleroConstruible(string tipo_terreno) : Casillero(tipo_terreno) {
 edificio = nullptr;
 tipo_casillero = CONSTRUIBLE;
 this->tipo_terreno = tipo_terreno;
}

void CasilleroConstruible:: colocar_edificio(string nombre, int jugador){
 if (nombre == MINA)
    this->edificio = new Mina(jugador);
 else if (nombre == ASERRADERO)
    this->edificio = new Aserradero(jugador);
 else if (nombre == FABRICA)
    this->edificio = new Fabrica(jugador);
 else if (nombre == ESCUELA)
    this->edificio = new Escuela(jugador);
 else if (nombre == OBELISCO)
    this->edificio = new Escuela(jugador);
 else if (nombre == PLANTA_ELECTRICA)
    this->edificio = new PlantaElectrica(jugador);
 else if(nombre == MINA_ORO)
    this->edificio = new MinaOro(jugador);
 else
    cout<< "No es un edificio colocable por lo que no se va a encontrar en el mapa" << endl;
}

bool CasilleroConstruible:: comprobar_vacio(){
   return (edificio==nullptr);
}

bool CasilleroConstruible:: comprobar_propietario(int jugador){
 return (this->edificio->comprobar_propietario(jugador));
}


void CasilleroConstruible:: mostrar(){
 cout<<"Soy un casillero construible";
 if (comprobar_vacio()){
    cout<<" y me encuentro vacio"<<endl;
 }
 else {
    cout<<" y no me encuentro vacio"<<endl;
    edificio->mostrar();
 }
}

void CasilleroConstruible:: mostrar_en_mapa(){
   if (comprobar_vacio())
    cout<<tipo_terreno<<" ";
   else
    edificio->mostrar_en_mapa();
}

void CasilleroConstruible::recoleccion(DatosMateriales* materiales){
   edificio->recolectar(materiales);
}


string CasilleroConstruible::demoler_edificio(){
  string nombre_edificio = edificio->nombre_edificio();
  delete edificio;
  edificio = nullptr;
  return (nombre_edificio);
}

void CasilleroConstruible::atacar_edificio(){
 edificio->recibir_bomba();
 cout<<edificio->nombre_edificio()<<" fue atacado/a con exito y";
 if (edificio->devolver_vida()==0){
  delete edificio;
  edificio = nullptr;
  cout<<" se ha destruido"<<endl;
 }
 else
  cout<<" se encuentra en malas condiciones"<<endl;
}

void CasilleroConstruible::reparar_edificio(){
 edificio->reparar_edificio();
}

string CasilleroConstruible::devolver_elemento_colocable(){
  return edificio->nombre_edificio();
}

CasilleroConstruible::~CasilleroConstruible(){
 delete edificio;
}
