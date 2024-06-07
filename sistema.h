// Leandro
#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include "DataTypes/dtRespuesta.h"
#include "DataTypes/direccion.h"
#include "DataTypes/dtProiedadInmo.h"
#include "DataTypes/registroMensajes.h"
#include "DataTypes/dtPropiedad.h"
#include "DataTypes/dtInmobiliaria.h"
#include "ICollection/collections/List.h"

using namespace std;

class sistema
{
public:
    sistema();
    ~sistema();
    void cerrarSesion();
    dtRespuesta ingresarInmobiliaria(string correo, direccion * dir, string nombre);
    dtRespuesta darAlta(string nombre, string apellido, int edad, string email);
    dtRespuesta ingresarEdificio(string nombre, int pisos, int gastosComunes);
    List listarDepartamentos();
    List listarZonaDep(char depSeleccionado);
    string seleccionarZona(string zonaSeleccionada);
    List listarEdificios();
    void seleccionarEdificio();
    dtRespuesta ingresarDatosApartamento(int, int, int, bool, direccion *, int);
    dtRespuesta ingresarDatosCasa(int, int, int, bool, direccion *, int);
    dtRespuesta ingresarPrecioAlquiler(int);
    dtRespuesta ingresarPrecioVenta(int);
    void finalizarAlta();
    List listarPropiedades(string);
    dtProiedadInmo infoPropInmo(string);
    void ingresarCodigoProp(string);
    void borrarPorp(string);
    List listarPropMens(string);
    registroMensajes listarMensajes(string);
    void crearChat();
    dtRespuesta ingresarMensaje(string);
    List listarMensajesRecientes();
    dtInmobiliaria mostrarDatosInmo();
    dtPropiedad mostrarPropiedad();
};


#endif