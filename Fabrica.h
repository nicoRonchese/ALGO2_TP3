#ifndef FABRICA_H_INCLUDED
#define FABRICA_H_INCLUDED
#include "Edificio Colocable.h"

class Fabrica : public EdificioColocable{

 public:
    //Métodos públicos
    /*
    Constructor
    * Pre: Recibe un jugador valido.
    * Post: Construye una fábrica.
    */
    Fabrica(int jugador);

    /*
    * Pre: -.
    * Post: Muestra por pantalla la vida y el propietario de la fábrica.
    */
    void mostrar();

    /*
    * Pre: -.
    * Post: Recolecta los materiales correspondientes a la fábrica.
    */
    void recolectar(DatosMateriales* materiales);

    /*
    Destructor
    * Pre: -.
    * Post: Libera la memoria.
    */
    ~Fabrica();
};


#endif // FABRICA_H_INCLUDED

