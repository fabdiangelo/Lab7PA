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


/*
string seleccionarZona(string zonaSeleccionada);
List listarEdificios();
void seleccionarEdificio();
dtRespuesta ingresarDatosApartamento(int, int, int, bool, direccion, int);
dtRespuesta ingresarDatosCasa(int, int, int, bool, direccion, int);
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
*/