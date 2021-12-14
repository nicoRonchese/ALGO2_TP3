#ifndef GRAFOS_GRAFO_H
#define GRAFOS_GRAFO_H
#include <string>
#include <iostream>
#include "Lista.h"
#include "Vertice.h"
#include "Floyd.h"

using namespace std;

class Grafo {
private:
    /*ATRIBUTOS*/
    int ** matriz_adyacencia;
    Lista<Vertice> * vertices;
    Floyd * algoritmo_camino_minimo;

/*MÉTODOS PRIVADOS*/

    //pre: tienen que existir tanto el origen como el destino. Ademas se deben haber calculado las matrices de Floyd
    //post: devuelve el camino minimo entre el origen y el destino
    camino_especifico camino_minimo(int origen, int destino);

    //post: agranda dinamicamente la matriz de adyacencia
    void agrandar_matriz_adyacente();

    //pre: la matriz que se le envie ya debe tener memoria reservada
    //post: copia la matriz de adyacencia en la nueva matriz
    void copiar_matriz_adyacente(int** nueva_adyacente);

    //post inicializa un nuevo vertice en la matriz de adyacencia con un valor de infinito
    void inicializar_nuevo_vertice(int** nueva_adyacente);

    //post libera la memoria de la matriz de adyacencia
    void liberar_matriz_adyacencia();

public:
    /*MÉTODOS PÚBLICOS*/
    //Constructor
    Grafo();

    //pre: No hay vertices repetidos en nombre
    //post: agrega un nuevo vertice al grafo con su costo
    void agregar_vertice(int fila, int columna, int costo);

    //pre: las filas y columnas deben estar dentro de las dimensiones de la matriz del mapa
    //post: devuelve el camino minimo
    camino_especifico camino_minimo(int fila_salida, int columna_salida, int fila_llegada, int columna_llegada);

    //pre: las filas y columnas deben estar dentro de las dimensiones de la matriz del mapa
    //post: Ajusta la matriz de adyacencia
    void agregar_camino(int fila_origen, int columna_origen, int fila_destino, int columna_destino);

    //post: selecciona el algortimo de Floyd para calcular el camino mínimo
    void usar_floyd();

    //Destructor
    ~Grafo();
};


#endif //GRAFOS_GRAFO_H
