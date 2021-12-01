#ifndef DATOS_EDIFICIOS_H_INCLUDED
#define DATOS_EDIFICIOS_H_INCLUDED
#include <string>
#include <iostream>
#include <fstream>
#include "Edificio Colocable.h"
using namespace std;

const string PATH_EDIFICIOS = "edificios.txt";
const string PRODUCCION_ASERRADERO = "Produce 25 de madera";
const string PRODUCCION_MINA = "Produce 15 de piedra";
const string PRODUCCION_FABRICA = "Produce 40 de metal";
const string PRODUCCION_ESCUELA = "Produce 25 andycoins";
const string PRODUCCION_PLANTA_ELECTRICA = "Produce 15 de energia";
const string PRODUCCION_MINA_ORO = "Produce 50 andycoins";

struct edificio
{
    int cantidad_piedra;
    int cantidad_madera;
    int cantidad_metal;
    int maxima_cantidad_permitida;
    string produccion = "";
};

struct nodo
{
    string llave;
    edificio datos;
    nodo *der;
    nodo *izq;
};


class Datos_edificios
{
private:
    //Atributos

    nodo *diccionario;
    int cantidad_edificios;

public:
    //Métodos públicos

    //Constructor
    //PRE:el archivo edificios.txt debe existir en el directorio donde se encuentre el programa
    //POS: carga la informacion del archivo en el vector dinamico edificios y la cantidad de
    //edificios que haya en cantidad_edificios
    Datos_edificios();

    //Destructor
    //PRE:
    //POS:libera la memoria tomada para en edificios
    ~Datos_edificios();

    //PRE:
    //POS:Muestra en la terminal los nombres de los edificios disponibles
    void mostrar_edificios();

    //PRE:
    //POS: muestra en terminal todos los edificios que se encuentren el el vector dinamico edificios
    void listar_edificios(edificio dato, string llave);

    //PRE:
    //POS:devuelve un edificio con los datos del edificio cuyo nombre_edificio sea igual a nombre
    edificio buscar_edificio(string nombre);

    //PRE:
    //POS: devuelve un booleano cuyo valor dependera si el nombre_edificio de algun edififcio concide con nombre
    bool comprobar_edificio(string nombre);

private:
    //Métodos privados

    void recursion_mostrar_edificios(nodo *origen);

    edificio recursion_buscar_edificio(nodo *ab, string n);

    void leer_edificios();

    void agregar_edificio(string llave, edificio datos);

    //PRE:
    //POS:muestra en la terminal cuanto produce ciertos edificios pero solo si se encuentran en el vector
    string datos_produccion(string nombre);

    void agregar_nodo(nodo *&origen,nodo *ab);
};


#endif // DATOS_EDIFICIOS_H_INCLUDED
