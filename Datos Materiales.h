#ifndef DATOS_MATERIALES_H_INCLUDED
#define DATOS_MATERIALES_H_INCLUDED
#include <string>
#include <iostream>
#include <fstream>
#include "Datos Edificios.h"
#include "Structs Constantes.h"
//#include "Datos Edificios.h"
//#include "Material Colocable.h"

using namespace std;

class DatosMateriales{
   private:

    //Atributos
    material*** materiales;
    int cantidad_materiales;
    int cantidad_jugadores;

   public:
    //Métodos públicos

    //Constructor
    //PRE: El archivo materiales.txt debe existir en el directorio donde se encuentre el programa.
    //POS: Carga la informacion del archivo en el vector dinamico materiales y la cantidad de
    //     materiales que haya en cantidad_materiales.
    DatosMateriales(int cantidad_jugadores);

    //PRE: Recibe un jugador y un material valido.
    //POS: Devuelve la cantidad de material que tiene el jugador.
    int devolver_cantidad(int jugador, int material);

    //PRE: -.
    //POS: Muestra la informacion de los materiales.
    void mostrar_materiales(int jugador);

    //PRE: Recibe un jugador valido.
    //POS: Si devuelve 'true' la compra se logro realizar con éxito, de lo contrario devolvera 'false'
    bool comprar_bombas(int jugador, int cantidad);

    //PRE: -.
    //POS: Guarda la informacion de los materiales en su correspondiente archivo
    void guardar_materiales();

    //PRE: Recibir un edificio.
    //POS: Devuelve si hay los materiales necesarios para la construccion o no.
    bool comprobar_materiales_construccion(edificio edificio, int jugador);

    //PRE: Recibir una posicion dentro del tamaño del vector y una cantidad.
    //POS: Suma la cantidad ingresada al material que se encuentre en esa posicion.
    void sumar_materiales(int posicion, int cantidad, int jugador);

    //PRE: Recibir un edificio.
    //POS: Resta los materiales usados para la construccion.
    void restar_construccion_materiales(edificio construido, int jugador);

    //PRE: Recibir un edificio.
    //POS: Suma los materiales demolidos correspondientes.
    void sumar_demolicion_materiales(edificio edificio, int jugador);

    //PRE: Recibe un edificio y un jugador valido.
    //POS: Devuelve 'true' si hay materiales suficientes para reparar el edifico y 'false'
    //     de no ser así.
    bool comprobar_materiales_reparacion(edificio edificio, int jugador);

    //Destructor
    //PRE: -
    //POS: Libera la memoria tomada.
    ~DatosMateriales();

   private:
    //Métodos privados

    //PRE: -.
    //POS: Lee el archivo por primera vez y carga los datos.
    void leer_archivo_inicial();

    //PRE:
    //POS: Lee el archivo y carga los datos.
    void leer_archivo();

    //PRE: Recibir un puntero de un material.
    //POS: Redimensiona el vector que guarda los materiales y le agrega el nuevo material.
    void agregar_material(material* material, int jugador);

    //PRE: Recibir posiciones dentro del tamaño del vector.
    //POS: Cambia el contenido de las 2 posiciones entre si.
    void cambio(int posicion1, int posicion2);

    //PRE: -.
    //POS: Ordena el vector de materiales.
    void ordenar_materiales();

    //PRE: Recibe un edificio y un jugador valido.
    //POS: Resta los materiales usados para la construcción del edificio.
    void restar_reparacion_materiales(edificio edificio, int jugador);

};

#endif // DATOS_MATERIALES_H_INCLUDED
