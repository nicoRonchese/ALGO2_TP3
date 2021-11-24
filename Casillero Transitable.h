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
    void mostrar_en_mapa();
    void mostrar_material();
    bool comprobar_vacio();
    void colocar_material(string nombre);
    void recolectar_material(DatosMateriales* materiales);
    string devolver_elemento_colocable();

};

#endif // CASILLERO_TRANSITABLE_H_INCLUDED
