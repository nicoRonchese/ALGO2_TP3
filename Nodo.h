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
    Nodo<Tipo>* obtener_siguiente();

    //post: devuelve el nombre del nodo
    string obtener_nombre();

    int obtener_fila();

    int obtener_columna();

    int obtener_costo();

    bool comprobar_nodo(int fila, int columna);

    //post: le asigna como siguiente el nodo recibido
    void asignar_siguiente(Nodo<Tipo>* siguiente);

    ~Nodo();
};

template<typename Tipo>
Nodo<Tipo>::Nodo(int fila, int columna, int costo) {
    elemento = new Tipo(fila, columna,costo);
    siguiente = nullptr;
}

template<typename Tipo>
Nodo<Tipo> *Nodo<Tipo>::obtener_siguiente() {
    return siguiente;
}

template<typename Tipo>
string Nodo<Tipo>::obtener_nombre() {
    return elemento -> obtener_nombre();
}

template<typename Tipo>
int Nodo<Tipo>::obtener_fila() {
    return elemento -> obtener_fila();
}

template<typename Tipo>
int Nodo<Tipo>::obtener_columna() {
    return elemento -> obtener_columna();
}

template<typename Tipo>
int Nodo<Tipo>::obtener_costo() {
    return elemento -> obtener_costo();
}

template<typename Tipo>
bool Nodo<Tipo>::comprobar_nodo(int fila, int columna){
 return elemento -> comprobar_vertice(fila, columna);
}

template<typename Tipo>
void Nodo<Tipo>::asignar_siguiente(Nodo<Tipo> *siguiente) {
    this -> siguiente = siguiente;
}

template<typename Tipo>
Nodo<Tipo>::~Nodo() {
    delete elemento;
}


#endif //GRAFOS_NODO_H
