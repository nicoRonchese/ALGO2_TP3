#ifndef GRAFOS_FLOYD_H
#define GRAFOS_FLOYD_H
#include <string>
#include "Lista.h"
#include "Vertice.h"
#include "Vertice.cpp"
#include <iostream>

const int INFINITO = 99999999;

struct camino_especifico
{
    int **camino;
    int costo;
    int longitud;
};


using namespace std;

class Floyd {
private:
    int ** matrizAdyacencia;
    Lista<Vertice> * vertices;
    int cantidadVertices;
    int ** matrizCostos;
    int ** matrizCaminos;


    void crearMatrizCamino_Costos(int ** matrizAdyacencia);

    void agrandarCaminoEspecifico(camino_especifico *datos, int fila , int columna);

    //post: libera la memoria de las matrices de costos y caminos
    void liberarMatrices();

    //post:calcula las matrices de costos y caminos.
    void calcularMatrices();

public:
    Floyd(Lista<Vertice> *vertices, int ** matrizAdyacencia);

    //post: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    camino_especifico caminoMinimo(int origen, int destino);

    ~Floyd();
};


#endif //GRAFOS_FLOYD_H
