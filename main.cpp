#include <iostream>
using namespace std;

#include "DataTypes/direccion.h"
#include "DataTypes/dtInmobiliaria.h"
#include "DataTypes/dtRespuesta.h"
#include "DataTypes/dtZona.h"


void pruebaDir(){
    direccion* dir = new direccion("a", "b", "c");
    cout << dir->getCalle() << " - " << dir->getCiudad() << " - " << dir->getNumero() << endl;   
    dir->~direccion();
}
void pruebaDtInmo(){
    direccion* dir = new direccion("a", "b", "c");
    cout << dir->getCalle() << " - " << dir->getCiudad() << " - " << dir->getNumero() << endl;
    
    dtInmobiliaria* dtInmo= new dtInmobiliaria("nom", "cor", dir);
    direccion* inmoDir = dtInmo->getDireccion();
    cout << dtInmo->getCorreo() << " - " << dtInmo->getNombre() << " - " << inmoDir->getCalle() << " - " << inmoDir->getCiudad() << " - " << inmoDir->getNumero() << endl;

    dtInmo->~dtInmobiliaria();
    dir->~direccion();
}
void pruebaDtRespuesta(){
    dtRespuesta *res = new dtRespuesta("mens");
    cout << res -> getMensaje() << endl; 
    res->~dtRespuesta(); 
}
void pruebaDtZona(){

}
// g++ -o temp main.cpp DataTypes/direccion.cpp DataTypes/dtInmobiliaria.cpp DataTypes/dtRespuesta.cpp
int main (){
    
    return 0;
}