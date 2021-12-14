#include "Grafo.h"

Grafo::Grafo() {
    matriz_adyacencia = nullptr;
    vertices = new Lista<Vertice>();
    algoritmo_camino_minimo = nullptr;
}

void Grafo::agregar_vertice(int fila, int columna, int costo) {
    agrandar_matriz_adyacente();
    vertices -> agregar(fila, columna, costo);
}

void Grafo::agregar_camino(int fila_origen, int columna_origen, int fila_destino, int columna_destino) {
    int posicionOrigen = vertices ->obtener_posicion(fila_origen, columna_origen);
    int posicionDestino = vertices ->obtener_posicion(fila_destino, columna_destino);
    matriz_adyacencia[posicionDestino][posicionOrigen] = vertices ->obtener_costo(posicionOrigen);
    matriz_adyacencia[posicionOrigen][posicionDestino] = vertices ->obtener_costo(posicionDestino);
}

camino_especifico Grafo::camino_minimo(int fila_salida, int columna_salida, int fila_llegada, int columna_llegada) {
    int posicionOrigen = vertices ->obtener_posicion(fila_salida, columna_salida);
    int posicionDestino = vertices ->obtener_posicion(fila_llegada, columna_llegada);
    return camino_minimo(posicionOrigen, posicionDestino);
}

void Grafo::agrandar_matriz_adyacente() {
    int** matrizAuxiliar;
    int nuevaCantidadDeVertices = vertices->obtener_cantidad_elementos() + 1;

    matrizAuxiliar = new int*[nuevaCantidadDeVertices];
    for(int i = 0; i < nuevaCantidadDeVertices; i++){
        matrizAuxiliar[i] = new int[nuevaCantidadDeVertices];
    }

    copiar_matriz_adyacente(matrizAuxiliar);
    inicializar_nuevo_vertice(matrizAuxiliar);
    liberar_matriz_adyacencia();
    matriz_adyacencia = matrizAuxiliar;
}

void Grafo::copiar_matriz_adyacente(int** nueva_adyacente) {
    for(int i = 0; i < vertices -> obtener_cantidad_elementos(); i++){
        for(int j = 0; j < vertices -> obtener_cantidad_elementos(); j++){
            nueva_adyacente[i][j] = matriz_adyacencia[i][j];
        }
    }
}

void Grafo::inicializar_nuevo_vertice(int** nueva_adyacente) {
    for(int i = 0; i < vertices -> obtener_cantidad_elementos(); i++){
        nueva_adyacente[vertices -> obtener_cantidad_elementos()][i] = INFINITO;
        nueva_adyacente[i][vertices -> obtener_cantidad_elementos()] = INFINITO;
    }
    nueva_adyacente[vertices -> obtener_cantidad_elementos()][vertices -> obtener_cantidad_elementos()] = 0;
}

void Grafo::liberar_matriz_adyacencia() {
    for(int i = 0; i < vertices -> obtener_cantidad_elementos(); i++){
        delete[] matriz_adyacencia[i];
    }
    delete[] matriz_adyacencia;
}

Grafo::~Grafo() {
    liberar_matriz_adyacencia();
    matriz_adyacencia = nullptr;
    delete vertices;
    delete algoritmo_camino_minimo;
}


camino_especifico Grafo::camino_minimo(int origen, int destino) {
    return algoritmo_camino_minimo -> camino_minimo(origen, destino);
}

void Grafo::usar_floyd() {
    algoritmo_camino_minimo = new Floyd(vertices, matriz_adyacencia);
}

