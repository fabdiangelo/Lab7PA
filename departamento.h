// Daniel
#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include "zona.h"
#include "ICollection/collections/List.h"

class departamento {
  private:
    string nombre;
    char id;
    List* zona;
  public:
    departamento(string nombre, char id);
    string getNombre();
    char getId();
    void setNombre(string);
    void setId(char);
    List* obtenerListado();
    zona seleccionarZona(string);
    ~departamento();
}

#endif DEPARTAMENTO_H
