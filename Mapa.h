#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
//#include "Casillero Transitable.h"
//#include "Casillero Construible.h"
//#include "Casillero Inaccesible.h"
//#include "Datos Edificios.h"
//#include "Datos Materiales.h"


using namespace std;
const string PATH_MAPA = "mapa.txt";
const string PATH_UBICACIONES = "ubicaciones.txt";

class Mapa{
 protected:
    //Atributos

    Casillero*** Matriz;
    int filas_matriz;
    int columnas_matriz;
    int **transitables;
    int cantidad_transitables;
    int cantidad_transitables_ocupados = 0;

 public:
    //Métodos públicos

    //Constructor
    //PRE: el archivo mapa.txt y ubicaciones.txt deben existir en el directorio donde se encuentre el programa
    //POS: cargala informacion de estos archivos en la matriz dinamica matriz y el vector dinamico transitables
    Mapa();

    //Destructor
    //PRE:
    //POS: libera la memoria tomada por matriz y transitables
    ~Mapa();

    //PRE:
    //POS: muestra en la terminal una matriz que representa al mapa del juego
    void mostrar_mapa();

    //PRE: la string que se le pasa representa al nombre del edificio
    //POS: devuelve un booleano cuyo valor dependera si existe ese edificio
    bool comprobar_edificio(string edificio);

    //PRE: la string que se le pasa representa al nombre del edificio
    //POS: devuelve el edificio si es que este existe
    edificio buscar_edificio(string nombre);

    //PRE: fila y columna deben estar dentro de los limites de la matriz
    //POS: muestra en terminal que tipo de casillero es
    void mostrar_casillero(int fila, int columna);

    //PRE:
    //POS: muestra en terminal todos los edificios que hay en datos_edificios
    void listar_edificios();

    //PRE: fila y columna deben estar dentro del rango de la matriz
    //POS: devuelve un booleano que representa si existe o no esa coordenada dentro del rango
    bool consultar_coordenada(int fila, int columna);

    //PRE:
    //POS: cambia el valor de algunos de los casilleros transitables dentro de matriz de forma aleatoria
    void lluvia_materiales();

    //PRE: fila y columna deben estar dentro del rango de la matriz
    //POS: devuelve el tipo del casillero que se encuentra en esa coordenada
    string consultar_casillero(int fila, int columna);

    //PRE: fila y columna deben estar dentro del rango de la matriz
    //POS: devuelve si el casillero que se encuentra en esa coordenada esta vacio en forma de booleano
    bool consultar_vacio(int fila, int columna);

    //PRE: fila y columna deben estar dentro del rango de la matriz y la string debe ser el nombre de un edificio
    //POS: suma 1 a la cantidad de esdificios construidos de ese tipo y lo coloca en matriz
    void construir_edificio(string nombre, int fila,int columna);

    //PRE: fila y columna deben estra dentro del rango de la matriz
    //POS: devuelve el nombre del edificio demolido
    string demoler_edificio(int fila, int columna, int turno);

    void atacar_edificio(int fila, int columna, int turno);

    void reparar_edificio(int fila, int columna, int turno);

    //PRE: debe recibir un puntero a un dato tipo Datos_materiales
    //POS: "recolecta" los recursos que hayan generado los edificios construidos y se los suma a materiales
    void recolectar_recursos(Datos_materiales* materiales);

    //PRE:
    //POS: mustra en la terminal todos los edificios que se hayan construido
    void mostrar_construcciones(int turno);

    //PRE: el archivo ubicaciones.txt debe existir en el directorio donde se encuentre en alrchivo
    //POS: guarda todos las ubicaciones de los archivos en el archivo
    void guardar_construcciones();

    //PRE: fila y columna deben estra dentro del rango de la matriz y la string debe ser el nombre de un edificio
    //POS: devuelve un booleano que representa si se puede construir en esa coordenada
    bool comprobar_coordenadas_construccion(int fila,int columna);

    bool comprobar_coordenadas_demolicion(int fila,int columna, int turno);

    bool comprobar_coordenadas_ataque(int fila,int columna, int turno);

    bool comprobar_coordenadas_reparacion(int fila,int columna, int turno);

    //PRE: debe recibir un puntero a un dato tipo Datos_materiales
    //POS: "recolecta" los recursos que se encuentren en casilleros transitables y se los suma a materiales
    void recolectar_material_tirado(int fila, int columna, int turno, DatosMateriales* materiales);

 private:
    //Métodos privados

    //PRE: el archivo ubicaciones.txt debe existir en el directorio donde se encuentre en alrchivo
    //POS: utiliza los datos del archivo para madificar matriz y var cuantos edificios construidos de cada tipo hay
    void ubicar_edificios_archivo();

    string leer_materiales_ubicaciones(ifstream &archivo, string objeto);

    string leer_jugador_uno(ifstream &archivo, string objeto);

    string leer_jugador_dos(ifstream &archivo, string objeto);

    //PRE: fila y columna deben estar dentro del rango de la matriz
    //POS: devuelve un  puntero a casillero que reprensenta un tipo de casillero segun el string
    Casillero* definir_casillero(string tipo_casillero,int fila,int columna);

    //PRE: fila y columna deben estar dentro del rango de la matriz
    //POS: guarda en un vector dinamico las coordenadas de los casilleros transitables
    void agregar_transitables(int fila,int columna);

    void guardar_materiales(ofstream &archivo);

    void guardar_jugador_uno(ofstream &archivo);

    void guardar_jugador_dos(ofstream &archivo);

    //PRE:
    //POS: elimina el espacio final de la palabra
    string quitar_espacio_final(string edificio);

};

#endif // MAPA_H_INCLUDED

