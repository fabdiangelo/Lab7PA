#include "dtRespuesta.h"

//CONSTRUCTOR:
dtRespuesta::dtRespuesta(string mensaje){
    this -> mensaje = mensaje;
}

// DESTRUCTOR:
dtRespuesta::~dtRespuesta()
{
    cout << "dtruct de dtRespuesta" << endl;
}

// GETTERS:
string dtRespuesta::getMensaje(){
    return this -> mensaje;
}