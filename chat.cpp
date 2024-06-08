// Daniel
#include "chat.h"


/*
    
    
    



void interesado::setEdad(int edad){
    this -> edad = edad;
}

void interesado::setNombre(string nombre){
    this -> nombre = nombre;
}

void interesado::setApellido(string apellido){
    this -> apellido = apellido;
}
    */

//CONSTRUCTOR:
chat::chat(fecha Fecha,int Hora,int CantMensajes){
    this -> Fecha = Fecha;
    this -> Hora = Hora;
    this -> CantMensajes = CantMensajes;
}

// DESTRUCTOR:
chat::~chat(){
    cout << "destruct de chat";
}

// GETTERS:
fecha chat::getFecha(){
    return this -> Fecha;
}

int chat::getHora(){
    return this -> Hora;
}

int chat::getCantMensajes(){
    return this -> CantMensajes;
}

int chat::getInteresado(){
    //return this ->   No tengo acceso a el interesado
} 


// SETTERS:
void chat::setCantMensajes(int CantMensajes){
    this -> CantMensajes = CantMensajes;
}


void BorrarMensajes(){
    //hago una recorrida por la lista de mensajes la borro y pongo el cant mensajes en 0 ?
}

registroMensajes chat::ObtenerRegistro(){
    //List *getMensajes(); // muestro la lista de los registros de mensajes?
    return this -> registroMensajes; //o esto?
}

void CrearMensaje(string mensaje){
    //creo el mensaje en el registro y lo añado? y si creo el mensaje me falta saber la hora por el dtMensaje
}
    


