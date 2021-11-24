#ifndef CASILLERO_INACCESIBLE_H_INCLUDED
#define CASILLERO_INACCESIBLE_H_INCLUDED
#include "Casillero.h"

class CasilleroInaccesible : public Casillero {
  public:
    //Métodos públicos

    CasilleroInaccesible(string tipo_terreno);
    void mostrar();
    void mostrar_en_mapa();
};


#endif // CASILLERO_INACCESIBLE_H_INCLUDED
