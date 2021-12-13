#ifndef DATOS_EDIFICIOS_H_INCLUDED
#define DATOS_EDIFICIOS_H_INCLUDED
#include <string>
#include <iostream>
#include <fstream>
#include "diccionario.h"
#include "Edificio Colocable.h"
using namespace std;

const string PATH_EDIFICIOS = "edificios.txt";
const string PRODUCCION_ASERRADERO = "Produce 25 de madera";
const string PRODUCCION_MINA = "Produce 15 de piedra";
const string PRODUCCION_FABRICA = "Produce 40 de metal";
const string PRODUCCION_ESCUELA = "Produce 25 andycoins";
const string PRODUCCION_PLANTA_ELECTRICA = "Produce 15 de energia";
const string PRODUCCION_MINA_ORO = "Produce 50 andycoins";

class Datos_edificios
{
private:
    //Atributos

    diccionario<edificio> edificios;
    int cantidad_edificios;

public:
    //Métodos públicos

    //Constructor
    //PRE: El archivo edificios.txt debe existir en el directorio donde se encuentre el programa.
    //POS: Carga la informacion del archivo en el vector dinamico edificios y la cantidad de
    //     edificios que haya en cantidad_edificios.
    Datos_edificios();

    //PRE: -.
    //POS: Muestra en la terminal los nombres de los edificios disponibles.
    void mostrar_edificios();

    //PRE: -.
    //POS: Devuelve un edificio con los datos del edificio cuyo nombre_edificio sea igual a nombre.
    edificio buscar_edificio(string nombre);

    //PRE: -.
    //POS: Devuelve un booleano cuyo valor dependera si el nombre_edificio de algun edififcio concide con nombre
    bool comprobar_edificio(string nombre);

    //PRE: -.
    //POS: Modifica el edificio con los datos pasados por parametro.
    void modificar_edificio(edificio dato, string llave);

    //PRE: -.
    //POS: Guarda los edificios en su correspondiente archivo.
    void guardar_edificios();

    //Destructor
    //PRE: -.
    //POS:libera la memoria tomada para en edificios.
    ~Datos_edificios();

private:
    //Métodos privados
    //PRE: -.
    //POS: Lee el archivo de edificios y carga los datos.
    void leer_edificios();

    //PRE: -.
    //POS: Agrega el edificio con los datos pasados por parametro.
    void agregar_edificio(string llave, edificio datos);

    //PRE:
    //POS:muestra en la terminal cuanto produce ciertos edificios pero solo si se encuentran en el vector
    string datos_produccion(string nombre);
};


#endif // DATOS_EDIFICIOS_H_INCLUDED
