#ifndef MATERIAL_COLOCABLE_H_INCLUDED
#define MATERIAL_COLOCABLE_H_INCLUDED
#include <iostream>
#include "Datos Materiales.h"
using namespace std;

class MaterialColocable{
 protected:
    //Atributos

    string nombre;
    string signo_mapa;
    int cantidad;

 public:
   //Metodos públicos

   //Constructor
   //PRE: -.
   //POS: Define el nombre y signo del edificio.
   MaterialColocable(string nombre);

   //PRE: -.
   //POS: Muestra en terminal un mensaje indicando que tque tipo  de material es.
   void mostrar();

   //PRE: -.
   //POS: Muestra en terminal una letra segun el material.
   string devolver_signo();

   //PRE: -.
   //POS: Devuelve un string que representa el nombre del material.
   string devolver_nombre();

   //Destructor
   //PRE: -.
   //POS: Libera la memoria.
   ~MaterialColocable();
};


#endif // MATERIAL_COLOCABLE_H_INCLUDED
