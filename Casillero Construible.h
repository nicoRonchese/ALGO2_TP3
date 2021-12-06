#ifndef CASILLERO_CONSTRUIBLE_H_INCLUDED
#define CASILLERO_CONSTRUIBLE_H_INCLUDED
#include "Casillero.h"
#include "DatosMateriales.h"

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
    void atacar_edificio(cantidad_edificios_construidos** datos);
    bool consultar_vida();
    void reparar_edificio();
    void recolectar_producido(DatosMateriales* materiales, int* energia, int jugador);
    int devolver_propietario();
    string devolver_elemento_colocable();

  private:
    void restar_edificio(string nombre, int jugador, cantidad_edificios_construidos** datos);
    string devolver_signo_mapa();

};

#endif // CASILLERO_CONSTRUIBLE_H_INCLUDED
