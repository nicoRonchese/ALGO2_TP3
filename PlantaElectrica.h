#ifndef PLANTA_ELECTRICA_H_INCLUDED
#define PLANTA_ELECTRICA_H_INCLUDED
#include "Edificio Colocable.h"

class PlantaElectrica : public EdificioColocable{

 public:
    //Metodos
    /*
    Constructor
    * Pre: Recibe un jugador valido.
    * Post: Construye una planta electrica.
    */
    PlantaElectrica(int jugador);

    /*
    * Pre: -.
    * Post: Muestra por pantalla la vida y el propietario de la planta electrica.
    */
    void mostrar();

    /*
    * Pre: -.
    * Post: Recolecta los materiales correspondientes a la planta electrica.
    */
    void recolectar(DatosMateriales* materiales);

    /*
    Destructor
    * Pre: -.
    * Post: Libera la memoria.
    */
    ~PlantaElectrica();
};

#endif // PLANTA_ELECTRICA_H_INCLUDED
