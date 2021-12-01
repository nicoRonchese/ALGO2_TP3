#include "Datos_Edificios.h"

Datos_edificios::Datos_edificios(){
    cantidad_edificios = 0;
    diccionario = NULL;
    leer_edificios();
}

void Datos_edificios::leer_edificios(){
    ifstream archivo(PATH_EDIFICIOS);
    edificio aux;
    string llave,datos[6];
    if(archivo.fail())
     cout << "Error abriendo el fichero " << PATH_EDIFICIOS << endl;
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
        aux.produccion = datos_produccion(llave);
        agregar_edificio(llave, aux);
     }
    }
    archivo.close();
}

void Datos_edificios::agregar_edificio(string llave, edificio datos){
    nodo *nuevo_nodo = new nodo();
    nuevo_nodo->llave = llave;
    nuevo_nodo->datos = datos;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    agregar_nodo(diccionario,nuevo_nodo);
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

void Datos_edificios::listar_edificios(edificio dato, string llave){
    cout<< llave <<" - "<<dato.produccion<<endl;
    cout<< "Requerimientos:";
    cout<< " - Piedra: " << dato.cantidad_piedra;
    cout<< " - Madera: " << dato.cantidad_madera;
    cout<< " - Metal: " << dato.cantidad_metal<<endl;
    cout<< "Maximo construible: " <<  dato.maxima_cantidad_permitida << endl << endl;

}

bool Datos_edificios::comprobar_edificio(string nombre){
  bool chequeo = false;
  if(buscar_edificio(nombre).maxima_cantidad_permitida!=0){
      chequeo = true;
  }
  else
    cout<<"Edificio no encontrado"<<endl;
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
    if (ASERRADERO==nombre){
        produccion = PRODUCCION_ASERRADERO;
    }
    else if (MINA==nombre){
        produccion = PRODUCCION_MINA;
    }
    else if (FABRICA==nombre){
        produccion = PRODUCCION_FABRICA;
    }
    else if (ESCUELA==nombre){
        produccion = PRODUCCION_ESCUELA;
    }
    else if (PLANTA_ELECTRICA==nombre){
        produccion = PRODUCCION_PLANTA_ELECTRICA;
    }
    else if (MINA_ORO==nombre){
        produccion = PRODUCCION_MINA_ORO;
    }
    return produccion;
  }

Datos_edificios::~Datos_edificios(){}

