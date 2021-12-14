#ifndef MINA_H_INCLUDED
#define MINA_H_INCLUDED
#include "Edificio Colocable.h"

class Mina : public EdificioColocable{

 public:
    //Métodos
    /*
    Constructor
    * Pre: Recibe un jugador valido.
    * Post: Construye una mina.
    */
    Mina (int jugador);

    /*
    * Pre: -.
    * Post: Muestra por pantalla la vida y el propietario de la mina.
    */
    void mostrar();

    /*
    * Pre: -.
    * Post: Recolecta los materiales correspondientes a la mina.
    */
    void recolectar(DatosMateriales* materiales, int* energia);

    /*
    Destructor
    * Pre: -.
    * Post: Libera la memoria.
    */
    ~Mina();
};

#endif // MINA_H_INCLUDED
