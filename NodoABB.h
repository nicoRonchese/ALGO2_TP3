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
    NodoABB(string llave,Tipo dato);

    //post: devuelve el nodo siguiente.
    NodoABB<Tipo>*& obtenerizq();

    NodoABB<Tipo>*& obtenerder();

    //post: devuelve el nombre del nodo
    string obtenerllave();

    Tipo obtenerelemento();

    void modificar_elemento(Tipo dato);

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
