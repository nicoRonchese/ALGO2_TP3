#ifndef CONTADOR_EDIFICIOS_H_INCLUDED
#define CONTADOR_EDIFICIOS_H_INCLUDED

class Contador_edificios {
 private:

  int cantidad_aserraderos = 0;
  int cantidad_fabricas = 0;
  int cantidad_minas = 0;
  int cantidad_minas_oro = 0;
  int cantidad_escuelas = 0;
  int cantidad_plantas_electricas = 0;

 public:
  //Métodos públicos
  /*
  * Pre: Recibe el nombre de un edificio valido.
  * Post: Devuelve la cantidad de construcciones del edificio pasado por parametro.
  */
  int devolver_cantidad_construida(string nombre);

  /*
  * Pre: Recibe el nombre de un edificio valido.
  * Post: Le suma una construcción al edificio pasado por parametro.
  */
  void sumar_edificio(string nombre);

  /*
  * Pre: Recibe el nombre de un edificio valido.
  * Post: Le resta una construcción al edificio pasado por parametro.
  */
  void restar_edificio(string nombre);
};

#endif // CONTADOR_EDIFICIOS_H_INCLUDED
