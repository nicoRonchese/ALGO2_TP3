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

void CasilleroConstruible:: colocar_edificio(EdificioColocable* edificio){
 this->edificio = edificio;
}

bool CasilleroConstruible:: comprobar_vacio(){
   return (edificio==nullptr);
}

bool CasilleroConstruible:: comprobar_propietario(int jugador){
 return (this->edificio->comprobar_propietario(jugador));
}


void CasilleroConstruible:: mostrar(){
 cout<<"Soy un casillero construible";
 if (comprobar_jugador_colocado()){
    cout<<" y no me encuentro vacio"<<endl;
    cout<<"Soy el jugador "<<(*jugador_colocado)<<" y me encuentro en el casillero consultado"<<endl;
 }
 else if (comprobar_vacio())
    cout<<" y me encuentro vacio"<<endl;
 else {
    cout<<" y no me encuentro vacio"<<endl;
    edificio->mostrar();
 }
}

string CasilleroConstruible::devolver_signo_mapa(){
   string signo;
   if (comprobar_jugador_colocado())
      signo = *jugador_colocado;
   else if (comprobar_vacio())
      signo = VACIO;
   else
      signo = edificio->devolver_signo();
   return signo;
}

void CasilleroConstruible:: mostrar_en_mapa(){
   string signo = devolver_signo_mapa();
   cout << COLOR_TERRENO << signo << END_COLOR;
}

void CasilleroConstruible::recolectar_producido(DatosMateriales* materiales, int* energia, int jugador){
   if (edificio->nombre_edificio()==ASERRADERO){
    materiales->sumar_materiales(MADERA, PRODUCCION_ASERRADERO_CANTIDAD, jugador);
    cout<<ASERRADERO<<" produjo "<<PRODUCCION_ASERRADERO_CANTIDAD<<" de madera"<<endl;
   }
   else if (edificio->nombre_edificio()==MINA){
    materiales->sumar_materiales(PIEDRA, PRODUCCION_MINA_CANTIDAD, jugador);
    cout<<MINA<<" produjo "<<PRODUCCION_MINA_CANTIDAD<<" de piedra"<<endl;
   }
   else if (edificio->nombre_edificio()==FABRICA){
    materiales->sumar_materiales(METAL, PRODUCCION_FABRICA_CANTIDAD, jugador);
    cout<<FABRICA<<" produjo "<<PRODUCCION_FABRICA_CANTIDAD<<" de metal"<<endl;
   }
   else if (edificio->nombre_edificio()==ESCUELA){
    materiales->sumar_materiales(ANDYCOIN, PRODUCCION_ESCUELA_CANTIDAD, jugador);
    cout<<ESCUELA<<" produjo "<<PRODUCCION_ESCUELA_CANTIDAD<<" andycoins"<<endl;
   }
   else if (edificio->nombre_edificio()==PLANTA_ELECTRICA){
    energia[jugador] += PRODUCCION_PLANTA_ELECTRICA_CANTIDAD;
    cout<<PLANTA_ELECTRICA<<" produjo "<<PRODUCCION_PLANTA_ELECTRICA_CANTIDAD<<" de energia"<<endl;
   }
   else if (edificio->nombre_edificio()==MINA_ORO){
    materiales->sumar_materiales(ANDYCOIN, PRODUCCION_MINA_ORO_CANTIDAD, jugador);
    cout<<MINA_ORO<<" produjo "<<PRODUCCION_MINA_ORO_CANTIDAD<<" andycoins"<<endl;
   }
}


string CasilleroConstruible::demoler_edificio(){
  string nombre_edificio = edificio->nombre_edificio();
  delete edificio;
  edificio = nullptr;
  return (nombre_edificio);
}

void CasilleroConstruible::atacar_edificio(cantidad_edificios_construidos** datos){
 edificio->recibir_bomba();
 cout<<edificio->nombre_edificio()<<" fue atacado/a con exito y";
 if (edificio->devolver_vida()==0){
  restar_edificio(edificio->nombre_edificio(), edificio->propietario_edificio(), datos);
  delete edificio;
  edificio = nullptr;
  cout<<" se ha destruido"<<endl;
 }
 else
  cout<<" se encuentra en malas condiciones"<<endl;
}

void CasilleroConstruible::restar_edificio(string nombre, int jugador, cantidad_edificios_construidos** datos){
 if (nombre==ESCUELA)
    datos[jugador]->cantidad_escuelas--;
 if (nombre==FABRICA)
    datos[jugador]->cantidad_fabricas--;
 if (nombre==MINA)
    datos[jugador]->cantidad_minas--;
 if (nombre==MINA_ORO)
    datos[jugador]->cantidad_minas_oro--;
 if (nombre==PLANTA_ELECTRICA)
    datos[jugador]->cantidad_plantas_electricas--;
 if (nombre==ASERRADERO)
    datos[jugador]->cantidad_aserraderos--;
}

bool CasilleroConstruible::consultar_vida(){
 bool vida_maxima = false;
 if (edificio->nombre_edificio()==MINA && edificio->devolver_vida()==VIDA_EDIFICIO_FUERTE)
  vida_maxima = true;
 else if (edificio->nombre_edificio()==FABRICA && edificio->devolver_vida()==VIDA_EDIFICIO_FUERTE)
  vida_maxima = true;
 else if (edificio->devolver_vida() == VIDA_EDIFICIO_DEBIL)
  vida_maxima = true;
 return vida_maxima;
}

void CasilleroConstruible::reparar_edificio(){
 edificio->reparar_edificio();
}

int CasilleroConstruible::devolver_propietario(){
 return (edificio->propietario_edificio());
}

string CasilleroConstruible::devolver_elemento_colocable(){
  return (edificio->nombre_edificio());
}

CasilleroConstruible::~CasilleroConstruible(){
 delete edificio;
}
