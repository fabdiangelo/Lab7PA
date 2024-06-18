#ifndef CHAT_H
#define CHAT_H

#include <ctime>
#include "mensaje.h"
#include "DataTypes/fecha.h"
#include "DataTypes/registroMensajes.h"
#include "interesado.h"

class chat : public ICollectible{
  private:
    fecha* Fecha;
    int Hora;
    int CantMensajes;
    ICollection* MisMensajes; 
    string persona;
  public:
    chat(string correo);
    fecha* getFecha();
    int getHora();
    int getCantMensajes();
    string getInteresado();
    void BorrarMensajes();
    registroMensajes* ObtenerRegistro();
    void CrearMensaje(string contenido);
    ~chat();
};

#endif
