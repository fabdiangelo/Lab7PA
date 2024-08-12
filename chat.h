#ifndef CHAT_H
#define CHAT_H

#include <chrono>
#include <ctime>
#include "mensaje.h"
#include "DataTypes/fecha.h"
#include "DataTypes/registroMensajes.h"
#include "interesado.h"
#include "propiedad.h"

class propiedad;

class chat : public ICollectible{
  private:
    fecha* Fecha;
    int Hora;
    int CantMensajes;
    ICollection* MisMensajes;
    propiedad *prop;
    string persona;
  public:
    chat(string correo, propiedad*prop);
    fecha* getFecha();
    int getHora();
    int getCantMensajes();
    string getInteresado();
    propiedad *getPropiedad();
    void BorrarMensajes();
    registroMensajes* ObtenerRegistro();
    void CrearMensaje(string contenido);
    string ultimoMens();
    ~chat();
};

#endif
