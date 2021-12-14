#ifndef CASILLERO_CONSTRUIBLE_H_INCLUDED
#define CASILLERO_CONSTRUIBLE_H_INCLUDED
#include "Casillero.h"
#include "Datos Materiales.h"
#include "Contador Edificios.h"
#include "Structs Constantes.h"

class CasilleroConstruible : public Casillero {
  private:
     //Atributos

     EdificioColocable* edificio;

  public:

    //Métodos publicos
    /*
    Constructor
    * Pre: Recibe un tipo de terreno valido.
    * Post: Construye un casillero construible.
    */
    CasilleroConstruible(string tipo_terreno);

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
    * Pre: Recibe un edificio valido.
    * Post: Coloca el edificio en el casillero.
    */
    void colocar_edificio(EdificioColocable* edificio);

    /*
    * Pre: -.
    * Post: Devuelve 'true' si el casillero esta vacio y 'false' en caso contrario.
    */
    bool comprobar_vacio();

    /*
    * Pre: Recibe un jugador válido.
    * Post: Devuelve 'true' si el propietario es el jugador pasado por referencia, 'false' en
    *       en caso de no serlo.
    */
    bool comprobar_propietario(int jugador);

    /*
    * Pre: -.
    * Post: Demuele el edificio y devuelve su nombre.
    */
    string demoler_edificio();

    /*
    * Pre: -.
    * Post: Ataca el edificio ubicado en el casillero y muestra por pantalla el estado del mismo.
    */
    void atacar_edificio(ContadorEdificios** edificios_construidos);

    /*
    * Pre: -.
    * Post: Devuelve 'true' si el edificio tiene su vida total y 'false' de lo contrario.
    */
    bool consultar_vida();

    /*
    * Pre: -.
    * Post: Repara el edificio ubicado en el casillero.
    */
    void reparar_edificio();

    /*
    * Pre: -.
    * Post: Recolecta los materiales producidos por el edificio del casillero. Muestra por pantalla
    *       lo recolectado.
    */
    void recolectar_producido(DatosMateriales* materiales, int* energia);

    /*
    * Pre: -.
    * Post: Devuelve el número del jugador que es el propietario.
    */
    int devolver_propietario();

    /*
    * Pre: -.
    * Post: Devuelve el nombre del edificio construido en el casillero.
    */
    string devolver_elemento_colocable();

    /*
    Destructor
    * Pre: -.
    * Post: Libera la memoria.
    */
    ~CasilleroConstruible();

  private:

    //Métodos privados
    /*
    * Pre: -.
    * Post: Devuelve el objeto ubicado, de no haberlo devuelve 'VACIO' y de estarlo devuelve el jugador.
    */
    string devolver_signo_mapa();

};

#endif // CASILLERO_CONSTRUIBLE_H_INCLUDED
