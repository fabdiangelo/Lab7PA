#include "casa.h"

casa::casa(string codigo, int cantAmbientes, int cantDormitorios, int cantBanios, bool garage, direccion* direccion, int m2Edificados, int mv2, zona* z) : propiedad(codigo, cantAmbientes, cantDormitorios, cantBanios, garage, direccion, m2Edificados, z){
    this->M2Totales = mv2 + m2Edificados;
    this->M2Verdes = mv2;
}

void casa::setM2Totales(int mt2){
    this->M2Totales = mt2;
}

void casa::setM2Verdes(int mtv){
    this->M2Verdes = mtv;
}

int casa::getM2Totales(){
    return this->M2Totales;
}

int casa::getM2Verdes(){
    return this->M2Verdes;
}

casa::~casa(){
    cout << "destruct de casa";
}

// FUNCIONALIDAD:
void casa::CortarLazos(){
    this -> getZona() -> desvincularPropiedad(this -> getCodigo());
    IIterator *iter = this -> getChats() -> getIterator();
    while(iter -> hasCurrent()){
        chat* c =(chat *) iter -> getCurrent();
        IKey *k = new String (c->getInteresado().c_str());
        c -> BorrarMensajes();
        iter -> next();
        this -> getChats() -> remove(k);
        c ->~chat();
    }
}
