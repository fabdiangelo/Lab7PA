#include "chat.h"

// CONSTRUCTOR:
chat::chat(fecha *Fecha, int Hora){
    this -> Fecha = Fecha;
    this -> Hora = Hora;
    this -> CantMensajes = 0;
    this -> MisMensajes = new List();
    this -> persona = NULL;
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
    for(IIterator *iter = this -> MisMensajes -> getIterator(); iter -> hasCurrent(); iter -> next()){
        mensaje *mens =(mensaje *) iter -> getCurrent();
        this -> MisMensajes -> remove(mens);
        mens -> ~mensaje();
    }
}

registroMensajes* chat::ObtenerRegistro(){
    registroMensajes* res = new registroMensajes();
    for(IIterator *iter = this -> MisMensajes -> getIterator(); iter -> hasCurrent(); iter -> next()){
        res -> agregarMensaje(iter -> getCurrent());
    }
    return res;
}

void chat::CrearMensaje(string mensaje){
    time_t t;
    struct tm *tm;
    t = time(NULL);
    tm = localtime(&t);
    int hora = tm -> tm_hour;
    mensaje * mens = new mensaje(hora, mensaje);
    this -> misMensajes -> add(mens);
}