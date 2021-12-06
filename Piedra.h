#ifndef PIEDRA_H_INCLUDED
#define PIEDRA_H_INCLUDED
#include "Material Colocable.h"

class Piedra : public MaterialColocable {

public:
    /*
    Constructor
    * Pre: -.
    * Post: Construye el material del tipo piedra.
    */
    Piedra();

    /*
    * Pre: -.
    * Post: Muestra por pantalla indicando que el material es piedra.
    */
    void mostrar();

    /*
    * Pre: -
    * Post: Muestra por pantalla el caracter correspondiente a la piedra.
    */
    void mostrar_en_mapa();

    /*
    Destructor
    * Pre: -.
    * Post: Destruye el elemento piedra.
    */
    ~Piedra();

};

#endif // PIEDRA_H_INCLUD