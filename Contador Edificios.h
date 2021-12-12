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

  int devolver_cantidad_construida(string nombre);
  void sumar_edificio(string nombre);
  void restar_edificio(string nombre);
};

#endif // CONTADOR_EDIFICIOS_H_INCLUDED
