#include "zona.h"
#include "departamento.h"
#include <algorithm>

// CONSTRUCTOR:
zona::zona(string nombre, string codigo, departamento* dep){
    transform(codigo.begin(), codigo.end(), codigo.begin(), ::toupper);
    this -> nombre = nombre;
    this -> codigo = codigo;
    this -> dep = dep;
    this -> edificios = new OrderedDictionary();
    this -> propiedades = new OrderedDictionary();
}

// DESTRUCTOR:
zona::~zona(){
    cout << "destruct de zona" << endl;
}

// GETTERS:
string zona::getNombre(){
    return this -> nombre;
}

string zona::getCodigo(){
    return this -> codigo;
}

departamento* zona::getDepartamento(){
    return this -> dep;
}

// SETTERS:
void zona::setNombre(string nombre){
    this -> nombre = nombre;
}

void zona::setCodigo(string codigo){
    this -> codigo = codigo;
}

// FUNCIONALIDADES:
IDictionary* zona::listarEdificios(){
    return this -> edificios;
}

edificio* zona::seleccionarEdificio(string nombre){
    IKey *k = new String(nombre.c_str());
    if(this -> edificios -> member(k)){
        edificio* ed = (edificio*) this -> edificios -> find(k);
        return ed;
    }
    cout << "No se encontró un edificio con el nombre " << nombre << " dentro de la zona " << this -> getNombre() << endl;
    return NULL;
}

void zona::agegarEdificio(string nombre, int cantPisos, int gastosComunes){
    IKey *k = new String(nombre.c_str());
    if(this -> edificios -> member(k)){
        delete k;
        throw invalid_argument("Ya existe un edificio con este nombre dentro de la zona " + this -> nombre + "\n");
    }
    edificio* ed = new edificio(nombre, cantPisos, gastosComunes);
    this -> edificios -> add(k, ed);
}

void zona::desvincularEdifico(string nombre){
    IKey *k = new String(nombre.c_str());
    if(this -> edificios -> member(k)){
        this -> edificios -> remove(k);
        cout << "El edificio con nombre " << nombre << " se desvinculo de la zona " << this -> getNombre() << endl;
    }else{
        cout << "El edificio con nombre " << nombre << " no se encontraba vinculado con la zona " << this -> getNombre() << endl;
    }
}

IDictionary* zona::listarPropiedades(){
    return this -> propiedades;
}

propiedad* zona::seleccionarPropiedad(string codigo){
    IKey *k = new String(codigo.c_str());
    if(this -> propiedades -> member(k)){
        propiedad* prop = (propiedad*) this -> propiedades -> find(k);
        return prop;
    }else{
        delete k;
        throw invalid_argument("No se encontró una propiedad con el codigo " + codigo + " dentro de la zona " + this -> getNombre() + "\n");
    }
}

void zona::agegarPropiedad(propiedad* prop){
    string codigo = prop -> getCodigo();
    IKey *k = new String(codigo.c_str());
    this -> propiedades -> add(k, prop);
}

void zona::desvincularPropiedad(string codigo){
    IKey *k = new String(codigo.c_str());
    if(this -> propiedades -> member(k)){
        this -> propiedades -> remove(k);
        cout << "La propiedad con codigo \x1B[92m" << codigo << "\033[0m se desvinculo de la zona \x1B[92m" << this -> getNombre() << "\033[0m\n";
    }
}

List* zona::listarPropMens(string correo){
    List *res = new List;
    for(IIterator* iter = this -> propiedades -> getIterator(); iter -> hasCurrent(); iter -> next()){
        propiedad *prop = (propiedad*) iter -> getCurrent();
        dtPropiedad *dtProp = new dtPropiedad(prop -> getCodigo(), prop -> getDireccion(), prop -> getPrecioVenta() > 0, prop -> getPrecioAlquiler() > 0);
        mensajesPropiedad *mp = new mensajesPropiedad(prop -> obtenerCantMensajes(correo), dtProp);
        res -> add (mp);
    }
    return res;
}

// SOBRECARGA:
ostream& operator<<(ostream& os, zona* z){
    os << "\t" << z -> getCodigo() << ") " << z -> getNombre() << endl;
    return os;
}