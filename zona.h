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
    IDictionary* edificios;
    IDictionary* propiedades;
  public:
    zona(string nombre, string codigo, departamento* dep);
    ~zona();
    string getNombre();
    string getCodigo();
    void setNombre(string nombre);
    void setCodigo(string codigo);
    List* listarEdificios();
    edificio* seleccionarEdificio(string nombre);
    void agegarEdificio(edificio* prop);
    void desvincularEdifico(string nombre);
    propiedad* seleccionarPropiedad(string codigo);
    void agegarPropiedad(propiedad* prop);
    void desvincularPropiedad(string codigo);
    List* listarPropMens();
    void encontrar(string nombre);
};

#endif