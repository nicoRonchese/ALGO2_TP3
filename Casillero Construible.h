#ifndef CASILLERO_CONSTRUIBLE_H_INCLUDED
#define CASILLERO_CONSTRUIBLE_H_INCLUDED
#include "Casillero.h"
#include "DatosMateriales.h"


const int PRODUCCION_ASERRADERO_CANTIDAD = 25;
const int PRODUCCION_FABRICA_CANTIDAD = 40;
const int PRODUCCION_MINA_CANTIDAD = 15;
const int PRODUCCION_ESCUELA_CANTIDAD = 25;
const int PRODUCCION_MINA_ORO_CANTIDAD = 50;
const int PRODUCCION_PLANTA_ELECTRICA_CANTIDAD = 15;


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
    void colocar_edificio(EdificioColocable* edificio);
    bool comprobar_vacio();
    bool comprobar_propietario(int jugador);
    string demoler_edificio();
    void atacar_edificio(Contador_edificios** edificios_construidos);
    bool consultar_vida();
    void reparar_edificio();
    void recolectar_producido(DatosMateriales* materiales, int* energia, int jugador);
    int devolver_propietario();
    string devolver_elemento_colocable();

  private:
    string devolver_signo_mapa();

};

#endif // CASILLERO_CONSTRUIBLE_H_INCLUDED
