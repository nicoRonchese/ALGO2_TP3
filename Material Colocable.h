#ifndef MATERIAL_COLOCABLE_H_INCLUDED
#define MATERIAL_COLOCABLE_H_INCLUDED
#include <iostream>
#include "DatosMateriales.h"
using namespace std;

const string SIGNO_MADERA = "W";
const string SIGNO_METAL = "I";
const string SIGNO_PIEDRA = "S";
const string SIGNO_ANDYCOIN = "G";
const int CANTIDAD_PIEDRA = 100;
const int CANTIDAD_MADERA = 50;
const int CANTIDAD_METAL = 50;
const int CANTIDAD_ANDYCOIN = 250;


class MaterialColocable{
 protected:
    //Atributos

    string nombre;
    string signo_mapa;
    int cantidad;

 public:
     //Metodos públicos

     //Constructor
     //PRE:
     //POS: define el nombre y signo del edificio
     MaterialColocable(string nombre);

     //Destructor
     //PRE:
     //POS: libera la memoria
     ~MaterialColocable();

     //PRE:
     //POS: muestra en terminal un mensaje indicando que tque tipo  de material es
     void mostrar();

     //PRE:
     //POS: muestra en terminal una letra segun el material
     void mostrar_en_mapa();

     //PRE:
     //POS: devuelve un string que representa el nombre del material
     string mostrar_material();

     string mostrar_signo();
};


#endif // MATERIAL_COLOCABLE_H_INCLUDED
