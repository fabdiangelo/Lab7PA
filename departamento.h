#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include "zona.h"
#include "ICollection/collections/List.h"
#include "DataTypes/dtZona.h"

class zona;

class departamento {
  private:
    string nombre;
    char id;
    ICollection* zonas;
  public:
    departamento(string nombre, char id);
    ~departamento();
    string getNombre();
    char getId();
    void setNombre(string nombre);
    void setId(char id);
    void agregarZona(string nombre, string codigo);
    ICollection* obtenerListado();
    zona* seleccionarZona(string);
};

#endif
