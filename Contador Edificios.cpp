#include "Contador Edificios.h"

int Contador_edificios::devolver_cantidad_construida(string nombre){
 int cantidad_construida;
 if (nombre==ESCUELA)
    cantidad_construida = cantidad_escuelas;
 else if (nombre==FABRICA)
    cantidad_construida = cantidad_fabricas;
 else if (nombre==MINA)
    cantidad_construida = cantidad_minas;
 else if (nombre==MINA_ORO)
    cantidad_construida = cantidad_minas_oro;
 else if (nombre==PLANTA_ELECTRICA)
    cantidad_construida = cantidad_plantas_electricas;
 else if (nombre==ASERRADERO)
    cantidad_construida = cantidad_aserraderos;
 return cantidad_construida;
}

void Contador_edificios::sumar_edificio(string nombre){
 if (nombre==ESCUELA){
    cantidad_escuelas++;
 }
 else if (nombre==FABRICA){
    cantidad_fabricas++;
 }
 else if (nombre==MINA){
    cantidad_minas++;
 }
 else if (nombre==MINA_ORO){
    cantidad_minas_oro++;
 }
 else if (nombre==PLANTA_ELECTRICA){
    cantidad_plantas_electricas++;
 }
 else if (nombre==ASERRADERO){
    cantidad_aserraderos++;
 }
}

void Contador_edificios::restar_edificio(string nombre){
 if (nombre==ESCUELA)
    cantidad_escuelas--;
 else if (nombre==FABRICA)
    cantidad_fabricas--;
 else if (nombre==MINA)
    cantidad_minas--;
 else if (nombre==MINA_ORO)
    cantidad_minas_oro--;
 else if (nombre==PLANTA_ELECTRICA)
    cantidad_plantas_electricas--;
 else if (nombre==ASERRADERO)
    cantidad_aserraderos--;
}
