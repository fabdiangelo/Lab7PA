#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

using namespace std;

class usuario
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
    void activarUsuario();
};

#endif