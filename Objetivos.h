#ifndef OBJETIVOS_H_INCLUDED
#define OBJETIVOS_H_INCLUDED
#include <iostream>
#include <string.h>
#include <random>
#include <ctime>

using namespace std;

const int COMPRAR_ANDYPOLIS = 0;
const int EDAD_PIEDRA = 1;
const int BOMBARDERO = 2;
const int ENERGETICO = 3;
const int LETRADO = 4;
const int MINERO = 5;
const int CANSADO = 6;
const int CONSTRUCTOR = 7;
const int ARMADO = 8;
const int EXTREMISTA = 9;
const int TOTAL_OBJETIVOS = 9;
const int TOTAL_OBJETIVOS_JUGADOR = 3;
const int TOTAL_OBJETIVOS_PARA_GANAR = 2;

struct Objetivo{
    int tipo_objetivo;
    bool cumplido;
    int cantidad;
};

class Objetivos{
 private:
  Objetivo** objetivos;
  int maximo_escuelas;
  bool obelisco = false;
  bool escuela = false;
  bool aserradero = false;
  bool mina = false;
  bool mina_oro = false;
  bool fabrica = false;
  bool planta_electrica = false;

 public:
  Objetivos(int maximo_escuelas);

  ~Objetivos();

  void construccion_obelisco();

  void mostrar_victoria(int jugador);

  bool comprobar_objetivos_cumplidos();

  void mostrar_objetivos();

  void actualizar_objetivo(int tipo_objetivo, int cantidad);

  void actualizar_tipos_construidos(string nombre);

  int devolver_cantidad_construidos();

  int devolver_tipos_minas_construidas();

 private:

  void sorteo_objetivos();

  void mostrar_objetivos_cumplidos();

  void mostrar_objetivo(int numero_objetivo, int ubicacion_objetivo);

  void mostrar_comprar_andypolis(int ubicacion_objetivo);

  void mostrar_edad_piedra(int ubicacion_objetivo);

  void mostrar_bombardero(int ubicacion_objetivo);

  void mostrar_energetico(int ubicacion_objetivo);

  void mostrar_letrado(int ubicacion_objetivo);

  void mostrar_minero(int ubicacion_objetivo);

  void mostrar_cansado(int ubicacion_objetivo);

  void mostrar_constructor(int ubicacion_objetivo);

  void mostrar_armado(int ubicacion_objetivo);

  void mostrar_extremista(int ubicacion_objetivo);

  void procesar_objetivo(int numero_objetivo, int cantidad, int ubicacion_objetivo);

  void comprar_andypolis(int andycoins_ganados, int ubicacion_objetivo);

  void edad_piedra(int piedra, int ubicacion_objetivo);

  void bombardero(int bombas_usadas, int ubicacion_objetivo);

  void energetico(int energia, int ubicacion_objetivo);

  void letrado(int cantidad_escuelas, int ubicacion_objetivo);

  void minero(int minas_construidas, int ubicacion_objetivo);

  void cansado(int energia, int ubicacion_objetivo);

  void constructor(int cantidad_edificios, int ubicacion_objetivo);

  void armado(int bombas_inventario, int ubicacion_objetivo);

  void extremista(int bombas_compradas, int ubicacion_objetivo);

  void sortear_objetivos(int* objetivos_preparados, int total_objetivos_jugador);

  bool hay_objetivo_repetido(int* objetivos_preparados, int objetivo_actual);
};

#endif // OBJETIVOS_H_INCLUDED
