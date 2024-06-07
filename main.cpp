#include <iostream>
using namespace std;

#include "DataTypes/direccion.h"
#include "DataTypes/dtInmobiliaria.h"
#include "DataTypes/dtPropiedad.h"
#include "DataTypes/dtRespuesta.h"
#include "DataTypes/dtZona.h"
#include "DataTypes/fecha.h"
#include "DataTypes/mensajesPropiedad.h"
#include "DataTypes/registroMensajes.h"


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
void pruebaDtPropiedad(){
    direccion* di = new direccion("a", "b", "c");
    dtPropiedad *prop = new dtPropiedad("cod", di, true, false);

    direccion *dir = prop -> getDir();

    cout << prop->getCodigo() << " - " << dir->getCalle() << " - " << dir->getCiudad() << " - " << dir->getNumero() << " - " << prop->getEnAlquiler() << " - " << prop->getEnVenta() << endl;
    
    prop ->~dtPropiedad();
    di->~direccion();
}
void pruebaDtRespuesta(){
    dtRespuesta *res = new dtRespuesta("mens");
    cout << res -> getMensaje() << endl; 
    res->~dtRespuesta(); 
}
void pruebaDtZona(){
    dtZona *zona = new dtZona("nom", "cod");
    cout << zona->getCodigo() << " - " << zona->getNombre() << endl;
    zona->~dtZona();
}
void pruebaFecha(){
    fecha *dia = new fecha("19", "11", "2004");
    cout << dia->getAnio() << " - " << dia ->getMes() << " - " << dia ->getDia() << endl;
    dia -> ~fecha();
}
void pruebaMensajesPropiedad(){
    direccion* di = new direccion("a", "b", "c");
    dtPropiedad *pro = new dtPropiedad("cod", di, true, false);

    mensajesPropiedad *mens = new mensajesPropiedad(5, pro);

    dtPropiedad *prop = mens -> getPropiedad();
    direccion *dir = prop -> getDir();

    cout << mens->getCantMensajes() << " - " << prop->getCodigo() << " - " << dir->getCalle() << " - " << dir->getCiudad() << " - " << dir->getNumero() << " - " << prop->getEnAlquiler() << " - " << prop->getEnVenta() << endl;
    
    mens ->~mensajesPropiedad();
    pro ->~dtPropiedad();
    di->~direccion();
}
void pruebaRegistroMensajes(){
    
}

/*
g++ -o temp main.cpp DataTypes/direccion.cpp DataTypes/dtInmobiliaria.cpp DataTypes/dtPropiedad.cpp DataTypes/dtRespuesta.cpp DataTypes/dtZona.cpp DataTypes/fecha.cpp DataTypes/mensajesPropiedad.cpp
*/
int main (){
    pruebaMensajesPropiedad();
    return 0;
}