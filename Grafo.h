#ifndef GRAFOS_GRAFO_H
#define GRAFOS_GRAFO_H
#include <string>
#include "Lista.h"
#include "Vertice.h"
#include "Floyd.h"
#include "Floyd.cpp"



using namespace std;

class Grafo {
/*ATRIBUTOS*/
private:
    int ** matrizDeAdyacencia;
    Lista<Vertice> * vertices;
    Floyd * algoritmoCaminoMinimo;

/*MÉTODOS PRIVADOS*/

    //pre: tienen que existir tanto el origen como el destino. Ademas se deben haber calculado las matrices de Floyd
    //post: muestra el camino minimo entre el origen y el destino
    camino_especifico caminoMinimo(int origen, int destino);

    //post: agranda dinamicamente la matriz de adyacencia
    void agrandarMatrizDeAdyacencia();

    //pre: la matriz que se le envie ya debe tener memoria reservada
    //post: copia la matriz de adyacencia en la nueva matriz
    void copiarMatrizAdyacente(int** nuevaAdyacente);

    //post inicializa un nuevo vertice en la matriz de adyacencia con un valor de infinito
    void inicializarNuevoVertice(int** nuevaAdyacente);

    //post libera la memoria de la matriz de adyacencia
    void liberarMatrizAdyacencia();

public:
    /*MÉTODOS PUBLICOS*/

    //Constructor
    Grafo();

    //pre: No hay vertices repetidos en nombre
    //post: agrega un nuevo vertice al grafo
    void agregarVertice(int fila, int columna, int costo);

    //pre: se debe tener un algortimo para calcular el camino mínimo previamente elegido
    //post: muestra por terminal el camino mínimo desde un origen a un destino
    camino_especifico caminoMinimo(int fila_salida, int columna_salida, int fila_llegada, int columna_llegada);

    //pre: el peso es un valor positivo
    //post: Ajusta la matriz de adyacencia con el peso ingresado
    void agregarCamino(int fila_origen, int columna_origen, int fila_destino, int columna_destino);

    //post: selecciona el algortimo de Floyd para calcular el camino mínimo
    void usarFloyd();

    //Destructor
    ~Grafo();
};


#endif //GRAFOS_GRAFO_H
