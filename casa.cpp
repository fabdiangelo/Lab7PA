#include "casa.h"

casa::casa(string codigo, int cantAmbientes, int cantDormitorios, int cantBanios, bool garage, direccion* direccion, int m2Edificados, int precioAlquiler, int precioVenta, int mt2, int mv2) : propiedad(codigo, cantAmbientes, cantDormitorios, cantBanios, garage, direccion, m2Edificados, precioAlquiler, precioVenta){
    this->M2Totales = mt2;
    this->M2Verdes = mt2;
    //NOSEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
    // ta arreglao bro bo sabe que me acorde fue increible
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
    cout << "derrumbo...";
}
