#ifndef CASILLERO_TRANSITABLE_H_INCLUDED
#define CASILLERO_TRANSITABLE_H_INCLUDED
#include "Casillero.h"
#include "Material Colocable.h"


class CasilleroTransitable : public Casillero {
  private:
    //Atributos

    MaterialColocable* material;


  public:
    //Métodos públicos

    CasilleroTransitable(string tipo_terreno);
    ~CasilleroTransitable();
    void mostrar();
    string comprobar_terreno();
    void mostrar_en_mapa();
    void mostrar_material();
    bool comprobar_vacio();
    void colocar_material(MaterialColocable* material);
    void recolectar_material(DatosMateriales* materiales, int jugador);
    string devolver_elemento_colocable();

  private:
    string devolver_signo_mapa();

};

#endif // CASILLERO_TRANSITABLE_H_INCLUDED
