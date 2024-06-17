#ifndef SISTEMA_H
#define SISTEMA_H

#include "DataTypes/registroMensajes.h"
#include "DataTypes/dtPropiedadInmo.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "inmobiliaria.h"
#include "administrador.h"
#include "interesado.h"
#include "ISistema.h"
#include <cstring>

class sistema : public ISistema
{
private:
    sistema();
    static sistema * instance;
    IDictionary *departamentos;
    IDictionary *usuarios;
    usuario *usuarioActual;
    departamento *departamentoActual;
    zona *zonaActual;
    edificio *edificioActual;
public:
    static sistema * getInstance();
    ~sistema();
    bool enviarCorreo(string correo);  //👌
    void establecerContra(string contra, string repContra);  //👌
    void verificarContra(string contra);  //👌
    void sesionAbierta();
    void sesionCerrada();
    void cerrarSesion(); //👌
    void confirmarAdmin();
    void confirmarInmobiliaria();
    void ingresarInmobiliaria(string correo, direccion * dir, string nombre); //👌
    void ingresarInteresado(string correo, int edad, string nombre, string apellido); //👌
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
    void listarPropiedades(); //
    void infoPropInmo(string propiedadSelec); //👌
    void ingresarCodigoProp(string codigo);
    void borrarProp(string codigo);
    void listarPropMens(string zonaSeleccionada);
    void listarMensajes(string propSeleccionada);
    void crearChat(string propSeleccionada);
    dtRespuesta* ingresarMensaje(string mensaje);
    void listarMensajesRecientes();
    dtInmobiliaria* mostrarDatosInmo();
    dtPropiedad* mostrarPropiedad();
};


#endif