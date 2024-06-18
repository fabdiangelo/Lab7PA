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
    if(reg -> getMensajes() -> getSize() == 0){
        cout << "No has enviado mensajes a esta propiedad anteriormente\n";
    }else{
        IIterator* iter = reg -> getMensajes() -> getIterator();
        while (iter -> hasCurrent()){
            dtMensaje *men = (dtMensaje*) iter -> getCurrent();
            os << men -> getHora() << "hs: " << men -> getMensaje() << endl;
            iter -> next();
        }
        delete iter;
    }
    return os;
}