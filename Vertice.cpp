#include "Vertice.h"

Vertice::Vertice(int fila, int columna, int costo) {
    this->fila = fila;
    this->columna =columna;
    this->costo = costo;
}

string Vertice::obtenerNombre() {
    string coordenada = "("+to_string(fila)+", "+to_string(columna)+")";
    return coordenada;
}

int Vertice::obtenerFila(){
    return fila;
}

int Vertice::obtenerColumna(){
    return columna;
}

bool Vertice::comprobar_vertice(int fila, int columna){
    return (this->fila == fila && this->columna == columna);
}

int Vertice::obtenerCosto() {
    return costo;
}

Vertice::~Vertice() {

}
