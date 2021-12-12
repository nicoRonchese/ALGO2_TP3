#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include "NodoABB.h"
#include <iostream>
using namespace std;

struct edificio
{
    int cantidad_piedra;
    int cantidad_madera;
    int cantidad_metal;
    int maxima_cantidad_permitida;
    string produccion = "";
};

template < typename Tipo >
class diccionario{
/*ATRIBUTOS*/
private:
    NodoABB<Tipo>* primero;

/*MÉTODOS*/
public:
    diccionario();

    //post: agrega un nuevo elemento a la lista
    void agregarElemento(string llave,Tipo dato);
    
    void agregarNodo(NodoABB<Tipo> *&origen, NodoABB<Tipo> *nuevo); 

    //post: devuelve el  nombre que se encuentra en la posicion recibida o NOMBRE_NO_ENCONTRADO si no lo encuentra
    string obtenerLlave(string nombre);

    Tipo buscarElemento(string nombre);

    Tipo recursion_buscar_elemento(NodoABB<Tipo> *origen, string llave);

    void mostrar_edificios();

    void recursion_mostrar_edificios(NodoABB<Tipo> *origen);

    void listar_edificios(edificio dato, string llave);

    void modificar_elemento(string llave,Tipo dato);

    void recursion_modificar_elemento(NodoABB<Tipo> *&origen,string llave, Tipo dato);

    void guardar_edificio(string nombre_archivo);

    void recursion_guardar_edificio(string nombre_archivo,NodoABB<Tipo> *nodo);

    ~diccionario();
};

template < typename Tipo >
diccionario <Tipo> :: diccionario(){
    primero = NULL;
}

template < typename Tipo >
void diccionario <Tipo> :: agregarElemento(string llave,Tipo dato){
    NodoABB<Tipo> *nuevo_nodo = new NodoABB<Tipo>(llave,dato);
    agregarNodo(primero,nuevo_nodo);
}

template < typename Tipo >
void diccionario <Tipo> :: agregarNodo(NodoABB<Tipo> *&origen, NodoABB<Tipo> *nuevo){
    if(origen == NULL){
        origen = nuevo;
	}
	else{
		string llave_raiz = origen->obtenerllave();
        string llave_nodo = nuevo->obtenerllave();
		if(llave_nodo.length() < llave_raiz.length()){
			agregarNodo(origen->obtenerizq(),nuevo);
		}else{
			agregarNodo(origen->obtenerder(),nuevo);
		}
	}
}

template < typename Tipo >
Tipo diccionario <Tipo> :: buscarElemento(string llave){
    return recursion_buscar_elemento(primero,llave);
}

template < typename Tipo >
Tipo diccionario <Tipo> :: recursion_buscar_elemento(NodoABB<Tipo> *origen, string llave){
    if(origen != NULL){
		if(llave == origen->obtenerllave()){
			Tipo aux = origen->obtenerelemento();
			return aux;
		}
		else if(llave.length() < (origen->obtenerllave()).length()){
			return recursion_buscar_elemento(origen->obtenerizq(),llave);
		}
		else{
		    return recursion_buscar_elemento(origen->obtenerder(),llave);
		}
    }
    else{
        Tipo vacio;
        return vacio;
    }

}

template < typename Tipo >
void diccionario<Tipo> :: mostrar_edificios(){
    recursion_mostrar_edificios(primero);
}

template < typename Tipo >
void diccionario<Tipo> :: recursion_mostrar_edificios(NodoABB<Tipo> *origen){
    if(origen != NULL){
        listar_edificios(origen->obtenerelemento(),origen->obtenerllave());
		recursion_mostrar_edificios(origen->obtenerder());
		recursion_mostrar_edificios(origen->obtenerizq());
	}
}

template < typename Tipo >
void diccionario<Tipo> ::listar_edificios(edificio dato, string llave){
    cout<< llave <<" - "<<dato.produccion<<endl;
    cout<< "Requerimientos:";
    cout<< " - Piedra: " << dato.cantidad_piedra;
    cout<< " - Madera: " << dato.cantidad_madera;
    cout<< " - Metal: " << dato.cantidad_metal<<endl;
    cout<< "Maximo construible: " <<  dato.maxima_cantidad_permitida << endl << endl;
}

template < typename Tipo >
void diccionario <Tipo> ::modificar_elemento(string llave,Tipo dato){
    return recursion_modificar_elemento(primero,llave,dato);
}

template < typename Tipo >
void diccionario <Tipo> :: recursion_modificar_elemento(NodoABB<Tipo> *&origen,string llave, Tipo dato){
    if(origen != NULL){
		if(llave == origen->obtenerllave()){
			origen->modificar_elemento(dato);
		}
		else if(llave.length() < (origen->obtenerllave()).length()){
			recursion_modificar_elemento(origen->obtenerizq(),llave,dato);
		}
		else{
		    recursion_modificar_elemento(origen->obtenerder(),llave,dato);
		}
    }
}

template < typename Tipo >
void diccionario <Tipo> :: guardar_edificio(string nombre_archivo){
    recursion_guardar_edificio(nombre_archivo,primero);
}

template < typename Tipo >
void diccionario <Tipo> :: recursion_guardar_edificio(string nombre_archivo,NodoABB<Tipo> *nodo){
    if (nodo != NULL)
    {
        ofstream archivo;
        string llave = nodo->obtenerllave();
        edificio datos = nodo->obtenerelemento();
        archivo.open(nombre_archivo,ios::app);
        archivo<< llave;
        archivo <<" "<< datos.cantidad_piedra;
        archivo <<" "<< datos.cantidad_madera;
        archivo <<" "<< datos.cantidad_metal;
        archivo <<" "<< datos.maxima_cantidad_permitida << endl;
        recursion_guardar_edificio(nombre_archivo,nodo->obtenerder());
        recursion_guardar_edificio(nombre_archivo,nodo->obtenerizq());
    }
    
    
}

template < typename Tipo >
diccionario<Tipo>::~diccionario(){
    delete primero;
}

#endif //GRAFOS_LISTA_H