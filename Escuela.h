#ifndef ESCUELA_H_INCLUDED
#define ESCUELA_H_INCLUDED
#include "Edificio Colocable.h"

class Escuela : public EdificioColocable{
 public:
     //Métodos públicos

     Escuela(int jugador);
     ~Escuela();
     void mostrar();
     void recolectar();
};


#endif // ESCUELA_H_INCLUDED

