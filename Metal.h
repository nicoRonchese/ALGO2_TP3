#ifndef METAL_H_INCLUDED
#define METAL_H_INCLUDED
#include "Material Colocable.h"

class Metal : public MaterialColocable {

public:
    /*
    Constructor
    * Pre: -.
    * Post: Construye el material del tipo metal.
    */
    Metal();

    /*
    * Pre: -.
    * Post: Muestra por pantalla indicando que el material es metal.
    */
    void mostrar();

    /*
    * Pre: -
    * Post: Muestra por pantalla el caracter correspondiente a la metal.
    */
    void mostrar_en_mapa();

    /*
    Destructor
    * Pre: -.
    * Post: Destruye el elemento metal.
    */
    ~Metal();

};

#endif // METAL_H_INCLUDED