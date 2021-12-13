#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
#include "Casillero Transitable.h"
#include "Casillero Construible.h"
#include "Casillero Inaccesible.h"
#include "Grafo.h"
#include "Grafo.cpp"
//#include "Datos Edificios.h"
//#include "Datos Materiales.h"


using namespace std;
const string PATH_MAPA = "mapa.txt";
const string PATH_UBICACIONES = "ubicaciones.txt";
const int COSTO_MUELLE_UNO = 5;
const int COSTO_MUELLE_DOS = 2;
const int COSTO_LAGO_UNO = 2;
const int COSTO_LAGO_DOS = 5;
const int COSTO_BETUN = 0;
const int COSTO_CAMINO = 4;
const int COSTO_TERRENO = 25;

class Mapa{
 protected:
    //Atributos

    Casillero*** Matriz;
    int filas_matriz;
    int columnas_matriz;
    int **transitables;
    int cantidad_transitables;
    Grafo grafo[2];

 public:
   //Métodos públicos

   //Constructor
   //PRE: el archivo mapa.txt y ubicaciones.txt deben existir en el directorio donde se encuentre el programa
   //POS: cargala informacion de estos archivos en la matriz dinamica matriz y el vector dinamico transitables
   Mapa();

   //PRE: el archivo ubicaciones.txt debe existir en el directorio donde se encuentre en alrchivo
   //POS: utiliza los datos del archivo para madificar matriz y var cuantos edificios construidos de cada tipo hay
   bool ubicar_edificios_archivo();

   //PRE: el archivo ubicaciones.txt debe existir en el directorio donde se encuentre en alrchivo
   //POS: utiliza los datos del archivo para madificar matriz y var cuantos edificios construidos de cada tipo hay
   void completar_cantidad_edificios(Contador_edificios** edificios_construidos, int** posicion_jugadores);

   //PRE: -.
   //POS: Muestra por pantalla el mapa de terrenos del juego.
   void mostrar_mapa_terrenos();

   //PRE:
   //POS: muestra en la terminal una matriz que representa al mapa del juego
   void mostrar_mapa();

   //PRE: la string que se le pasa representa al nombre del edificio
   //POS: devuelve un booleano cuyo valor dependera si existe ese edificio
   bool comprobar_edificio(string edificio);

   //PRE: Recibe una fila y columna validas.
   //POS: Devuelve el nombre del elemento ubicado en el casillero.
   string devolver_elemento_en_casillero(int fila, int columna);

   //PRE: fila y columna deben estar dentro de los limites de la matriz
   //POS: muestra en terminal que tipo de casillero es
   void mostrar_casillero(int fila, int columna);

   //PRE: -.
   //POS: muestra en terminal todos los edificios que hay en datos_edificios
   void listar_edificios();

   //PRE: fila y columna deben estar dentro del rango de la matriz
   //POS: devuelve un booleano que representa si existe o no esa coordenada dentro del rango
   bool consultar_coordenada(int fila, int columna);

   //PRE: Recibe una fila, columna y jugador validos.
   //POS: Coloca el jugador en dicha posición.
   void colocar_jugador(int fila, int columna, int jugador);

   //PRE: -.
   //POS: cambia el valor de algunos de los casilleros transitables dentro de matriz de forma aleatoria
   void lluvia_materiales();

   //PRE: fila y columna deben estar dentro del rango de la matriz y la string debe ser el nombre de un edificio
   //POS: suma 1 a la cantidad de esdificios construidos de ese tipo y lo coloca en matriz
   bool construccion_edificio(string nombre, int fila,int columna, int turno);

   //PRE: fila y columna deben estra dentro del rango de la matriz
   //POS: devuelve el nombre del edificio demolido
   string demoler_edificio(int fila, int columna);

   //PRE: Recibe una fila, columna y turno validos.
   //POS: Devuelve 'true' si se pudo efectuar el ataque y 'false' de no ser así.
   bool atacar_edificio(int fila, int columna, int turno, Contador_edificios** datos);

   //PRE: Recibe una fila y columna validas.
   //POS: Repara el edificio ubicado en la posición referenciada.
   void reparar_edificio(int fila, int columna);

   //PRE: debe recibir un puntero a un dato tipo Datos_materiales
   //POS: "recolecta" los recursos que hayan generado los edificios construidos y se los suma a materiales
   bool recolectar_recursos(DatosMateriales* materiales, int* energia, int jugador);

   //PRE:
   //POS: mustra en la terminal todos los edificios que se hayan construido
   void mostrar_construcciones(int turno);

   //PRE: el archivo ubicaciones.txt debe existir en el directorio donde se encuentre en alrchivo
   //POS: guarda todos las ubicaciones de los archivos en el archivo
   void guardar_construcciones(int posicion_1[], int posicion_2[]);

   //PRE: Recibe una fila y columna validas.
   //POS: Devuelve 'true' si el jugador puede ser colocado en esa posición y 'false' de no ser así
   bool comprobar_colocacion_jugador(int fila, int columna);

   //PRE: Recibe una fila, columna y turno validos.
   //POS: Devuelve 'true' si se puede demoler en esa posición y 'false' de no poderse.
   bool comprobar_coordenadas_demolicion(int fila,int columna, int turno);

   //PRE: Recibe una fila, columna y turno validos.
   //POS: Devuelve 'true' si se puede reparar en esa posición y 'false' de no poderse.
   bool comprobar_coordenadas_reparacion(int fila,int columna, int turno);

   //PRE: Recibe una fila y columna validas.
   //POS: Devuelve 'true' si el jugador se puede mover a esa posición y 'false' de no poderse.
   bool comprobar_coordenadas_moverse(int fila, int columna);

   //PRE: debe recibir un puntero a un dato tipo Datos_materiales
   //POS: "recolecta" los recursos que se encuentren en casilleros transitables y se los suma a materiales
   void recolectar_material_tirado(int fila, int columna, int turno, DatosMateriales* materiales);

   //PRE: Recibe un jugador, filas y columnas validos.
   //POS: Devuelve el camino y muestra por pantalla su costo.
   camino_especifico moverse_coordenada(int jugador,int fila_origen,int columna_origen,int fila_destino,int columna_destino);

   //PRE: -.
   //POS: Cambia el jugador de posición.
   void cambiar_posicion(int jugador,camino_especifico dato,DatosMateriales* materiales);

   //Destructor
   //PRE:
   //POS: libera la memoria tomada por matriz y transitables
   ~Mapa();

 private:
    //Métodos privados

   //PRE: -.
   //POS: Crea la matriz a partir del archivo.
    void crear_matriz_archivo();

   //PRE: -.
   //POS: Lee las ubicaciones de los materiales y devuelve la ubicación.
   string leer_materiales_ubicaciones(ifstream &archivo, string objeto);

   //PRE: -.
   //POS: Lee los datos correspondientes al jugador uno y devuelve la ubicación.
   string leer_jugador_uno(ifstream &archivo, string objeto);

   //PRE: -.
   //POS: Lee los datos correspondientes al jugador dos y devuelve la ubicación..
   string leer_jugador_dos(ifstream &archivo, string objeto);

   //PRE: -.
   //POS: Devuelve el costo de transitar el terreno.
   int costo_terreno(string tipo_casillero, int jugador);

   //PRE: -.
   //POS: Carga los datos al grafo.
   void cargar_datos_grafo();

   //PRE: fila y columna deben estar dentro del rango de la matriz
   //POS: devuelve un  puntero a casillero que reprensenta un tipo de casillero segun el string
   Casillero* definir_casillero(string tipo_terreno,int fila,int columna);

   //PRE: fila y columna deben estar dentro del rango de la matriz
   //POS: guarda en un vector dinamico las coordenadas de los casilleros transitables
   void agregar_transitables(int fila,int columna);

   //PRE: -.
   //POS: Elimina el casillero transitable.
   void eliminar_transitables(int fila, int columna);

   //PRE: fila y columna deben estra dentro del rango de la matriz y la string debe ser el nombre de un edificio
   //POS: devuelve un booleano que representa si se puede construir en esa coordenada
   bool comprobar_coordenadas_construccion(int fila,int columna);

   //PRE: -.
   //POS: Construye el edificio correspondiente al nombre pasado por parametro. De no ser válido
   //     devuelve un mensaje de error por pantalla.
   EdificioColocable* construir_edificio(string nombre, int jugador);

   //PRE: -.
   //POS: Crea un nuevo material correspondiente al nombre pasado por parametro.
   MaterialColocable* construir_material(string nombre);

   //PRE: -.
   //POS: Devuelve 'true' si se puede atacar esa posición y 'false' de no poderse.
   bool comprobar_coordenadas_ataque(int fila,int columna, int turno);

   //PRE: -.
   //POS: Muestra el camino por pantalla.
   void mostrar_camino(camino_especifico datos);

   //PRE: -.
   //POS: Guarda los materiales correspondientes al archivo de ubicaciones.
   void guardar_materiales(ofstream &archivo);

   //PRE: -.
   //POS: Guarda los datos de los jugadores.
   void guardar_jugador(ofstream &archivo, int jugador, int posicion[]);

   //PRE: -.
   //POS: elimina el espacio final de la palabra
   string quitar_espacio_final(string edificio);

};

#endif // MAPA_H_INCLUDED



