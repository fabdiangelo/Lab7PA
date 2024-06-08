#ifndef DTZONA_H
#define DTZONA_H

#include <iostream>
#include "../ICollection/interfaces/ICollectible.h"

using namespace std;

class dtZona : public ICollectible
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