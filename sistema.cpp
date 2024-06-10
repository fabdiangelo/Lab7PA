// LEANDRO

#include "sistema.h"

// CONSTRUCTOR

sistema::sistema(){
    cout << "SISTEMA CREADO" << endl;
}

// DESTRUCTOR

sistema::~sistema(){
    cout << "NO HAY SISTEMA SENIORA VENGA MAS TARDE" << endl;
}

// FUNCIONALIDADES

void sistema::cerrarSesion(){

}

dtRespuesta* sistema::ingresarInmobiliaria(string correo, direccion * dir, string nombre){
    return NULL;    
}

dtRespuesta* sistema::darAlta(string nombre, string apellido, int edad, string email){
    return NULL;
}

dtRespuesta* sistema::ingresarEdificio(string nombre, int pisos, int gastosComunes){
    return NULL;
}

List* sistema::listarDepartamentos(){
    return NULL;
}

List* sistema::listarZonaDep(char depSeleccionado){
    return NULL;
}

string sistema::seleccionarZona(string zonaSeleccionada){
    return NULL;
}

List* sistema::listarEdificios(){
    return NULL;
}

void sistema::seleccionarEdificio(){

}

dtRespuesta* sistema::ingresarDatosApartamento(int ambientes, int dormitorios, int banios, bool garage, direccion * dir, int metros){
    return NULL;
}

dtRespuesta* sistema::ingresarDatosCasa(int ambientes, int dormitorios, int banios , bool garage, direccion * dir, int M2Verde){
    return NULL;
}

dtRespuesta* sistema::ingresarPrecioAlquiler(int valorAlqui){
    return NULL;
}

dtRespuesta* sistema::ingresarPrecioVenta(int valorVenta){
    return NULL;
}

void sistema::finalizarAlta(){

}

List* sistema::listarPropiedades(string zonaSeleccionada){
    return NULL;
}

dtPropiedadInmo* sistema::infoPropInmo(string propInmo){
    return NULL;
}

void sistema::ingresarCodigoProp(string codigo){

}

void sistema::borrarPorp(string codigo){

}

List* sistema::listarPropMens(string zonaSeleccionada){
    return NULL;
}

registroMensajes* sistema::listarMensajes(string propSeleccionada){
    return NULL;
}

void sistema::crearChat(){

}

dtRespuesta* sistema::ingresarMensaje(string mensaje){
    return NULL;
}

List* sistema::listarMensajesRecientes(){
    return NULL;
}

dtInmobiliaria* sistema::mostrarDatosInmo(){
    return NULL;
}

dtPropiedad* sistema::mostrarPropiedad(){
    return NULL;
}