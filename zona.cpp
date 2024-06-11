#include "zona.h"

// CONSTRUCTOR:
zona::zona(string nombre, string codigo, departamento* dep){
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

void zona::agegarEdificio(edificio* ed){
    string codigo = ed -> getNombre();
    IKey *k = new String(codigo.c_str());
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
    }
    cout << "No se encontró una propiedad con el codigo " << codigo << " dentro de la zona " << this -> getNombre() << endl;
    return NULL;
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
        cout << "La propiedad con codigo " << codigo << " se desvinculo de la zona " << this -> getNombre() << endl;
    }else{
        cout << "La propiedad con codigo " << codigo << " no se encontraba vinculada con la zona " << this -> getNombre() << endl;
    }
}

List* zona::listarPropMens(){
    List *res = new List;
    for(IIterator* iter = this -> propiedades -> getIterator(); iter -> hasCurrent(); iter -> next()){
        propiedad *prop = (propiedad*) iter -> getCurrent();
        dtPropiedad *dtProp = new dtPropiedad(prop -> getCodigo(), prop -> getDireccion(), prop -> getPrecioVenta() > 0, prop -> getPrecioAlquiler() > 0);
        mensajesPropiedad *mp = new mensajesPropiedad(prop -> obtenerCantMensajes(), dtProp);
        res -> add (mp);
    }
    return res;
}