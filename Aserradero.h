#ifndef ASERRADERO_H_INCLUDED
#define ASERRADERO_H_INCLUDED
#include "Edificio Colocable.h"

class Aserradero : public EdificioColocable{

 public:
    //Métodos
    /*
    Constructor
    * Pre: Recibe un jugador valido.
    * Post: Construye un aserradero.
    */
    Aserradero(int jugador);

    /*
    * Pre: -.
    * Post: Muestra por pantalla la vida y el propietario del aserradero.
    */
    void mostrar();

    /*
    * Pre: -.
    * Post: Recolecta los materiales correspondientes al aserradero,
    */
    void recolectar();

    /*
    Destructor
    * Pre: -.
    * Post: Libera la memoria.
    */
    ~Aserradero();
};

#endif // ASERRADERO_H_INCLUDED