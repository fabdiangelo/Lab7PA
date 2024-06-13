#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include "DataTypes/dtRespuesta.h"
#include "DataTypes/direccion.h"
#include "DataTypes/registroMensajes.h"
#include "DataTypes/dtPropiedad.h"
#include "DataTypes/dtInmobiliaria.h"
#include "DataTypes/dtPropiedadInmo.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "inmobiliaria.h"
#include "administrador.h"
#include "interesado.h"

using namespace std;

class sistema
{
private:
    IDictionary *departamentos;
    IDictionary *usuarios;
    usuario *usuarioActual;
    departamento *departamentoActual;
    zona *zonaActual;
    edificio *edificioActual;
public:// Faltan las de ingresar sesion
    sistema();
    ~sistema();
    void cerrarSesion(); //👌
    dtRespuesta* ingresarInmobiliaria(string correo, string contrasenia, direccion * dir, string nombre); //👌
    dtRespuesta* ingresarInteresado(string correo, string contrasenia, int edad, string nombre, string apellido); //👌
    void listarDepartamentos(); //👌
    void seleccionarDepartamento(string depSelec); //👌
    void ingresarZona(string nombre, string codigo); //👌
    void listarZonas(); //👌
    void seleccionarZona(string zonaSeleccionada); //👌
    dtRespuesta* ingresarEdificio(string nombre, int pisos, int gastosComunes);
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