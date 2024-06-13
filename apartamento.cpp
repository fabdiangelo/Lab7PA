#include "apartamento.h"


apartamento::apartamento(string codigo, int cantAmbientes, int cantDormitorios, int cantBanios, bool garage, direccion* direccion, int m2Edificados, zona* z, edificio* ed) : propiedad(codigo, cantAmbientes, cantDormitorios, cantBanios, garage, direccion, m2Edificados, z){
    this -> M2Totales = m2Edificados;
    this -> ed = ed;
    ed ->agreagrPropiedad(this);
}

void apartamento::setM2Totales(int mt2){
    this->M2Totales = mt2;
}

int apartamento::getM2Totales(){
    return this->M2Totales;
}
apartamento::~apartamento(){
    cout << "destruct de apartamento ";
}

// FUNCIONALIDAD:
void apartamento::CortarLazos(){
    this -> getZona() -> desvincularPropiedad(this -> getCodigo());
    this -> ed -> desvincularProp(this -> getCodigo());
    IIterator *iter = this -> getChats() -> getIterator();
    while(iter -> hasCurrent()){
        chat* c =(chat *) iter -> getCurrent();
        IKey *k = new String(c->getInteresado().c_str());
        c -> BorrarMensajes();
        iter -> next();
        this -> getChats() -> remove(k);
        c ->~chat();
    }
}