#ifndef GRAFOS_VERTICE_H
#define GRAFOS_VERTICE_H

#include <string>

using namespace std;

class Vertice {
/*ATRIBUTOS*/
private:
    int fila;
    int columna;
    int costo;

/*MÉTODOS*/
public:
    Vertice(int fila, int columna, int peso);

    string obtenerNombre();

    bool comprobar_vertice(int fila, int columna);

    int obtenerCosto();

    int obtenerFila();

    int obtenerColumna();

    ~Vertice();
};


#endif //GRAFOS_VERTICE_H
