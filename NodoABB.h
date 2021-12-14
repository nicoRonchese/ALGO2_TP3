#ifndef NODOABB_H
#define NODOABB_H
#include <string>

using namespace std;

template < typename Tipo >
class NodoABB {

private:
    /*ATRIBUTOS*/
    string llave;
    Tipo elemento;
    NodoABB<Tipo>* der;
    NodoABB<Tipo>* izq;

public:
    /*MÉTODOS PÚBLICOS*/
    /*
    Constructor
    * Pre: Recibe una llave y un dato.
    * Post: Crea un nodo.
    */
    NodoABB(string llave,Tipo dato);

    /*
    * Pre: -.
    * Post: Devuelve el nodo izquierdo.
    */
    NodoABB<Tipo>*& obtener_izquierdo();

    /*
    * Pre: -.
    * Post: Devuelve el nodo derecho.
    */
    NodoABB<Tipo>*& obtener_derecho();

    /*
    * Pre: -.
    * Post: Devuelve la llave.
    */
    string obtener_llave();

    /*
    * Pre: -.
    * Post: Devuelve el elemento ubicado en el nodo.
    */
    Tipo obtener_elemento();

    /*
    * Pre: -.
    * Post: Modifica el elemento actual con el pasado por parametro.
    */
    void modificar_elemento(Tipo dato);

     /*
    Destructor
    * Pre: -.
    * Post: Libera la memoria.
    */
    ~NodoABB();
};

template<typename Tipo>
NodoABB<Tipo>::NodoABB(string nombre,Tipo dato) {
    llave = nombre;
    elemento = dato;
    izq = nullptr;
    der = nullptr;
}

template<typename Tipo>
NodoABB<Tipo> *&NodoABB<Tipo>::obtener_izquierdo() {
    return izq;
}

template<typename Tipo>
NodoABB<Tipo> *&NodoABB<Tipo>::obtener_derecho() {
    return der;
}

template<typename Tipo>
string NodoABB<Tipo>::obtener_llave() {
    return llave;
}

template<typename Tipo>
Tipo NodoABB<Tipo>::obtener_elemento() {
    return elemento;
}

template<typename Tipo>
void NodoABB<Tipo>::modificar_elemento(Tipo dato) {
    elemento =  dato;
}


template<typename Tipo>
NodoABB<Tipo>::~NodoABB() {
}


#endif //GRAFOS_NODO_H
