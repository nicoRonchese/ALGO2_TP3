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
   string color_terreno = comprobar_terreno();
   string ubicacion = comprobar_ubicacion();

   cout << color_terreno << ubicacion << END_COLOR;
   
}

void CasilleroTransitable:: colocar_material(string nombre){
 material = new MaterialColocable(nombre);
}

void CasilleroTransitable:: recolectar_material(DatosMateriales* materiales){
 if (this->material->mostrar_material()==NOMBRE_MADERA)
    materiales->sumar_materiales(MADERA,CANTIDAD_MADERA);
 if (this->material->mostrar_material()==NOMBRE_PIEDRA)
    materiales->sumar_materiales(PIEDRA,CANTIDAD_PIEDRA);
 if (this->material->mostrar_material()==NOMBRE_METAL)
    materiales->sumar_materiales(METAL,CANTIDAD_METAL);
 if (this->material->mostrar_material()==NOMBRE_ANDYCOIN)
    materiales->sumar_materiales(ANDYCOIN,CANTIDAD_ANDYCOIN);
 cout<<"se recolecto "<<material->mostrar_material()<<endl;
 delete material;
 material = nullptr;
}

string CasilleroTransitable::devolver_elemento_colocable(){
 //return material->nombre_material();
 return material->mostrar_material();
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

string CasilleroTransitable::comprobar_ubicacion(){
   string ubicacion_actual;

   if (comprobar_vacio()){
      ubicacion_actual = VACIO;
   }else if (comprobar_jugador_colocado()){
      ubicacion_actual = *jugador_colocado;
   }else{
     ubicacion_actual = material->mostrar_signo();
   }

   return ubicacion_actual;
}

CasilleroTransitable::~CasilleroTransitable(){
 delete material;
}
