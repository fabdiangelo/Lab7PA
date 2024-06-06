#ifndef DTZONA_H
#define DTZONA_H

#include <iostream>

using namespace std;

class dtZona
{
private:
    string nombre, codigo;
public:
    dtZona(string nombre, string codigo);
    ~dtZona();
    string getNombre();
    string getCodigo();
};

#endif