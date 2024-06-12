#include "propZona.h"

// CONSTRUCTOR:
propZona::propZona(zona *z){
    this -> z = z;
    this -> propiedades = new OrderedDictionary();
}

// DESTRUCTOR:
propZona::~propZona(){
    cout << "destruct de propZona" << endl;
}

// GETTERS:
zona* propZona::getZona(){
    return this -> z;
}

IDictionary* propZona::getPropiedades(){
    return this -> propiedades;
}

// SETTER:
void propZona::agregarProp(propiedad* prop){
    IKey *k = new String(prop -> getCodigo().c_str());
    this -> propiedades -> add (k, prop);
}