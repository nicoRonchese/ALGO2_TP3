#include "Grafo.h"
#include <iostream>

Grafo::Grafo() {
    matrizDeAdyacencia = nullptr;
    vertices = new Lista<Vertice>();
    algoritmoCaminoMinimo = nullptr;
}

void Grafo::agregarVertice(int fila, int columna, int costo) {
    agrandarMatrizDeAdyacencia();
    vertices -> agregar(fila, columna, costo);
}

void Grafo::agregarCamino(int fila_origen, int columna_origen, int fila_destino, int columna_destino) {
    int posicionOrigen = vertices ->obtenerPosicion(fila_origen, columna_origen);
    int posicionDestino = vertices ->obtenerPosicion(fila_destino, columna_destino);

    if(posicionOrigen == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << vertices ->obtenerNombre(posicionOrigen) << " no existe en el grafo" << endl;
    }
    if(posicionDestino == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << vertices ->obtenerNombre(posicionOrigen) << " no existe en el grafo" << endl;
    }
    else {
        matrizDeAdyacencia[posicionDestino][posicionOrigen] = vertices ->obtenerCosto(posicionOrigen);
        matrizDeAdyacencia[posicionOrigen][posicionDestino] = vertices ->obtenerCosto(posicionDestino);
    }
}

camino_especifico Grafo::caminoMinimo(int fila_salida, int columna_salida, int fila_llegada, int columna_llegada) {
    int posicionOrigen = vertices ->obtenerPosicion(fila_salida, columna_salida);
    int posicionDestino = vertices ->obtenerPosicion(fila_llegada, columna_llegada);
    if(posicionOrigen == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << vertices ->obtenerNombre(posicionOrigen) << " no existe en el grafo" << endl;
    }
    if(posicionDestino == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << vertices ->obtenerNombre(posicionDestino) << " no existe en el grafo" << endl;
    }
    return caminoMinimo(posicionOrigen, posicionDestino);
}

void Grafo::agrandarMatrizDeAdyacencia() {
    int** matrizAuxiliar;
    int nuevaCantidadDeVertices = vertices->obtenerCantidadDeElementos() + 1;

    matrizAuxiliar = new int*[nuevaCantidadDeVertices];
    for(int i = 0; i < nuevaCantidadDeVertices; i++){
        matrizAuxiliar[i] = new int[nuevaCantidadDeVertices];
    }

    copiarMatrizAdyacente(matrizAuxiliar);
    inicializarNuevoVertice(matrizAuxiliar);
    liberarMatrizAdyacencia();
    matrizDeAdyacencia = matrizAuxiliar;
}

void Grafo::copiarMatrizAdyacente(int** nuevaAdyacente) {
    for(int i = 0; i < vertices -> obtenerCantidadDeElementos(); i++){
        for(int j = 0; j < vertices -> obtenerCantidadDeElementos(); j++){
            nuevaAdyacente[i][j] = matrizDeAdyacencia[i][j];
        }
    }
}

void Grafo::inicializarNuevoVertice(int** nuevaAdyacente) {
    for(int i = 0; i < vertices -> obtenerCantidadDeElementos(); i++){
        nuevaAdyacente[vertices -> obtenerCantidadDeElementos()][i] = INFINITO;
        nuevaAdyacente[i][vertices -> obtenerCantidadDeElementos()] = INFINITO;
    }
    nuevaAdyacente[vertices -> obtenerCantidadDeElementos()][vertices -> obtenerCantidadDeElementos()] = 0;
}

void Grafo::liberarMatrizAdyacencia() {
    for(int i = 0; i < vertices -> obtenerCantidadDeElementos(); i++){
        delete[] matrizDeAdyacencia[i];
    }
    delete[] matrizDeAdyacencia;
}

Grafo::~Grafo() {
    liberarMatrizAdyacencia();
    matrizDeAdyacencia = nullptr;
    delete vertices;
    delete algoritmoCaminoMinimo;
}


camino_especifico Grafo::caminoMinimo(int origen, int destino) {
    return algoritmoCaminoMinimo -> caminoMinimo(origen, destino);
}

void Grafo::usarFloyd() {
    algoritmoCaminoMinimo = new Floyd(vertices, matrizDeAdyacencia);
}

