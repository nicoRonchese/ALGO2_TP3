#include "Vertice.h"

Vertice::Vertice(int fila, int columna, int costo) {
    this->fila = fila;
    this->columna =columna;
    this->costo = costo;
}

int Vertice::obtener_fila(){
 return fila;
}

int Vertice::obtener_columna(){
 return columna;
}

bool Vertice::comprobar_vertice(int fila, int columna){
 return (this->fila==fila && this->columna==columna);
}

int Vertice::obtener_costo() {
    return costo;
}

Vertice::~Vertice() {

}
