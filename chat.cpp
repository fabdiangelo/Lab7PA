#include "chat.h"

// CONSTRUCTOR:
chat::chat(fecha *Fecha, int Hora){
    this -> Fecha = Fecha;
    this -> Hora = Hora;
    this -> CantMensajes = 0;
    this -> MisMensajes = new List();
    this -> persona = NULL; // Cambiar por actualUser
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

interesado* chat::getInteresado(){
    return this -> persona;
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
    for(IIterator *iter = this -> MisMensajes -> getIterator(); iter -> hasCurrent(); iter -> next()){
        mensaje *mens =(mensaje*) iter -> getCurrent();
        dtMensaje *men = new dtMensaje(mens ->getMensaje(), mens -> getHora());
        res -> agregarMensaje(men);
    }
    return res;
}

void chat::CrearMensaje(string contenido){
    time_t t;
    struct tm *tm;
    t = time(NULL);
    tm = localtime(&t);
    int hora = tm -> tm_hour;

    mensaje *mens = new mensaje(hora, contenido);
    MisMensajes -> add(mens);

    this -> CantMensajes++;
}