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
    //Atributos
    int ** matrizAdyacencia;
    Lista<Vertice> * vertices;
    int cantidadVertices;
    int ** matrizCostos;
    int ** matrizCaminos;

    //Metodos privados
    /*
    * Pre: -.
    * Post: Crea la matriz de caminos y costos.
    */
    void crearMatrizCamino_Costos(int ** matrizAdyacencia);

    /*
    * Pre: -.
    * Post: Agranda el camino pasado por parametro.
    */
    void agrandarCaminoEspecifico(camino_especifico *datos, int fila , int columna);

    /*
    * Pre: Recibe el nombre de un edificio valido.
    * Post: Libera la memoria de las matrices de costos y caminos.
    */
    void liberarMatrices();

    /*
    * Pre: -.
    * Post: Calcula las matrices de costos y caminos
    */
    void calcularMatrices();

public:
    //Métodos públicos
    //Constructor
    Floyd(Lista<Vertice> *vertices, int ** matrizAdyacencia);

    /*
    * Pre: Recibe un origen y un destino.
    * Post: Muestra por pantalla el camino mínimo entre el origen y el destino, 
    *       detallando su recorrido y peso.
    */
    camino_especifico caminoMinimo(int origen, int destino);

    //Destructor
    ~Floyd();
};


#endif //GRAFOS_FLOYD_H
