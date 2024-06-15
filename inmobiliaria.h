#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include "usuario.h"
#include "casa.h"
#include "apartamento.h"
#include "DataTypes/zonasDep.h"

class propiedad;
class casa;
class apartamento;

class inmobiliaria : public usuario
{
private:
    string nombre;
    direccion* dir;
    IDictionary* propiedades;
public:
    inmobiliaria(string correo, string contrasenia, string nom, direccion* dir);
    ~inmobiliaria();
    string getNombre();
    direccion* getDireccion();
    void setNombre(string nom);
    void setDireccion(direccion* dir);
    propiedad* IngresarDatosApartamento(string cod, int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2, zona* z, edificio* ed);
    propiedad* IngresarDatosCasa(string cod, int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2, int m2V, zona* z);
    void IngresarPrecioAlquiler(string cod, int precio);
    void IngresarPrecioVenta(string cod, int precio);
    void BorrarPropiedad(string codigo);
    void ModificarDatosApartamento(string cod, int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2, int precioAlquiler, int precioVenta);
    void ModifiarDatosCasa(string cod, int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2, int precioAlquiler, int precioVenta, int m2V);
    void MostrarDatos();
    propiedad * encontrarPropiedad(string codigo);
};

#endif