#ifndef ISISTEMA_H
#define ISISTEMA_H

#include <iostream>
#include "DataTypes/direccion.h"
using namespace std;

class ISistema 
{
public:
    virtual bool enviarCorreo(string correo) = 0;  
    virtual void establecerContra(string contra, string repContra) = 0;  
    virtual void verificarContra(string contra) = 0;  
    virtual void sesionAbierta() = 0;
    virtual void sesionCerrada() = 0;
    virtual void cerrarSesion() = 0; 
    virtual void confirmarAdmin() = 0;
    virtual void confirmarInmobiliaria() = 0;
    virtual void confirmarInteresado() = 0;
    virtual void confirmarValidezCodigo(string codigo) = 0;
    virtual void ingresarInmobiliaria(string correo, direccion * dir, string nombre) = 0; 
    virtual void ingresarInteresado(string correo, int edad, string nombre, string apellido) = 0; 
    virtual void listarDepartamentos() = 0; 
    virtual void seleccionarDepartamento(string depSelec) = 0; 
    virtual void ingresarZona(string nombre, string codigo) = 0; 
    virtual void listarZonas() = 0; 
    virtual void seleccionarZona(string zonaSeleccionada) = 0; 
    virtual void ingresarEdificio(string nombre, int pisos, int gastosComunes) = 0; 
    virtual void listarEdificios() = 0; 
    virtual void seleccionarEdificio(string edSelec) = 0; 
    virtual void ingresarDatosApartamento(string codigo, int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2) = 0; 
    virtual void ingresarDatosCasa(string codigo, int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2, int m2V) = 0; 
    virtual void ingresarPrecioAlquiler(string codigo, int valorAlqui) = 0; 
    virtual void ingresarPrecioVenta(string codigo, int valorVenta) = 0; 
    virtual void finalizarAlta() = 0; 
    virtual void listarPropiedades() = 0; //
    virtual void infoPropInmo(string propiedadSelec) = 0; 
    virtual bool depTieneZona() = 0;
    virtual bool zonaTieneProp() = 0;
    virtual bool ingresarCodigoProp(string codigo) = 0;
    virtual void imprimirPropsInmo() = 0;
    virtual void modificarApartamento(string codigo, int cantAmb, int cantDorm, int cantBa, bool garage, int m2, int precioAlq, int precioVenta) = 0;
    virtual void modificarCasa(string codigo, int cantAmb, int cantDorm, int cantBa, bool garage, int m2, int m2V, int precioAlq, int precioVenta) = 0;
    virtual void borrarProp(string codigo) = 0;
    virtual void listarPropMens() = 0;
    virtual void listarMensajes(string propSeleccionada) = 0;
    virtual void crearChat(string propSeleccionada) = 0;
    virtual void ingresarMensaje(string mensaje, string codigo) = 0;
    virtual void listarMensajesRecientes() = 0;
    virtual void enviarMensajeA(string codigo, string correo, string mensaje) = 0;
    virtual void mostrarDatosInmo() = 0;
    ~ISistema();
};

#endif