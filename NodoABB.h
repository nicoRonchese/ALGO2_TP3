#ifndef NODOABB_H
#define NODOABB_H
#include <string>

using namespace std;

template < typename Tipo >
class NodoABB {
/*ATRIBUTOS*/
private:
    string llave;
    Tipo elemento;
    NodoABB<Tipo>* der;
    NodoABB<Tipo>* izq;

/*MÉTODOS*/
public:
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
    NodoABB<Tipo>*& obtenerizq();

    /*
    * Pre: -.
    * Post: Devuelve el nodo derecho.
    */
    NodoABB<Tipo>*& obtenerder();

    /*
    * Pre: -.
    * Post: Devuelve la llave.
    */
    string obtenerllave();

    /*
    * Pre: -.
    * Post: Devuelve el elemento ubicado en el nodo.
    */
    Tipo obtenerelemento();

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
NodoABB<Tipo> *&NodoABB<Tipo>::obtenerizq() {
    return izq;
}

template<typename Tipo>
NodoABB<Tipo> *&NodoABB<Tipo>::obtenerder() {
    return der;
}

template<typename Tipo>
string NodoABB<Tipo>::obtenerllave() {
    return llave;
}

template<typename Tipo>
Tipo NodoABB<Tipo>::obtenerelemento() {
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
