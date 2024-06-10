#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include <iostream>
#include "DataTypes/direccion.h"
#include "usuario.h"
#include "propiedad.h"
#include "collections/List.h"

using namespace std;

class inmobiliaria : public usuario
{
private:
    string nombre;
    direccion* dir;
    List* propiedades;
public:
    inmobiliaria(string correo, string contrasenia, string nom, direccion* dir);
    ~inmobiliaria();
    string getNombre();
    direccion* getDireccion();
    void setNombre(string nom);
    void setDireccion(direccion* dir);
    propiedad IngresarDatosApartamento(int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2);
    propiedad IngresarDatosCasa(int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2Edif, int m2Verd);
    void IngresarPrecioAlquiler(int precio);
    void IngresarPrecioVenta(int precio);
    void BorrarPropiedad(string prop);
    propiedad ModificarDatosApartamento(int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2);
    propiedad ModifiarDatosCasa(int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2Edif, int m2Verd);
    void MostrarDatos();
};

#endif