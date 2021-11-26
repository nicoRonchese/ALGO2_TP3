#include "Datos_Edificios.h"

Datos_edificios::Datos_edificios(){
    cantidad_edificios = 0;
    ifstream archivo(PATH_EDIFICIOS);
    edificio aux;
    nodo *nuevo_nodo = new nodo();
    string llave,datos[6];
    diccionario = NULL;
    if(archivo.fail()){
     cout << "Error abriendo el fichero " << PATH_EDIFICIOS << endl;
    }
    else{
    while(archivo>>datos[0]){
        archivo >> datos[1];
        if (isdigit(datos[1][0])!=0)
        {
            archivo >> datos[2];
            archivo >> datos[3];
            archivo >> datos[4];
            llave = datos[0];
            aux.cantidad_piedra = stoi(datos[1]);
            aux.cantidad_madera = stoi(datos[2]);
            aux.cantidad_metal = stoi(datos[3]);
            aux.maxima_cantidad_permitida = stoi(datos[4]);
        }
        else{
            archivo >> datos[2];
            archivo >> datos[3];
            archivo >> datos[4];
            archivo >> datos[5];
            llave = datos[0] +" "+datos[1];
            aux.cantidad_piedra = stoi(datos[2]);
            aux.cantidad_madera = stoi(datos[3]);
            aux.cantidad_metal = stoi(datos[4]);
            aux.maxima_cantidad_permitida = stoi(datos[5]);
        }
        nodo *nuevo_nodo = new nodo();
        aux.cantidad_construida=0;
        aux.produccion = datos_produccion(llave);
        nuevo_nodo->llave = llave;
	    nuevo_nodo->datos = aux;
	    nuevo_nodo->der = NULL;
	    nuevo_nodo->izq = NULL;
        agregar_nodo(diccionario,nuevo_nodo);
    }
    archivo.close();
 }
}

void Datos_edificios::agregar_nodo(nodo*&origen,nodo *ab){
    if(origen == NULL){
        origen = ab;
	}
	else{
		string llave_raiz = origen->llave;
        string llave_nodo = ab->llave;
		if(llave_nodo.length() < llave_raiz.length()){
			agregar_nodo(origen->izq,ab);
		}else{
			agregar_nodo(origen->der,ab);
		}
	}
}


void Datos_edificios::mostrar_edificios(){
    recursion_mostrar_edificios(diccionario);
}

void Datos_edificios::recursion_mostrar_edificios(nodo *origen){
    if(origen != NULL){
        listar_edificios(origen->datos,origen->llave);
		recursion_mostrar_edificios(origen->der);
		recursion_mostrar_edificios(origen->izq);
	}	
}

void Datos_edificios::edificio_construido_o_demolido(string nombre, int n){
    recursion_edificio_construido_o_demolido(diccionario,nombre,n);
}

void Datos_edificios::recursion_edificio_construido_o_demolido(nodo *ab,string nombre, int n){
    if(ab != NULL){
		if(nombre == ab->llave){
			edificio aux = ab->datos;
			aux.cantidad_construida = aux.cantidad_construida + n;
            ab->datos =aux;
		}
		else if( nombre.length() < (ab->llave).length()){
			recursion_edificio_construido_o_demolido(ab->izq,nombre,n);
		}
		else{
		    recursion_edificio_construido_o_demolido(ab->der,nombre,n);
		}
}
}

void Datos_edificios::listar_edificios(edificio dato, string llave){
    cout<< llave <<" - Construidos: " << dato.cantidad_construida<<" - "<<dato.produccion<<endl;
    cout<< "Requerimientos:";
    cout<< " - Piedra: " << dato.cantidad_piedra;
    cout<< " - Madera: " << dato.cantidad_madera;
    cout<< " - Metal: " << dato.cantidad_metal<<endl;
    cout<<"Se pueden construir " <<  dato.maxima_cantidad_permitida - dato.cantidad_construida << " "<< llave<< endl << endl;

}

bool Datos_edificios::comprobar_edificio(string nombre){
  bool chequeo = false;
  if(buscar_edificio(nombre).maxima_cantidad_permitida!=0){
      chequeo = true;
  }
  return chequeo;
}

edificio Datos_edificios::recursion_buscar_edificio(nodo *ab,string nombre){
    if(ab != NULL){
		if(nombre == ab->llave){
			edificio aux = ab->datos;
			return aux;
		}
		else if( nombre.length() < (ab->llave).length()){
			return recursion_buscar_edificio(ab->izq,nombre);
		}
		else{
		    return recursion_buscar_edificio(ab->der,nombre);
		}
    }
    else{
        edificio edificio_vacio;
        edificio_vacio.maxima_cantidad_permitida = 0;
        return edificio_vacio;
    }

}

edificio Datos_edificios::buscar_edificio(string nombre){
    return recursion_buscar_edificio(diccionario,nombre);
}

string Datos_edificios::datos_produccion(string nombre){
    string produccion;
    if ("aserradero"==nombre){
        produccion = "Produce 25 de madera";
    }
    else if ("mina"==nombre){
        produccion = "Produce 15 de piedra";
    }
    else if ("fabrica"==nombre){
        produccion = "Produce 40 de metal";
    }
    else if ("Escuela"==nombre){
        produccion = "Produce 25 andycoins";
    }
    else if ("Planta eléctrica"==nombre){
        produccion = "Produce 15 de energia";
    }
    else if ("Mina oro:"==nombre){
        produccion = "Produce 50 andycoins";
    }
    return produccion;
  }

Datos_edificios::~Datos_edificios(){}

