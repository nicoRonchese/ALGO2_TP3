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

string CasilleroTransitable::comprobar_terreno(){
   string color_terreno;

   if(this->tipo_terreno == BETUN){
      color_terreno = COLOR_BETUN;
   }else if(this->tipo_terreno == CAMINO){
      color_terreno = COLOR_CAMINO;
   }else{
      color_terreno = COLOR_MUELLE;
   }

   return color_terreno;
}

string CasilleroTransitable::devolver_signo_mapa(){
   string signo;
   if (comprobar_jugador_colocado())
     signo = *jugador_colocado;
   else if (comprobar_vacio())
     signo = VACIO;
   else
     signo = material->devolver_signo();
   return signo;
}

void CasilleroTransitable:: mostrar_en_mapa(){
  string color_terreno = comprobar_terreno();
  string signo =  devolver_signo_mapa();
  cout << color_terreno << signo << END_COLOR;
}

void CasilleroTransitable:: colocar_material(string nombre){
 material = new MaterialColocable(nombre);
}

void CasilleroTransitable:: recolectar_material(DatosMateriales* materiales, int jugador){
 if (this->material->mostrar_material()==NOMBRE_MADERA)
    materiales->sumar_materiales(MADERA, CANTIDAD_MADERA, jugador);
 if (this->material->mostrar_material()==NOMBRE_PIEDRA)
    materiales->sumar_materiales(PIEDRA, CANTIDAD_PIEDRA, jugador);
 if (this->material->mostrar_material()==NOMBRE_METAL)
    materiales->sumar_materiales(METAL, CANTIDAD_METAL, jugador);
 if (this->material->mostrar_material()==NOMBRE_ANDYCOIN)
    materiales->sumar_materiales(ANDYCOIN, CANTIDAD_ANDYCOIN, jugador);
 cout<<"se recolecto "<<material->mostrar_material()<<endl;
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
