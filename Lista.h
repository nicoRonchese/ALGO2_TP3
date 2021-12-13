#ifndef GRAFOS_LISTA_H
#define GRAFOS_LISTA_H
#include <string>
#include "Nodo.h"
#include <iostream>
using namespace std;

const int POSICION_NO_ENCONTRADA = -1;
const string NOMBRE_NO_ENCONTRADO = "";

template < typename Tipo >
class Lista{
/*ATRIBUTOS*/
private:
    int cantidadDeElementos;
    Nodo<Tipo>* primero;
    Nodo<Tipo>* ultimo;

/*MÉTODOS*/
public:

    //Constructor
    Lista();

    /*
    * Pre: -.
    * Post: Devuelve la cantidad de elementos que tiene la lista.
    */ 
    int obtenerCantidadDeElementos();

    /*
    * Pre: -.
    * Post: Devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra.
    */ 
    int obtenerPosicion(int fila, int columna);

    /*
    * Pre: -.
    * Post: Devuelve el  nombre que se encuentra en la posicion recibida o 
    *      NOMBRE_NO_ENCONTRADO si no lo encuentra.
    */ 
    string obtenerNombre(int posicion);

    /*
    * Pre: -.
    * Post: Devuelve la fila de la posición pasada por parametro.
    */ 
    int obtenerFila(int posicion);

    /*
    * Pre: -.
    * Post: Devuelve la columna de la posición pasada por parametro.
    */ 
    int obtenerColumna(int posicion);

    /*
    * Pre: -.
    * Post: Devuelve el costo de la posición pasada por parametro.
    */ 
    int obtenerCosto(int posicion);

    /*
    * Pre: -.
    * Post: Agrega un nuevo elemento a la lista.
    */ 
    void agregar(int fila, int columna, int peso);

    //Destructor
    ~Lista();
};

template < typename Tipo >
Lista<Tipo>::Lista(){
    cantidadDeElementos = 0;
    ultimo = nullptr;
    primero =  nullptr;
}

template < typename Tipo >
int Lista<Tipo>::obtenerCantidadDeElementos(){
    return cantidadDeElementos;
}

template < typename Tipo >
int Lista<Tipo>::obtenerPosicion(int fila, int columna) {
    bool elementoEncontrado = false;
    int i = 0;
    Nodo<Tipo>* auxiliar = primero;

    while(!elementoEncontrado && i < cantidadDeElementos){
        if(auxiliar -> comprobar_nodo(fila, columna)){
            elementoEncontrado = true;
        }
        i++;
        auxiliar = auxiliar -> obtenerSiguiente();
    }

    if(!elementoEncontrado){
        return POSICION_NO_ENCONTRADA;
    }
    return i - 1;
}

template < typename Tipo >
void Lista<Tipo>::agregar(int fila, int columna, int costo) {
    Nodo<Tipo>* nuevoNodo = new Nodo<Tipo>(fila, columna, costo);
    if(primero == nullptr){
        primero = nuevoNodo;
        ultimo = primero;
    } else {
        ultimo -> asignarSiguiente(nuevoNodo);
        ultimo = nuevoNodo;
    }
    cantidadDeElementos++;
}

template<typename Tipo>
Lista<Tipo>::~Lista() {
    Nodo<Tipo>* siguiente;
    while(primero != nullptr){
        siguiente = primero -> obtenerSiguiente();
        delete primero;
        primero = siguiente;
    }
}

template<typename Tipo>
string Lista<Tipo>::obtenerNombre(int posicion) {
    int i = 0;
    Nodo<Tipo>* auxiliar = primero;

    if(posicion > cantidadDeElementos){
        return NOMBRE_NO_ENCONTRADO;
    }

    while(i != posicion - 1){
        auxiliar = auxiliar -> obtenerSiguiente();
        i++;
    }
    return auxiliar -> obtenerNombre();
}

template<typename Tipo>
int Lista<Tipo>::obtenerFila(int posicion) {
    int i = 0;
    Nodo<Tipo>* auxiliar = primero;

    if(posicion > cantidadDeElementos){
        return 0;
    }

    while(i != posicion - 1){
        auxiliar = auxiliar -> obtenerSiguiente();
        i++;
    }
    return auxiliar -> obtenerFila();
}

template<typename Tipo>
int Lista<Tipo>::obtenerColumna(int posicion) {
    int i = 0;
    Nodo<Tipo>* auxiliar = primero;

    if(posicion > cantidadDeElementos){
        return 0;
    }

    while(i != posicion - 1){
        auxiliar = auxiliar -> obtenerSiguiente();
        i++;
    }
    return auxiliar -> obtenerColumna();
}

template<typename Tipo>
int Lista<Tipo>::obtenerCosto(int posicion) {
    int i = 0;
    Nodo<Tipo>* auxiliar = primero;

    if(posicion > cantidadDeElementos){
        return 0;
    }

    while(i != posicion){
        auxiliar = auxiliar -> obtenerSiguiente();
        i++;
    }
    return auxiliar -> obtenerCosto();
}

#endif //GRAFOS_LISTA_H
