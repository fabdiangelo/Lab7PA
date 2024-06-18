#ifndef SISTEMA_H
#define SISTEMA_H

#include "DataTypes/registroMensajes.h"
#include "DataTypes/dtPropiedadInmo.h"
#include "inmobiliaria.h"
#include "administrador.h"
#include "interesado.h"
#include "ISistema.h"
#include <cstring>
#include <algorithm>

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
    void confirmarInteresado();
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
    bool depTieneZona();
    bool zonaTieneProp();
    bool ingresarCodigoProp(string codigo);
    void imprimirPropsInmo();
    void modificarApartamento(string codigo, int cantAmb, int cantDorm, int cantBa, bool garage, int m2, int precioAlq, int precioVenta);
    void modificarCasa(string codigo, int cantAmb, int cantDorm, int cantBa, bool garage, int m2, int m2V, int precioAlq, int precioVenta);
    void borrarProp(string codigo);
    void listarPropMens();
    void listarMensajes(string propSeleccionada);
    void crearChat(string propSeleccionada);
    void ingresarMensaje(string mensaje, string codigo);
    void listarMensajesRecientes();
    void enviarMensajeA(string codigo, string correo, string mensaje);
    void mostrarDatosInmo();
};


#endif