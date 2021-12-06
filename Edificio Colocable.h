#ifndef EDIFICIO_COLOCABLE_H_INCLUDED
#define EDIFICIO_COLOCABLE_H_INCLUDED
#include <string>
#include <iostream>
#include "DatosMateriales.h"


using namespace std;

const string ASERRADERO = "aserradero";
const string MINA = "mina";
const string FABRICA = "fabrica";
const string ESCUELA = "escuela";
const string OBELISCO = "obelisco";
const string PLANTA_ELECTRICA = "planta electrica";
const string MINA_ORO = "mina oro";
const string SIGNO_ASERRADERO = "A";
const string SIGNO_MINA = "M";
const string SIGNO_FABRICA = "F";
const string SIGNO_ESCUELA = "E";
const string SIGNO_OBELISCO = "O";
const string SIGNO_PLANTA_ELECTRICA = "P";
const string SIGNO_MINA_ORO = "G";
const int VIDA_EDIFICIO_FUERTE = 100;
const int VIDA_EDIFICIO_DEBIL = 50;


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
     //PRE:
     //POS: define el nombre y signo del edificio
     EdificioColocable(int jugador);

     //Destructor
     //PRE:
     //POS: libera la memoria
     virtual ~EdificioColocable();

     //PRE:
     //POS: muestra en la terminal un mensaje indicando que tipo de edificio es
     virtual void mostrar();

     //PRE:
     //POS: muestra en terminal el simbolo que representa ese edificio
     string devolver_signo();

     int propietario_edificio();

     //PRE:
     //POS: devuelve en forma de string el nombre del edificio
     string nombre_edificio();

     bool comprobar_propietario(int propietario);

     int devolver_vida();

     void recibir_bomba();

     void reparar_edificio();

};



#endif // EDIFICIO_COLOCABLE_H_INCLUDED

