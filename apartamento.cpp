#include "apartamento.h"


apartamento::apartamento(string codigo, int cantAmbientes, int cantDormitorios, int cantBanios, bool garage, direccion* direccion, int m2Edificados, int precioAlquiler, int precioVenta, int mt2)::propiedad(codigo, cantAmbientes, cantDormitorios, cantBanios, garage, direccion, m2Edificados, precioAlquiler, precioVenta){
    this->M2Totales = mt2;
}

void apartamento::setM2Totales(int mt2){
    this->M2Totales = mt2;
}

int apartamento::getM2Totales(){
    return this->M2Totales;
}
apartamento::~apartamento(){
    cout << "incendio...";
}
