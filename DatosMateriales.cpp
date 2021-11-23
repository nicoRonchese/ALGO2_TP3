#include "DatosMateriales.h"

DatosMateriales::DatosMateriales(int cantidad_jugadores) {
    this->materiales = new Material**[cantidad_jugadores];
    this->cantidad_jugadores = cantidad_jugadores;
    if (cantidad_jugadores==CANTIDAD_JUGADORES)
     leer_archivo();
    else
     leer_archivo_inicial();
    ordenar_materiales();
}

void DatosMateriales::leer_archivo_inicial(){
    cantidad_materiales = 0;
    ifstream archivo(PATH_MATERIALES);
    string nombre, cantidad_uno, cantidad_dos;
    Material* material;
    Material aux;
    if(archivo.fail()){
     cout << "Error abriendo el fichero " << PATH_MATERIALES << endl;
    }
    else{
     while(archivo >> nombre){
        archivo >> cantidad_uno;
        archivo >> cantidad_dos;
        material = new Material;
        material -> nombre = nombre;
        material -> cantidad = 0;
        for (int jugador = 0; jugador<cantidad_jugadores; jugador++){
         agregar_material(material, jugador);
         aux = *material;
         material = new Material;
         *material = aux;
        }
        delete material;
        cantidad_materiales++;
     }
    }
    archivo.close();
}

void DatosMateriales::leer_archivo(){
    cantidad_materiales = 0;
    ifstream archivo(PATH_MATERIALES);
    string nombre, cantidad_uno, cantidad_dos;
    Material* material_uno;
    Material* material_dos;
    if(archivo.fail()){
     cout << "Error abriendo el fichero " << PATH_MATERIALES << endl;
    }
    else{
     while(archivo >> nombre){
        archivo >> cantidad_uno;
        archivo >> cantidad_dos;
        material_uno = new Material;
        material_dos = new Material;
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

void DatosMateriales::agregar_material(Material* material, int jugador){
    Material** materiales_aux = new Material*[(cantidad_materiales + 1)];
    for(int i = 0; i < cantidad_materiales; i++){
        materiales_aux[i] = materiales[jugador][i];
    }
    materiales_aux[cantidad_materiales] = material;
    if (cantidad_materiales != 0)
     delete [] materiales[jugador];
    materiales[jugador]= materiales_aux;
}

int DatosMateriales::devolver_cantidad(int jugador, int material){
 return materiales[jugador][material] -> cantidad;
}

void DatosMateriales::mostrar_materiales(int jugador){
    for (int material=0; material<cantidad_materiales; material++)
        cout<<materiales[jugador][material] -> nombre<<": "<<materiales[jugador][material] -> cantidad<<" unidades"<<endl;
}

bool DatosMateriales::comprar_bombas(int jugador, int cantidad){
 bool compra_realizada=false;
 if (cantidad*COSTO_BOMBA>materiales[jugador][ANDYCOIN]->cantidad)
    cout<<"No tiene la cantidad necesaria de Andycoins para esta compra"<<endl;
 else{
    materiales[jugador][ANDYCOIN]->cantidad-=cantidad*COSTO_BOMBA;
    materiales[jugador][BOMBA]->cantidad+=cantidad;
    cout<<"Compra realizada con exito"<<endl;
    compra_realizada=true;
 }
 return compra_realizada;
}

void DatosMateriales::cambio(int posicion1, int posicion2){
    Material *aux;
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
    }
    else{
        for(int i=0; i<cantidad_materiales;i++){
            archivo<< materiales[JUGADOR_UNO][i]->nombre;
            archivo <<" "<< materiales[JUGADOR_UNO][i]->cantidad;
            archivo <<" "<< materiales[JUGADOR_DOS][i]->cantidad<< endl;
        }
        cout<<"Datos materiales guardados"<<endl;
        archivo.close();
    }
}

bool DatosMateriales::comprobar_materiales_necesarios(//edificio edificio
                                                      ){
 //return (materiales[PIEDRA]->cantidad>=edificio.cantidad_piedra && materiales[MADERA]->cantidad>=edificio.cantidad_madera && materiales[METAL]->cantidad>=edificio.cantidad_metal);
 return false;
}

void DatosMateriales::sumar_materiales_demolidos(//edificio edificio
                                                 ){
 //materiales[PIEDRA]->cantidad += edificio.cantidad_piedra/2;
 //materiales[MADERA]->cantidad += edificio.cantidad_madera/2;
 //materiales[METAL]->cantidad += edificio.cantidad_metal/2;
}

void DatosMateriales::sumar_materiales(int posicion,int cant){
    //materiales[posicion]->cantidad += cant;
}

void DatosMateriales::restar_materiales_usados(//edificio edificio
                                               ){
 //materiales[PIEDRA]->cantidad -= edificio.cantidad_piedra;
 //materiales[MADERA]->cantidad -= edificio.cantidad_madera;
 //materiales[METAL]->cantidad -= edificio.cantidad_metal;
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

