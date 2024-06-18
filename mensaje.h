#ifndef MENSAJE_H
#define MENSAJE_H

#include <iostream>
#include "ICollection/interfaces/ICollectible.h"

using namespace std;

class mensaje : public ICollectible
{
private:
    int hora;
    string contenido;
    string momento;
public:
    mensaje(int hora, string cont, string ahora);
    ~mensaje();
    int getHora();
    string getMensaje();
    string getMomento();
    void setMensaje(string mens);
};

#endif