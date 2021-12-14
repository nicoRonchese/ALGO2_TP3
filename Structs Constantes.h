#ifndef STRUCTS_CONSTANTES_H_INCLUDED
#define STRUCTS_CONSTANTES_H_INCLUDED
#include <string>

using namespace std;


const string PATH_MATERIALES = "materiales.txt";
const int PIEDRA = 0;
const int MADERA = 1;
const int METAL = 2;
const int ANDYCOIN = 3;
const int BOMBA = 4;
const string NOMBRE_PIEDRA = "piedra";
const string NOMBRE_MADERA = "madera";
const string NOMBRE_METAL = "metal";
const string NOMBRE_ANDYCOIN = "andycoins";
const string NOMBRE_BOMBA = "bombas";
const int COSTO_BOMBA = 100;
const string PATH_EDIFICIOS = "edificios.txt";
const string PRODUCCION_ASERRADERO = "Produce 25 de madera";
const string PRODUCCION_MINA = "Produce 15 de piedra";
const string PRODUCCION_FABRICA = "Produce 40 de metal";
const string PRODUCCION_ESCUELA = "Produce 25 andycoins";
const string PRODUCCION_PLANTA_ELECTRICA = "Produce 15 de energia";
const string PRODUCCION_MINA_ORO = "Produce 50 andycoins";
const string ASERRADERO = "aserradero";
const string MINA = "mina";
const string FABRICA = "fabrica";
const string ESCUELA = "escuela";
const string OBELISCO = "obelisco";
const string PLANTA_ELECTRICA = "planta electrica";
const string MINA_ORO = "mina oro";
const string SIGNO_ASERRADERO = "A";
const string SIGNO_MINA = "M";
const string SIGNO_FABRICA = "F";
const string SIGNO_ESCUELA = "E";
const string SIGNO_OBELISCO = "O";
const string SIGNO_PLANTA_ELECTRICA = "P";
const string SIGNO_MINA_ORO = "G";
const int VIDA_EDIFICIO_FUERTE = 100;
const int VIDA_EDIFICIO_DEBIL = 50;
const string CONSTRUIBLE = "C";
const string INACCESIBLE = "L";
const string TRANSITABLE = "T";
const string LAGO = "L";
const string CAMINO = "C";
const string MUELLE = "M";
const string BETUN = "B";
const string TERRENO = "T";
const string VACIO = "V";
const string SIGNO_MADERA = "W";
const string SIGNO_METAL = "I";
const string SIGNO_PIEDRA = "S";
const string SIGNO_ANDYCOIN = "G";
const int CANTIDAD_PIEDRA = 100;
const int CANTIDAD_MADERA = 50;
const int CANTIDAD_METAL = 50;
const int CANTIDAD_ANDYCOIN = 250;
const int PRODUCCION_ASERRADERO_CANTIDAD = 25;
const int PRODUCCION_FABRICA_CANTIDAD = 40;
const int PRODUCCION_MINA_CANTIDAD = 15;
const int PRODUCCION_ESCUELA_CANTIDAD = 25;
const int PRODUCCION_MINA_ORO_CANTIDAD = 50;
const int PRODUCCION_PLANTA_ELECTRICA_CANTIDAD = 15;
const string PATH_MAPA = "mapa.txt";
const string PATH_UBICACIONES = "ubicaciones.txt";
const int COSTO_MUELLE_UNO = 5;
const int COSTO_MUELLE_DOS = 2;
const int COSTO_LAGO_UNO = 2;
const int COSTO_LAGO_DOS = 5;
const int COSTO_BETUN = 0;
const int COSTO_CAMINO = 4;
const int COSTO_TERRENO = 25;
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
const int POSICION_NO_ENCONTRADA = -1;
const string NOMBRE_NO_ENCONTRADO = "";
const int INFINITO = 99999999;

struct camino_especifico
{
    int **camino;
    int costo;
    int longitud;
};

struct objetivo{
    int tipo_objetivo;
    bool cumplido;
    int cantidad;
};

struct edificio{
    int cantidad_piedra;
    int cantidad_madera;
    int cantidad_metal;
    int maxima_cantidad_permitida;
    string produccion = "";
};


struct material{
    string nombre;
    int cantidad;
};


#endif
