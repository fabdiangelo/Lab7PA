// Leandro
#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include "DataTypes/dtRespuesta.h"
#include "DataTypes/direccion.h"
#include "DataTypes/registroMensajes.h"
#include "DataTypes/dtPropiedad.h"
#include "DataTypes/dtInmobiliaria.h"
#include "ICollection/collections/List.h"
#include "DataTypes/dtPropiedadInmo.h"

using namespace std;

class sistema
{
public:
    sistema();
    ~sistema();
    void cerrarSesion();
    dtRespuesta* ingresarInmobiliaria(string correo, direccion * dir, string nombre);
    dtRespuesta* darAlta(string nombre, string apellido, int edad, string email);
    dtRespuesta* ingresarEdificio(string nombre, int pisos, int gastosComunes);
    List* listarDepartamentos();
    List* listarZonaDep(char depSeleccionado);
    string seleccionarZona(string zonaSeleccionada);
    List* listarEdificios();
    void seleccionarEdificio();
    dtRespuesta* ingresarDatosApartamento(int ambientes, int dormitorios, int banios, bool garage, direccion * dir, int metros);
    dtRespuesta* ingresarDatosCasa(int ambientes, int dormitorios, int banios , bool garage, direccion * dir, int M2Verde);
    dtRespuesta* ingresarPrecioAlquiler(int valorAlqui);
    dtRespuesta* ingresarPrecioVenta(int valorVenta);
    void finalizarAlta();
    List* listarPropiedades(string zonaSeleccionada);
    dtPropiedadInmo* infoPropInmo(string propInmo);
    void ingresarCodigoProp(string codigo);
    void borrarPorp(string codigo);
    List* listarPropMens(string zonaSeleccionada);
    registroMensajes* listarMensajes(string propSeleccionada);
    void crearChat();
    dtRespuesta* ingresarMensaje(string mensaje);
    List* listarMensajesRecientes();
    dtInmobiliaria* mostrarDatosInmo();
    dtPropiedad* mostrarPropiedad();
};


#endif