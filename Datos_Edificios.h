#ifndef DATOS_EDIFICIOS_H_INCLUDED
#define DATOS_EDIFICIOS_H_INCLUDED
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

const string PATH_EDIFICIOS = "edificios.txt";

struct edificio
{
    int cantidad_piedra;
    int cantidad_madera;
    int cantidad_metal;
    int maxima_cantidad_permitida;
    int cantidad_construida;
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

    void recursion_mostrar_edificios(nodo *origen);
    
    //PRE:
    //POS: suma o resta 1 a cantidad_construida de el edificio que nombre_edificio sea igual a nombre 
    void edificio_construido_o_demolido(string nombre,int n);
    
    void recursion_edificio_construido_o_demolido(nodo* ab,string nombre,int n);
    
    //PRE:
    //POS: muestra en terminal todos los edificios que se encuentren el el vector dinamico edificios
    void listar_edificios(edificio dato, string llave);
    
    //PRE:
    //POS:devuelve un edificio con los datos del edificio cuyo nombre_edificio sea igual a nombre
    edificio buscar_edificio(string nombre);

    edificio recursion_buscar_edificio(nodo *ab, string n);
    
    //PRE:
    //POS: devuelve un booleano cuyo valor dependera si el nombre_edificio de algun edififcio concide con nombre
    bool comprobar_edificio(string nombre);
    
private:
    //Métodos privados
    
    //PRE:
    //POS:muestra en la terminal cuanto produce ciertos edificios pero solo si se encuentran en el vector
    string datos_produccion(string nombre);

    void agregar_nodo(nodo *&origen,nodo *ab);
};


#endif // DATOS_EDIFICIOS_H_INCLUDED
