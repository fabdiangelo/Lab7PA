#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include "ICollection/interfaces/ICollectible.h"

using namespace std;

class usuario : public ICollectible
{
private:
    string correo;
    string contrasenia;
public:
    usuario(string correo, string contrasenia);
    ~usuario();
    string getCorreo();
    string getContrasenia();
    void setCorreo(string correo);
    void setContrasenia(string contrasenia);
};

#endif