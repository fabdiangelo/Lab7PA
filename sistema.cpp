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

dtRespuesta sistema::ingresarInmobiliaria(string correo, direccion * dir, string nombre){
    
}

dtRespuesta sistema::darAlta(string nombre, string apellido, int edad, string email){

}

dtRespuesta sistema::ingresarEdificio(string nombre, int pisos, int gastosComunes){

}

List sistema::listarDepartamentos(){

}

List sistema::listarZonaDep(char depSeleccionado){

}

string sistema::seleccionarZona(string zonaSeleccionada){

}

List sistema::listarEdificios(){

}

void sistema::seleccionarEdificio(){

}

dtRespuesta sistema::ingresarDatosApartamento(int ambientes, int dormitorios, int banios, bool garage, direccion * dir, int metros){

}

dtRespuesta sistema::ingresarDatosCasa(int ambientes, int dormitorios, int banios , bool garage, direccion * dir, int M2Verde){

}

dtRespuesta sistema::ingresarPrecioAlquiler(int valorAlqui){

}

dtRespuesta sistema::ingresarPrecioVenta(int valorVenta){

}

void sistema::finalizarAlta(){

}

List sistema::listarPropiedades(string zonaSeleccionada){

}

dtPropiedadInmo sistema::infoPropInmo(string propInmo){

}

void sistema::ingresarCodigoProp(string codigo){

}

void sistema::borrarPorp(string codigo){

}

List sistema::listarPropMens(string zonaSeleccionada){

}

registroMensajes sistema::listarMensajes(string propSeleccionada){

}

void sistema::crearChat(){

}

dtRespuesta sistema::ingresarMensaje(string mensaje){

}

List sistema::listarMensajesRecientes(){

}

dtInmobiliaria sistema::mostrarDatosInmo(){

}

dtPropiedad sistema::mostrarPropiedad(){

}