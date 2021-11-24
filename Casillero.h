#ifndef CASILLERO_H_INCLUDED
#define CASILLERO_H_INCLUDED
#include <iostream>
#include <string>
#include "DatosMateriales.h"

using namespace std;
const string CONSTRUIBLE = "C";
const string INACCESIBLE = "L";
const string TRANSITABLE = "T";
const string LAGO = "L";
const string CAMINO = "C";
const string MUELLE = "M";
const string BETUN = "B";
const string TERRENO = "T";

class Casillero{
 protected:
    //Atributo

    string tipo_casillero;
    string tipo_terreno;

 public:
    //Metódos públicos

    //Constructor
    //PRE:
    //POS: asigna el tipo de casillero
    Casillero(string tipo_terreno);

    //Destructor
    //PRE:
    //POS: libera la memoria tomada por edificios o materiales
    virtual ~Casillero();

    //PRE:
    //POS: muestra en terminal un mensaje indicando que tque tipo  de casillero es
    virtual void mostrar();

    //PRE:
    //POS: muestra en terminal una letra segun el casillero
    virtual void mostrar_en_mapa();

    //PRE:
    //POS: segun el string identifica que tipo de edifcio es y que caracteristicas tiene
    virtual void colocar_edificio(string edificio, int jugador);

    //PRE:
    //POS: en los casilleros coonstruibles y transitables verifica si hay un material o un edificio en ese casillero
    virtual bool comprobar_vacio();

    virtual bool comprobar_propietario(int jugador);

    //PRE: material ingresado debe ser existente
    //POS: segun el string identifica que tipo de material es y que caracteristicas tiene
    virtual void colocar_material(string material);

    //PRE:
    //POS: devuelve un string que representa que que tipo de casillero es
    string devolver_tipo_casillero();

    //PRE:
    //POS: borra el edificio y devuelve el nombre del edificio que borro
    virtual string demoler_edificio();
 
    virtual void atacar_edificio();

    virtual void reparar_edificio();

    //PRE: materiales debe ser un puntero a Datos_materiales con por lo menos madera, piedra y metal en el
    //POS: segun el edificio agrega un tipo de material o no
    virtual void recoleccion(DatosMateriales* materiales, int jugador);

    //PRE:
    //POS: devuelve el nombre de los edificios en casilleros construibles
    virtual string devolver_elemento_colocable();

    //PRE: materiales debe ser un puntero a Datos_materiales con por lo menos madera, piedra y metal en el
    //POS: segun el material en el casillero agregan un tipo de material o no
    virtual void recolectar_material(DatosMateriales* materiales, int jugador);

};

#endif // CASILLERO_H_INCLUDED
