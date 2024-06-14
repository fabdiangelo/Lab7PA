#ifndef INTERESADO_H
#define INTERESADO_H

#include "usuario.h"

class interesado : public usuario
{
private:
    int edad;
    string nombre, apellido;
public:
    interesado(string correo, string contrasenia, int edad, string nombre, string apellido);
    ~interesado();
    int getEdad();
    string getNombre();
    string getApellido();
    void setEdad(int edad);
    void setNombre(string nombre);
    void setApellido(string apellido);
};

#endif