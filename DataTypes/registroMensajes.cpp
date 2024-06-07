#include "registroMensajes.h"

// COSNTRUCTOR:
registroMensajes::registroMensajes(ICollectible *mens){
    // cout << mensajes -> getSize();
    // // if(mens -> getSize() > 5){
    // //     IIterator *iter = mens -> getIterator();
    // //     this -> mensajes = new List();
    // //     // List * temp = new List();
    // //     for (int i = 0; i < 5; i++){
    // //         this -> mensajes -> add( iter -> getCurrent() );
    // //         iter -> next();
    // //     }
    // // }else{
    //     this -> mensajes = mensajes;
    // // }
    this->mensajes->add(mens);
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