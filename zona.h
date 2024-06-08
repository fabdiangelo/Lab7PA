#ifndef ZONA_H
#define ZONA_H

#include <iostream>
#include "ICollection/collections/List.h"
#include "edificio.h"
#include "departamento.h"

class departamento;

class zona : public ICollectible{
  private:
    string nombre;
    string codigo;
    departamento* dep;
  public:
    zona(string nombre, string codigo, departamento* dep);
    ~zona();
    string getNombre();
    string getCodigo();
    void setNombre(string nombre);
    void setCodigo(string codigo);
    List* listarEdificios();
    edificio* seleccionarEdificio(string nombre);
    void anidarAZona(propiedad prop);
    void desvincularZona(string nombre);
    List* listarPropMens();
    void encontrar(string nombre);
};

#endif