#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include <iostream>
#include <string.h>
#include "Mapa.h"
#include "Datos Materiales.h"
#include "Datos Edificios.h"
#include "Objetivos.h"
#include "Structs Constantes.h"


using namespace std;

#define SUBRAYADO "\033[4m"
#define CUADRO_HORIZONTAL "\u2505"
#define CUADRO_VERTICAL "\u2507"


class Juego{
 private:
     //Atributos

     Mapa* mapa;
     DatosMateriales* datosMateriales;
     DatosEdificios* datosEdificios;
     ContadorEdificios** edificios_construidos;
     Objetivos** objetivos;
     int** posiciones_jugadores;
     int turno;
     int cantidad_jugadores;
     int* energia;

 public:
     //Métodos públicos

     //Constructor
     //PRE: Los archivos que necesitan los objetos mapa y datos materiales deben existir en el directorio.
     //POS: Obtiene los datos con los que el sistema puede trabajar.
     Juego();

     //Destructor
     //PRE:
     //POS: libera la memoria tomada
     ~Juego();

     //PRE:
     //POS: Permite al usuario utilizar el juego y modificar los archivos
     void empezar_juego();

 private:
     //Métodos privados

     //PRE: -.
     //POS: Crea los datos de los jugadores.
     void crear_datos_jugadores();

     //PRE: -.
     //POS: Actualiza los objetivos con los datos iniciales del juego
     void inicializar_datos_objetivos();

     //PRE:-.
     //POS: Actualiza y procesa las opciones del menú inicial.
     void menu_inicial();

     //PRE: -.
     //POS: Actualiza y procesa las opciones del menú de la partida.
     void menu_juego();

     //PRE: debe recibir un int
     //POS: segun el numero realizara una tarea
     void procesar_opcion_inicial(int opcion);

     //PRE: debe recibir un int
     //POS: segun el numero realizara una tarea
     void procesar_opcion_juego(int opcion);

     //PRE:-.
     //POS:muestra en terminal el menu inicial
     void mostrar_menu_inicial();

     //PRE:-.
     //POS: muestra en terminal el menu de juego
     void mostrar_menu_juego();

     //PRE: -.
     //POS: Pide las coordenadas para colocar todos los jugadores del juego.
     void colocar_jugadores();

     //PRE: -.
     //POS: Coloca un jugador en el mapa.
     void poner_jugador(int jugador);

     //PRE:-.
     //POS: Cambia el turno al jugador siguiente.
     void cambiar_turno();

     //PRE:-.
     //POS: muestra quien tiene el turno
     void mostrar_turno();

     //PRE:-.
     //POS: muestra la energia del jugador que este en su turno
     void mostrar_energia();

     //PRE:
     //POS: controla que la energia no pase el maximo y de cambiar de turno si se acaba
     void chequear_energia();

     //PRE: -.
     //POS: Devuelve 'true' si se tiene la energia necesaria para realizar la acción y
     //     'false' de no ser así.
     bool consultar_energia(int costo_energia);

     //PRE:-.
     //POS: modifica el edificio que se pasa por consola.
     void modificar_edificio();

     //PRE:-.
     //POS: muestra en terminal todos los edificios leidos en edificios.txt con sus cualidades
     void listar_edificios();

     //PRE:-.
     //POS: muestra en terminal una matriz con letras que representan terrenos
     void mostrar_mapa_terrenos();

     //PRE:-.
     //POS: cambia la cantidad de jugadores.
     void cambiar_cantidad_jugadores();

     //PRE:-.
     //POS: comienza la partida
     void comenzar_partida();

     //PRE: debe recibir un tipo de dato edificio
     //POS: devuelve un valor booleano que representa si se puede o no construir el edificio,
     // ademas de mostrar un mensaje en caso de que no se pueda
     bool comprobar_construccion(string nombre);

     //PRE: -.
     //POS: Imprime un caracter especial las veces pasadas por parametro.
     void imprimir_caracter_especial(string caracter, int cantidad, bool espacio);

     //PRE: -.
     //POS: Imprime por pantalla las referencias a los terrenos.
     void imprimir_cuadro_referencias_terrenos();

     //PRE: -.
     //POS: muestra en terminal una matriz con letras en diferentes colores segun el tipo de casillero,
     // esta matriz representa el mapa del juego
     void mostrar_mapa();

     //PRE:
     //POS: si los datos  de mapa y datos_materiales tanto como de los ingresados por el usuario lo permiten,
     // se "construye" un edificio y  se modifican mapa y datos_materiales
     void construir_edificio();

     //PRE:
     //POS: muestra en terminal los edificios construidos, si hay edificios construidos
     void listar_edificios_construidos();


     //PRE:
     //POS: si los datos  de mapa tanto como de los ingresados por el usuario lo permiten,
     // se "destruye" un edificio y se modifican mapa y datos_materiales
     void demoler_edificio();

     //PRE:
     //POS: Ataca la construcción ubicada en la fila y columna pasada por consola.
     void atacar_construccion();

     //PRE:
     //POS: Repara la construcción ubicada en la fila y columna pasada por consola.
     void reparar_construccion();

     //PRE:-.
     //POS:Compra la cantidad de bombas que son pasadas por consola.
     void comprar_bombas();

     //PRE:-.
     //POS: le permite al usuario consultar que hay en una coordenada
     // y segun lo que ingrese el usuario mostrara en termina diferentes mensajes
     void consultar_coordenada();

     //PRE:-.
     //POS: muestra en terminal los materiales  y la cantidad de materiales que se tiene
     void mostrar_inventario();

     //PRE: -.
     //POS: Muestra los objetivos del jugador.
     void mostrar_objetivos();

     //PRE: -.
     //POS: recolecta los materiales/energia que generan los edificios y los guarda en datos_materiales
     void recolectar_recursos();

     //PRE:
     //POS: genera aleatoriamente materiales en los casilleros transitables del mapa
     void lluvia_recursos();

     //PRE: -.
     //POS: Se mueve al casillero pasado por consola.
     void moverse_coordenada();

     //PRE: -.
     //POS: Finaliza el turno del jugador actual.
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

     //PRE: -.
     //POS: Evalua si la cantidad ingresada esta en un rango valido y la devuelve.
     int ingresar_cantidad();
};

#endif // JUEGO_H_INCLUDED

#ifdef __linux__
#define CLR_SCREEN "clear"
#endif // __linux__

#ifdef __MINGW32__
#define CLR_SCREEN "CLS"
#endif // __MINGW32__
