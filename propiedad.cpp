#include "propiedad.h"
#include <cctype>
#include <algorithm>

// CONSTRUCTOR:
propiedad::propiedad(string codigo, int cantAmbientes, int cantDormitorios, int cantBanios, bool garage, direccion* dir, int m2Edificados, zona* z, string nombreInmo){
    transform(codigo.begin(), codigo.end(), codigo.begin(), ::toupper);
    this -> codigo = codigo;
    this -> cantAmbientes = cantAmbientes;
    this -> cantDormitorios = cantDormitorios;
    this -> cantBanios = cantBanios;
    this -> garage = garage;
    this -> dir = dir;
    this -> m2Edificados = m2Edificados;
    this -> z = z;
    this -> precioAlquiler = 0;
    this -> precioVenta = 0;
    this -> chats = new OrderedDictionary();
    this -> nombreInmo = nombreInmo;
    z -> agegarPropiedad(this);
}

// DESTRUCTOR:
propiedad::~propiedad(){
    cout << ": propiedad" << endl;
}

// GETTERS:
string propiedad::getCodigo(){
    return this -> codigo;
}

int propiedad::getCantAmbientes(){
    return this -> cantAmbientes;
}

int propiedad::getCantDormitorios(){
    return this -> cantDormitorios;
}

int propiedad::getCantBanios(){
    return this -> cantBanios;
}

bool propiedad::getGarage(){
    return this -> garage;
}

direccion* propiedad::getDireccion(){
    return this -> dir;
}

int propiedad::getM2Edificados(){
    return this -> m2Edificados;
}

int propiedad::getPrecioAlquiler(){
    return this -> precioAlquiler;
}

int propiedad::getPrecioVenta(){
    return this -> precioVenta;
}

zona* propiedad::getZona(){
    return this -> z;
}

IDictionary* propiedad::getChats(){
    return this -> chats;
}

string propiedad::getInmobiliaria(){
    return this -> nombreInmo;
}

// SETTERS:
void propiedad::setCantAmbientes(int cant){
    this -> cantAmbientes = cant;
}

void propiedad::setCantDormitorios(int cant){
    this -> cantDormitorios = cant;
}

void propiedad::setCantBanios(int cant){
    this -> cantBanios = cant;
}

void propiedad::setGarage(bool garage){
    this -> garage = garage;
}

void propiedad::setDireccion(direccion* dir){
    this -> dir = dir;
}

void propiedad::setM2Edificados(int m2){
    this -> m2Edificados = m2;
}

void propiedad::setPrecioAlquiler(int precio){
    this -> precioAlquiler = precio;
}

void propiedad::setPrecioVenta(int precio){
    this -> precioVenta = precio;
}

// FUNCIONALIDAD:
registroMensajes *propiedad::MostrarMensajes(string correo){
    IKey *k = new String(correo.c_str());
    if(!chats -> member(k)){
        return NULL;
    }else{
        chat *c =(chat*) chats -> find(k);
        return c -> ObtenerRegistro();
    }
}

void propiedad::CrearChat(string correo){
    IKey *k = new String(correo.c_str());
    if(chats -> member(k)){
        cout << "El usuario " << correo << " ya ha creado un chat con la propiedad " << this -> getCodigo() << endl;
    }else{
        chat * c = new chat(correo, this);
        chats -> add(k, c);
    }
}

void propiedad::IngresarMensaje(string correo, string mensaje){
    IKey *k = new String(correo.c_str());
    if(!chats -> member(k)){
        cout << "El usuario " << correo << " no ha creado un chat con la propiedad " << this -> getCodigo() << endl;
    }else{
        chat * c =(chat *) this -> chats -> find(k);
        c -> CrearMensaje(mensaje);
    }
}

int propiedad::obtenerCantMensajes(string correo){
    IKey *k = new String(correo.c_str());
    if(!chats -> member(k)){
        return 0;
    }else{
        chat * c =(chat *) this -> chats -> find(k);
        return c -> getCantMensajes();
    }
}

// SOBRECARGA:
ostream& operator<<(ostream& os, propiedad* prop){
    os << "\t" << prop -> getCodigo() << ") Direccion: " << prop -> getDireccion() <<"    ";
    if(prop -> getPrecioAlquiler() > 0){
        os << "Precio Alquiler: " << prop -> getPrecioAlquiler() << "    ";
    }
    if(prop -> getPrecioVenta() > 0){
        os << "Precio Venta: " << prop -> getPrecioVenta();
    }
    os << endl;
    return os;
}