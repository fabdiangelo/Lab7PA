#include <iostream>
using namespace std;

#include "DataTypes/direccion.h"
#include "DataTypes/dtInmobiliaria.h"
#include "DataTypes/dtMensaje.h"
#include "DataTypes/dtPropiedad.h"
#include "DataTypes/dtPropiedadInmo.h"
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
void pruebaDtMensaje(){
    dtMensaje *mens = new dtMensaje("mens1", 1);
    cout << mens->getHora() << " - " << mens->getMensaje() << endl;
    mens -> ~dtMensaje();
}
void pruebaDtPropiedad(){
    direccion* di = new direccion("a", "b", "c");
    dtPropiedad *prop = new dtPropiedad("cod", di, true, false);

    direccion *dir = prop -> getDir();

    cout << prop->getCodigo() << " - " << dir->getCalle() << " - " << dir->getCiudad() << " - " << dir->getNumero() << " - " << prop->getEnAlquiler() << " - " << prop->getEnVenta() << endl;
    
    prop ->~dtPropiedad();
    di->~direccion();
}
void pruebaDtPropiedadInmo(){
    direccion* dir = new direccion("a", "b", "c");
    cout << dir->getCalle() << " - " << dir->getCiudad() << " - " << dir->getNumero() << endl;   
    direccion* dirInmo = new direccion("d", "e", "f");
    

    dtPropiedadInmo *prop = new dtPropiedadInmo("123", 3, 4, 1, true, 23, dir, true, false, "propsSA", dirInmo);

    cout << prop->getCantAmbientes() << " - " << prop->getCantBanios() << " - " << prop->getCantDormitorios() << " - " << prop->getCodigo() << " - " << prop->getDireccion() << " - " << prop->getDireccionInmo() << " - " << prop->getEnAlquiler() << " - " << prop->getEnVenta() << " - " << prop->getGarage() << " - " << prop->getM2Edificados() << " - " << prop->getNombreInmo() << endl;
    
    prop->~dtPropiedadInmo();
    dir->~direccion();
    dirInmo->~direccion();
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
    dtMensaje *mens1 = new dtMensaje("mens1", 1);
    dtMensaje *mens2 = new dtMensaje("mens2", 2);
    dtMensaje *mens3 = new dtMensaje("mens3", 3);
    dtMensaje *mens4 = new dtMensaje("mens4", 4);
    dtMensaje *mens5 = new dtMensaje("mens5", 5);
    dtMensaje *mens6 = new dtMensaje("mens6", 6);

    registroMensajes* registro = new registroMensajes();
    registro -> agregarMensaje(mens1);
    registro -> agregarMensaje(mens2);
    registro -> agregarMensaje(mens3);
    registro -> agregarMensaje(mens4);
    registro -> agregarMensaje(mens5);
    registro -> agregarMensaje(mens6);

    List *mensRegistro = (List *) registro -> getMensajes();
    IIterator *iter = mensRegistro -> getIterator();

    for (int i = 0; i < mensRegistro -> getSize(); i++){
        dtMensaje *mens =(dtMensaje *) iter -> getCurrent();
        cout << mens->getHora() << " - " << mens->getMensaje() << endl;
        iter -> next();
    }
    
    mens1 -> ~dtMensaje();
    mens2 -> ~dtMensaje();
    mens3 -> ~dtMensaje();
    mens4 -> ~dtMensaje();
}


#include "chat.h"

// CLASES:
void pruebaChat(){
    fecha *fe = new fecha("19", "11", "2004");
    chat *ch = new chat(fe, 4);
    fecha *dia = ch -> getFecha();
    cout << dia->getAnio() << " - " << dia ->getMes() << " - " << dia ->getDia() << " - " << ch -> getHora() << " - " << ch -> getCantMensajes() << endl;
    ch -> CrearMensaje("fa");
    ch -> CrearMensaje("da");


    registroMensajes* registro = ch -> ObtenerRegistro();

    List *mensRegistro = (List *) registro -> getMensajes();
    IIterator *iter = mensRegistro -> getIterator();

    for (int i = 0; i < mensRegistro -> getSize(); i++){
        dtMensaje *mens =(dtMensaje *) iter -> getCurrent();
        cout << mens->getHora() << " - " << mens->getMensaje() << endl;
        iter -> next();
    }

    
    fe -> ~fecha();
}

/*
clear; g++ -o temp ICollection/interfaces/ICollectible.cpp ICollection/interfaces/IIterator.cpp ICollection/interfaces/ICollection.cpp ICollection/collections/ListNode.cpp ICollection/collections/ListIterator.cpp ICollection/collections/List.cpp main.cpp DataTypes/direccion.cpp DataTypes/dtInmobiliaria.cpp DataTypes/dtMensaje.cpp DataTypes/dtPropiedad.cpp DataTypes/dtPropiedadInmo.cpp DataTypes/dtRespuesta.cpp DataTypes/dtZona.cpp DataTypes/fecha.cpp DataTypes/mensajesPropiedad.cpp DataTypes/registroMensajes.cpp chat.cpp

    ICollection/interfaces/ICollectible.cpp 
    ICollection/interfaces/IIterator.cpp 
    ICollection/interfaces/ICollection.cpp
    ICollection/collections/ListNode.cpp
    ICollection/collections/ListIterator.cpp
    ICollection/collections/List.cpp
*/

int main (){
    pruebaChat();
    return 0;
}