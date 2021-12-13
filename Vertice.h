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
    /*
    Constructor.
    * Pre: -.
    * Post: Construye el vertice con los datos pasados por parametro.
    */
    Vertice(int fila, int columna, int peso);

    /*
    * Pre:  -.
    * Post: Devuelve la coordenada en forma de string.
    */
    string obtenerNombre();

    /*
    * Pre:  -.
    * Post: Devuelve 'true' si la fila y columna pasadas por parametro coinciden con las del
    *       vertice y 'false' de no ser así.
    */
    bool comprobar_vertice(int fila, int columna);

    /*
    * Pre:  -.
    * Post: Devuelve el costo.
    */
    int obtenerCosto();

    /*
    * Pre:  -.
    * Post: Devuelve la fila.
    */
    int obtenerFila();

    /*
    * Pre:  -.
    * Post: Devuelve la columna.
    */
    int obtenerColumna();

    /*
    Destructor
    */
    ~Vertice();
};


#endif //GRAFOS_VERTICE_H
