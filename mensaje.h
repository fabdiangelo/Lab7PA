#ifndef MENSAJE_H
#define MENSAJE_H

#include <iostream>

using namespace std;

class mensaje
{
private:
    int hora;
    string mensaje;
public:
    mensaje(int hora, string mensaje);
    ~mensaje();
    int getHora();
    string getMensaje();
    void setMensaje(string mens);
};

#endif