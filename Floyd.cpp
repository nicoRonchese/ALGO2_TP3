#include "Floyd.h"



void Floyd::crearMatrizCamino_Costos(int ** matrizAdyacencia){
    int ** caminos = new int*[cantidadVertices];
    int ** costos = new int*[cantidadVertices];
    for(int i = 0; i < cantidadVertices; i++){
        caminos[i] = new int[cantidadVertices];
        costos[i] = new int[cantidadVertices];
    }

    for(int i = 0; i < cantidadVertices; i++){
        for(int j = 0; j < cantidadVertices; j++) {
            caminos[i][j] = j;
            costos[i][j] = matrizAdyacencia[i][j];
        }
    }
    matrizCaminos = caminos;
    matrizCostos = costos;
}

void Floyd::calcularMatrices() {

    //matrizCostos = crearMatrizCostos(matrizAdyacencia);
    //matrizCaminos = crearMatrizCaminos();

    crearMatrizCamino_Costos(matrizAdyacencia);

    for (int verticeIntermedio = 0; verticeIntermedio < cantidadVertices; verticeIntermedio++) {

        for (int origen = 0; origen < cantidadVertices; origen++){

            for (int destino = 0; destino < cantidadVertices; destino++) {

                int costo = matrizCostos[origen][verticeIntermedio] + matrizCostos[verticeIntermedio][destino];

                if (matrizCostos[origen][destino] > costo) {
                    matrizCostos[origen][destino] = costo;
                    matrizCaminos[origen][destino] = matrizCaminos[origen][verticeIntermedio];
                } else if (matrizCostos[origen][destino] == INFINITO){
                    matrizCaminos[origen][destino] = POSICION_NO_ENCONTRADA;
                }

            }

        }
    }

}

void Floyd::agrandarCaminoEspecifico(camino_especifico *dato, int fila ,int columna){
    int** camino_aux = new int*[dato->longitud+1];
    for(int i = 0; i < (dato->longitud); i++){
        camino_aux[i] = dato->camino[i];
    }
    camino_aux[dato->longitud] = new int[2] ;
    camino_aux[dato->longitud][0]= fila;
    camino_aux[dato->longitud][1]= columna;
    if(dato->longitud != 0){
        delete [] dato->camino;
    }
    dato->camino = camino_aux;
    dato->longitud++;
}

camino_especifico Floyd::caminoMinimo(int origen, int destino) {
    camino_especifico* datos = new camino_especifico;
    datos->longitud = 0;
    datos->costo = matrizCostos[origen][destino];
    agrandarCaminoEspecifico(datos,vertices->obtenerFila(origen +1),vertices->obtenerColumna(origen +1));
    if(matrizCaminos[origen][destino] == POSICION_NO_ENCONTRADA){
        cout << "No hay un camino que conecte " <<  vertices->obtenerNombre(origen + 1) << " con " << vertices->obtenerNombre(destino + 1);
    }else{
        do{
            origen = matrizCaminos[origen][destino];
            agrandarCaminoEspecifico(datos,vertices->obtenerFila(origen +1),vertices->obtenerColumna(origen +1));

        }while(origen != destino);
    }
    cout << endl;
    return *datos;

}

void Floyd::liberarMatrices() {
    if(matrizCostos != nullptr && matrizCaminos != nullptr){
        for(int i = 0; i < cantidadVertices; i++){
            delete[] matrizCostos[i];
            delete[] matrizCaminos[i];
        }
        delete[] matrizCostos;
        delete[] matrizCaminos;

        matrizCostos = nullptr;
        matrizCaminos = nullptr;
    }
}

Floyd::~Floyd(){
    liberarMatrices();
}

Floyd::Floyd(Lista<Vertice> *vertices, int ** matrizAdyacencia) {
    this -> vertices = vertices;
    this -> matrizAdyacencia = matrizAdyacencia;
    cantidadVertices = vertices -> obtenerCantidadDeElementos();
    calcularMatrices();
//    mostrarMatrices();
}




