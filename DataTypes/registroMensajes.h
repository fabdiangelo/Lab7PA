// Leandro
#ifndef REGISTROMENSAJES_H
#define REGISTROMENSAJES_H
#include <iostream>

#include "dtMensaje.h"
#include "../ICollection/collections/List.h"

using namespace std;

class registroMensajes
{
private:
    List mensajes[5];
public:
    registroMensajes(List mensajes[5]);
    ~registroMensajes();
    List ** getMensajes();
};


#endif