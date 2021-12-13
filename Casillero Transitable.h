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
    /*
    Constructor
    * Pre: Recibe un tipo de terreno valido.
    * Post: Construye un casillero transitable.
    */
    CasilleroTransitable(string tipo_terreno);

    /*
    * Pre: -.
    * Post: Imprime por pantalla información sobre el casillero.
    */
    void mostrar();

    /*
    * Pre: -.
    * Post: Imprime por el signo del objeto ubicado en el casillero y el color correspondiente al 
    *       terreno.
    */
    void mostrar_en_mapa();

    /*
    * Pre: -.
    * Post: Imprime por pantalla información sobre el material ubicado en el casillero.
    */
    void mostrar_material();

    /*
    * Pre: -.
    * Post: Devuelve 'true' si el casillero esta vacio y 'false' en caso contrario.
    */
    bool comprobar_vacio();

    /*
    * Pre: Recibe un material valido.
    * Post: Coloca el material en el casillero.
    */
    void colocar_material(MaterialColocable* material);

    /*
    * Pre: -.
    * Post: Recolecta el material del casillero.
    */
    void recolectar_material(DatosMateriales* materiales, int jugador);
  
    /*
    * Pre: -.
    * Post: Devuelve el nombre del material ubicado en el casillero.
    */
    string devolver_elemento_colocable();

    /*
    Destructor
    * Pre: -.
    * Post: Libera la memoria.
    */
    ~CasilleroTransitable();

  private:

    //Métodos privados
    /*
    * Pre: -.
    * Post: Devuelve el color del terreno correspondiente.
    */
    string comprobar_color_terreno();

    /*
    * Pre: -.
    * Post: Devuelve el objeto ubicado, de no haberlo devuelve 'VACIO' y de estarlo devuelve el 
    *       jugador.
    */
    string devolver_signo_mapa();

};

#endif // CASILLERO_TRANSITABLE_H_INCLUDED
