#include "registroMensajes.h"

// COSNTRUCTOR:
registroMensajes::registroMensajes(){
    this -> mensajes = new List();
}

// DESTRUCTOR:
registroMensajes::~registroMensajes(){
    cout << "destruct de registroMensajes" << endl;
}

// GETTERS:
List *registroMensajes::getMensajes(){
    List * mensajes = (List *) this -> mensajes; 
    return mensajes;
}

// FUNCIONALIDADES:
void registroMensajes::agregarMensaje(dtMensaje * mens){
    if (this -> mensajes -> getSize() < 5){
        this -> mensajes -> add(mens);
    }
}

// SOBRECARGA:
ostream& operator<<(ostream& os, registroMensajes* reg){
    IIterator* iter = reg -> getMensajes() -> getIterator();
    if(reg -> getMensajes() -> getSize() == 0){
        cout << "No haz enviado mensajes a esta propiedad anteriormente\n";
    }else{
        while (iter -> hasCurrent()){
            mensaje* men = (mensaje*) iter -> getCurrent();
            os << men -> getHora() << "hs: " << men -> getMensaje() << endl;
        }
        os << reg -> getMensajes();
    }
    return os;
}