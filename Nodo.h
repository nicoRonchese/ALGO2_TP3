#ifndef GRAFOS_NODO_H
#define GRAFOS_NODO_H
#include <string>

using namespace std;

template < typename Tipo >
class Nodo {
/*ATRIBUTOS*/
private:
    Tipo* elemento;
    Nodo<Tipo>* siguiente;

/*MÉTODOS*/
public:
    /*
    Constructor
    * Pre: Recibe una fila, columna y costo.
    * Post: Crea el nodo.
    */
    Nodo(int fila, int columna, int costo);

    /*
    * Pre: -.
    * Post: Devuelve el nodo siguiente.
    */
    Nodo<Tipo>* obtenerSiguiente();

    /*
    * Pre: -.
    * Post: Devuelve el nombre del nodo.
    */ 
    string obtenerNombre();

    /*
    * Pre: -.
    * Post: Devuelve la fila del nodo.
    */
    int obtenerFila();

    /*
    * Pre: -.
    * Post: Devuelve la columna del nodo.
    */
    int obtenerColumna();

    /*
    * Pre: -.
    * Post: Devuelve el costo del nodo.
    */
    int obtenerCosto();

    /*
    * Pre: -.
    * Post: Devuelve 'true' si la fila y columna es la correspondiente al nodo y 'false' de no ser así.
    */
    bool comprobar_nodo(int fila, int columna);

    /*
    * Pre: -.
    * Post: le asigna como siguiente el nodo recibido.
    */
    void asignarSiguiente(Nodo<Tipo>* siguiente);

    /*
    Destructor
    * Pre: -.
    * Post: Libera la memoria.
    */
    ~Nodo();
};

template<typename Tipo>
Nodo<Tipo>::Nodo(int fila, int columna, int costo) {
    elemento = new Tipo(fila, columna,costo);
    siguiente = nullptr;
}

template<typename Tipo>
Nodo<Tipo> *Nodo<Tipo>::obtenerSiguiente() {
    return siguiente;
}

template<typename Tipo>
string Nodo<Tipo>::obtenerNombre() {
    return elemento -> obtenerNombre();
}

template<typename Tipo>
int Nodo<Tipo>::obtenerFila() {
    return elemento -> obtenerFila();
}

template<typename Tipo>
int Nodo<Tipo>::obtenerColumna() {
    return elemento -> obtenerColumna();
}

template<typename Tipo>
int Nodo<Tipo>::obtenerCosto() {
    return elemento -> obtenerCosto();
}

template<typename Tipo>
bool Nodo<Tipo>::comprobar_nodo(int fila, int columna){
 return elemento -> comprobar_vertice(fila, columna);
}

template<typename Tipo>
void Nodo<Tipo>::asignarSiguiente(Nodo<Tipo> *siguiente) {
    this -> siguiente = siguiente;
}

template<typename Tipo>
Nodo<Tipo>::~Nodo() {
    delete elemento;
}


#endif //GRAFOS_NODO_H
