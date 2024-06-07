// Leandro
#ifndef ZONA_H
#define ZONA_H

#include <iostream>
#include "ICollection/collections/List.h"
#include "edificio.h"

class zona
{
private:
    string nombre;
    string codigo;
public:
    zona(string nombre, string codigo);
    ~zona();
    string getNombre();
    string getCodigo();
    void setNombre(string nombre);
    void setCodigo(string nombre);
    List listarEdificios();
    edificio seleccionarEdificio(string nombre);
    void anidarAZona(propiedad prop);
    void desvincularZona(string nombre);
    List listarPropMens();
    void encontrar(string nombre);
};

#endif