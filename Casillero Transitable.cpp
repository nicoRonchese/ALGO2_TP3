#include "Casillero Transitable.h"
#include "Material Colocable.cpp"


CasilleroTransitable::CasilleroTransitable(string tipo_terreno) : Casillero(tipo_terreno) {
 material = nullptr;
 tipo_casillero = TRANSITABLE;
 this->tipo_terreno = tipo_terreno;
}

void CasilleroTransitable::mostrar_material(){
  material->mostrar();
}

bool CasilleroTransitable:: comprobar_vacio(){
   return (material==nullptr);
}

void CasilleroTransitable:: mostrar(){
 cout<<"Soy un casillero transitable";
 if (comprobar_vacio()){
    cout<<" y me encuentro vacio"<<endl;
 }
 else {
    cout<<" y no me encuentro vacio"<<endl;
    mostrar_material();
 }
}
void CasilleroTransitable:: mostrar_en_mapa(){
  if (comprobar_vacio())
    cout<<"V";
  if (comprobar_jugador_colocado())
    cout<<*jugador_colocado;
  else
    material->mostrar_en_mapa();
}

void CasilleroTransitable:: colocar_material(string nombre){
 if (nombre==NOMBRE_PIEDRA){
    material = new MaterialColocable;
 }
 else if (nombre==NOMBRE_MADERA){
    material = new MaterialColocable;
 }
 else if (nombre==NOMBRE_METAL){
    material = new MaterialColocable;
 }
}

void CasilleroTransitable:: recolectar_material(DatosMateriales* materiales){
 if (this->material->mostrar_material()==NOMBRE_MADERA)
    materiales->sumar_materiales(MADERA,CANTIDAD);
 if (this->material->mostrar_material()==NOMBRE_PIEDRA)
    materiales->sumar_materiales(PIEDRA,CANTIDAD);
 if (this->material->mostrar_material()==NOMBRE_METAL)
    materiales->sumar_materiales(METAL,CANTIDAD);
 cout<<"se recolecto "<<CANTIDAD<<" de "<<material->mostrar_material()<<endl;
 delete material;
 material = nullptr;
}

string CasilleroTransitable::devolver_elemento_colocable(){
 //return material->nombre_material();
 return material->mostrar_material();
}

CasilleroTransitable::~CasilleroTransitable(){
 delete material;
}
