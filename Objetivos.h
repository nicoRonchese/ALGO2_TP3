#ifndef OBJETIVOS_H_INCLUDED
#define OBJETIVOS_H_INCLUDED
#include <iostream>
#include <string.h>
#include <random>
#include <ctime>
#include "Structs Constantes.h"

using namespace std;


class Objetivos{
 private:
  objetivo** objetivos;
  int maximo_escuelas;
  bool obelisco = false;
  bool escuela = false;
  bool aserradero = false;
  bool mina = false;
  bool mina_oro = false;
  bool fabrica = false;
  bool planta_electrica = false;

 public:
  //Métodos públicos
  /*
  Constructor
  * Pre: Recibe el máximo de escuelas.
  * Post: Crea los objetivos.
  */
  Objetivos(int maximo_escuelas);

  /*
  * Pre: -.
  * Post: Se cumple el objetivo de construcción del obelisco.
  */
  void construccion_obelisco();

  /*
  * Pre:  Recibe un jugador valido.
  * Post: Muestra por pantalla un mensaje cuando el jugador gana el juego.
  */
  void mostrar_victoria(int jugador);

  /*
  * Pre: -.
  * Post: Devuelve 'true' si se cumplieron los objetivos necesarios para ganar o 'false' en caso
  *       contrario.
  */
  bool comprobar_objetivos_cumplidos();

  /*
  * Pre: -.
  * Post: Muestra por pantalla los objetivos actuales.
  */
  void mostrar_objetivos();

  /*
  * Pre: -.
  * Post: Actualiza el objetivo pasado por parametro con la cantidad enviada.
  */
  void actualizar_objetivo(int tipo_objetivo, int cantidad);

  /*
  * Pre: -.
  * Post: Actualiza el estado de los edificios.
  */
  void actualizar_tipos_construidos(string nombre);

  /*
  * Pre: -.
  * Post: Devuelve la cantidad de construcciones construidas.
  */
  int devolver_cantidad_construidos();

  /*
  * Pre:  -.
  * Post: Devuelve la cantidad de minas construidas.
  */
  int devolver_tipos_minas_construidas();

  /*
  Destructor
  * Pre: -.
  * Post: Libera la memoria.
  */
  ~Objetivos();

 private:
  //Metodos privados
  /*
  * Pre:  -.
  * Post: Sortea y selecciona los objetivos.
  */
  void sorteo_objetivos();

  /*
  * Pre:  -.
  * Post: Muestra por pantalla los objetivos cumplidos.
  */
  void mostrar_objetivos_cumplidos();

  /*
  * Pre:  -.
  * Post: Muestra el objetivo pasado por parametro y el progreso del mismo.
  */
  void mostrar_objetivo(int numero_objetivo, int ubicacion_objetivo);

  /*
  * Pre:  -.
  * Post: Muestra detalles del objetivo 'comprar andypolis' y el progreso del objetivo.
  */
  void mostrar_comprar_andypolis(int ubicacion_objetivo);

  /*
  * Pre:  -.
  * Post: Muestra detalles del objetivo 'edad de piedra' y el progreso del objetivo.
  */
  void mostrar_edad_piedra(int ubicacion_objetivo);

  /*
  * Pre:  -.
  * Post: Muestra detalles del objetivo 'bombardero' y el progreso del objetivo.
  */
  void mostrar_bombardero(int ubicacion_objetivo);

  /*
  * Pre:  -.
  * Post: Muestra detalles del objetivo 'energetico' y el progreso del objetivo.
  */
  void mostrar_energetico(int ubicacion_objetivo);

  /*
  * Pre:  -.
  * Post: Muestra detalles del objetivo 'letrado' y el progreso del objetivo.
  */
  void mostrar_letrado(int ubicacion_objetivo);

  /*
  * Pre:  -.
  * Post: Muestra detalles del objetivo 'minero' y el progreso del objetivo.
  */
  void mostrar_minero(int ubicacion_objetivo);

  /*
  * Pre:  -.
  * Post: Muestra detalles del objetivo 'cansado' y el progreso del objetivo.
  */
  void mostrar_cansado(int ubicacion_objetivo);

  /*
  * Pre:  -.
  * Post: Muestra detalles del objetivo 'constructor' y el progreso del objetivo.
  */
  void mostrar_constructor(int ubicacion_objetivo);

  /*
  * Pre:  -.
  * Post: Muestra detalles del objetivo 'armado' y el progreso del objetivo.
  */
  void mostrar_armado(int ubicacion_objetivo);

  /*
  * Pre:  -.
  * Post: Muestra detalles del objetivo 'extremista' y el progreso del objetivo.
  */
  void mostrar_extremista(int ubicacion_objetivo);

  /*
  * Pre:  -.
  * Post: Actualiza el objetivo con los datos pasados.
  */
  void procesar_objetivo(int numero_objetivo, int cantidad, int ubicacion_objetivo);

  /*
  * Pre:  -.
  * Post: Actualiza el objetivo 'comprar andypolis' y revisa si esta cumplido.
  */
  void comprar_andypolis(int andycoins_ganados, int ubicacion_objetivo);

  /*
  * Pre:  -.
  * Post: Actualiza el objetivo 'edad de piedra' y revisa si esta cumplido.
  */
  void edad_piedra(int piedra, int ubicacion_objetivo);

  /*
  * Pre:  -.
  * Post: Actualiza el objetivo 'bombardero' y revisa si esta cumplido.
  */
  void bombardero(int bombas_usadas, int ubicacion_objetivo);

  /*
  * Pre:  -.
  * Post: Actualiza el objetivo 'energetico' y revisa si esta cumplido.
  */
  void energetico(int energia, int ubicacion_objetivo);

  /*
  * Pre:  -.
  * Post: Actualiza el objetivo 'letrado' y revisa si esta cumplido.
  */
  void letrado(int cantidad_escuelas, int ubicacion_objetivo);

  /*
  * Pre:  -.
  * Post: Actualiza el objetivo 'minero' y revisa si esta cumplido.
  */
  void minero(int minas_construidas, int ubicacion_objetivo);

  /*
  * Pre:  -.
  * Post: Actualiza el objetivo 'cansado' y revisa si esta cumplido.
  */
  void cansado(int energia, int ubicacion_objetivo);

  /*
  * Pre:  -.
  * Post: Actualiza el objetivo 'constructor' y revisa si esta cumplido.
  */
  void constructor(int cantidad_edificios, int ubicacion_objetivo);

  /*
  * Pre:  -.
  * Post: Actualiza el objetivo 'armado' y revisa si esta cumplido.
  */
  void armado(int bombas_inventario, int ubicacion_objetivo);

  /*
  * Pre:  -.
  * Post: Actualiza el objetivo 'extremista' y revisa si esta cumplido.
  */
  void extremista(int bombas_compradas, int ubicacion_objetivo);

  /*
  * Pre:  -.
  * Post: Sortea un número para elegir los objetivos.
  */
  void sortear_objetivos(int* objetivos_preparados, int total_objetivos_jugador);

  /*
  * Pre:  -.
  * Post: Devuelve 'true' si hay un objetivo repetido y 'false' de no ser así.
  */
  bool hay_objetivo_repetido(int* objetivos_preparados, int objetivo_actual);
};

#endif // OBJETIVOS_H_INCLUDED
