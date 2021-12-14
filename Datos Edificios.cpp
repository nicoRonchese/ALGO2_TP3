#include "Datos Edificios.h"

DatosEdificios::DatosEdificios(){
    cantidad_edificios = 0;
    leer_edificios();
}

void DatosEdificios::leer_edificios(){
    ifstream archivo(PATH_EDIFICIOS);
    edificio aux;
    string llave,datos[6];
    if(archivo.fail()){
        cout << "Error abriendo el fichero " << PATH_EDIFICIOS << endl;
    } else{
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
        cantidad_edificios++;
        agregar_edificio(llave, aux);
     }
    }
    archivo.close();
}

void DatosEdificios::agregar_edificio(string llave, edificio datos){
    edificios.agregar_elemento(llave,datos);
}

void DatosEdificios::mostrar_edificios(){
    edificios.mostrar_edificios();
}

bool DatosEdificios::comprobar_edificio(string nombre){
  bool chequeo = false;
  if(edificios.buscar_elemento(nombre).maxima_cantidad_permitida != 0){
      chequeo = true;
  } else{
    cout << "Edificio no encontrado" << endl;
  }

  return chequeo;
}

edificio DatosEdificios::buscar_edificio(string nombre){
    return edificios.buscar_elemento(nombre);
}

string DatosEdificios::datos_produccion(string nombre){
    string produccion;
    if (ASERRADERO == nombre){
        produccion = PRODUCCION_ASERRADERO;
    }
    else if (MINA == nombre){
        produccion = PRODUCCION_MINA;
    }
    else if (FABRICA == nombre){
        produccion = PRODUCCION_FABRICA;
    }
    else if (ESCUELA == nombre){
        produccion = PRODUCCION_ESCUELA;
    }
    else if (PLANTA_ELECTRICA == nombre){
        produccion = PRODUCCION_PLANTA_ELECTRICA;
    }
    else if (MINA_ORO == nombre){
        produccion = PRODUCCION_MINA_ORO;
    }
    return produccion;
  }

void DatosEdificios::modificar_edificio(edificio dato, string llave){
    dato.produccion = datos_produccion(llave);
    edificios.modificar_elemento(llave,dato);
}

void DatosEdificios::guardar_edificios(){
    ofstream archivo;
    archivo.open(PATH_EDIFICIOS,ios::out);
    if(!archivo)
     cout << "Error abriendo el fichero" << endl;
    else{
     edificios.guardar_edificio(PATH_EDIFICIOS);
     cout<<"Datos Edificios guardados"<<endl;
    }
    archivo.close();
}

DatosEdificios::~DatosEdificios(){}

