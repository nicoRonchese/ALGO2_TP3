#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include "NodoABB.h"
#include "Structs Constantes.h"
#include <iostream>
using namespace std;



template < typename Tipo >
class Diccionario{
/*ATRIBUTOS*/
private:
    NodoABB<Tipo>* primero;

/*MÉTODOS*/
public:
    Diccionario();

    //post: agrega un nuevo elemento a la lista
    void agregar_elemento(string llave,Tipo dato);

    void agregar_nodo(NodoABB<Tipo> *&origen, NodoABB<Tipo> *nuevo);

    //post: devuelve el  nombre que se encuentra en la posicion recibida o NOMBRE_NO_ENCONTRADO si no lo encuentra
    string obtener_llave(string nombre);

    Tipo buscar_elemento(string nombre);

    Tipo recursion_buscar_elemento(NodoABB<Tipo> *origen, string llave);

    void mostrar_edificios();

    void recursion_mostrar_edificios(NodoABB<Tipo> *origen);

    void listar_edificios(edificio dato, string llave);

    void modificar_elemento(string llave,Tipo dato);

    void recursion_modificar_elemento(NodoABB<Tipo> *&origen,string llave, Tipo dato);

    void guardar_edificio(string nombre_archivo);

    void recursion_guardar_edificio(string nombre_archivo,NodoABB<Tipo> *nodo);

    void recursion_liberar_arbol(NodoABB<Tipo> *&origen);

    ~Diccionario();
};

template < typename Tipo >
Diccionario <Tipo> :: Diccionario(){
    primero = NULL;
}

template < typename Tipo >
void Diccionario <Tipo> :: agregar_elemento(string llave,Tipo dato){
    NodoABB<Tipo> *nuevo_nodo = new NodoABB<Tipo>(llave,dato);
    agregar_nodo(primero,nuevo_nodo);
}

template < typename Tipo >
void Diccionario <Tipo> :: agregar_nodo(NodoABB<Tipo> *&origen, NodoABB<Tipo> *nuevo){
    if(origen == NULL){
        origen = nuevo;
	}
	else{
		string llave_raiz = origen->obtener_llave();
        string llave_nodo = nuevo->obtener_llave();
		if(llave_nodo.length() < llave_raiz.length()){
			agregar_nodo(origen->obtener_izquierdo(),nuevo);
		}else{
			agregar_nodo(origen->obtener_derecho(),nuevo);
		}
	}
}

template < typename Tipo >
Tipo Diccionario <Tipo> :: buscar_elemento(string llave){
    return recursion_buscar_elemento(primero,llave);
}

template < typename Tipo >
Tipo Diccionario <Tipo> :: recursion_buscar_elemento(NodoABB<Tipo> *origen, string llave){
    if(origen != NULL){
		if(llave == origen->obtener_llave()){
			Tipo aux = origen->obtener_elemento();
			return aux;
		}
		else if(llave.length() < (origen->obtener_llave()).length()){
			return recursion_buscar_elemento(origen->obtener_izquierdo(),llave);
		}
		else{
		    return recursion_buscar_elemento(origen->obtener_derecho(),llave);
		}
    }
    else{
        Tipo vacio;
        return vacio;
    }

}

template < typename Tipo >
void Diccionario<Tipo> :: mostrar_edificios(){
    recursion_mostrar_edificios(primero);
}

template < typename Tipo >
void Diccionario<Tipo> :: recursion_mostrar_edificios(NodoABB<Tipo> *origen){
    if(origen != NULL){
        listar_edificios(origen->obtener_elemento(),origen->obtener_llave());
		recursion_mostrar_edificios(origen->obtener_derecho());
		recursion_mostrar_edificios(origen->obtener_izquierdo());
	}
}

template < typename Tipo >
void Diccionario<Tipo> ::listar_edificios(edificio dato, string llave){
    cout<< llave <<" - "<<dato.produccion<<endl;
    cout<< "Requerimientos:";
    cout<< " - Piedra: " << dato.cantidad_piedra;
    cout<< " - Madera: " << dato.cantidad_madera;
    cout<< " - Metal: " << dato.cantidad_metal<<endl;
    cout<< "Maximo construible: " <<  dato.maxima_cantidad_permitida << endl << endl;
}

template < typename Tipo >
void Diccionario <Tipo> ::modificar_elemento(string llave,Tipo dato){
    return recursion_modificar_elemento(primero,llave,dato);
}

template < typename Tipo >
void Diccionario <Tipo> :: recursion_modificar_elemento(NodoABB<Tipo> *&origen,string llave, Tipo dato){
    if(origen != NULL){
		if(llave == origen->obtener_llave()){
			origen->modificar_elemento(dato);
		}
		else if(llave.length() < (origen->obtener_llave()).length()){
			recursion_modificar_elemento(origen->obtener_izquierdo(),llave,dato);
		}
		else{
		    recursion_modificar_elemento(origen->obtener_derecho(),llave,dato);
		}
    }
}

template < typename Tipo >
void Diccionario <Tipo> :: guardar_edificio(string nombre_archivo){
    recursion_guardar_edificio(nombre_archivo,primero);
}

template < typename Tipo >
void Diccionario <Tipo> :: recursion_guardar_edificio(string nombre_archivo,NodoABB<Tipo> *nodo){
    if (nodo != NULL)
    {
        ofstream archivo;
        string llave = nodo->obtener_llave();
        edificio datos = nodo->obtener_elemento();
        archivo.open(nombre_archivo,ios::app);
        archivo<< llave;
        archivo <<" "<< datos.cantidad_piedra;
        archivo <<" "<< datos.cantidad_madera;
        archivo <<" "<< datos.cantidad_metal;
        archivo <<" "<< datos.maxima_cantidad_permitida << endl;
        recursion_guardar_edificio(nombre_archivo,nodo->obtener_derecho());
        recursion_guardar_edificio(nombre_archivo,nodo->obtener_izquierdo());
    }


}

template < typename Tipo >
void Diccionario<Tipo> :: recursion_liberar_arbol(NodoABB<Tipo> *&origen){
if(origen != NULL){
recursion_liberar_arbol(origen->obtener_derecho());
recursion_liberar_arbol(origen->obtener_izquierdo());
}
delete origen;
}

template < typename Tipo >
Diccionario<Tipo>::~Diccionario(){
recursion_liberar_arbol(primero);
}


#endif //GRAFOS_LISTA_H
