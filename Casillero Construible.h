#ifndef CASILLERO_CONSTRUIBLE_H_INCLUDED
#define CASILLERO_CONSTRUIBLE_H_INCLUDED
#include "Escuela.h"
#include "Fabrica.h"
#include "Casillero.h"

class CasilleroConstruible : public Casillero {
  private:
     //Atributos

     EdificioColocable* edificio;

  public:
    //Métodos publicos

    CasilleroConstruible(string tipo_terreno);
    ~CasilleroConstruible();
    void mostrar();
    void mostrar_en_mapa();
    void colocar_edificio(string nombre, int jugador);
    bool comprobar_vacio();
    bool comprobar_propietario(int jugador);
    string demoler_edificio();
    void atacar_edificio();
    void reparar_edificio();
    void recoleccion(DatosMateriales* materiales);
    string devolver_elemento_colocable();

};

#endif // CASILLERO_CONSTRUIBLE_H_INCLUDED
