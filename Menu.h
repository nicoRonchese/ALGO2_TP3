#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include <string.h>
#include "Mapa.h"
#include "DatosMateriales.h"
#include "Datos_Edificios.h"
#include "Objetivos.h"

using namespace std;

#define SUBRAYADO "\033[4m"
#define CUADRO_HORIZONTAL "\u2505"
#define CUADRO_VERTICAL "\u2507"

const int CANTIDAD_JUGADORES = 2;
const int JUGADOR_UNO = 0;
const int JUGADOR_DOS = 1;
const int MODIFICAR_EDIFICIO = 1;
const int LISTAR_EDIFICIOS = 2;
const int MOSTRAR_MAPA = 3;
const int CAMBIAR_CANTIDAD_JUGADORES = 4;
const int COMENZAR_PARTIDA = 5;
const int GUARDAR_SALIR_INICIAL = 6;
const int CONSTRUIR_EDIFICIO = 1;
const int LISTAR_CONSTRUCCIONES = 2;
const int DEMOLER_CONSTRUCCION = 3;
const int ATACAR_CONSTRUCCION = 4;
const int REPARAR_CONSTRUCCION = 5;
const int COMPRAR_BOMBAS = 6;
const int CONSULTAR_COORDENADA = 7;
const int MOSTRAR_INVENTARIO = 8;
const int MOSTRAR_OBJETIVOS = 9;
const int RECOLECTAR_RECURSOS = 10;
const int MOVERSE_COORDENADA = 11;
const int FINALIZAR_TURNO = 12;
const int GUARDAR_SALIR = 13;
const int COSTO_CONSTRUIR = 15;
const int COSTO_DEMOLER = 15;
const int COSTO_ATACAR = 30;
const int COSTO_REPARAR = 25;
const int COSTO_COMPRAR = 5;
const int COSTO_RECOLECTAR = 20;
const int ENERGIA_INICIAL = 50;
const int ENERGIA_RECIBIDA = 20;
const int ENERGIA_MAXIMA = 100;

class Menu{
 private:
     //Atributos

     Mapa* mapa;
     DatosMateriales* datosMateriales;
     Datos_edificios* datosEdificios;
     cantidad_edificios_construidos** edificios_construidos;
     Objetivos** objetivos;
     int turno;
     int cantidad_jugadores;
     int* energia;

 public:
     //Métodos públicos

     //Constructor
     //PRE: los archivos que necesitan los objetos mapa y datos materiales deben existir en el directorio
     //POS:obtiene los datos con los que el sistema puede trabajar
     Menu();

     //Destructor
     //PRE:
     //POS: libera la memoria tomada
     ~Menu();

     //PRE:
     //POS: Permite al usuario utilizar el menu y modificar los archivos
     void empezar_menu();

 private:
     //Métodos privados

     //PRE:
     //POS:
     void crear_datos_jugadores();

     void inicializar_datos_objetivos();

     //PRE:
     //POS:
     void menu_inicial();

     //PRE:
     //POS:
     void menu_juego();

     //PRE: debe recibir un int
     //POS: segun el numero realizara una tarea
     void procesar_opcion_inicial(int opcion);

     //PRE: debe recibir un int
     //POS: segun el numero realizara una tarea
     void procesar_opcion_juego(int opcion);

     //PRE:
     //POS:muestra en terminal el menu inicial
     void mostrar_menu_inicial();

     //PRE:
     //POS:muestra en terminal el menu de juego
     void mostrar_menu_juego();

     void colocar_jugadores();
 
     void poner_jugador(int jugador);

     //PRE:
     //POS:
     void cambiar_turno();

     //PRE:
     //POS: muestra quien tiene el turno
     void mostrar_turno();

     //PRE:
     //POS: muestra la energia del jugador que este en su turno
     void mostrar_energia();

     //PRE:
     //POS: controla que la energia no pase el maximo y de cambiar de turno si se acaba
     void chequear_energia();

     bool consultar_energia(int costo_energia);

     //PRE:
     //POS:
     void modificar_edificio();

     //PRE:
     //POS: muestra en terminal todos los edificios leidos en edificios.txt con sus cualidades
     void listar_edificios();

     //PRE:
     //POS: muestra en terminal una matriz con letras en diferentes colores segun el tipo de casillero,
     // esta matriz representa el mapa del juego
     void mostrar_mapa_terrenos();

     //PRE:
     //POS:
     void cambiar_cantidad_jugadores();

     //PRE:
     //POS: comienza el juego
     void comenzar_partida();

     //PRE: debe recibir un tipo de dato edificio
     //POS: devuelve un valor booleano que representa si se puede o no construir el edificio,
     // ademas de mostrar un mensaje en caso de que no se pueda
     bool comprobar_construccion(string nombre);

     int devolver_cantidad_construida(string nombre);

     void sumar_edificio(string nombre);

     void restar_edificio(string nombre);

     void imprimir_caracter_especial(string caracter, int cantidad, bool espacio);

     void imprimir_cuadro_referencias_terrenos();

     void mostrar_mapa();

     //PRE:
     //POS: si los datos  de mapa y datos_materiales tanto como de los ingresados por el usuario lo permiten,
     // se "construye" un edificio y  se modifican mapa y datos_materiales
     void construir_edificio();

     int tipos_minas_construidas();

     int tipos_edificios_construidos(string nombre);

     //PRE:
     //POS: muestra en terminal los edificios construidos, si hay edificios construidos
     void listar_edificios_construidos();


     //PRE:
     //POS: si los datos  de mapa tanto como de los ingresados por el usuario lo permiten,
     // se "destruye" un edificio y se modifican mapa y datos_materiales
     void demoler_edificio();

     //PRE:
     //POS:
     void atacar_construccion();

     //PRE:
     //POS:
     void reparar_construccion();

     //PRE:
     //POS:
     void comprar_bombas();

     //PRE:
     //POS: le permite al usuario consultar que hay en una coordenada
     // y segun lo que ingrese el usuario mostrara en termina diferentes mensajes
     void consultar_coordenada();

     //PRE:
     //POS: muestra en terminal los materiales  y la cantidad de materiales que se tiene
     void mostrar_inventario();

     //PRE:
     //POS:
     void mostrar_objetivos();

     //PRE:
     //POS: recolecta los materiales que generan los edificios, si es que hay edificios que generan materiales,
     // y los guarda en datos_materiales
     void recolectar_recursos();

     //PRE:
     //POS: genera aleatoriamente materiales en los casilleros transitables del mapa
     void lluvia_recursos();

     //PRE:
     //POS:
     void moverse_coordenada();

     //PRE:
     //POS:
     void finalizar_turno();

     //PRE: los archivos que necesitan los objetos mapa y datos materiales deben existir en el directorio
     //POS: guardan las modificaciones que se hayan producido durante la ejecucion del programa
     void guardar_salir();

     //PRE: debe recibir un string
     //POS: devuelve la misma string pero con todos las palabras en minuscula
     string minusculizar(string nombre);

     //PRE: debe recibir un string
     //POS: comprueba si es un numero y si no lo es pide el ingreso de uno
     int ingrese_numero(string numero);
};

#endif // MENU_H_INCLUDED

#ifdef __linux__
#define CLR_SCREEN "clear"
#endif // __linux__

#ifdef __MINGW32__
#define CLR_SCREEN "CLS"
#endif // __MINGW32__
