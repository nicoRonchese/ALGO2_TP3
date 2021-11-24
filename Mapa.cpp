#include "Mapa.h"
#include "Casillero Transitable.cpp"
#include "Casillero Construible.cpp"
#include "Casillero Inaccesible.cpp"
#include "Casillero.cpp"

Mapa::Mapa(){
   cantidad_transitables = 0;
   cantidad_transitables_ocupados = 0;
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
     }
    }
   }
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
     Matriz[fila][columna]->colocar_material(objeto);
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
      //Matriz[fila][columna]->colocar_jugador(JUGADOR_UNO);
      getline(archivo, objeto, '(');
      objeto = quitar_espacio_final(objeto);
      while (objeto != "2"){
        getline(archivo, fila_objeto, ',');
        getline(archivo, columna_objeto, ')');
        getline(archivo, basura, '\n');
        fila = stoi(fila_objeto) - 1;
        columna = stoi(columna_objeto) - 1;
        Matriz[fila][columna]->colocar_edificio(objeto, JUGADOR_UNO);
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
         //Matriz[fila][columna]->colocar_jugador(JUGADOR_DOS);
         getline(archivo, objeto, '(');
         objeto = quitar_espacio_final(objeto);
         while (!archivo.eof()){
             getline(archivo, fila_objeto, ',');
             getline(archivo, columna_objeto, ')');
             getline(archivo, basura, '\n');
             fila = stoi(fila_objeto) - 1;
             columna = stoi(columna_objeto) - 1;
             Matriz[fila][columna]->colocar_edificio(objeto, JUGADOR_DOS);
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



void Mapa::mostrar_mapa(){
  for (int fila=0; fila<filas_matriz; fila++){
    for (int columna=0; columna<columnas_matriz; columna++){
        Matriz[fila][columna]->mostrar_en_mapa();
        if (columna == columnas_matriz -1)
        {
           cout <<" "<<endl;
        }

    }
  }
}

void Mapa::mostrar_casillero(int fila, int columna){
  Matriz[(fila)][(columna)]->mostrar();
}

bool Mapa::consultar_coordenada(int fila,int columna){
 return (fila<filas_matriz && fila>=0 && columna<columnas_matriz && columna>=0);
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

void Mapa::lluvia_materiales(){
  srand((unsigned) time(NULL));
  int piedra,madera,metal,total;
  piedra = rand()%2+1;
  madera = rand()%2;
  metal =rand()%3+2;
  total = metal+madera+piedra;
  while((total !=0)&&(cantidad_transitables!=cantidad_transitables_ocupados))
  {
    int i = rand()%cantidad_transitables;
    if ( Matriz[transitables[i][0]][transitables[i][1]]->comprobar_vacio())
    {
      if ((metal+madera < total))
        Matriz[transitables[i][0]][transitables[i][1]]->colocar_material(NOMBRE_PIEDRA);
      else if (metal < total)
        Matriz[transitables[i][0]][transitables[i][1]]->colocar_material(NOMBRE_MADERA);
      else
        Matriz[transitables[i][0]][transitables[i][1]]->colocar_material(NOMBRE_METAL);
      cantidad_transitables_ocupados++;
      total--;
    }
  }
  if (cantidad_transitables==cantidad_transitables_ocupados)
    cout<<"No se produjo la lluvia de recursos porque no tenian lugar donde caer"<<endl;
  else
    cout<<"Estan lloviendo materiales!!"<<endl;
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

void Mapa::recolectar_recursos(int turno, DatosMateriales* materiales){
     int producido = 0;
     for (int fila=0; fila<filas_matriz; fila++){
      for (int columna=0; columna<columnas_matriz; columna++){
        if ((Matriz[fila][columna]->devolver_tipo_casillero()==CONSTRUIBLE) && (!Matriz[fila][columna]->comprobar_vacio()) && (consultar_propietario(fila, columna, turno))){
          if ((Matriz[fila][columna]->devolver_elemento_colocable()==ASERRADERO) || (Matriz[fila][columna]->devolver_elemento_colocable()==MINA) || (Matriz[fila][columna]->devolver_elemento_colocable()==FABRICA)) {
           cout<<"En la coordenada ("<<fila+1<<", "<<columna+1<<") ";
           Matriz[fila][columna]->recoleccion(materiales, turno);
           producido++;
          }
         }
       }
      }
      if (producido==0)
        cout<<"No se produjo recursos"<<endl;
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

bool Mapa::construir_edificio(string nombre, int fila, int columna, int turno){
   bool construccion_completada = false;
  //datos_edificios->edificio_construido(nombre);
  if (comprobar_coordenadas_construccion(fila, columna)){
    Matriz[fila][columna]->colocar_edificio(nombre, turno);
    construccion_completada = true;
  }
  return construccion_completada;
}

string Mapa::demoler_edificio(int fila, int columna, int turno){
 string edificio;
 if (comprobar_coordenadas_demolicion(fila, columna, turno))
   edificio = Matriz[fila][columna]->demoler_edificio();
 //datos_edificios->edificio_demolido(edificio);
 return (edificio);
}

bool Mapa::atacar_edificio(int fila, int columna, int turno){
  bool ataque_completado = false;
  if (comprobar_coordenadas_ataque(fila, columna, turno)){
    Matriz[fila][columna]->atacar_edificio();
    ataque_completado = true;
  }
  return ataque_completado;
}

bool Mapa::reparar_edificio(int fila, int columna, int turno){
  bool reparacion_completada = false;
  if (comprobar_coordenadas_reparacion(fila, columna, turno)){
    Matriz[fila][columna]->reparar_edificio();
    reparacion_completada = true;
  }
  return reparacion_completada;
}

void Mapa::guardar_construcciones(){
    ofstream archivo(PATH_UBICACIONES);
    if(archivo.fail()){
     cout << "Error abriendo el fichero" << PATH_UBICACIONES << endl;
    }
    else{
        guardar_materiales(archivo);
        guardar_jugador(archivo, JUGADOR_UNO);
        guardar_jugador(archivo, JUGADOR_DOS);
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

void Mapa::guardar_jugador(ofstream &archivo, int jugador){
  //archivo<<jugador+1<<" ("<<coordenada_jugador(jugador)<<")"<<endl;
  for (int fila=0; fila<filas_matriz; fila++){
    for (int columna=0; columna<columnas_matriz; columna++){
      if ((Matriz[fila][columna]->devolver_tipo_casillero()==CONSTRUIBLE) && (!Matriz[fila][columna]->comprobar_vacio()) && (Matriz[fila][columna]->comprobar_propietario(jugador)))
            archivo<<Matriz[fila][columna]->devolver_elemento_colocable()<<" ("<<fila+1<<", "<<columna+1<<")"<<endl;

    }
  }
}

bool Mapa::comprobar_coordenadas_construccion(int fila,int columna){
     bool chequeo = false;
     if (!consultar_coordenada(fila,columna))
         cout<<"Error: Coordenada fuera del mapa"<<endl;
     else if (!(consultar_casillero(fila,columna)==CONSTRUIBLE))
         cout<<"No es un casillero construible"<<endl;
     else if (!consultar_vacio(fila,columna))
         cout<<"Ya se encuentra una construccion en el casillero"<<endl;
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
     else
         chequeo = true;
     return chequeo;
}


void Mapa::recolectar_material_tirado(int fila, int columna, int turno, DatosMateriales* materiales){
    fila--;
    columna--;
    if ((Matriz[fila][columna]->devolver_tipo_casillero()==TRANSITABLE) && (!Matriz[fila][columna]->comprobar_vacio()))
            Matriz[fila][columna]->recolectar_material(materiales, turno);
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



