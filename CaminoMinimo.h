#ifndef GRAFOS_CAMINOMINIMO_H
#define GRAFOS_CAMINOMINIMO_H
#include <string>
#include "Lista.h"
#include "Vertice.h"
#include "Vertice.cpp"
#include <iostream>



class CaminoMinimo {
//Atributos
protected:
    int ** matrizAdyacencia;
    Lista<Vertice> * vertices;
    int cantidadVertices;

//Métodos
public:
    CaminoMinimo(Lista<Vertice> * vertices, int** matrizAdyacencia);

    //post: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    virtual int caminoMinimo(int origen, int destino);

    virtual void recolectarCamino(int origen, int destino);

    virtual ~CaminoMinimo() = default;
};


#endif //GRAFOS_CAMINOMINIMO_H
