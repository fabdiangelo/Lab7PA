#ifndef ISISTEMA_H
#define ISISTEMA_H

#include <iostream>
#include "DataTypes/dtRespuesta.h"
#include "DataTypes/direccion.h"
#include "DataTypes/dtInmobiliaria.h"
#include "DataTypes/dtPropiedad.h"
using namespace std;

class ISistema 
{
public:
    virtual bool enviarCorreo(string correo) = 0;  //👌
    virtual void establecerContra(string contra, string repContra) = 0;  //👌
    virtual void verificarContra(string contra) = 0;  //👌
    virtual void cerrarSesion() = 0; //👌
    virtual dtRespuesta* ingresarInmobiliaria(string correo, direccion * dir, string nombre) = 0; //👌
    virtual dtRespuesta* ingresarInteresado(string correo, int edad, string nombre, string apellido) = 0; //👌
    virtual void listarDepartamentos() = 0; //👌
    virtual void seleccionarDepartamento(string depSelec) = 0; //👌
    virtual void ingresarZona(string nombre, string codigo) = 0; //👌
    virtual void listarZonas() = 0; //👌
    virtual void seleccionarZona(string zonaSeleccionada) = 0; //👌
    virtual void ingresarEdificio(string nombre, int pisos, int gastosComunes) = 0; //👌
    virtual void listarEdificios() = 0; //👌
    virtual void seleccionarEdificio(string edSelec) = 0; //👌
    virtual void ingresarDatosApartamento(string codigo, int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2) = 0; //👌
    virtual void ingresarDatosCasa(string codigo, int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2, int m2V) = 0; //👌
    virtual void ingresarPrecioAlquiler(string codigo, int valorAlqui) = 0; //👌
    virtual void ingresarPrecioVenta(string codigo, int valorVenta) = 0; //👌
    virtual void finalizarAlta() = 0; //👌
    virtual void listarPropiedades(string zonaSeleccionada) = 0; //
    virtual void infoPropInmo(string propiedadSelec) = 0; //👌
    virtual void ingresarCodigoProp(string codigo) = 0;
    virtual void borrarProp(string codigo) = 0;
    virtual void listarPropMens(string zonaSeleccionada) = 0;
    virtual void listarMensajes(string propSeleccionada) = 0;
    virtual void crearChat(string propSeleccionada) = 0;
    virtual dtRespuesta* ingresarMensaje(string mensaje) = 0;
    virtual void listarMensajesRecientes() = 0;
    virtual dtInmobiliaria* mostrarDatosInmo() = 0;
    virtual dtPropiedad* mostrarPropiedad() = 0;
    ~ISistema();
};

#endif