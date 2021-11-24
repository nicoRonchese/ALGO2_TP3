#ifndef FABRICA_H_INCLUDED
#define FABRICA_H_INCLUDED
#include "Edificio Colocable.h"

class Fabrica : public EdificioColocable{

 public:
     //Métodos públicos

     Fabrica(int jugador);
     ~Fabrica();
     void mostrar();
     void recolectar();

};


#endif // FABRICA_H_INCLUDED

