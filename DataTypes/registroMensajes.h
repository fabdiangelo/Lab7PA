#ifndef REGISTROMENSAJES_H
#define REGISTROMENSAJES_H

#include "dtMensaje.h"
#include "../ICollection/collections/List.h"
#include "../ICollection/interfaces/IIterator.h"
#include "../mensaje.h"

class registroMensajes
{
private:
    ICollection *mensajes;
public:
    registroMensajes();
    ~registroMensajes();
    List *getMensajes();
    void agregarMensaje(dtMensaje *mens);
    friend ostream& operator<<(ostream& os, registroMensajes *prop);
};

#endif