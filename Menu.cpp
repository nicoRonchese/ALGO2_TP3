
#include "Menu.h"
#include "DatosMateriales.cpp"

Menu::Menu(){
 //this->mapa = new Mapa;
 this->datosMateriales = new DatosMateriales;
 this->turno = JUGADOR_UNO;
 this->energia = new int[2];
 energia[JUGADOR_UNO] = ENERGIA_INICIAL;
 energia[JUGADOR_DOS] = ENERGIA_INICIAL;
}

string Menu::minusculizar(string nombre){
    int largo_nombre = int(nombre.size());
    string nuevo_nombre;
    for (int letra=0; letra<largo_nombre;letra++){
             nuevo_nombre+=char(tolower(nombre[letra]));
    }
    return nuevo_nombre;
}

int Menu::ingrese_numero(string numero){
    int opcion;
    while (!(isdigit(numero[0])))
    {
        cout << "Ingrese un numero porfavor: ";
        cin >> numero;
    }
    opcion = stoi(numero);
    return opcion;
}

void Menu::empezar_menu(){
 //if (mapa->construcciones_vacio())
 //else
 int opcion = 0;
 string basura,resp;
 while (opcion!=GUARDAR_SALIR && opcion!=COMENZAR_PARTIDA){
    mostrar_menu_inicial();
    cout <<"Ingrese una opcion: ";
    cin>>resp;
    opcion = ingrese_numero(resp);
    cout<<endl;
    if (opcion==COMENZAR_PARTIDA)
     system(CLR_SCREEN);
    procesar_opcion_inicial(opcion);
    if (opcion!=GUARDAR_SALIR && opcion!=COMENZAR_PARTIDA){
     cout<<endl;
     cout << "Presione una letra y enter para continuar: ";
     cin >> basura;
     system(CLR_SCREEN);
    }
 }
}

void Menu::mostrar_menu_inicial(){
 cout<<"1. Modificar edificio por nombre."<<endl;
 cout<<"2. Listar todos los edificios."<<endl;
 cout<<"3. Mostrar mapa."<<endl;
 cout<<"4. Comenzar partida"<<endl;
 cout<<"5. Guardar y salir"<<endl;
}

void Menu::mostrar_menu_juego(){
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

void Menu::procesar_opcion_inicial(int opcion){
    switch (opcion) {
        case MODIFICAR_EDIFICIO:
            construir_edificio();
            break;
        case LISTAR_EDIFICIOS:
            listar_edificios();
            break;
        case MOSTRAR_MAPA:
            mostrar_mapa();
            break;
        case COMENZAR_PARTIDA:
            comenzar_partida();
            break;
        case GUARDAR_SALIR_INICIAL:
            guardar_salir();
            break;
        default:
            cout << "Error: opcion invalida"<<endl;
    }
}

void Menu::modificar_edificio(){
 //mapa->modificar_edificio();
}

void Menu::listar_edificios(){
 //mapa->listar_edificios();
}

void Menu::mostrar_mapa(){
 //mapa->mostrar_mapa();
}


void Menu::comenzar_partida(){
 int opcion = 0;
 string basura,resp;
 lluvia_recursos();
 while (opcion!=GUARDAR_SALIR){
    mostrar_turno();
    mostrar_energia();
    mostrar_menu_juego();
    cout <<"Ingrese una opcion: ";
    cin>>resp;
    opcion = ingrese_numero(resp);
    cout<<endl;
    procesar_opcion_juego(opcion);
    chequear_energia();
    if (opcion!=GUARDAR_SALIR)
    {
        cout<<endl;
        cout << "Presione una letra y enter para continuar: ";
        cin >> basura;
        system(CLR_SCREEN);
    }
 }
}

void Menu::lluvia_recursos(){
 //mapa->lluvia_materiales();
}

void Menu::mostrar_turno(){
 if (turno==JUGADOR_UNO)
    cout<<"Turno: Jugador 1"<<endl;
 else
    cout<<"Turno: Jugador 2"<<endl;
}

void Menu::mostrar_energia(){
 cout<<"Energia disponible: "<<energia[turno]<<endl;
}

void Menu::chequear_energia(){
 if (energia[turno]==0){
  cout<<endl;
  finalizar_turno();
 }
 if (energia[turno]>ENERGIA_MAXIMA)
  energia[turno] = ENERGIA_MAXIMA;
}

void Menu::procesar_opcion_juego(int opcion){
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

void Menu::construir_edificio(){
 string nombre, nombre_electrica;
 //edificio edificio;
 cin.get(); // Colocamos una pausa para que se ejecute correctamente el codigo
 cout << "Edificio: ";
 getline(cin,nombre);
 nombre = minusculizar(nombre);
 //if (mapa->comprobar_edificio(nombre)){
   //edificio = mapa->buscar_edificio(nombre);
   //if (comprobar_construccion(edificio)){
    string fila_string,columna_string;
    int fila,columna;
    cout<<"Fila: ";
    cin>>fila_string;
    fila = ingrese_numero(fila_string);
    cout<<"Columna: ";
    cin>>columna_string;
    columna = ingrese_numero(columna_string);
    //if (mapa->comprobar_coordenadas_construccion(fila,columna)){
        //mapa->construir_edificio(nombre,fila,columna);
        //datosMateriales->restar_materiales_usados(edificio);
        //cout<<"Edificio construido correctamente"<<endl;
        if (energia[turno] >= COSTO_CONSTRUIR)
          energia[turno] -= COSTO_CONSTRUIR;
    //}
   //}
 //}
 //else
    //cout<<"Edificio no encontrado"<<endl;
}

bool Menu::comprobar_construccion(//edificio edificio
                                  ){
 bool chequeo = false;
 //if (edificio.maxima_cantidad_permitida-edificio.cantidad_construida==0)
    //cout<<"Maximo construido"<<endl;
 //else if (!datosMateriales->comprobar_materiales_necesarios(edificio))
    //cout<<"Materiales insuficientes"<<endl;
 //else
    //chequeo = true;
 return chequeo;
}

void Menu::listar_edificios_construidos(){
 //mapa->mostrar_construcciones();
}

void Menu::demoler_edificio(){
 string fila_string,columna_string;
 int fila,columna;
 cout<<"Fila: ";
 cin>>fila_string;
 fila = ingrese_numero(fila_string);
 cout<<"Columna: ";
 cin>>columna_string;
 columna = ingrese_numero(columna_string);
 //if (!mapa->consultar_coordenada(fila,columna))
    //cout<<"Error: Coordenada fuera del mapa"<<endl;
 //else if (mapa->consultar_casillero(fila,columna)!=CONSTRUIBLE)
    //cout<<"No es un casillero construible por lo que no puede haber un edificio"<<endl;
 //else if (mapa->consultar_vacio(fila,columna))
    //cout<<"No hay edificio construido en el casillero"<<endl;
 //else{
    //string nombre_edificio = mapa->demoler_edificio(fila,columna);
    //edificio edificio = mapa->buscar_edificio(nombre_edificio);
    //datosMateriales->sumar_materiales_demolidos(edificio);
    //cout<<"Demolicion de "<<nombre_edificio<<" realizada correctamente"<<endl;
    if (energia[turno] >= COSTO_DEMOLER)
     energia[turno] -= COSTO_DEMOLER;
 //}
}

void Menu::atacar_construccion(){
 //mapa->atacar_construccion(datosMateriales);
 if (energia[turno] >= COSTO_ATACAR)
  energia[turno] -= COSTO_ATACAR;
}

void Menu::reparar_construccion(){
 //mapa->reparar_construccion(datosMateriales);
 if (energia[turno] >= COSTO_REPARAR)
  energia[turno] -= COSTO_REPARAR;
}

void Menu::comprar_bombas(){
 if (energia[turno] >= COSTO_COMPRAR){
  string cantidad_string;
  int cantidad;
  cout<<"Cantidad de bombas a comprar: ";
  cin>>cantidad_string;
  cantidad = ingrese_numero(cantidad_string);
  if (datosMateriales->comprar_bombas(turno, cantidad))
   energia[turno] -= COSTO_COMPRAR;
 }
 else
    cout<<"No tienes la energia suficiente para realizar esta accion"<<endl;
}

void Menu::consultar_coordenada(){
 string fila_string,columna_string;
 int fila,columna;
 cout<<"Fila: ";
 cin>>fila_string;
 fila = ingrese_numero(fila_string);
 cout<<"Columna: ";
 cin>>columna_string;
 columna = ingrese_numero(columna_string);
 //if (!mapa->consultar_coordenada(fila,columna))
    //cout<<"Error: Coordenada fuera del mapa"<<endl;
 //else
    //mapa->mostrar_casillero(fila,columna);
}

void Menu::mostrar_inventario(){
 datosMateriales->mostrar_materiales(turno);
}

void Menu::mostrar_objetivos(){
}

void Menu::recolectar_recursos(){
 //mapa->recolectar_recursos(datosMateriales);
 if (energia[turno] >= COSTO_RECOLECTAR)
  energia[turno] -= COSTO_RECOLECTAR;
}

void Menu::moverse_coordenada(){
 //energia_necesaria=mapa->moverse_coordenada();
}

void Menu::finalizar_turno(){
 if (energia[turno]==0)
    cout<<"Turno finalizado por falta de energia"<<endl;
 else
    cout<<"Turno finalizado"<<endl;
 energia[turno] += ENERGIA_RECIBIDA;
 if (turno==JUGADOR_UNO)
    turno = JUGADOR_DOS;
 else
    turno = JUGADOR_UNO;
 lluvia_recursos();
}

void Menu::guardar_salir(){
 datosMateriales->guardar_materiales();
 //mapa->guardar_construcciones();
 //mapa->guardar_edificios();
}

Menu::~Menu(){
 //delete mapa;
 delete datosMateriales;
}




