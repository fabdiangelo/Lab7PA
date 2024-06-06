// Leandro
#ifndef REGISTROMENSAJES_H
#define REGISTROMENSAJES_H
#include <iostream>

#include "dtMensaje.h"

using namespace std;

class registroMensajes
{
private:
    dtMensaje mensajes[5];
public:
    registroMensajes(dtMensaje mensajes[5]);
    ~registroMensajes();
    dtMensaje getMensajes();
};


#endif