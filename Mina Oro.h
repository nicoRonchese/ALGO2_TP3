#ifndef MINA_ORO_H_INCLUDED
#define MINA_ORO_H_INCLUDED
#include "Edificio Colocable.h"


class MinaOro : public EdificioColocable{

 public:

    //Métodos
    /*
    Constructor
    * Pre: Recibe un jugador valido.
    * Post: Construye una mina de oro.
    */
    MinaOro (int jugador);

    /*
    * Pre: -.
    * Post: Muestra por pantalla la vida y el propietario de la mina de oro construida.
    */
    void mostrar();

    /*
    * Pre: -.
    * Post: Recolecta los materiales correspondientes a la mina de oro.
    */
    void recolectar(DatosMateriales* materiales, int* energia);

    /*
    Destructor
    * Pre: -.
    * Post: Libera la memoria.
    */
    ~MinaOro();
};

#endif // MINA_ORO_H_INCLUDED
