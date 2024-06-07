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
    List dtMensaje;
public:
    registroMensajes(List mensajes);
    ~registroMensajes();
    List getMensajes();
};

#endif