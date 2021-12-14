#include "Floyd.h"



void Floyd::crear_matriz_camino_costos(int ** matriz_adyacencia){
    int ** caminos = new int*[cantidad_vertices];
    int ** costos = new int*[cantidad_vertices];
    for(int i = 0; i < cantidad_vertices; i++){
        caminos[i] = new int[cantidad_vertices];
        costos[i] = new int[cantidad_vertices];
    }

    for(int i = 0; i < cantidad_vertices; i++){
        for(int j = 0; j < cantidad_vertices; j++) {
            caminos[i][j] = j;
            costos[i][j] = matriz_adyacencia[i][j];
        }
    }
    matriz_caminos = caminos;
    matriz_costos = costos;
}

void Floyd::calcular_matrices() {

    //matriz_costos = crearmatriz_costos(matriz_adyacencia);
    //matriz_caminos = crearmatriz_caminos();

    crear_matriz_camino_costos(matriz_adyacencia);

    for (int verticeIntermedio = 0; verticeIntermedio < cantidad_vertices; verticeIntermedio++) {

        for (int origen = 0; origen < cantidad_vertices; origen++){

            for (int destino = 0; destino < cantidad_vertices; destino++) {

                int costo = matriz_costos[origen][verticeIntermedio] + matriz_costos[verticeIntermedio][destino];

                if (matriz_costos[origen][destino] > costo) {
                    matriz_costos[origen][destino] = costo;
                    matriz_caminos[origen][destino] = matriz_caminos[origen][verticeIntermedio];
                } else if (matriz_costos[origen][destino] == INFINITO){
                    matriz_caminos[origen][destino] = POSICION_NO_ENCONTRADA;
                }

            }

        }
    }

}

void Floyd::agrandar_camino_especifico(camino_especifico *dato, int fila ,int columna){
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

camino_especifico Floyd::camino_minimo(int origen, int destino) {
    camino_especifico* aux = new camino_especifico();
    camino_especifico datos;
    aux->longitud = 0;
    aux->costo = matriz_costos[origen][destino];
    agrandar_camino_especifico(aux,vertices->obtener_fila(origen +1),vertices->obtener_columna(origen +1));
    do{
        origen = matriz_caminos[origen][destino];
        agrandar_camino_especifico(aux,vertices->obtener_fila(origen +1),vertices->obtener_columna(origen +1));

    }while(origen != destino);
    cout << endl;
    datos = *aux;
    delete aux;
    return datos;
}

void Floyd::liberarMatrices() {
    if(matriz_costos != nullptr && matriz_caminos != nullptr){
        for(int i = 0; i < cantidad_vertices; i++){
            delete[] matriz_costos[i];
            delete[] matriz_caminos[i];
        }
        delete[] matriz_costos;
        delete[] matriz_caminos;

        matriz_costos = nullptr;
        matriz_caminos = nullptr;
    }
}

Floyd::~Floyd(){
    liberarMatrices();
}

Floyd::Floyd(Lista<Vertice> *vertices, int ** matriz_adyacencia) {
    this -> vertices = vertices;
    this -> matriz_adyacencia = matriz_adyacencia;
    cantidad_vertices = vertices -> obtener_cantidad_elementos();
    calcular_matrices();
}




