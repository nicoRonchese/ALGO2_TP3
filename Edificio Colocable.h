#ifndef EDIFICIO_COLOCABLE_H_INCLUDED
#define EDIFICIO_COLOCABLE_H_INCLUDED
#include <string>
#include <iostream>
#include "Datos Materiales.h"
#include "Structs Constantes.h"

using namespace std;

class EdificioColocable{
 protected:
     //Atributos

     string nombre;
     string signo_mapa;
     int vida;
     int propietario;

 public:
    //Métodos públicos

    //Constructor
    //PRE: -.
    //POS: Define el nombre y signo del edificio.
    EdificioColocable(int jugador);

    //PRE: -.
    //POS: Muestra en la terminal un mensaje indicando que tipo de edificio es.
    virtual void mostrar();

    //PRE: -.
    //POS: Muestra en terminal el simbolo que representa ese edificio.
    string devolver_signo();

    //PRE: -.
    //POS: Devuelve el propietario del edificio.
    int propietario_edificio();

    //PRE: -.
    //POS: Devuelve en forma de string el nombre del edificio.
    string devolver_nombre();

    //PRE: -.
    //POS: Devuelve 'true' si el propietario pasado por referencia es el del edificio y
    //     'false' de no serlo.
    bool comprobar_propietario(int propietario);

    //PRE: -.
    //POS: Devuelve la vida del edificio.
    int devolver_vida();

    //PRE: -.
    //POS: Le resta la vida correspondiente de ser atacado por una bomba al edificio.
    void recibir_bomba();

    //PRE: -.
    //POS: Repara el edificio.
    void reparar_edificio();

    virtual void recolectar(DatosMateriales* materiales, int* energia);

    //Destructor
    //PRE: -.
    //POS: Libera la memoria.
    virtual ~EdificioColocable();

};

#endif // EDIFICIO_COLOCABLE_H_INCLUDED

