#ifndef SISTEMA_H
#define SISTEMA_H

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

class sistema
{
private:
    IDictionary *departamentos;
    IDictionary *usuarios;
    usuario *usuarioActual;
    departamento *departamentoActual;
    zona *zonaActual;
    edificio *edificioActual;
public:
    sistema();
    ~sistema();
    void enviarCorreo(string correo);  //👌
    void establecerContra(string contra, string repContra);  //👌
    void verificarContra(string contra);  //👌
    void cerrarSesion(); //👌
    dtRespuesta* ingresarInmobiliaria(string correo, direccion * dir, string nombre); //👌
    dtRespuesta* ingresarInteresado(string correo, int edad, string nombre, string apellido); //👌
    void listarDepartamentos(); //👌
    void seleccionarDepartamento(string depSelec); //👌
    void ingresarZona(string nombre, string codigo); //👌
    void listarZonas(); //👌
    void seleccionarZona(string zonaSeleccionada); //👌
    void ingresarEdificio(string nombre, int pisos, int gastosComunes); //👌
    void listarEdificios(); //👌
    void seleccionarEdificio(string edSelec); //👌
    void ingresarDatosApartamento(string codigo, int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2); //👌
    void ingresarDatosCasa(string codigo, int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2, int m2V); //👌
    void ingresarPrecioAlquiler(string codigo, int valorAlqui); //👌
    void ingresarPrecioVenta(string codigo, int valorVenta); //👌
    void finalizarAlta(); //👌
    void listarPropiedades(string zonaSeleccionada); //
    void infoPropInmo(string propiedadSelec); //
    void ingresarCodigoProp(string codigo);
    void borrarProp(string codigo);
    List* listarPropMens(string zonaSeleccionada);
    registroMensajes* listarMensajes(string propSeleccionada);
    void crearChat();
    dtRespuesta* ingresarMensaje(string mensaje);
    List* listarMensajesRecientes();
    dtInmobiliaria* mostrarDatosInmo();
    dtPropiedad* mostrarPropiedad();
};


#endif