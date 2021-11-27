#ifndef MADERA_H_INCLUDED
#define MADERA_H_INCLUDED
#include "Material Colocable.h"

class Madera : public MaterialColocable {

public:
    /*
    Constructor
    * Pre: -.
    * Post: Construye el material del tipo Madera.
    */
    Madera();

    /*
    * Pre: -.
    * Post: Muestra por pantalla indicando que el material es madera.
    */
    void mostrar();

    /*
    * Pre: -
    * Post: Muestra por pantalla el caracter correspondiente a la madera.
    */
    void mostrar_en_mapa();

    /*
    Destructor
    * Pre: -.
    * Post: Destruye el elemento madera.
    */
    ~Madera();

};

#endif // MADERA_H_INCLUDED