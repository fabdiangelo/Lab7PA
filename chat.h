#ifndef CHAT_H
#define CHAT_H

#include <ctime>
#include "mensaje.h"
#include "DataTypes/fecha.h"
#include "DataTypes/registroMensajes.h"
#include "interesado.h"
#include "ICollection/interfaces/IIterator.h"

using namespace std;

class chat : public ICollectible{
  private:
    fecha* Fecha;
    int Hora;
    int CantMensajes;
    ICollection* MisMensajes; 
    interesado * persona;
  public:
    chat();
    fecha* getFecha();
    int getHora();
    int getCantMensajes();
    interesado* getInteresado();
    void BorrarMensajes();
    registroMensajes* ObtenerRegistro();
    void CrearMensaje(string contenido);
    ~chat();
};

#endif
