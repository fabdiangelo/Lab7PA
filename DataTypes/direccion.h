#ifndef DIRECCION_H
#define DIRECCION_H

#include <iostream>

using namespace std;

class direccion
{
private:
    string ciudad, calle, numero;
public:
    direccion(string ciudad, string calle, string numero);
    ~direccion();
    string getCiudad();
    string getCalle();
    string getNumero();
    friend ostream& operator<<(ostream& os, direccion *dir);
};

#endif