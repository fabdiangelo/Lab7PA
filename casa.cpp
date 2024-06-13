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
    cout << "todo ok 0" << endl;
    this -> getZona() -> desvincularPropiedad(this -> getCodigo());
    cout << "todo ok 0";
    IIterator *iter = this -> getChats() -> getIterator();
    cout << "todo ok 1";
    while(iter -> hasCurrent()){
    cout << "todo ok 2";
        chat* c =(chat *) iter -> getCurrent();
    cout << "todo ok 3";
        IKey *k = new String(c->getInteresado()->getCorreo().c_str());
    cout << "todo ok 4";
        c -> BorrarMensajes();
    cout << "todo ok 5";
        iter -> next();
    cout << "todo ok 6";
        this -> getChats() -> remove(k);
    cout << "todo ok 7";
        c ->~chat();
    }
}
