#include "Objetivos.h"

Objetivos::Objetivos(int maximo_escuelas){
 this->obelisco_construido = false;
 this->maximo_escuelas = maximo_escuelas;
 this->objetivos = new Objetivo*[3];
 sorteo_objetivos();
}

void Objetivos::sorteo_objetivos(){
 int objetivos_preparados[TOTAL_OBJETIVOS_JUGADOR];
 sortear_objetivos(objetivos_preparados, TOTAL_OBJETIVOS_JUGADOR);
 for (int objetivo = 0; objetivo < 3; objetivo++){
   objetivos[objetivo] = new Objetivo;
   objetivos[objetivo]->tipo_objetivo = objetivos_preparados[objetivo];
   objetivos[objetivo]->cumplido = false;
   if (objetivos[objetivo]->tipo_objetivo == CANSADO)
    objetivos[objetivo]->cantidad = 50;
   else
    objetivos[objetivo]->cantidad = 0;
 }
}

void Objetivos::construccion_obelisco(){
 obelisco_construido = true;
}

void Objetivos::mostrar_victoria(int turno){
 cout << "FELICITACIONES JUGADOR "<< turno+1 <<" GANASTE!!!"<<endl<<endl;
 if (!obelisco_construido)
  mostrar_objetivos();
 else
  cout<<"Obelisco fue construido y la patria se restauro"<<endl;
}

bool Objetivos::comprobar_objetivos_cumplidos(){
 int objetivos_cumplidos = 0;
 if (obelisco_construido)
  objetivos_cumplidos = 3;
 else{
  for (int objetivo=0; objetivo<3; objetivo++){
   if (objetivos[objetivo]->cumplido)
    objetivos_cumplidos++;
  }
 }
 return (objetivos_cumplidos == 3);
}

void Objetivos::mostrar_objetivo(int tipo_objetivo, int ubicacion_objetivo){
 switch (tipo_objetivo) {
        case COMPRAR_ANDYPOLIS:
            mostrar_comprar_andypolis(ubicacion_objetivo);
            break;
        case EDAD_PIEDRA:
            mostrar_edad_piedra(ubicacion_objetivo);
            break;
        case BOMBARDERO:
            mostrar_bombardero(ubicacion_objetivo);
            break;
        case ENERGETICO:
            mostrar_energetico(ubicacion_objetivo);
            break;
        case LETRADO:
            mostrar_letrado(ubicacion_objetivo);
            break;
        case MINERO:
            mostrar_minero(ubicacion_objetivo);
            break;
        case CANSADO:
            mostrar_cansado(ubicacion_objetivo);
            break;
        case CONSTRUCTOR:
            mostrar_constructor(ubicacion_objetivo);
            break;
        case ARMADO:
            mostrar_armado(ubicacion_objetivo);
            break;
         case EXTREMISTA:
            mostrar_extremista(ubicacion_objetivo);
            break;
        default:
            cout << "Error: opcion invalida"<<endl;
    }
}

void Objetivos::mostrar_objetivos(){
 int objetivos_cumplidos = 0;
 for (int objetivo=0; objetivo<3; objetivo++){
   if (objetivos[objetivo]->cumplido)
       objetivos_cumplidos++;
 }
 cout<<"Objetivos cumplidos: ("<<objetivos_cumplidos<<", 3)"<<endl<<endl;
 for (int objetivo=0; objetivo<3; objetivo++){
    mostrar_objetivo(objetivos[objetivo]->tipo_objetivo, objetivo);
 }
}


void Objetivos::mostrar_comprar_andypolis(int ubicacion_objetivo){
 cout<<"Comprar andypolis: haber juntado 100.000 andycoins a lo largo de la partida"<<endl;
 cout<<"Progreso: ("<<objetivos[ubicacion_objetivo]->cantidad<<", 100.000)"<<endl<<endl;
}

void Objetivos::mostrar_edad_piedra(int ubicacion_objetivo){
 cout<<"Edad de piedra: tener en el inventario 50000 piedras"<<endl;
 cout<<"Progreso: ("<<objetivos[ubicacion_objetivo]->cantidad<<", 50.000)"<<endl<<endl;
}

void Objetivos::mostrar_bombardero(int ubicacion_objetivo){
 cout<<"Bombardero: haber usado 5 bombas."<<endl;
 cout<<"Progreso: ("<<objetivos[ubicacion_objetivo]->cantidad<<", 5)"<<endl<<endl;
}

void Objetivos::mostrar_energetico(int ubicacion_objetivo){
 cout<<"Energetico: haber terminado un turno con 100 puntos de energia."<<endl;
 cout<<"Progreso: ("<<objetivos[ubicacion_objetivo]->cantidad<<", 100)"<<endl<<endl;
}

void Objetivos::mostrar_letrado(int ubicacion_objetivo){
 cout<<"Letrado: haber construido el máximo posible de escuelas."<<endl;
 cout<<"Progreso: ("<<objetivos[ubicacion_objetivo]->cantidad<<", "<<maximo_escuelas<<")"<<endl<<endl;
}

void Objetivos::mostrar_minero(int ubicacion_objetivo){
 cout<<"Minero: haber construido una mina de cada tipo."<<endl;
 cout<<"Progreso: ("<<objetivos[ubicacion_objetivo]->cantidad<<", 2)"<<endl<<endl;
}

void Objetivos::mostrar_cansado(int ubicacion_objetivo){
 cout<<"Cansado: terminar un turno con 0 de energia."<<endl;
 cout<<"Progreso: ("<<objetivos[ubicacion_objetivo]->cantidad<<", 0)"<<endl<<endl;
}

void Objetivos::mostrar_constructor(int ubicacion_objetivo){
 cout<<"Constructor: construir un edificio de cada tipo."<<endl;
 cout<<"Progreso: ("<<objetivos[ubicacion_objetivo]->cantidad<<", 6)"<<endl<<endl;
}

void Objetivos::mostrar_armado(int ubicacion_objetivo){
 cout<<"Armado: tener 10 bombas en el inventario."<<endl;
 cout<<"Progreso: ("<<objetivos[ubicacion_objetivo]->cantidad<<", 10)"<<endl<<endl;
}

void Objetivos::mostrar_extremista(int ubicacion_objetivo){
 cout<<"Extremista: haber comprado 500 bombas en una partida."<<endl;
 cout<<"Progreso: ("<<objetivos[ubicacion_objetivo]->cantidad<<", 500)"<<endl<<endl;
}

void Objetivos::procesar_objetivo(int numero_objetivo, int cantidad, int ubicacion_objetivo){
 switch (numero_objetivo) {
        case COMPRAR_ANDYPOLIS:
            comprar_andypolis(cantidad, ubicacion_objetivo);
            break;
        case EDAD_PIEDRA:
            edad_piedra(cantidad, ubicacion_objetivo);
            break;
        case BOMBARDERO:
            bombardero(cantidad, ubicacion_objetivo);
            break;
        case ENERGETICO:
            energetico(cantidad, ubicacion_objetivo);
            break;
        case LETRADO:
            letrado(cantidad, ubicacion_objetivo);
            break;
        case MINERO:
            minero(cantidad, ubicacion_objetivo);
            break;
        case CANSADO:
            cansado(cantidad, ubicacion_objetivo);
            break;
        case CONSTRUCTOR:
            constructor(cantidad, ubicacion_objetivo);
            break;
        case ARMADO:
            armado(cantidad, ubicacion_objetivo);
            break;
         case EXTREMISTA:
            extremista(cantidad, ubicacion_objetivo);
            break;
        default:
            cout << "Error: opcion invalida"<<endl;
    }
}

void Objetivos::actualizar_objetivo(int tipo_objetivo, int cantidad){
 for (int objetivo=0; objetivo<3; objetivo++){
   if (objetivos[objetivo]->tipo_objetivo == tipo_objetivo)
     procesar_objetivo(tipo_objetivo, cantidad, objetivo);
 }
}

void Objetivos::comprar_andypolis(int andycoins_ganados, int ubicacion_objetivo){
    objetivos[ubicacion_objetivo]->cantidad += andycoins_ganados;
    if (objetivos[ubicacion_objetivo]->cantidad >= 100000)
     objetivos[ubicacion_objetivo]->cumplido = true;
}

void Objetivos::edad_piedra(int piedra, int ubicacion_objetivo){
    if (objetivos[ubicacion_objetivo]->cantidad < piedra)
     objetivos[ubicacion_objetivo]->cantidad = piedra;
    if (objetivos[ubicacion_objetivo]->cantidad >= 50000)
     objetivos[ubicacion_objetivo]->cumplido = true;
}

void Objetivos::bombardero(int bombas_usadas, int ubicacion_objetivo){
    objetivos[ubicacion_objetivo]->cantidad += bombas_usadas;
    if (objetivos[ubicacion_objetivo]->cantidad >= 5)
     objetivos[ubicacion_objetivo]->cumplido = true;
}

void Objetivos::energetico(int energia, int ubicacion_objetivo){
    if (objetivos[ubicacion_objetivo]->cantidad < energia)
     objetivos[ubicacion_objetivo]->cantidad = energia;
    if (objetivos[ubicacion_objetivo]->cantidad >= 100)
     objetivos[ubicacion_objetivo]->cumplido = true;
}

void Objetivos::letrado(int cantidad_escuelas, int ubicacion_objetivo){
    if (objetivos[ubicacion_objetivo]->cantidad < cantidad_escuelas)
     objetivos[ubicacion_objetivo]->cantidad = cantidad_escuelas;
    if (objetivos[ubicacion_objetivo]->cantidad >= maximo_escuelas)
     objetivos[ubicacion_objetivo]->cumplido = true;
}

void Objetivos::minero(int minas_construidas, int ubicacion_objetivo){
    if (objetivos[ubicacion_objetivo]->cantidad < minas_construidas)
     objetivos[ubicacion_objetivo]->cantidad = minas_construidas;
    if (objetivos[ubicacion_objetivo]->cantidad == 2)
     objetivos[ubicacion_objetivo]->cumplido = true;
}

void Objetivos::cansado(int energia, int ubicacion_objetivo){
    if (objetivos[ubicacion_objetivo]->cantidad > energia)
     objetivos[ubicacion_objetivo]->cantidad = energia;
    if (objetivos[ubicacion_objetivo]->cantidad == 0)
     objetivos[ubicacion_objetivo]->cumplido = true;
}

void Objetivos::constructor(int cantidad_edificios, int ubicacion_objetivo){
    if (objetivos[ubicacion_objetivo]->cantidad < cantidad_edificios)
     objetivos[ubicacion_objetivo]->cantidad = cantidad_edificios;
    if (objetivos[ubicacion_objetivo]->cantidad == 6)
     objetivos[ubicacion_objetivo]->cumplido = true;
}

void Objetivos::armado(int bombas_inventario, int ubicacion_objetivo){
    if (objetivos[ubicacion_objetivo]->cantidad < bombas_inventario)
     objetivos[ubicacion_objetivo]->cantidad = bombas_inventario;
    if (objetivos[ubicacion_objetivo]->cantidad >= 10)
     objetivos[ubicacion_objetivo]->cumplido = true;
}

void Objetivos::extremista(int bombas_compradas, int ubicacion_objetivo){
    objetivos[ubicacion_objetivo]->cantidad += bombas_compradas;
    if (objetivos[ubicacion_objetivo]->cantidad >= 500)
     objetivos[ubicacion_objetivo]->cumplido = true;
}

void Objetivos::sortear_objetivos(int* objetivos_preparados, int total_objetivos_jugador){
    for(int contador = 0; contador < total_objetivos_jugador; contador++){
        objetivos_preparados[contador] = rand() % TOTAL_OBJETIVOS + 1;
        if(contador > 0){
            while(hay_objetivo_repetido(objetivos_preparados, contador)){
                objetivos_preparados[contador] = rand() % TOTAL_OBJETIVOS + 1;
            }
        }
    }
}

bool Objetivos::hay_objetivo_repetido(int* objetivos_preparados, int objetivo_actual){
    bool objetivo_repetido = false;
    int contador = 0;

    while((contador < objetivo_actual) && !(objetivo_repetido)){
        if(objetivos_preparados[contador] == objetivos_preparados[objetivo_actual]){
            objetivo_repetido = true;
        }
        contador++;
    }

    return objetivo_repetido;
}

Objetivos::~Objetivos(){
  for (int objetivo=0; objetivo<3; objetivo++)
   delete objetivos[objetivo];
  delete [] objetivos;
}
