#ifndef CHAT_H
#define CHAT_H

#include <ctime>
#include "mensaje.h"
#include "DataTypes/fecha.h"
#include "DataTypes/registroMensajes.h"
#include "interesado.h"
#include "ICollection/interfaces/IIterator.h"

class chat{
  private:
    fecha* Fecha;
    int Hora;
    int CantMensajes;
    ICollection* MisMensajes; 
    interesado * persona;
  public:
    chat(fecha* Fecha, int Hora);
    fecha* getFecha();
    int getHora();
    int getCantMensajes();
    interesado* getInteresado();
    void BorrarMensajes();
    registroMensajes* ObtenerRegistro();
    void CrearMensaje(string);
    ~chat();
};

#endif
