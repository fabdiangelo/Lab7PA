#ifndef MENSAJE_H
#define MENSAJE_H

#include <iostream>
#include "ICollection/interfaces/ICollectible.h"

using namespace std;

class mensaje : ICollectible
{
private:
    int hora;
    string contenido;
public:
    mensaje(int hora, string mensaje);
    ~mensaje();
    int getHora();
    string getMensaje();
    void setMensaje(string mens);
};

#endif