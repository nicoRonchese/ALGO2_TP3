#include "Mapa.h"
#include "Casillero Transitable.cpp"
#include "Casillero Construible.cpp"
#include "Casillero Inaccesible.cpp"
#include "Casillero.cpp"

Mapa::Mapa(){
   cantidad_transitables = 0;
   crear_matriz_archivo();
}

void Mapa::crear_matriz_archivo(){
   int filas, columnas;
   string tipo_casillero;
   ifstream archivo(PATH_MAPA);
   if(archivo.fail() || archivo.eof()){
     cout << "Error abriendo el fichero " << PATH_MAPA << endl;
   }
   else{
    archivo >> filas;
    archivo >> columnas;
    this->filas_matriz = filas;
    this->columnas_matriz = columnas;
    this->Matriz = new Casillero**[filas];
    for (int i=0;i<filas;i++)
     Matriz[i]=new Casillero*[columnas];
    for (int fila=0; fila<filas_matriz; fila++){
     for (int columna=0; columna<columnas_matriz; columna++){
      archivo >> tipo_casillero;
      Matriz[fila][columna]=definir_casillero(tipo_casillero,fila,columna);
      grafo[JUGADOR_UNO].agregarVertice(fila, columna, costo_terreno(tipo_casillero, JUGADOR_UNO));
      grafo[JUGADOR_DOS].agregarVertice(fila, columna, costo_terreno(tipo_casillero, JUGADOR_DOS));
     }
    }
   }
   cargar_datos_grafo();
}

int Mapa::costo_terreno(string tipo_casillero, int jugador){
 int costo;
 if (tipo_casillero==MUELLE && jugador==JUGADOR_UNO)
  costo = 5;
 else if (tipo_casillero==MUELLE && jugador==JUGADOR_DOS)
  costo = 2;
 else if (tipo_casillero==LAGO && jugador==JUGADOR_UNO)
  costo = 2;
 else if (tipo_casillero==LAGO && jugador==JUGADOR_DOS)
  costo = 5;
 else if (tipo_casillero==TERRENO)
  costo = 25;
 else if (tipo_casillero==CAMINO)
  costo = 4;
 else if (tipo_casillero==BETUN)
  costo = 0;
 return costo;
}

void Mapa::cargar_datos_grafo(){
  for (int fila=0; fila<filas_matriz; fila++){
     for (int columna=0; columna<columnas_matriz; columna++){
       if (fila!=0){
         grafo[JUGADOR_UNO].agregarCamino(fila, columna, fila-1, columna);
         grafo[JUGADOR_DOS].agregarCamino(fila, columna, fila-1, columna);
       }
       if (columna!=0){
         grafo[JUGADOR_UNO].agregarCamino(fila, columna, fila, columna-1);
         grafo[JUGADOR_DOS].agregarCamino(fila, columna, fila, columna-1);
       }
     }
    }
    grafo[JUGADOR_UNO].usarFloyd();
    grafo[JUGADOR_DOS].usarFloyd();
}

Casillero* Mapa::definir_casillero(string tipo_terreno,int fila,int columna){
   Casillero* casillero;
   if (tipo_terreno == BETUN || tipo_terreno == CAMINO || tipo_terreno == MUELLE){
      casillero = new CasilleroTransitable(tipo_terreno);
      agregar_transitables(fila,columna);
   }
   else if (tipo_terreno == LAGO){
      casillero = new CasilleroInaccesible(tipo_terreno);
   }
   else if (tipo_terreno == TERRENO){
      casillero = new CasilleroConstruible(tipo_terreno);
   }
   else{
     casillero =  new CasilleroInaccesible(LAGO);
   }
   return casillero;
}

bool Mapa::ubicar_edificios_archivo(){
  bool archivo_usable = true;
  ifstream archivo(PATH_UBICACIONES);
  string objeto;
  if(archivo.fail() || archivo.eof())
     archivo_usable = false;
  else{
     while (!archivo.eof()){
        getline(archivo, objeto, '(');
        objeto = quitar_espacio_final(objeto);
        objeto = leer_materiales_ubicaciones(archivo, objeto);
        objeto = leer_jugador_uno(archivo, objeto);
        objeto = leer_jugador_dos(archivo, objeto);
     }
  }
  archivo.close();
  return archivo_usable;
 }

string Mapa::leer_materiales_ubicaciones(ifstream &archivo, string objeto){
    string fila_objeto, columna_objeto, basura;
    int fila, columna;
    while (objeto!="1"){
     getline(archivo, fila_objeto, ',');
     getline(archivo, columna_objeto, ')');
     getline(archivo, basura, '\n');
     fila = stoi(fila_objeto) - 1;
     columna = stoi(columna_objeto) - 1;
     Matriz[fila][columna]->colocar_material(construir_material(objeto));
     eliminar_transitables(fila,columna);
     getline(archivo, objeto, '(');
     objeto = quitar_espacio_final(objeto);
    }
    return objeto;
 }

 string Mapa::leer_jugador_uno(ifstream &archivo, string objeto){
    string fila_objeto, columna_objeto, basura;
    int fila, columna;
    if (objeto == "1"){
      getline(archivo, fila_objeto, ',');
      getline(archivo, columna_objeto, ')');
      getline(archivo, basura, '\n');
      fila = stoi(fila_objeto) - 1;
      columna = stoi(columna_objeto) - 1;
      colocar_jugador(fila, columna, JUGADOR_UNO);
      getline(archivo, objeto, '(');
      objeto = quitar_espacio_final(objeto);
      while (objeto != "2"){
        getline(archivo, fila_objeto, ',');
        getline(archivo, columna_objeto, ')');
        getline(archivo, basura, '\n');
        fila = stoi(fila_objeto) - 1;
        columna = stoi(columna_objeto) - 1;
        Matriz[fila][columna]->colocar_edificio(construir_edificio(objeto, JUGADOR_UNO));
        getline(archivo, objeto, '(');
        objeto = quitar_espacio_final(objeto);
      }
    }
    return objeto;
 }

 string Mapa::leer_jugador_dos(ifstream &archivo, string objeto){
    string fila_objeto, columna_objeto, basura;
    int fila, columna;
    if (objeto == "2"){
         getline(archivo, fila_objeto, ',');
         getline(archivo, columna_objeto, ')');
         getline(archivo, basura, '\n');
         fila = stoi(fila_objeto) - 1;
         columna = stoi(columna_objeto) - 1;
         colocar_jugador(fila, columna, JUGADOR_DOS);
         getline(archivo, objeto, '(');
         objeto = quitar_espacio_final(objeto);
         while (!archivo.eof()){
             getline(archivo, fila_objeto, ',');
             getline(archivo, columna_objeto, ')');
             getline(archivo, basura, '\n');
             fila = stoi(fila_objeto) - 1;
             columna = stoi(columna_objeto) - 1;
             Matriz[fila][columna]->colocar_edificio(construir_edificio(objeto, JUGADOR_DOS));
             getline(archivo, objeto, '(');
             objeto = quitar_espacio_final(objeto);
         }
    }
    return objeto;
 }

string Mapa::quitar_espacio_final(string edificio){
  string sin_espacio;
  int longitud = int(edificio.size())-1;
  for (int i = 0; i < longitud; i++)
        sin_espacio += edificio[i];
  return sin_espacio;
}

void Mapa::mostrar_mapa_terrenos(){
  for (int fila=0; fila<filas_matriz; fila++){
    for (int columna=0; columna<columnas_matriz; columna++){
        Matriz[fila][columna]->mostrar_en_mapa_terreno();
        if (columna == columnas_matriz -1)
        {
           cout<<endl;
        }

    }
  }
}

void Mapa::mostrar_mapa(){
  for(int k = 1; k <= columnas_matriz; k++){
        cout << k << " ";
  }
  cout << endl;

  for (int fila=0; fila<filas_matriz; fila++){
    for (int columna=0; columna<columnas_matriz; columna++){
        Matriz[fila][columna]->mostrar_en_mapa();
        cout << " ";
    }
    cout << " " << fila+1 << endl;
  }
}

void Mapa::mostrar_casillero(int fila, int columna){
  Matriz[fila][columna]->mostrar();
}

bool Mapa::consultar_coordenada(int fila,int columna){
 return (fila<filas_matriz && fila>=0 && columna<columnas_matriz && columna>=0);
}

string Mapa::devolver_elemento_en_casillero(int fila, int columna){
 return (Matriz[fila][columna]->devolver_elemento_colocable());
}

void Mapa::agregar_transitables(int fila, int columna){
    int** transitables_aux = new int*[(cantidad_transitables + 1)];

    for(int i = 0; i < cantidad_transitables; i++){
        transitables_aux[i] = transitables[i];
    }
    transitables_aux[cantidad_transitables] = new int[2] ;
    transitables_aux[cantidad_transitables][0]= fila;
    transitables_aux[cantidad_transitables][1]= columna;

    if(cantidad_transitables != 0){
        delete [] transitables;
    }
    transitables = transitables_aux;
    cantidad_transitables++;
}

void Mapa::eliminar_transitables(int fila, int columna){
    int** transitables_aux = new int*[(cantidad_transitables - 1)];
    int aux=0;

    for(int i = 0; i < (cantidad_transitables-1); i++){
      if ((transitables[i][0]==fila)&&(transitables[i][1]==columna))
        aux = 1;
      transitables_aux[i] = transitables[i+aux];
    }
    if(cantidad_transitables != 0){
        delete [] transitables;
    }
    transitables = transitables_aux;
    cantidad_transitables--;
}

void Mapa::colocar_jugador(int fila, int columna, int jugador){
 if (Matriz[fila][columna]->devolver_tipo_casillero() == TRANSITABLE)
  eliminar_transitables(fila, columna);
 Matriz[fila][columna]->colocar_jugador(jugador);
}

void Mapa::lluvia_materiales(){
  srand((unsigned) time(NULL));
  int piedra,madera,metal,total,andycoins;
  piedra = rand()%2+1;
  madera = rand()%2;
  metal =rand()%3+2;
  andycoins = rand()%2;
  total = metal+madera+piedra+andycoins;
  while((total != 0)&&(cantidad_transitables != 0))
  {
    int i = rand()%cantidad_transitables;
    if ((metal+madera+andycoins < total))
        Matriz[transitables[i][0]][transitables[i][1]]->colocar_material(construir_material(NOMBRE_PIEDRA));
    else if (metal+andycoins < total)
        Matriz[transitables[i][0]][transitables[i][1]]->colocar_material(construir_material(NOMBRE_MADERA));
    else if (andycoins < total)
        Matriz[transitables[i][0]][transitables[i][1]]->colocar_material(construir_material(NOMBRE_METAL));
    else
        Matriz[transitables[i][0]][transitables[i][1]]->colocar_material(construir_material(NOMBRE_ANDYCOIN));
    eliminar_transitables(transitables[i][0], transitables[i][1]);
    total--;
   }
}

string Mapa::consultar_casillero(int fila, int columna){
 return (Matriz[fila][columna]->devolver_tipo_casillero());
}

bool Mapa::consultar_vacio(int fila,int columna){
    return (Matriz[fila][columna]->comprobar_vacio());
}

bool Mapa::consultar_propietario(int fila, int columna, int turno){
  return (Matriz[fila][columna]->comprobar_propietario(turno));
}

bool Mapa::recolectar_recursos(DatosMateriales* materiales, int* energia, int jugador){
     int producido = 0;
     for (int fila=0; fila<filas_matriz; fila++){
      for (int columna=0; columna<columnas_matriz; columna++){
        if ((Matriz[fila][columna]->devolver_tipo_casillero()==CONSTRUIBLE) && (!Matriz[fila][columna]->comprobar_vacio()) && (consultar_propietario(fila, columna, jugador))){
           cout<<"En la coordenada ("<<fila+1<<", "<<columna+1<<"), ";
           Matriz[fila][columna]->recolectar_producido(materiales, energia, jugador);
           producido++;
          }
       }
      }
      if (producido==0)
        cout<<"No se produjo recursos"<<endl;
      return (producido!=0);
}

void Mapa::mostrar_construcciones(int turno){
 int construcciones = 0;
 for (int fila=0; fila<filas_matriz; fila++){
     for (int columna=0; columna<columnas_matriz; columna++){
        if ((Matriz[fila][columna]->devolver_tipo_casillero()==CONSTRUIBLE) && (!Matriz[fila][columna]->comprobar_vacio()) && (Matriz[fila][columna]->comprobar_propietario(turno))){
            cout<<Matriz[fila][columna]->devolver_elemento_colocable()<<" ("<<fila+1<<", "<<columna+1<<")"<<endl;
            construcciones++;
        }
     }
  }
  if (construcciones==0)
    cout<<"No tienes edificios construidos"<<endl;
}

bool Mapa::construccion_edificio(string nombre, int fila, int columna, int turno){
   bool construccion_completada = false;
  //datos_edificios->edificio_construido(nombre);
  if (comprobar_coordenadas_construccion(fila, columna)){
    Matriz[fila][columna]->colocar_edificio(construir_edificio(nombre, turno));
    construccion_completada = true;
  }
  return construccion_completada;
}

EdificioColocable* Mapa::construir_edificio(string nombre, int jugador){
 EdificioColocable* edificio;
 if (nombre == MINA)
    edificio = new Mina(jugador);
 else if (nombre == ASERRADERO)
    edificio = new Aserradero(jugador);
 else if (nombre == FABRICA)
    edificio = new Fabrica(jugador);
 else if (nombre == ESCUELA)
    edificio = new Escuela(jugador);
 else if (nombre == OBELISCO)
    edificio = nullptr;
 else if (nombre == PLANTA_ELECTRICA)
    edificio = new PlantaElectrica(jugador);
 else if(nombre == MINA_ORO)
    edificio = new MinaOro(jugador);
 else
    cout<< "No es un edificio colocable por lo que no se va a encontrar en el mapa" << endl;
 return edificio;
}

MaterialColocable* Mapa::construir_material(string nombre){
 MaterialColocable* material = new MaterialColocable(nombre);
 return material;
}

string Mapa::demoler_edificio(int fila, int columna){
 string edificio;
 edificio = Matriz[fila][columna]->demoler_edificio();
 return edificio;
}

bool Mapa::atacar_edificio(int fila, int columna, int turno, cantidad_edificios_construidos** datos){
  bool ataque_completado = false;
  if (comprobar_coordenadas_ataque(fila, columna, turno)){
    Matriz[fila][columna]->atacar_edificio(datos);
    ataque_completado = true;
  }
  return ataque_completado;
}

void Mapa::reparar_edificio(int fila, int columna){
    Matriz[fila][columna]->reparar_edificio();
}

void Mapa::guardar_construcciones(int posicion_1[], int posicion_2[]){
    ofstream archivo(PATH_UBICACIONES);
    if(archivo.fail()){
     cout << "Error abriendo el fichero " << PATH_UBICACIONES << endl;
    }
    else{
        guardar_materiales(archivo);
        guardar_jugador(archivo, JUGADOR_UNO, posicion_1);
        guardar_jugador(archivo, JUGADOR_DOS, posicion_2);
        cout<<"Datos ubicaciones guardados"<<endl;
        archivo.close();
    }
}

void Mapa::guardar_materiales(ofstream &archivo){
  for (int fila=0; fila<filas_matriz; fila++){
    for (int columna=0; columna<columnas_matriz; columna++){
      if ((Matriz[fila][columna]->devolver_tipo_casillero()==TRANSITABLE) && (!Matriz[fila][columna]->comprobar_vacio()))
            archivo<<Matriz[fila][columna]->devolver_elemento_colocable()<<" ("<<fila+1<<", "<<columna+1<<")"<<endl;
    }
  }
}

void Mapa::guardar_jugador(ofstream &archivo, int jugador,  int posicion[]){
  archivo<<jugador+1<<" ("<<posicion[0]+1<<", "<<posicion[1]+1<<")"<<endl;
  for (int fila=0; fila<filas_matriz; fila++){
    for (int columna=0; columna<columnas_matriz; columna++){
      if ((Matriz[fila][columna]->devolver_tipo_casillero()==CONSTRUIBLE) && (!Matriz[fila][columna]->comprobar_vacio()) && (Matriz[fila][columna]->comprobar_propietario(jugador)))
            archivo<<Matriz[fila][columna]->devolver_elemento_colocable()<<" ("<<fila+1<<", "<<columna+1<<")"<<endl;

    }
  }
}

bool Mapa::comprobar_colocacion_jugador(int fila, int columna){
 bool chequeo = false;
 if (!consultar_coordenada(fila,columna))
  cout<<"Error: Coordenada fuera del mapa"<<endl;
 else if (Matriz[fila][columna]->comprobar_jugador_colocado())
  cout<<"Jugador ya colocado en esa posicion"<<endl;
 else
  chequeo = true;
 return chequeo;
}

bool Mapa::comprobar_coordenadas_construccion(int fila,int columna){
     bool chequeo = false;
     if (!consultar_coordenada(fila,columna))
         cout<<"Error: Coordenada fuera del mapa"<<endl;
     else if (!(consultar_casillero(fila,columna)==CONSTRUIBLE))
         cout<<"No es un casillero construible"<<endl;
     else if (!consultar_vacio(fila,columna))
         cout<<"Ya se encuentra una construccion en el casillero"<<endl;
     else if (Matriz[fila][columna]->comprobar_jugador_colocado())
         cout<<"No puedes construir encima de un jugador"<<endl;
     else
         chequeo = true;
     return chequeo;
}

bool Mapa::comprobar_coordenadas_demolicion(int fila,int columna, int turno){
     bool chequeo = false;
     if (!consultar_coordenada(fila,columna))
         cout<<"Error: Coordenada fuera del mapa"<<endl;
     else if (!(consultar_casillero(fila,columna)==CONSTRUIBLE))
         cout<<"No es un casillero construible por lo que no puede haber una construccion"<<endl;
     else if (consultar_vacio(fila,columna))
         cout<<"Se encuentra vacio el casillero, no hay nada para demoler"<<endl;
     else if (!consultar_propietario(fila, columna, turno))
         cout<<"No puedes demoler un edificio que no es tuyo"<<endl;
     else
         chequeo = true;
     return chequeo;
}

bool Mapa::comprobar_coordenadas_ataque(int fila,int columna, int turno){
     bool chequeo = false;
     if (!consultar_coordenada(fila,columna))
         cout<<"Error: Coordenada fuera del mapa"<<endl;
     else if (!(consultar_casillero(fila,columna)==CONSTRUIBLE))
         cout<<"No es un casillero construible por lo que no puede haber una construccion"<<endl;
     else if (consultar_vacio(fila,columna))
         cout<<"Se encuentra vacio el casillero, no hay nada para atacar"<<endl;
     else if (consultar_propietario(fila, columna, turno))
         cout<<"No puedes atacar un edificio que es tuyo"<<endl;
     else
         chequeo = true;
     return chequeo;
}

bool Mapa::comprobar_coordenadas_reparacion(int fila,int columna, int turno){
     bool chequeo = false;
     if (!consultar_coordenada(fila,columna))
         cout<<"Error: Coordenada fuera del mapa"<<endl;
     else if (!(consultar_casillero(fila,columna)==CONSTRUIBLE))
         cout<<"No es un casillero construible por lo que no puede haber una construccion"<<endl;
     else if (consultar_vacio(fila,columna))
         cout<<"Se encuentra vacio el casillero, no hay nada para reparar"<<endl;
     else if (!consultar_propietario(fila, columna, turno))
         cout<<"No puedes reparar un edificio que no es tuyo"<<endl;
     else if (Matriz[fila][columna]->consultar_vida())
         cout<<"No puedes reparar un edificio que esta en perfectas condiciones"<<endl;
     else
         chequeo = true;
     return chequeo;
}

bool Mapa::comprobar_coordenadas_moverse(int fila, int columna){
     bool chequeo = false;
     if (!consultar_coordenada(fila,columna))
         cout<<"Error: Coordenada fuera del mapa"<<endl;
     if (Matriz[fila][columna]->comprobar_jugador_colocado())
        cout<<"No te puedes mover a una coordenada ocupada por otro jugador"<<endl;
     else if ((consultar_casillero(fila,columna)==CONSTRUIBLE) && (!consultar_vacio(fila,columna)))
        cout<<"No te puedes mover a un casillero ocupado por un edificio"<<endl;
     else
         chequeo = true;
     return chequeo;
}

void Mapa::recolectar_material_tirado(int fila, int columna, int turno, DatosMateriales* materiales){
    if ((Matriz[fila][columna]->devolver_tipo_casillero()==TRANSITABLE) && (!Matriz[fila][columna]->comprobar_vacio())){
            cout<<"En la coordenada ("<<fila+1<<", "<<columna+1<<") ";
            Matriz[fila][columna]->recolectar_material(materiales, turno);
            agregar_transitables(fila,columna);
    }
}

camino_especifico Mapa::moverse_coordenada(int jugador,int fila_origen,int columna_origen,int fila_destino,int columna_destino){
  //falta muestra en el mapa el camino
  camino_especifico datos;
  if ((jugador+1)%2 != 0)
  {
    datos = grafo[JUGADOR_UNO].caminoMinimo(fila_origen, columna_origen, fila_destino, columna_destino);
  }
  else{
    datos = grafo[JUGADOR_DOS].caminoMinimo(fila_origen, columna_origen, fila_destino, columna_destino);
  }
  cout<<"El camino tiene un costo de: "<<datos.costo<<" y es el siguiente: "<<endl;
  mostrar_camino(datos);
  return datos;
}

void Mapa::mostrar_camino(camino_especifico dato){
    for (int i = 0; i < dato.longitud; i++){
      Matriz[dato.camino[i][0]][dato.camino[i][1]]->marcar_casillero_camino();
    }
    mostrar_mapa_terrenos();
}

void Mapa::cambiar_posicion(int jugador,camino_especifico dato,DatosMateriales* materiales){
  for (int i = 0; i < dato.longitud; i++){
    recolectar_material_tirado(dato.camino[i][0],dato.camino[i][1],jugador,materiales);
    if (i == 0){
      Matriz[dato.camino[i][0]][dato.camino[i][1]]->sacar_jugador();
      if  (Matriz[dato.camino[i][0]][dato.camino[i][1]]->devolver_tipo_casillero() == TRANSITABLE)
       agregar_transitables(dato.camino[i][0], dato.camino[i][1]);
    }
    else if (i == dato.longitud-1){
      colocar_jugador(dato.camino[i][0], dato.camino[i][1], jugador);
    }
  }
}

Mapa::~Mapa(){
   //delete datos_edificios;
   for (int fila=0; fila<filas_matriz; fila++){
    for (int columna=0; columna<columnas_matriz; columna++){
            delete Matriz[fila][columna];
    }
    delete [] Matriz[fila];
   }
   delete [] Matriz;

  for (int i=0; i<cantidad_transitables; i++){
            delete []transitables[i];
    }
   delete [] transitables;

}

void Mapa::completar_cantidad_edificios(cantidad_edificios_construidos** edificios_construidos){
     for (int fila=0; fila<filas_matriz; fila++){
      for (int columna=0; columna<columnas_matriz; columna++){
        if ((Matriz[fila][columna]->devolver_tipo_casillero()==CONSTRUIBLE) && (!Matriz[fila][columna]->comprobar_vacio())){
           sumar_edificio(edificios_construidos, Matriz[fila][columna]->devolver_propietario(), Matriz[fila][columna]->devolver_elemento_colocable());
        }
        if (Matriz[fila][columna]->comprobar_jugador_colocado()){
          edificios_construidos[Matriz[fila][columna]->devolver_jugador()]->posicion_jugador[0]=fila;
          edificios_construidos[Matriz[fila][columna]->devolver_jugador()]->posicion_jugador[1]=columna;
        }
      }
     }
}

void Mapa::sumar_edificio(cantidad_edificios_construidos** edificios_construidos, int jugador, string tipo_edificio){
 if (tipo_edificio==ESCUELA)
    edificios_construidos[jugador]->cantidad_escuelas++;
 if (tipo_edificio==FABRICA)
    edificios_construidos[jugador]->cantidad_fabricas++;
 if (tipo_edificio==MINA)
    edificios_construidos[jugador]->cantidad_minas++;
 if (tipo_edificio==MINA_ORO)
    edificios_construidos[jugador]->cantidad_minas_oro++;
 if (tipo_edificio==PLANTA_ELECTRICA)
    edificios_construidos[jugador]->cantidad_plantas_electricas++;
 if (tipo_edificio==ASERRADERO)
    edificios_construidos[jugador]->cantidad_aserraderos++;
}




