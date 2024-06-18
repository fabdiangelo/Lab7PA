#include "chat.h"

// CONSTRUCTOR:
chat::chat(string correo, propiedad*prop){
    time_t t;
    struct tm *tm;
    t = time(NULL);
    tm = localtime(&t);
    int hora = tm -> tm_hour;
    int dia = tm ->tm_mday;
    int mes = tm ->tm_mon;
    int anio = tm ->tm_year;

    fecha* f = new fecha(dia, mes, anio);

    this -> Fecha = f;
    this -> Hora = hora;
    this -> CantMensajes = 0;
    this -> MisMensajes = new List();
    this -> persona = correo;
    this -> prop = prop;
}

// DESTRUCTOR:
chat::~chat(){
    cout << "destruct de chat" << endl;
}

// GETTERS:
fecha* chat::getFecha(){
    return this -> Fecha;
}

int chat::getHora(){
    return this -> Hora;
}

int chat::getCantMensajes(){
    return this -> CantMensajes;
}

string chat::getInteresado(){
    return this -> persona;
} 

propiedad* chat::getPropiedad(){
    return this -> prop;
}


// FUNCIONALIDAD:
void chat::BorrarMensajes(){
    IIterator *iter = this -> MisMensajes -> getIterator();

    while(iter -> hasCurrent()){
        mensaje *mens =(mensaje *) iter -> getCurrent();
        iter -> next();
        this -> MisMensajes -> remove(mens);
        mens -> ~mensaje();
    }
    
    this -> CantMensajes = 0;
}

registroMensajes* chat::ObtenerRegistro(){
    registroMensajes* res = new registroMensajes();
    IIterator *iter = this -> MisMensajes -> getIterator();
    int size = this -> MisMensajes -> getSize();
    if(size > 5){
        for (int i = 0; i < size - 5; i++){
            iter -> next();
        }
    }
    while(iter -> hasCurrent()){
        mensaje *mens =(mensaje*) iter -> getCurrent();
        dtMensaje *men = new dtMensaje(mens ->getMensaje(), mens -> getHora());
        res -> agregarMensaje(men);
        iter -> next();
    }
    return res;
}

void chat::CrearMensaje(string contenido){
    time_t t;
    struct tm *tm;
    t = time(NULL);
    tm = localtime(&t);
    int hora = tm -> tm_hour;

    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    string ahora = ctime(&now_time);

    mensaje *mens = new mensaje(hora, contenido, ahora);
    MisMensajes -> add(mens);

    this -> CantMensajes++;
}

string chat::ultimoMens(){
    IIterator *iter = this -> MisMensajes -> getIterator();
    int size = this -> MisMensajes -> getSize();
    for (int i = 0; i < size - 1; i++){
        iter -> next();
    }
    mensaje *mens =(mensaje*) iter -> getCurrent();
    return mens -> getMomento();
}