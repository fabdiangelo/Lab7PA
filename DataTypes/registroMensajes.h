#ifndef REGISTROMENSAJES_H
#define REGISTROMENSAJES_H
#include <iostream>

#include "dtMensaje.h"
#include "../ICollection/collections/List.h"
#include "../ICollection/interfaces/IIterator.h"
using namespace std;

class registroMensajes
{
private:
    ICollection *mensajes;
public:
    registroMensajes();
    ~registroMensajes();
    List *getMensajes();
    void agregarMensaje(dtMensaje *mens);
};

#endif