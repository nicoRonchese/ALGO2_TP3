#ifndef ESCUELA_H_INCLUDED
#define ESCUELA_H_INCLUDED
#include "Edificio Colocable.h"

class Escuela : public EdificioColocable{
 public:
    //Métodos públicos
    /*
    Constructor
    * Pre: Recibe un jugador valido.
    * Post: Construye una escuela.
    */
    Escuela(int jugador);

    /*
    * Pre: -.
    * Post: Muestra por pantalla la vida y el propietario de la escuela.
    */
    void mostrar();

    /*
    * Pre: -.
    * Post: Recolecta los materiales correspondientes a la escuela.
    */
    void recolectar(DatosMateriales* materiales, int* energia);

    /*
    Destructor
    * Pre: -.
    * Post: Libera la memoria.
    */
    ~Escuela();
};


#endif // ESCUELA_H_INCLUDED

