#ifndef ZONA_H
#define ZONA_H

#include "departamento.h"
#include "DataTypes/mensajesPropiedad.h"
#include "ICollection/interfaces/IDictionary.h"
#include "edificio.h"

class edificio;
class departamento;
class propiedad;

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
    departamento* getDepartamento();
    void setNombre(string nombre);
    void setCodigo(string codigo);
    IDictionary* listarEdificios();
    edificio* seleccionarEdificio(string nombre);
    void agegarEdificio(edificio* ed);
    void desvincularEdifico(string nombre);
    IDictionary* listarPropiedades();
    propiedad* seleccionarPropiedad(string codigo);
    void agegarPropiedad(propiedad* prop);
    void desvincularPropiedad(string codigo);
    List* listarPropMens(string correo);
    friend ostream& operator<<(ostream& os, zona *z);
};

#endif