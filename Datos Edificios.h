#ifndef DatosEdificios_H_INCLUDED
#define DatosEdificios_H_INCLUDED
#include <string>
#include <iostream>
#include <fstream>
#include "Diccionario.h"
#include "Structs Constantes.h"
using namespace std;

class DatosEdificios{
private:
    //Atributos

    Diccionario<edificio> edificios;
    int cantidad_edificios;

public:
    //Métodos públicos

    //Constructor
    //PRE: El archivo edificios.txt debe existir en el directorio donde se encuentre el programa.
    //POS: Carga la informacion del archivo en el vector dinamico edificios y la cantidad de
    //     edificios que haya en cantidad_edificios.
    DatosEdificios();

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
    ~DatosEdificios();

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


#endif // DatosEdificios_H_INCLUDED
