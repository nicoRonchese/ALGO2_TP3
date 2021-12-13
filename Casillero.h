#ifndef CASILLERO_H_INCLUDED
#define CASILLERO_H_INCLUDED
#include <iostream>
#include <string>
#include "DatosMateriales.h"
#include "Material Colocable.h"
#include "Edificio Colocable.h"
#include "Contador Edificios.h"


using namespace std;
const string CONSTRUIBLE = "C";
const string INACCESIBLE = "L";
const string TRANSITABLE = "T";
const string LAGO = "L";
const string CAMINO = "C";
const string MUELLE = "M";
const string BETUN = "B";
const string TERRENO = "T";
const string VACIO = "V";

#define COLOR_CAMINO "\033[48;5;246m"
#define COLOR_BETUN "\033[48;5;8m"
#define COLOR_LAGO "\033[48;5;35m"
#define COLOR_MUELLE "\033[48;5;94m"
#define COLOR_TERRENO "\033[48;5;2m"
#define END_COLOR "\033[0m"

class Casillero{
 protected:
    //Atributo

    string* jugador_colocado;
    string tipo_casillero;
    string tipo_terreno;
    bool casillero_marcado_camino;

 public:
   //Metódos públicos

   //Constructor
   //PRE:
   //POS: Asigna el tipo de casillero.
   Casillero(string tipo_terreno);
   
   //PRE: Recibe un jugador valido.
   //POS: Muestra en terminal un mensaje indicando que tipo  de casillero es.
   void colocar_jugador(int jugador);

   //PRE: -.
   //POS: Elimina al jugador actual del casillero.
   void sacar_jugador();

   //PRE: -.
   //POS: Devuelve el número del jugador colocado.
   int devolver_jugador();

   //PRE: -.
   //POS: Devuelve 'true' si el casillero no esta vacio y 'false' de estarlo.
   bool comprobar_jugador_colocado();

   //PRE: -.
   //POS: Muestra en terminal un mensaje indicando que tque tipo  de casillero es.
   virtual void mostrar();

   //PRE: -.
   //POS: Muestra en terminal una letra segun el casillero.
   virtual void mostrar_en_mapa();

   //PRE: -.
   //POS: Marca el casillero como camino.
   void marcar_casillero_camino();

   //PRE: -.
   //POS: Muestra por pantalla el color del casillero.
   void mostrar_en_mapa_terreno();

   //PRE: -.
   //POS: Coloca un edificio en el casillero correspondiente.
   virtual void colocar_edificio(EdificioColocable* edificio);

   //PRE: -.
   //POS: En los casilleros coonstruibles y transitables verifica si hay un material 
   //     o un edificio en ese casillero.
   virtual bool comprobar_vacio();

   //PRE: -.
   //POS: Comprueba si el casillero tiene propietario.
   virtual bool comprobar_propietario(int jugador);

   //PRE: Material ingresado debe ser existente.
   //POS: Segun el string identifica que tipo de material es y que caracteristicas tiene.
   virtual void colocar_material(MaterialColocable* material);

   //PRE: -.
   //POS: Devuelve un string que representa que que tipo de casillero es.
   string devolver_tipo_casillero();

   //PRE: -.
   //POS: Borra el edificio y devuelve el nombre del edificio que borro.
   virtual string demoler_edificio();

   //PRE: -.
   //POS: Ataca el edificio ubicado en el casillero y muestra por pantalla el estado del mismo.
   virtual void atacar_edificio(Contador_edificios** datos);

   //PRE: -.
   //POS: Devuelve 'true' si el edificio tiene su vida total y 'false' de lo contrario.
   virtual bool consultar_vida();

   //PRE: -.
   //POS: Repara el edificio ubicado en el casillero.
   virtual void reparar_edificio();

   //PRE: Materiales debe ser un puntero a Datos_materiales con por lo menos madera, piedra y metal en el.
   //POS: Segun el edificio agrega un tipo de material o no.
   virtual void recolectar_producido(DatosMateriales* materiales, int* energia, int jugador);

   //PRE: -.
   //POS: devuelve el nombre del elemento colocado en el casillero.
   virtual string devolver_elemento_colocable();

   //PRE: -.
   //POS: Devuelve el propietario del casillero.
   virtual int devolver_propietario();

   //PRE: Materiales debe ser un puntero a Datos_materiales con por lo menos madera, piedra y metal en el.
   //POS: Segun el material en el casillero agregan un tipo de material o no.
   virtual void recolectar_material(DatosMateriales* materiales, int jugador);

   //Destructor
   //PRE: -.
   //POS: Libera la memoria tomada por edificios o materiales.
   virtual ~Casillero();

};

#endif // CASILLERO_H_INCLUDED
