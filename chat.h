// Daniel

#ifndef CHAT_H
#define CHAT_H

#include "mensaje.h"
#include "DataTypes/fecha.h"
#include "DataTypes/registroMensajes.h"
class chat{
  private:
    fecha Fecha;
    int Hora;
    int CantMensajes;
    MisMensajes* mensaje; //para marcar que el chat tiene una lista de mensajes...mal creo
  public:
    chat(fecha Fecha,int Hora,int CantMensajes);
    fecha getFecha();
    int getHora();
    int getCantMensajes();
    int getInteresado();
    void setCantMensajes(int);
    void BorrarMensajes();
    registroMensajes ObtenerRegistro();
    void CrearMensaje(string);
    ~chat();
};

#endif CHAT_H
