#ifndef MATERIAL_COLOCABLE_H_INCLUDED
#define MATERIAL_COLOCABLE_H_INCLUDED
#include <iostream>
#include "DatosMateriales.h"
using namespace std;
const int CANTIDAD = 1;

class MaterialColocable{
 private:
    //Atributos

    string nombre;
    string signo_mapa;
    int cantidad;

 public:
     //Metodos públicos

     //Constructor
     //PRE:
     //POS: define el nombre y signo del edificio
     MaterialColocable();

     //Destructor
     //PRE:
     //POS: libera la memoria
     virtual ~MaterialColocable();

     //PRE:
     //POS: muestra en terminal un mensaje indicando que tque tipo  de material es
     virtual void mostrar();

     //PRE:
     //POS: muestra en terminal una letra segun el material
     virtual void mostrar_en_mapa();

     //PRE:
     //POS: devuelve un string que representa el nombre del material
     string mostrar_material();
};


#endif // MATERIAL_COLOCABLE_H_INCLUDED
