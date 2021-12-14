#ifndef GRAFOS_LISTA_H
#define GRAFOS_LISTA_H
#include <string>
#include "Nodo.h"
#include "Structs Constantes.h"
#include <iostream>
using namespace std;

template < typename Tipo >
class Lista{
private:
    /*ATRIBUTOS*/
    int cantidad_de_elementos;
    Nodo<Tipo>* primero;
    Nodo<Tipo>* ultimo;


public:
    /*MÉTODOS PÚBLICOS*/
    //Constructor
    Lista();

    /*
    * Pre: -.
    * Post: Devuelve la cantidad de elementos que tiene la lista.
    */
    int obtener_cantidad_elementos();

    /*
    * Pre: -.
    * Post: Devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra.
    */
    int obtener_posicion(int fila, int columna);

    /*
    * Pre: -.
    * Post: Devuelve la fila de la posición pasada por parametro.
    */
    int obtener_fila(int posicion);

     /*
    * Pre: -.
    * Post: Devuelve la columna de la posición pasada por parametro.
    */
    int obtener_columna(int posicion);

    /*
    * Pre: -.
    * Post: Devuelve el costo de la posición pasada por parametro.
    */
    int obtener_costo(int posicion);

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
    cantidad_de_elementos = 0;
    ultimo = nullptr;
    primero =  nullptr;
}

template < typename Tipo >
int Lista<Tipo>::obtener_cantidad_elementos(){
    return cantidad_de_elementos;
}

template < typename Tipo >
int Lista<Tipo>::obtener_posicion(int fila, int columna) {
    bool elementoEncontrado = false;
    int i = 0;
    Nodo<Tipo>* auxiliar = primero;

    while(!elementoEncontrado && i < cantidad_de_elementos){
        if(auxiliar -> comprobar_nodo(fila, columna)){
            elementoEncontrado = true;
        }
        i++;
        auxiliar = auxiliar -> obtener_siguiente();
    }

    if(!elementoEncontrado){
        return POSICION_NO_ENCONTRADA;
    }
    return i - 1;
}

template < typename Tipo >
void Lista<Tipo>::agregar(int fila, int columna, int costo) {
    Nodo<Tipo>* nuevo_nodo = new Nodo<Tipo>(fila, columna, costo);
    if(primero == nullptr){
        primero = nuevo_nodo;
        ultimo = primero;
    } else {
        ultimo -> asignar_siguiente(nuevo_nodo);
        ultimo = nuevo_nodo;
    }
    cantidad_de_elementos++;
}

template<typename Tipo>
Lista<Tipo>::~Lista() {
    Nodo<Tipo>* siguiente;
    while(primero != nullptr){
        siguiente = primero -> obtener_siguiente();
        delete primero;
        primero = siguiente;
    }
}

template<typename Tipo>
int Lista<Tipo>::obtener_fila(int posicion) {
    int i = 0;
    Nodo<Tipo>* auxiliar = primero;

    if(posicion > cantidad_de_elementos){
        return 0;
    }

    while(i != posicion - 1){
        auxiliar = auxiliar -> obtener_siguiente();
        i++;
    }
    return auxiliar -> obtener_fila();
}

template<typename Tipo>
int Lista<Tipo>::obtener_columna(int posicion) {
    int i = 0;
    Nodo<Tipo>* auxiliar = primero;

    if(posicion > cantidad_de_elementos){
        return 0;
    }

    while(i != posicion - 1){
        auxiliar = auxiliar -> obtener_siguiente();
        i++;
    }
    return auxiliar -> obtener_columna();
}

template<typename Tipo>
int Lista<Tipo>::obtener_costo(int posicion) {
    int i = 0;
    Nodo<Tipo>* auxiliar = primero;

    if(posicion > cantidad_de_elementos){
        return 0;
    }

    while(i != posicion){
        auxiliar = auxiliar -> obtener_siguiente();
        i++;
    }
    return auxiliar -> obtener_costo();
}

#endif //GRAFOS_LISTA_H
