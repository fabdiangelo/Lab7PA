#include "zonasDep.h"

// COSNTRUCTOR:
zonasDep::zonasDep(departamento* dep){
    this -> dep = dep;
    this -> propZonas = new OrderedDictionary();
}

// DESTRUCTOR:
zonasDep::~zonasDep(){
    cout << "detruct de zonasDep" << endl;
}

// GETTERS:
departamento* zonasDep::getDepartamento(){
    return this -> dep;
}

IDictionary* zonasDep::getZonas(){
    return this -> propZonas;
}


void zonasDep::agregarZona(zona* z){
    propZona *prZ = new propZona(z);
    IKey *k = new String(z -> getCodigo().c_str());
    this -> propZonas -> add(k, prZ);
}