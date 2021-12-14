#ifndef GRAFOS_FLOYD_H
#define GRAFOS_FLOYD_H
#include <string>
#include <iostream>
#include "Lista.h"
#include "Vertice.h"
#include "Structs Constantes.h"

using namespace std;

class Floyd {
private:
    //Atributos
    int ** matriz_adyacencia;
    Lista<Vertice> * vertices;
    int cantidad_vertices;
    int ** matriz_costos;
    int ** matriz_caminos;

    //Metodos privados
    /*
    * Pre: -.
    * Post: Crea la matriz de caminos y costos.
    */
    void crear_matriz_camino_costos(int ** matriz_adyacencia);

     /*
    * Pre: -.
    * Post: Agranda el camino pasado por parametro.
    */
    void agrandar_camino_especifico(camino_especifico *datos, int fila , int columna);

    /*
    * Pre:
    * Post: Libera la memoria de las matrices de costos y caminos.
    */
    void liberarMatrices();

     /*
    * Pre: -.
    * Post: Calcula las matrices de costos y caminos
    */
    void calcular_matrices();

public:
    //Métodos públicos
    //Constructor
    Floyd(Lista<Vertice> *vertices, int ** matriz_adyacencia);

    /*
    * Pre: Recibe un origen y un destino.
    * Post: Muestra por pantalla el camino mínimo entre el origen y el destino,
    *       detallando su recorrido y peso.
    */
    camino_especifico camino_minimo(int origen, int destino);

    //Destructor
    ~Floyd();
};


#endif //GRAFOS_FLOYD_H
