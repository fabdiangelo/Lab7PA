#include "edificio.h"

/*


    
    
    */

edificio::edificio(string nombre,int cantPisos,int gastosComunes){
    this -> nombre = nombre;
    this -> cantPisos = cantPisos;
    this -> gastosComunes = gastosComunes;
}

string edificio::getNombre(){
    return this -> nombre;
}
int edificio::getCantPisos(){
    return this -> cantPisos;
}

int edificio::getGastosComunes(){
    return this -> gastosComunes;
}

void edificio::setNombre(string nombre){
    this -> nombre = nombre;
}    

void edificio::setCantPisos(int cantPisos){
    this -> cantPisos = cantPisos;
}

void edificio::aniadirAEdificio(propiedad p){
    //no se bien como se hace
}

void edificio::desvincularEd(string e){
    //no se a que se refiere con desvincular el edificio 
}

edificio::~edificio(){    
}