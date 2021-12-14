#ifndef GRAFOS_VERTICE_H
#define GRAFOS_VERTICE_H

#include <string>

using namespace std;

class Vertice {
private:
    /*ATRIBUTOS*/
    int fila;
    int columna;
    int costo;

public:
    /*MÉTODOS PÚBLICOS*/
    /*
    Constructor.
    * Pre: -.
    * Post: Construye el vertice con los datos pasados por parametro.
    */
    Vertice(int fila, int columna, int peso);


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
    int obtener_costo();

    /*
    * Pre:  -.
    * Post: Devuelve la fila.
    */
    int obtener_fila();

    /*
    * Pre:  -.
    * Post: Devuelve la columna.
    */
    int obtener_columna();

    /*
    Destructor
    */
    ~Vertice();
};


#endif //GRAFOS_VERTICE_H
