#include "dtRespuesta.h"

//CONSTRUCTOR:
dtRespuesta::dtRespuesta(string mensaje){
    this -> mensaje = mensaje;
}

// DESTRUCTOR:
dtRespuesta::~dtRespuesta()
{
    cout << "dtruct de dtRespuesta :D";
}

// GETTERS:
string dtRespuesta::getMensaje(){
    return this -> mensaje;
}