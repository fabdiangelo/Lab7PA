#ifndef MENSAJESPROPIEDAD_H
#define MENSAJESPROPIEDAD_H
#include "dtPropiedad.h"
#include "../ICollection/interfaces/ICollectible.h"

class mensajesPropiedad : public ICollectible
{
private:
    int cantMensajes;
    dtPropiedad *propiedad;
public:
    mensajesPropiedad(int cantidadMensajes, dtPropiedad *propiedad);
    ~mensajesPropiedad();
    int getCantMensajes();
    dtPropiedad *getPropiedad();
};


#endif