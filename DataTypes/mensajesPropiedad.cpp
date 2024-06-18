#include "mensajesPropiedad.h"

// CONSTRUCTOR:
mensajesPropiedad::mensajesPropiedad(int cantidadMensajes, dtPropiedad *propiedad){
    this -> cantMensajes = cantidadMensajes;
    this -> propiedad = propiedad;
}

// DESTRUCTOR:
mensajesPropiedad::~mensajesPropiedad(){
    cout << "destruct de mensajesPropiedad" << endl;
}

// GETTERS:
int mensajesPropiedad::getCantMensajes(){
    return this -> cantMensajes;
}

dtPropiedad *mensajesPropiedad::getPropiedad(){
    return this -> propiedad;
}

// SOBRECARGA:
ostream& operator<<(ostream& os, mensajesPropiedad* prop){
    os << "" << prop -> getPropiedad() -> getCodigo()<< ") Direccion: " << prop -> getPropiedad() -> getDir() << endl;
    os << "\tCantidad de mensajes enviados: " << prop -> getCantMensajes() << endl << endl;
    return os;
}