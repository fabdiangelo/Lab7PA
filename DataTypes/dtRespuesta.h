#ifndef DTRESPUESTA_H
#define DTRESPUESTA_H

#include <iostream>

using namespace std;

class dtRespuesta
{
private:
    string mensaje;
public:
    dtRespuesta(string mensaje);
    ~dtRespuesta();
    string getMensaje();
};

#endif