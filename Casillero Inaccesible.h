#ifndef CASILLERO_INACCESIBLE_H_INCLUDED
#define CASILLERO_INACCESIBLE_H_INCLUDED
#include "Casillero.h"

class CasilleroInaccesible : public Casillero {
  public:
    //Métodos públicos
    /*
    Constructor
    * Pre: Recibe un tipo de terreno valido.
    * Post: Construye un casillero inaccesible.
    */
    CasilleroInaccesible(string tipo_terreno);

    /*
    * Pre: -.
    * Post: Imprime por pantalla información sobre el casillero.
    */
    void mostrar();

    /*
    * Pre: -.
    * Post: Imprime por pantalla 'VACIO' de no estar el jugador posicionado en el casillero, el número
    *       del jugador de no ser así y el color correspondiente al casillero.
    */
    void mostrar_en_mapa();
};


#endif // CASILLERO_INACCESIBLE_H_INCLUDED
