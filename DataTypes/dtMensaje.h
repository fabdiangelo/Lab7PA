#ifndef DTMENSAJE_H
#define DTMENSAJE_H
#include <iostream>

#include "../ICollection/interfaces/ICollectible.h"

using namespace std;

class dtMensaje : public ICollectible
{
private:
    string mensaje;
    int hora;
public:
    dtMensaje(string mensaje, int hora);
    ~dtMensaje();
    string getMensaje();
    int getHora();
};

#endif