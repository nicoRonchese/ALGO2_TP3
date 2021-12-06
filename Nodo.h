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
    Nodo(int fila, int columna, int costo);

    //post: devuelve el nodo siguiente.
    Nodo<Tipo>* obtenerSiguiente();

    //post: devuelve el nombre del nodo
    string obtenerNombre();

    int obtenerFila();

    int obtenerColumna();

    int obtenerCosto();

    bool comprobar_nodo(int fila, int columna);

    //post: le asigna como siguiente el nodo recibido
    void asignarSiguiente(Nodo<Tipo>* siguiente);

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
