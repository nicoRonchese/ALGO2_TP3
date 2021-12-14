#include "Datos Materiales.h"

DatosMateriales::DatosMateriales(int cantidad_jugadores) {
    this->materiales = new material**[cantidad_jugadores];
    this->cantidad_jugadores = cantidad_jugadores;
    if (cantidad_jugadores == CANTIDAD_JUGADORES){
        leer_archivo();
    }else{
        leer_archivo_inicial();
    }
    ordenar_materiales();
}

void DatosMateriales::leer_archivo_inicial(){
    cantidad_materiales = 0;
    ifstream archivo(PATH_MATERIALES);
    string nombre, cantidad_uno, cantidad_dos;
    material* material_leido;
    material aux;
    if(archivo.fail()){
     cout << "Error abriendo el fichero " << PATH_MATERIALES << endl;
    }
    else{
     while(archivo >> nombre){
        archivo >> cantidad_uno;
        archivo >> cantidad_dos;
        material_leido = new material;
        material_leido -> nombre = nombre;
        material_leido -> cantidad = 0;
        for (int jugador = 0; jugador<cantidad_jugadores; jugador++){
         agregar_material(material_leido, jugador);
         aux = *material_leido;
         material_leido = new material;
         *material_leido = aux;
        }
        delete material_leido;
        cantidad_materiales++;
     }
    }
    archivo.close();
}

void DatosMateriales::leer_archivo(){
    cantidad_materiales = 0;
    ifstream archivo(PATH_MATERIALES);
    string nombre, cantidad_uno, cantidad_dos;
    material* material_uno;
    material* material_dos;
    if(archivo.fail()){
     cout << "Error abriendo el fichero " << PATH_MATERIALES << endl;
    }
    else{
     while(archivo >> nombre){
        archivo >> cantidad_uno;
        archivo >> cantidad_dos;
        material_uno = new material;
        material_dos = new material;
        material_uno -> nombre = nombre;
        material_dos -> nombre = nombre;
        material_uno -> cantidad = stoi(cantidad_uno);
        material_dos -> cantidad = stoi(cantidad_dos);
        agregar_material(material_uno, JUGADOR_UNO);
        agregar_material(material_dos, JUGADOR_DOS);
        cantidad_materiales++;
     }
    }
    archivo.close();
}

void DatosMateriales::agregar_material(material* material_leido, int jugador){
    material** materiales_aux = new material*[(cantidad_materiales + 1)];
    for(int i = 0; i < cantidad_materiales; i++){
        materiales_aux[i] = materiales[jugador][i];
    }
    materiales_aux[cantidad_materiales] = material_leido;
    if (cantidad_materiales != 0){
        delete [] materiales[jugador];
    }
    materiales[jugador]= materiales_aux;
}

int DatosMateriales::devolver_cantidad(int jugador, int material){
    return materiales[jugador][material] -> cantidad;
}

void DatosMateriales::mostrar_materiales(int jugador){
    for (int material = 0; material<cantidad_materiales; material++){
        cout<<materiales[jugador][material] -> nombre<<": "<<materiales[jugador][material] -> cantidad<<" unidades"<<endl;
    }
}

bool DatosMateriales::comprar_bombas(int jugador, int cantidad){
    bool compra_realizada = false;
    if (cantidad*COSTO_BOMBA>materiales[jugador][ANDYCOIN]->cantidad){
       cout << "No tiene la cantidad necesaria de Andycoins para esta compra" << endl;
    }else{
       materiales[jugador][ANDYCOIN]->cantidad -= cantidad*COSTO_BOMBA;
       materiales[jugador][BOMBA]->cantidad += cantidad;
       cout<< "Compra realizada con exito" << endl;
       compra_realizada = true;
    }
    return compra_realizada;
}

void DatosMateriales::cambio(int posicion1, int posicion2){
    material *aux;
    for (int jugador = 0; jugador < cantidad_jugadores; jugador++){
        aux = materiales[jugador][posicion1];
        materiales[jugador][posicion1] = materiales[jugador][posicion2];
        materiales[jugador][posicion2] = aux;
    }
}

void DatosMateriales::ordenar_materiales(){
    for (int material=0;material<cantidad_materiales;material++){
        if (materiales[JUGADOR_UNO][material]->nombre == NOMBRE_MADERA)
            cambio(material,MADERA);
        if (materiales[JUGADOR_UNO][material]->nombre == NOMBRE_PIEDRA)
            cambio(material,PIEDRA);
        if (materiales[JUGADOR_UNO][material]->nombre == NOMBRE_METAL)
            cambio(material,METAL);
        if (materiales[JUGADOR_UNO][material]->nombre == NOMBRE_ANDYCOIN)
            cambio(material,ANDYCOIN);
        if (materiales[JUGADOR_UNO][material]->nombre == NOMBRE_BOMBA)
            cambio(material,BOMBA);
    }
}

void DatosMateriales::guardar_materiales() {
    ofstream archivo(PATH_MATERIALES);
    if(archivo.fail()){
    cout << "Error abriendo el fichero " << PATH_MATERIALES << endl;
    } else{
        for(int i=0; i<cantidad_materiales;i++){
            archivo<< materiales[JUGADOR_UNO][i]->nombre;
            archivo <<" "<< materiales[JUGADOR_UNO][i]->cantidad;
            archivo <<" "<< materiales[JUGADOR_DOS][i]->cantidad<< endl;
        }
        cout<<"Datos materiales guardados"<<endl;
        archivo.close();
    }
}

bool DatosMateriales::comprobar_materiales_construccion(edificio edificio, int jugador){
    return (materiales[jugador][PIEDRA]->cantidad>=edificio.cantidad_piedra && materiales[jugador][MADERA]->cantidad>=edificio.cantidad_madera && materiales[jugador][METAL]->cantidad>=edificio.cantidad_metal);
}


void DatosMateriales::sumar_materiales(int posicion, int cantidad, int jugador){
    materiales[jugador][posicion]->cantidad += cantidad;
}

void DatosMateriales::restar_construccion_materiales(edificio edificio, int jugador){
    materiales[jugador][PIEDRA]->cantidad -= edificio.cantidad_piedra;
    materiales[jugador][MADERA]->cantidad -= edificio.cantidad_madera;
    materiales[jugador][METAL]->cantidad -= edificio.cantidad_metal;
}

void DatosMateriales::sumar_demolicion_materiales(edificio edificio, int jugador){
    materiales[jugador][PIEDRA]->cantidad += edificio.cantidad_piedra/2;
    materiales[jugador][MADERA]->cantidad += edificio.cantidad_madera/2;
    materiales[jugador][METAL]->cantidad += edificio.cantidad_metal/2;
}

bool DatosMateriales::comprobar_materiales_reparacion(edificio edificio, int jugador){
    bool materiales_suficientes = false;
    if  (materiales[jugador][PIEDRA]->cantidad >= edificio.cantidad_piedra/4 && materiales[jugador][MADERA]->cantidad >= edificio.cantidad_madera/4 && materiales[jugador][METAL]->cantidad >= edificio.cantidad_metal/4){
        materiales_suficientes = true;
        restar_reparacion_materiales(edificio, jugador);
    }
    else{
        cout << "No tienes los materiales suficientes para reparar este edificio" << endl;
    }
    return materiales_suficientes;
}

void DatosMateriales::restar_reparacion_materiales(edificio edificio, int jugador){
    materiales[jugador][PIEDRA]->cantidad -= edificio.cantidad_piedra/4;
    materiales[jugador][MADERA]->cantidad -= edificio.cantidad_madera/4;
    materiales[jugador][METAL]->cantidad -= edificio.cantidad_metal/4;
}

DatosMateriales::~DatosMateriales() {
    for (int jugador=0; jugador<cantidad_jugadores; jugador++){
        for (int material=0; material<cantidad_materiales; material++){
            delete materiales[jugador][material];
    }
        delete [] materiales[jugador];
   }

    delete [] materiales;
}

