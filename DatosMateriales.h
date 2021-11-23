#ifndef DATOSMATERIALES_H_INCLUDED
#define DATOSMATERIALES_H_INCLUDED
#include <string>
#include <iostream>
#include <fstream>
#include "Menu.h"
//#include "Datos Edificios.h"
//#include "Material Colocable.h"

using namespace std;
const string PATH_MATERIALES = "materiales.txt";
const int PIEDRA = 0;
const int MADERA = 1;
const int METAL = 2;
const int ANDYCOIN = 3;
const int BOMBA = 4;
const string NOMBRE_PIEDRA = "piedra";
const string NOMBRE_MADERA = "madera";
const string NOMBRE_METAL = "metal";
const string NOMBRE_ANDYCOIN = "andycoins";
const string NOMBRE_BOMBA = "bombas";
const int COSTO_BOMBA = 100;

struct Material{
    string nombre;
    int cantidad;
};

class DatosMateriales{
   private:

    //Atributos
    Material*** materiales;
    int cantidad_materiales;
    int cantidad_jugadores;

   public:
    //Métodos públicos

    //Constructor
    //PRE:el archivo materiales.txt debe existir en el directorio donde se encuentre el programa
    //POS: carga la informacion del archivo en el vector dinamico materiales y la cantidad de
    //materiales que haya en cantidad_materiales
    DatosMateriales(int cantidad_jugadores);

    //Destructor
    //PRE:
    //POS:libera la memoria tomada
    ~DatosMateriales();

    //PRE:
    //POS:
    int devolver_cantidad(int jugador, int material);
    
    //PRE:
    //POS:Muestra la informacion de los materiales
    void mostrar_materiales(int jugador);

    //PRE:
    //POS:
    bool comprar_bombas(int jugador, int cantidad);

    //PRE:
    //POS:Guarda la informacion de los materiales en su correspondiente archivo
    void guardar_materiales();

    //PRE:Recibir un edificio
    //POS:Devuelve si hay los materiales necesarios para la construccion o no
    bool comprobar_materiales_necesarios(//edificio edificio
                                         );

    //PRE:Recibir un edificio
    //POS:Suma los materiales demolidos correspondientes
    void sumar_materiales_demolidos(//edificio edificio
                                    );

    //PRE:Recibir una posicion dentro del tamaño del vector y una cantidad
    //POS:Suma la cantidad ingresada al material que se encuentre en esa posicion
    void sumar_materiales(int posicion, int cant);

    //PRE:Recibir un edificio
    //POS:Resta los materiales usados para la construccion
    void restar_materiales_usados(//edificio construido
                                  );

   private:
    //Métodos privados
    
    //PRE:
    //POS:
    void leer_archivo_inicial();

    //PRE:
    //POS:
    void leer_archivo();

    //PRE:Recibir un puntero de un material
    //POS:Redimensiona el vector que guarda los materiales y le agrega el nuevo material
    void agregar_material(Material* material, int jugador);

    //PRE:Recibir posiciones dentro del tamaño del vector
    //POS:Cambia el contenido de las 2 posiciones entre si
    void cambio(int posicion1, int posicion2);

    //PRE:
    //POS: Ordena el vector de materiales
    void ordenar_materiales();

};

#endif // DATOSMATERIALES_H_INCLUDED
