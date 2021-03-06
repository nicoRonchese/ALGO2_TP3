
#include "Juego.h"


Juego::Juego(){
 this->mapa = new Mapa;
 this->datosEdificios = new DatosEdificios;
 this->cantidad_jugadores = CANTIDAD_JUGADORES;
}

string Juego::minusculizar(string nombre){
    int largo_nombre = int(nombre.size());
    string nuevo_nombre;
    for (int letra=0; letra<largo_nombre;letra++){
             nuevo_nombre+=char(tolower(nombre[letra]));
    }
    return nuevo_nombre;
}

int Juego::ingrese_numero(string numero){
 int opcion;
 while (!(isdigit(numero[0]))){
  cout << "Ingrese un numero porfavor: ";
  cin >> numero;
 }
 opcion = stoi(numero);
 return opcion;
}

int Juego::ingresar_cantidad(){
 string numero;
 int cantidad;
 cin >> numero;
 cantidad = ingrese_numero(numero);
 while (cantidad >= 50000 || cantidad <= 0){
  cout << "Ingrese un numero mayor a 0 y menor a 50.000 porfavor: ";
  cin >> numero;
  cantidad = ingrese_numero(numero);
 }
 return cantidad;
}

void Juego::crear_datos_jugadores(){
 this->datosMateriales = new DatosMateriales(cantidad_jugadores);
 this->edificios_construidos = new ContadorEdificios*[cantidad_jugadores];
 this->objetivos = new Objetivos*[cantidad_jugadores];
 this->energia = new int[cantidad_jugadores];
 this->posiciones_jugadores = new int *[cantidad_jugadores];
 for (int jugador = 0; jugador < cantidad_jugadores; jugador++){
    posiciones_jugadores[jugador] = new int[2];
    objetivos[jugador] = new Objetivos(datosEdificios->buscar_edificio(ESCUELA).maxima_cantidad_permitida);
    edificios_construidos[jugador] = new ContadorEdificios;
    energia[jugador] = ENERGIA_INICIAL;
 }
 mapa->completar_cantidad_edificios(edificios_construidos, posiciones_jugadores);
 this->turno = JUGADOR_UNO;
}

void Juego::empezar_juego(){
 if (mapa->ubicar_edificios_archivo())
  comenzar_partida();
 else
  menu_inicial();
}

void Juego::colocar_jugadores(){
 for (int jugador = 0; jugador < cantidad_jugadores; jugador++){
     poner_jugador(jugador);
 }
}

void Juego::poner_jugador(int jugador){
  int fila, columna;
  string fila_string,columna_string;
  cout<<"Jugador "<<jugador+1<<":"<<endl;
  cout<<"Fila: ";
  cin>>fila_string;
  fila = ingrese_numero(fila_string);
  cout<<"Columna: ";
  cin>>columna_string;
  columna = ingrese_numero(columna_string);
  fila--;
  columna--;
  if (mapa->comprobar_colocacion_jugador(fila, columna)){
   cout<<endl;
   mapa->colocar_jugador(fila, columna, jugador);
  }
  else{
   cout<<endl;
   poner_jugador(jugador);
  }
 }


void Juego::menu_inicial(){
 int opcion = 0;
 string basura,resp;
 while (opcion!=GUARDAR_SALIR_INICIAL && opcion!=COMENZAR_PARTIDA){
    mostrar_menu_inicial();
    cout <<"Ingrese una opcion: ";
    cin>>resp;
    opcion = ingrese_numero(resp);
    cout<<endl;
    procesar_opcion_inicial(opcion);
    if (opcion!=GUARDAR_SALIR_INICIAL && opcion!=COMENZAR_PARTIDA){
     cout<<endl;
     cout << "Presione una letra y enter para continuar: ";
     cin >> basura;
     system(CLR_SCREEN);
    }
  }
}

void Juego::menu_juego(){
 int opcion = 0;
 string basura,resp;
  while (opcion!=GUARDAR_SALIR && !objetivos[turno]->comprobar_objetivos_cumplidos()){
    mostrar_mapa();
    mostrar_turno();
    mostrar_energia();
    mostrar_menu_juego();
    cout <<"Ingrese una opcion: ";
    cin>>resp;
    opcion = ingrese_numero(resp);
    cout<<endl;
    procesar_opcion_juego(opcion);
    objetivos[turno]->actualizar_objetivo(EDAD_PIEDRA, datosMateriales->devolver_cantidad(turno, PIEDRA));
    objetivos[turno]->actualizar_objetivo(ARMADO, datosMateriales->devolver_cantidad(turno, BOMBA));
    chequear_energia();
    if (objetivos[turno]->comprobar_objetivos_cumplidos()){
        system(CLR_SCREEN);
        objetivos[turno]->mostrar_victoria(turno);
    }
    else if (opcion!=GUARDAR_SALIR){
        cout<<endl;
        cout << "Presione una letra y enter para continuar: ";
        cin >> basura;
        system(CLR_SCREEN);
    }
 }
}

void Juego::mostrar_menu_inicial(){
 cout<<"1. Modificar edificio por nombre."<<endl;
 cout<<"2. Listar todos los edificios."<<endl;
 cout<<"3. Mostrar mapa."<<endl;
 cout<<"4. Cambiar cantidad de jugadores."<<endl;
 cout<<"5. Comenzar partida"<<endl;
 cout<<"6. Guardar y salir"<<endl;
}

void Juego::mostrar_menu_juego(){
 cout<<"1. Construir edificio por nombre."<<endl;
 cout<<"2. Listar mis edificios construidos."<<endl;
 cout<<"3. Demoler un edificio por coordenada."<<endl;
 cout<<"4. Atacar un edificio por coordenada."<<endl;
 cout<<"5. Reparar un edificio por coordenada"<<endl;
 cout<<"6. Comprar bombas"<<endl;
 cout<<"7. Consultar coordenada."<<endl;
 cout<<"8. Mostrar inventario."<<endl;
 cout<<"9. Mostrar objetivos."<<endl;
 cout<<"10. Recolectar recursos producidos."<<endl;
 cout<<"11. Moverse a una coordenada."<<endl;
 cout<<"12. Finalizar turno."<<endl;
 cout<<"13. Guardar y salir."<<endl;
}

void Juego::procesar_opcion_inicial(int opcion){
    switch (opcion) {
        case MODIFICAR_EDIFICIO:
            modificar_edificio();
            break;
        case LISTAR_EDIFICIOS:
            listar_edificios();
            break;
        case MOSTRAR_MAPA:
            mostrar_mapa_terrenos();
            break;
        case CAMBIAR_CANTIDAD_JUGADORES:
            cambiar_cantidad_jugadores();
            break;
        case COMENZAR_PARTIDA:
            colocar_jugadores();
            system(CLR_SCREEN);
            comenzar_partida();
            break;
        case GUARDAR_SALIR_INICIAL:
            datosEdificios->guardar_edificios();
            crear_datos_jugadores(); //creo los datos para que los delete del destructor funcionen y no se rompa el programa
            break;
        default:
            cout << "Error: opcion invalida"<<endl;
    }
}

void Juego::modificar_edificio(){
 edificio edificio;
 string llave, respuesta;
 cout<< "Ingrese el nombre del edificio a modificar: ";
 cin>>llave;
 llave = minusculizar(llave);
 if (datosEdificios->comprobar_edificio(llave)){
  if (llave != OBELISCO){
   edificio = datosEdificios->buscar_edificio(llave);
   cout<<"Desea modificar la cantidad piedra?(s/n): ";
   cin>>respuesta;
   respuesta = minusculizar(respuesta);
   if (respuesta=="s"){
    cout<< "Ingrese cantidad piedra: ";
    edificio.cantidad_piedra = ingresar_cantidad();
   }
   cout<<"Desea modificar la cantidad madera?(s/n): ";
   cin>>respuesta;
   respuesta = minusculizar(respuesta);
   if (respuesta=="s"){
    cout<< "Ingrese cantidad madera: ";
    edificio.cantidad_madera = ingresar_cantidad();
   }
   cout<<"Desea modificar la cantidad metal?(s/n): ";
   cin>>respuesta;
   respuesta = minusculizar(respuesta);
   if (respuesta=="s"){
    cout<< "Ingrese cantidad metal: ";
    edificio.cantidad_metal = ingresar_cantidad();
   }
   cout<<"Desea modificar la maxima cantidad permitida?(s/n): ";
   cin>>respuesta;
   respuesta = minusculizar(respuesta);
   if (respuesta=="s"){
    cout<<"Ingrese maxima cantidad permitida: ";
    edificio.maxima_cantidad_permitida = ingresar_cantidad();
   }
   datosEdificios->modificar_edificio(edificio, llave);
  }
  else
   cout<<"No se puede modificar el obelisco"<<endl;
 }
}

void Juego::listar_edificios(){
 datosEdificios->mostrar_edificios();
}

void Juego::mostrar_mapa_terrenos(){
 mapa->mostrar_mapa_terrenos();
}

void Juego::cambiar_cantidad_jugadores(){
 string cantidad_jugadores_string;
 int cantidad_jugadores;
 cout<<"Cantidad de jugadores: ";
 cin>>cantidad_jugadores_string;
 cantidad_jugadores = ingrese_numero(cantidad_jugadores_string);
 while (cantidad_jugadores <= 1){
  cout<<"Ingrese una cantidad de jugadores mayor a 1 porfavor: ";
  cin >> cantidad_jugadores_string;
  cantidad_jugadores = ingrese_numero(cantidad_jugadores_string);
 }
 this->cantidad_jugadores = cantidad_jugadores;
}

void Juego::cambiar_turno(){
 turno++;
 if (turno == cantidad_jugadores){
    lluvia_recursos();
    turno = JUGADOR_UNO;
 }
}

void Juego::inicializar_datos_objetivos(){
 for (int turno = 0; turno<cantidad_jugadores; turno++){
  if (edificios_construidos[turno]->devolver_cantidad_construida(ESCUELA) > 0){
   objetivos[turno]->actualizar_objetivo(LETRADO, edificios_construidos[turno]->devolver_cantidad_construida(ESCUELA));
   objetivos[turno]->actualizar_tipos_construidos(ESCUELA);
  }
  if (edificios_construidos[turno]->devolver_cantidad_construida(FABRICA) > 0)
   objetivos[turno]->actualizar_tipos_construidos(FABRICA);
  if (edificios_construidos[turno]->devolver_cantidad_construida(MINA) > 0)
   objetivos[turno]->actualizar_tipos_construidos(MINA);
  if (edificios_construidos[turno]->devolver_cantidad_construida(MINA_ORO) > 0)
   objetivos[turno]->actualizar_tipos_construidos(MINA_ORO);
  if (edificios_construidos[turno]->devolver_cantidad_construida(ASERRADERO) > 0)
   objetivos[turno]->actualizar_tipos_construidos(ASERRADERO);
  if (edificios_construidos[turno]->devolver_cantidad_construida(PLANTA_ELECTRICA) > 0)
   objetivos[turno]->actualizar_tipos_construidos(PLANTA_ELECTRICA);
  objetivos[turno]->actualizar_objetivo(MINERO, 0);
  objetivos[turno]->actualizar_objetivo(CONSTRUCTOR, 0);
  objetivos[turno]->actualizar_objetivo(COMPRAR_ANDYPOLIS, datosMateriales->devolver_cantidad(turno, ANDYCOIN));
  objetivos[turno]->actualizar_objetivo(EDAD_PIEDRA, datosMateriales->devolver_cantidad(turno, PIEDRA));
  objetivos[turno]->actualizar_objetivo(ARMADO, datosMateriales->devolver_cantidad(turno, BOMBA));
 }
}

void Juego::comenzar_partida(){
 lluvia_recursos();
 crear_datos_jugadores();
 inicializar_datos_objetivos();
 menu_juego();
}

void Juego::lluvia_recursos(){
 mapa->lluvia_materiales();
}

void Juego::mostrar_turno(){
 cout<<"Turno: Jugador "<<turno+1<<endl;
}

void Juego::mostrar_energia(){
 cout<<"Energia disponible: "<<energia[turno]<<endl;
}

void Juego::chequear_energia(){
 if (energia[turno]==0){
  cout<<endl;
  finalizar_turno();
 }
 if (energia[turno]>ENERGIA_MAXIMA)
  energia[turno] = ENERGIA_MAXIMA;
}

bool Juego::consultar_energia(int costo_energia){
  if (energia[turno] < costo_energia)
    cout<<"No tienes la energia suficiente para realizar esta accion"<<endl;
  return (energia[turno] >= costo_energia);
}

void Juego::procesar_opcion_juego(int opcion){
    switch (opcion) {
        case CONSTRUIR_EDIFICIO:
            construir_edificio();
            break;
        case LISTAR_CONSTRUCCIONES:
            listar_edificios_construidos();
            break;
        case DEMOLER_CONSTRUCCION:
            demoler_edificio();
            break;
        case ATACAR_CONSTRUCCION:
            atacar_construccion();
            break;
        case REPARAR_CONSTRUCCION:
            reparar_construccion();
            break;
        case COMPRAR_BOMBAS:
            comprar_bombas();
            break;
        case CONSULTAR_COORDENADA:
            consultar_coordenada();
            break;
        case MOSTRAR_INVENTARIO:
            mostrar_inventario();
            break;
        case MOSTRAR_OBJETIVOS:
            mostrar_objetivos();
            break;
        case RECOLECTAR_RECURSOS:
            recolectar_recursos();
            break;
        case MOVERSE_COORDENADA:
            moverse_coordenada();
            break;
        case FINALIZAR_TURNO:
            finalizar_turno();
            break;
        case GUARDAR_SALIR:
            guardar_salir();
            break;
        default:
            cout << "Error: opcion invalida"<<endl;
    }
}

void Juego::imprimir_caracter_especial(string caracter, int cantidad, bool espacio){
    for(int i = 0; i < cantidad; i++){
        cout << caracter;
        if(espacio){
            cout << " ";
        }
    }
}

void Juego::imprimir_cuadro_referencias_terrenos(){
    cout << "               " << SUBRAYADO << "Referencias de colores" << END_COLOR << "                           " << endl;
    cout << " ";
    imprimir_caracter_especial(CUADRO_HORIZONTAL, 25, true);
    cout << " " << endl;
    cout << CUADRO_VERTICAL << "                                                 " << CUADRO_VERTICAL << endl;
    cout << CUADRO_VERTICAL <<" Camino " << COLOR_CAMINO << " " << END_COLOR << "  Betun " << COLOR_BETUN << " " << END_COLOR << "  Muelle " << COLOR_MUELLE << " " << END_COLOR << "  Lago " << COLOR_LAGO << " " << END_COLOR << "  Terreno " << COLOR_TERRENO << " " << END_COLOR <<"  " << CUADRO_VERTICAL << endl;
    cout << CUADRO_VERTICAL << "                                                 " << CUADRO_VERTICAL << endl;
    cout << " ";
    imprimir_caracter_especial(CUADRO_HORIZONTAL, 25, true);
    cout << " " << endl;
}

void Juego::mostrar_mapa(){
 imprimir_cuadro_referencias_terrenos();
 mapa->mostrar_mapa();
}

void Juego::construir_edificio(){
 if (consultar_energia(COSTO_CONSTRUIR)){
  string nombre;
  //edificio edificio;
  cin.get(); // Colocamos una pausa para que se ejecute correctamente el codigo
  cout << "Edificio: ";
  getline(cin,nombre);
  nombre = minusculizar(nombre);
  if (datosEdificios->comprobar_edificio(nombre)){
    if (comprobar_construccion(nombre)){
     string fila_string,columna_string;
     int fila,columna;
     cout<<"Fila: ";
     cin>>fila_string;
     fila = ingrese_numero(fila_string);
     cout<<"Columna: ";
     cin>>columna_string;
     columna = ingrese_numero(columna_string);
     fila--;
     columna--;
     if (mapa->construccion_edificio(nombre,fila,columna,turno)){
        datosMateriales->restar_construccion_materiales(datosEdificios->buscar_edificio(nombre), turno);
        edificios_construidos[turno]->sumar_edificio(nombre);
        if (nombre == OBELISCO)
         objetivos[turno]->construccion_obelisco();
        else if (nombre == ESCUELA)
         objetivos[turno]->actualizar_objetivo(LETRADO, 1);
        objetivos[turno]->actualizar_tipos_construidos(nombre);
        objetivos[turno]->actualizar_objetivo(CONSTRUCTOR, 0);
        objetivos[turno]->actualizar_objetivo(MINERO, 0);
        cout<<nombre<<" construido/a correctamente"<<endl;
        energia[turno] -= COSTO_CONSTRUIR;
     }
    }
   }
  }
}

bool Juego::comprobar_construccion(string nombre){
 bool edificio_construible = false;
 edificio edificio_a_construir = datosEdificios->buscar_edificio(nombre);
 if (edificio_a_construir.maxima_cantidad_permitida==edificios_construidos[turno]->devolver_cantidad_construida(nombre))
    cout<<"Maximo construido"<<endl;
 else if (!datosMateriales->comprobar_materiales_construccion(edificio_a_construir, turno))
    cout<<"Materiales insuficientes"<<endl;
 else
    edificio_construible = true;
 return edificio_construible;
}


void Juego::listar_edificios_construidos(){
 mapa->mostrar_construcciones(turno);
}

void Juego::demoler_edificio(){
 string edificio_demolido;
 if (consultar_energia(COSTO_DEMOLER)){
  if (edificios_construidos[turno]->devolver_cantidad_edificios_construidos()>0){
   string fila_string,columna_string;
   int fila,columna;
   cout<<"Fila: ";
   cin>>fila_string;
   fila = ingrese_numero(fila_string);
   cout<<"Columna: ";
   cin>>columna_string;
   columna = ingrese_numero(columna_string);
   fila--;
   columna--;
   if (mapa->comprobar_coordenadas_demolicion(fila, columna, turno)){
    edificio_demolido = mapa->demoler_edificio(fila, columna);
    datosMateriales->sumar_demolicion_materiales(datosEdificios->buscar_edificio(edificio_demolido), turno);
    edificios_construidos[turno]->restar_edificio(edificio_demolido);
    cout<<edificio_demolido<<" demolido/a correctamente"<<endl;
    energia[turno] -= COSTO_DEMOLER;
   }
  }
  else
   cout<<"No tienes edificios construidos por lo que no tienes nada para demoler"<<endl;
 }
}

void Juego::atacar_construccion(){
 if (consultar_energia(COSTO_ATACAR)){
    if (datosMateriales->devolver_cantidad(turno, BOMBA)>=1){
     string fila_string,columna_string;
     int fila,columna;
     cout<<"Fila: ";
     cin>>fila_string;
     fila = ingrese_numero(fila_string);
     cout<<"Columna: ";
     cin>>columna_string;
     columna = ingrese_numero(columna_string);
     fila--;
     columna--;
     if (mapa->atacar_edificio(fila, columna, turno, edificios_construidos)){
      energia[turno] -= COSTO_ATACAR;
      objetivos[turno]->actualizar_objetivo(BOMBARDERO, 1);
     }
    }
    else
     cout<<"No tienes bombas, no puede atacar"<<endl;
 }
}

void Juego::reparar_construccion(){
 if (consultar_energia(COSTO_REPARAR)){
     if (edificios_construidos[turno]->devolver_cantidad_edificios_construidos()>0){
      string fila_string,columna_string;
      int fila,columna;
      cout<<"Fila: ";
      cin>>fila_string;
      fila = ingrese_numero(fila_string);
      cout<<"Columna: ";
      cin>>columna_string;
      columna = ingrese_numero(columna_string);
      fila--;
      columna--;
      if (mapa->comprobar_coordenadas_reparacion(fila, columna, turno)){
       string nombre_edificio = mapa->devolver_elemento_en_casillero(fila, columna);
       edificio edificio_a_reparar = datosEdificios->buscar_edificio(nombre_edificio);
       if (datosMateriales->comprobar_materiales_reparacion(edificio_a_reparar, turno)){
        mapa->reparar_edificio(fila, columna);
        cout<<nombre_edificio<<" reparado/a correctamente"<<endl;
        energia[turno] -= COSTO_REPARAR;
       }
      }
     }
     else
      cout<<"No tienes edificios construidos por lo que no tienes nada para reparar"<<endl;
   }
}

void Juego::comprar_bombas(){
 if (consultar_energia(COSTO_COMPRAR)){
  string cantidad_string;
  int cantidad;
  cout<<"Cantidad de bombas a comprar: ";
  cin>>cantidad_string;
  cantidad = ingrese_numero(cantidad_string);
  if (cantidad>0){
   if (datosMateriales->comprar_bombas(turno, cantidad)){
    energia[turno] -= COSTO_COMPRAR;
    objetivos[turno]->actualizar_objetivo(EXTREMISTA, cantidad);
   }
  }
 }
}

void Juego::consultar_coordenada(){
 string fila_string,columna_string;
 int fila,columna;
 cout<<"Fila: ";
 cin>>fila_string;
 fila = ingrese_numero(fila_string);
 cout<<"Columna: ";
 cin>>columna_string;
 columna = ingrese_numero(columna_string);
 fila--;
 columna--;
 if (!mapa->consultar_coordenada(fila,columna))
    cout<<"Error: Coordenada fuera del mapa"<<endl;
 else
    mapa->mostrar_casillero(fila,columna);
}

void Juego::mostrar_inventario(){
 datosMateriales->mostrar_materiales(turno);
}

void Juego::mostrar_objetivos(){
 objetivos[turno]->mostrar_objetivos();
}

void Juego::recolectar_recursos(){
 int andycoins_ganadas, andycoins = datosMateriales->devolver_cantidad(turno, ANDYCOIN);
 if (consultar_energia(COSTO_RECOLECTAR)){
  if (mapa->recolectar_recursos(datosMateriales, energia, turno)){
     energia[turno] -= COSTO_RECOLECTAR;
     andycoins_ganadas =  datosMateriales->devolver_cantidad(turno, ANDYCOIN) - andycoins;
     objetivos[turno]->actualizar_objetivo(COMPRAR_ANDYPOLIS, andycoins_ganadas);
  }
 }
}

void Juego::moverse_coordenada(){
 int fila_destino, columna_destino, andycoins_ganadas, andycoins = datosMateriales->devolver_cantidad(turno, ANDYCOIN);
 camino_especifico datos;
 string movimiento,fila,columna;
 cout<<"Ingrese coordenada de destino:"<<endl<<"Fila: ";
 cin>>fila;
 fila_destino = ingrese_numero(fila);
 cout<<"Columna: ";
 cin>> columna;
 columna_destino = ingrese_numero(columna);
 fila_destino--;
 columna_destino--;
 if (mapa->comprobar_coordenadas_moverse(fila_destino,columna_destino)){
   datos = mapa->moverse_coordenada(turno, posiciones_jugadores[turno][0], posiciones_jugadores[turno][1], fila_destino, columna_destino);
   if (consultar_energia(datos.costo)){
    cout<<"Desea moverse?(s/n): ";
    cin>>movimiento;
    if (movimiento== "s"){
     mapa->cambiar_posicion(turno,datos,datosMateriales);
     posiciones_jugadores[turno][0] = fila_destino;
     posiciones_jugadores[turno][1] = columna_destino;
     andycoins_ganadas =  datosMateriales->devolver_cantidad(turno, ANDYCOIN) - andycoins;
     objetivos[turno]->actualizar_objetivo(COMPRAR_ANDYPOLIS, andycoins_ganadas);
     energia[turno] = energia[turno] - datos.costo;
    }
   }
   for (int fila=0; fila<(datos.longitud); fila++){
    delete [] datos.camino[fila];
   }
   delete [] datos.camino;
 }
}

void Juego::finalizar_turno(){
 objetivos[turno]->actualizar_objetivo(CANSADO, energia[turno]);
 objetivos[turno]->actualizar_objetivo(ENERGETICO, energia[turno]);
 if (energia[turno]==0)
    cout<<"Turno finalizado por falta de energia"<<endl;
 else
    cout<<"Turno finalizado"<<endl;
 energia[turno] += ENERGIA_RECIBIDA;
 if (!objetivos[turno]->comprobar_objetivos_cumplidos())
    cambiar_turno();
}

void Juego::guardar_salir(){
 datosMateriales->guardar_materiales();
 datosEdificios->guardar_edificios();
 mapa->guardar_construcciones(posiciones_jugadores[JUGADOR_UNO], posiciones_jugadores[JUGADOR_DOS]);
}

Juego::~Juego(){
 for (int i = 0; i < cantidad_jugadores; i++){
  delete objetivos[i];
  delete edificios_construidos[i];
  delete[] posiciones_jugadores[i];
 }
 delete[] posiciones_jugadores;
 delete [] objetivos;
 delete [] edificios_construidos;
 delete mapa;
 delete datosEdificios;
 delete datosMateriales;
 delete [] energia;
}






