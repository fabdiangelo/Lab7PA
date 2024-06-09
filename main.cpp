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

#include "administrador.h"
#include "chat.h"
#include "departamento.h"
#include "edificio.h"
#include "interesado.h"
#include "mensaje.h"
#include "usuario.h"

// CLASES:
void pruebaAdmin(){
    administrador *user = new administrador("pepe@mail", "pepito123");
    cout << user->getCorreo() << " - " << user->getContrasenia() << endl;
    user -> setCorreo("p@p");
    user -> setContrasenia("p");
    cout << user->getCorreo() << " - " << user->getContrasenia() << endl;
    user ->~administrador();
}
void pruebaChat(){
    fecha *fe = new fecha("19", "11", "2004");
    chat *ch = new chat(fe, 4);

    fecha *dia = ch -> getFecha();

    cout << dia->getAnio() << " - " << dia ->getMes() << " - " << dia ->getDia() << " - " 
    << ch -> getHora() << " - " << ch -> getCantMensajes() << endl;

    ch -> CrearMensaje("fa");
    ch -> CrearMensaje("da");
    cout << "Largo: " << ch -> getCantMensajes() << endl;

    registroMensajes* registro = ch -> ObtenerRegistro();
    List *mensRegistro = (List *) registro -> getMensajes();
    IIterator *iter = mensRegistro -> getIterator();

    for (int i = 0; i < mensRegistro -> getSize(); i++){
        dtMensaje *mens =(dtMensaje *) iter -> getCurrent();
        cout << mens->getHora() << " - " << mens->getMensaje() << endl;
        iter -> next();
    }
    registro -> ~registroMensajes();

    ch -> BorrarMensajes();
    cout << ch -> getCantMensajes() << endl;

    ch ->~chat();
    fe -> ~fecha();
}
void pruebaDepartamento(){
    departamento* dep = new departamento("San José", 'M');
    cout << dep->getNombre() << " - " << dep->getId() << endl;

    dep -> setId('L');
    dep -> setNombre("Colonia");
    cout << dep->getNombre() << " - " << dep->getId() << endl;

    dep -> agregarZona("pepe", "NH");
    dep -> agregarZona("epep", "HN");
    ICollection *zonas = dep -> obtenerListado();

    IIterator *iter = zonas -> getIterator();
    for (int i = 0; i < zonas -> getSize(); i++){
        zona *z =(zona *) iter -> getCurrent();
        cout << z->getNombre() << " - " << z->getCodigo() << endl;
        iter -> next();
    }

    zona* z = dep -> seleccionarZona("NH");
    cout << z->getNombre() << " - " << z->getCodigo() << endl;

    dep -> ~departamento();
}
void pruebaEdificio(){
    edificio *ed = new edificio("nombre", 2, 1000);
    cout << ed->getNombre() << " - " << ed->getCantPisos() << " - " << ed->getGastosComunes() << endl;
    ed -> setNombre("ed");
    ed -> setCantPisos(3);
    ed -> setGastosComunes(2000);
    cout << ed->getNombre() << " - " << ed->getCantPisos() << " - " << ed->getGastosComunes() << endl;

    direccion *dir = new direccion("a", "b", "c");
    propiedad *prop1 = new propiedad("cod1", 1, 1, 1, true, dir, 1, 1, 1);
    propiedad *prop2 = new propiedad("cod2", 2, 2, 1, true, dir, 2, 2, 2);

    ed -> agreagrPropiedad(prop1);
    ed -> agreagrPropiedad(prop2);

    ed -> desvincularProp(prop2 -> getCodigo());
    ed -> desvincularProp(prop1 -> getCodigo());

    prop1 -> ~propiedad();
    prop2 -> ~propiedad();
    ed -> ~edificio();
    dir->~direccion();
}
void pruebaInteresado(){
    interesado *user = new interesado("pepe@mail", "pepito123", 17, "pepe", "perdomo");
    cout << user->getCorreo() << " - " << user->getContrasenia() << " - " << user->getEdad() << " - " << user->getNombre() << " - " << user->getApellido() << endl;
    user -> setCorreo("p@p");
    user -> setContrasenia("p");
    user -> setEdad(71);
    user -> setNombre("epep");
    user -> setApellido("omodrep");
    cout << user->getCorreo() << " - " << user->getContrasenia() << " - " << user->getEdad() << " - " << user->getNombre() << " - " << user->getApellido() << endl;
    user ->~interesado();
}
void pruebaMensaje(){
    mensaje *mens = new mensaje(5, "pepe");
    cout << mens ->getHora() << " - " << mens -> getMensaje() << endl;
    mens -> setMensaje("jojo");
    cout << mens -> getMensaje() << endl;
    mens ->~mensaje();
}
void pruebaUsuario(){
    usuario *user = new usuario("pepe@mail", "pepito123");
    cout << user->getCorreo() << " - " << user->getContrasenia() << endl;
    user -> setCorreo("p@p");
    user -> setContrasenia("p");
    cout << user->getCorreo() << " - " << user->getContrasenia() << endl;
    user ->~usuario();
}

/*
clear; g++ -o temp ICollection/interfaces/ICollectible.cpp ICollection/interfaces/ICollection.cpp ICollection/interfaces/IDictionary.cpp ICollection/interfaces/IIterator.cpp ICollection/interfaces/IKey.cpp ICollection/interfaces/OrderedKey.cpp ICollection/collections/List.cpp ICollection/collections/ListIterator.cpp ICollection/collections/ListNode.cpp ICollection/collections/OrderedDictionary.cpp ICollection/collections/OrderedDictionaryEntry.cpp ICollection/String.cpp main.cpp DataTypes/direccion.cpp DataTypes/dtInmobiliaria.cpp DataTypes/dtMensaje.cpp DataTypes/dtPropiedad.cpp DataTypes/dtPropiedadInmo.cpp DataTypes/dtRespuesta.cpp DataTypes/dtZona.cpp DataTypes/fecha.cpp DataTypes/mensajesPropiedad.cpp DataTypes/registroMensajes.cpp administrador.cpp chat.cpp departamento.cpp edificio.cpp interesado.cpp mensaje.cpp propiedad.cpp usuario.cpp zona.cpp

    ICollection/String.cpp
    ICollection/interfaces/ICollectible.cpp 
    ICollection/interfaces/ICollection.cpp
    ICollection/interfaces/IDictionary.cpp
    ICollection/interfaces/IIterator.cpp 
    ICollection/interfaces/IKey.cpp 
    ICollection/interfaces/OrderedKey.cpp
    ICollection/collections/List.cpp
    ICollection/collections/ListIterator.cpp
    ICollection/collections/ListNode.cpp
    ICollection/collections/OrderedDictionary.cpp
    ICollection/collections/OrderedDictionaryEntry.cpp
*/

int main (){
    pruebaEdificio();
    return 0;
}