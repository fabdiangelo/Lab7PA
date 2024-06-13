#include <iostream>
using namespace std;

#include "DataTypes/direccion.h"
#include "DataTypes/dtDepartamento.h"
#include "DataTypes/dtEdificio.h"
#include "DataTypes/dtInmobiliaria.h"
#include "DataTypes/dtMensaje.h"
#include "DataTypes/dtPropiedad.h"
#include "DataTypes/dtPropiedadInmo.h"
#include "DataTypes/dtRespuesta.h"
#include "DataTypes/dtZona.h"
#include "DataTypes/fecha.h"
#include "DataTypes/mensajesPropiedad.h"
#include "DataTypes/propZona.h"
#include "DataTypes/registroMensajes.h"
#include "DataTypes/zonasDep.h"
#include "apartamento.h"

void pruebaDir(){
    direccion* dir = new direccion("a", "b", "c");
    cout << dir->getCalle() << " - " << dir->getCiudad() << " - " << dir->getNumero() << endl;   
    dir->~direccion();
}
void pruebaDtDepa(){
    dtDepartamento * dep = new dtDepartamento("Colonia", 'L');
    cout << dep -> getNombre() << " - " << dep->getIdentificador() << endl;
    dep->~dtDepartamento();
}
void pruebaDtEdificio(){
    dtEdificio *ed = new dtEdificio("ed", 2, 1000);
    cout << ed->getNombre() << " - " << ed->getCantPisos() << " - " << ed->getGastosComunes() << endl;
    ed->~dtEdificio();
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
    fecha *dia = new fecha(19, 11, 2004);
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
void pruebaPropZona(){
    edificio *ed = new edificio("nombre", 2, 1000);
    departamento *d = new departamento("COl", 'L');
    zona * z = new zona("zona1", "l1", d);
    propZona *pz = new propZona(z);
    direccion* dir = new direccion("a", "b", "c");
    propiedad* p1 = new apartamento("prop1 - apartamento", 1, 1, 1, true, dir, 1, z, ed);
    propiedad* p2 = new apartamento("prop2 - apartamento", 2, 2, 2, true, dir, 2, z, ed);
    
    pz->agregarProp(p1);
    pz->agregarProp(p2);

    IDictionary* dict = pz -> getPropiedades();

    for(IIterator* iter = dict -> getIterator(); iter -> hasCurrent(); iter -> next()){
        propiedad* p = (propiedad *) iter -> getCurrent();
        cout << p -> getCodigo() << " - " << p -> getCantAmbientes() << endl;
    }

    zona * zon = pz -> getZona();
    cout << zon -> getCodigo() << " - " << zon -> getNombre() << endl;

    pz ->~propZona();
    dict ->~IDictionary();
    z ->~zona();
    d->~departamento();
    p1->~propiedad();
    p2->~propiedad();
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
void pruebaZonasDep(){
    departamento *d = new departamento("COl", 'L');
    zonasDep* zd = new zonasDep(d);
    zona * z1 = new zona("zona1", "l1", d);
    zona * z2 = new zona("zona2", "l2", d);

    zd -> agregarZona(z1);
    zd -> agregarZona(z2);

    IDictionary* dict = zd -> getZonas();

    for(IIterator* iter = dict -> getIterator(); iter -> hasCurrent(); iter -> next()){
        propZona* p = (propZona *) iter -> getCurrent();
        cout << p -> getZona() ->getCodigo() << endl;
    }

    zd->~zonasDep();
    dict->~IDictionary();
    d->~departamento();
    z1->~zona();
    z2->~zona();
}

#include "administrador.h"
#include "apartamento.h"
#include "chat.h"
#include "departamento.h"
#include "edificio.h"
#include "inmobiliaria.h"
#include "interesado.h"
#include "mensaje.h"
#include "propiedad.h"
#include "sistema.h"
#include "usuario.h"
#include "zona.h"

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
    chat *ch = new chat();

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
}
void pruebaDepartamento(){
    departamento* dep = new departamento("San José", 'M');
    cout << dep->getNombre() << " - " << dep->getId() << endl;

    dep -> setId('L');
    dep -> setNombre("Colonia");
    cout << dep->getNombre() << " - " << dep->getId() << endl;

    dep -> agregarZona("pepe", "NH");
    dep -> agregarZona("epep", "HN");
    IDictionary *zonas = dep -> getZonas();

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

    departamento* dep1 = new departamento("Colonia", 'L');
    zona * z1= new zona("COL1", "L1", dep1);

    direccion *dir = new direccion("a", "b", "c");
    propiedad *prop1 = new apartamento("cod1", 1, 1, 1, true, dir, 1, z1, ed);
    propiedad *prop2 = new apartamento("cod2", 2, 2, 1, true, dir, 2, z1, ed);

    ed -> agreagrPropiedad(prop1);
    ed -> agreagrPropiedad(prop2);

    ed -> desvincularProp(prop2 -> getCodigo());
    ed -> desvincularProp(prop1 -> getCodigo());

    prop1 -> ~propiedad();
    prop2 -> ~propiedad();
    ed -> ~edificio();
    dir->~direccion();
}
void pruebaInmobiliaria(){
    direccion* dir = new direccion("a", "b", "c");
    inmobiliaria * inmo = new inmobiliaria("mail", "123", "pepitoSRL", dir);
    direccion *d = inmo -> getDireccion();
    cout << inmo ->getContrasenia() << " - " << inmo->getCorreo() << " - " << inmo->getNombre() << " - " << dir->getCalle() << " - " << dir->getCiudad() << " - " << dir->getNumero() << endl;   

    inmo -> setContrasenia("321");
    inmo -> setCorreo("email@gmail.com");
    dir = new direccion("San Jose de Mayo", "No se calles", "1432");
    inmo -> setDireccion(dir);
    inmo -> setNombre("inmobiliaria1");
    d = inmo -> getDireccion();
    cout << inmo ->getContrasenia() << " - " << inmo->getCorreo() << " - " << inmo->getNombre() << " - " << dir->getCalle() << " - " << dir->getCiudad() << " - " << dir->getNumero() << endl;   

    departamento* dep1 = new departamento("Colonia", 'L');
    departamento* dep2 = new departamento("San Jose", 'M');
    zona * z1= new zona("COL1", "L1", dep1);
    zona * z2= new zona("COL2", "L1", dep1);
    zona * z3= new zona("SJ1", "M1", dep2);
    zona * z4= new zona("SJ2", "M2", dep2);
    zona * z5= new zona("SJ3", "M3", dep2);
    edificio *ed = new edificio("nombre", 2, 1000);

    propiedad* p1 = inmo -> IngresarDatosApartamento("prop1 - apartamento", 1, 1, 1, true, dir, 1, z1, ed);
    propiedad* p2 = inmo -> IngresarDatosApartamento("prop2 - apartamento", 2, 2, 2, true, dir, 2, z2, ed);
    propiedad* p3 = inmo -> IngresarDatosApartamento("prop3 - apartamento", 3, 3, 3, true, dir, 3, z3, ed);
    propiedad* p4 = inmo -> IngresarDatosApartamento("prop4 - apartamento", 4, 4, 4, true, dir, 4, z4, ed);
    propiedad* p5 = inmo -> IngresarDatosApartamento("prop5 - apartamento", 5, 5, 5, true, dir, 5, z5, ed);
    propiedad* p6 = inmo -> IngresarDatosCasa("prop6 - casa", 6, 6, 6, true, dir, 6, 6, z1);
    propiedad* p7 = inmo -> IngresarDatosCasa("prop7 - casa", 7, 7, 7, true, dir, 7, 7, z2);
    propiedad* p8 = inmo -> IngresarDatosCasa("prop8 - casa", 8, 8, 8, true, dir, 8, 8, z3);

    inmo -> IngresarPrecioAlquiler("prop1 - apartamento", 1111);
    inmo -> IngresarPrecioAlquiler("prop4 - apartamento", 4444);
    inmo -> IngresarPrecioAlquiler("prop8 - casa", 8888);
    inmo -> IngresarPrecioVenta("prop2 - apartamento", 2222);
    inmo -> IngresarPrecioVenta("prop4 - apartamento", 4444);
    inmo -> IngresarPrecioVenta("prop7 - casa", 7777);

    inmo -> ModificarDatosApartamento("prop1 - apartamento", 11, 11, 11, true, dir, 11, 111, 111);
    inmo -> ModifiarDatosCasa("prop8 - casa", 88, 88, 88, true, dir, 88, 88, 888, 888);

    inmo -> MostrarDatos();

    inmo -> BorrarPropiedad("prop1 - apartamento");
    inmo -> BorrarPropiedad("prop2 - apartamento");
    inmo -> BorrarPropiedad("prop3 - apartamento");
    inmo -> BorrarPropiedad("prop4 - apartamento");
    inmo -> BorrarPropiedad("prop5 - apartamento");
    inmo -> BorrarPropiedad("prop6 - casa");
    inmo -> BorrarPropiedad("prop7 - casa");
    inmo -> BorrarPropiedad("prop8 - casa");

    dep1->~departamento();
    dep2->~departamento();
    dir->~direccion();
    inmo->~inmobiliaria();
    z1->~zona();
    z2->~zona();
    z3->~zona();
    z4->~zona();
    z5->~zona();
    p1->~propiedad();
    p2->~propiedad();
    p3->~propiedad();
    p4->~propiedad();
    p5->~propiedad();
    p6->~propiedad();
    p7->~propiedad();
    p8->~propiedad();
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
void pruebaPropiedad(){
    edificio *ed = new edificio("nombre", 2, 1000);
    direccion* dir = new direccion("a", "b", "c");
    departamento* dep = new departamento("San José", 'M');
    zona *z = new zona("zonita", "123", dep);
    
    propiedad *ca = new casa("casa1", 1, 1, 1, true, dir, 1, 1, z);
    propiedad *ap = new apartamento("apartamento", 2, 2, 2, false, dir, 2, z, ed);

    ca -> CrearChat ("juan@gmail.com");
    ca -> CrearChat ("juan@gmail.com");
    ca -> CrearChat ("pepe@gmail.com");
    ca -> CrearChat ("pedro@gmail.com");
    ca -> CrearChat ("pepito@gmail.com");

    ca -> IngresarMensaje("pepe@gmail.com", "Hola, k onda");
    ca -> IngresarMensaje("pepe@gmail.com", "¿");
    ca -> IngresarMensaje("pepe@gmail.com", "cómo");
    ca -> IngresarMensaje("pepe@gmail.com", "estás");
    ca -> IngresarMensaje("pepe@gmail.com", "hoy");
    ca -> IngresarMensaje("pepe@gmail.com", "?");

    cout << "cant mens " << ca -> obtenerCantMensajes("pepe@gmail.com") << " - " <<  ca -> obtenerCantMensajes("pedro@gmail.com") << endl;

    registroMensajes * reg = ca -> MostrarMensajes("pepe@gmail.com");
    List *mensRegistro = (List *) reg -> getMensajes();
    IIterator *iter = mensRegistro -> getIterator();
    for (int i = 0; i < mensRegistro -> getSize(); i++){
        dtMensaje *mens =(dtMensaje *) iter -> getCurrent();
        cout << mens->getHora() << "hs - " << mens->getMensaje() << endl;
        iter -> next();
    }

    reg = ca -> MostrarMensajes("juan@gmail.com");
    mensRegistro = (List *) reg -> getMensajes();
    iter = mensRegistro -> getIterator();
    for (int i = 0; i < mensRegistro -> getSize(); i++){
        dtMensaje *mens =(dtMensaje *) iter -> getCurrent();
        cout << mens->getHora() << " - " << mens->getMensaje() << endl;
        iter -> next();
    }

    ca -> CortarLazos();
    cout << "apartamento: " << endl;
    ap -> CortarLazos();

    ed->~edificio();
    dir->~direccion();
    dep->~departamento();
    z->~zona();
    ca->~propiedad();
    ap->~propiedad();
    reg->~registroMensajes();
    mensRegistro->~List();
    iter->~IIterator();
}
void pruebaSistema(){
    direccion* dir = new direccion("ciudad", "calle", "numero");
    sistema* sis = new sistema();


    sis -> ingresarInmobiliaria("inmo1", dir, "inmobiliriaria1");
    sis -> enviarCorreo("inmo1");
    sis -> establecerContra("inmo", "inmo");


    sis -> listarDepartamentos();
    sis -> seleccionarDepartamento("L");
    sis -> ingresarZona("COL1", "L1");
    sis -> ingresarZona("COL2", "L2");
    sis -> ingresarZona("COL2", "L3");
    sis -> ingresarZona("COL2", "L4");
    sis -> listarZonas();
    sis -> seleccionarZona("L1");
    sis -> ingresarEdificio("Ed1", 1, 100);
    sis -> ingresarEdificio("Ed2", 1, 150);
    sis -> ingresarEdificio("Ed3", 12, 9999991);
    sis -> listarEdificios();
    sis -> seleccionarEdificio("Ed2");
    sis -> ingresarDatosApartamento("ap21", 1, 1, 1, true, dir, 1);
    sis -> ingresarDatosApartamento("ap22", 2, 2, 2, true, dir, 2);
    sis -> ingresarPrecioAlquiler("ap21", 100);
    sis -> ingresarPrecioAlquiler("ap22", 1000);
    sis -> seleccionarEdificio("Ed1");
    sis -> ingresarDatosApartamento("ap11", 3, 3, 3, true, dir, 3);
    sis -> ingresarDatosCasa("ca1", 1, 1, 1, true, dir, 1, 1);
    sis -> ingresarDatosCasa("ca2", 2, 2, 2, true, dir, 2, 2);
    sis -> ingresarPrecioAlquiler("ap11", 300);
    sis -> ingresarPrecioVenta("ap11", 500);
    sis -> ingresarPrecioAlquiler("ca1", 10000);
    sis -> ingresarPrecioVenta("ca2", 1000);

    sis -> finalizarAlta();
    sis -> seleccionarDepartamento("L");
    sis -> listarPropiedades("L1");
}
void pruebaUsuario(){
    usuario *user = new usuario("pepe@mail", "pepito123");
    cout << user->getCorreo() << " - " << user->getContrasenia() << endl;
    user -> setCorreo("p@p");
    user -> setContrasenia("p");
    cout << user->getCorreo() << " - " << user->getContrasenia() << endl;
    user ->~usuario();
}
void pruebaZona(){
    departamento* dep = new departamento("San José", 'M');
    zona *z = new zona("zonita", "123", dep); 
    cout << z->getCodigo() << " - " << z->getNombre() << endl;
    z -> setNombre("zona1");
    z -> setCodigo("135");
    cout << z->getCodigo() << " - " << z->getNombre() << endl;

    edificio* ed1 = new edificio("ed1", 2, 100);
    edificio* ed2 = new edificio("ed2", 3, 1000);
    z -> agegarEdificio(ed1);
    z -> agegarEdificio(ed2);
    IDictionary *edificios = z -> listarEdificios();

    for (IIterator *iter = edificios -> getIterator(); iter -> hasCurrent(); iter -> next()){
        edificio *ed =(edificio *) iter -> getCurrent();
        cout << ed->getNombre() << " - " << ed->getCantPisos() << " - " << ed ->getGastosComunes() << endl;
    }
    edificio * ed = z -> seleccionarEdificio("ed1");
    cout << ed->getNombre() << " - " << ed->getCantPisos() << " - " << ed ->getGastosComunes() << endl;

    z -> desvincularEdifico("ed1");
    ed = z -> seleccionarEdificio("ed1");
    z -> desvincularEdifico("ed2");

    direccion* dir = new direccion("a", "b", "c");
    propiedad* prop1 = new apartamento("123", 2, 2, 2, true, dir, 3, z, ed);
    propiedad* prop2 = new apartamento("456", 4, 4, 4, false, dir, 6, z, ed);
    z -> agegarPropiedad(prop1);
    z -> agegarPropiedad(prop2);
    IDictionary *propiedades = z -> listarPropiedades();

    for (IIterator *itera = propiedades -> getIterator(); itera -> hasCurrent(); itera -> next()){
        propiedad *prop =(propiedad *) itera -> getCurrent();
        cout << prop->getCodigo() << " - " << prop->getCantBanios() << endl;
    }
    propiedad *prop = z -> seleccionarPropiedad("123");
    cout << prop->getCodigo() << " - " << prop->getCantBanios() << endl;

    z -> desvincularPropiedad("123");
    prop = z -> seleccionarPropiedad("123");
    z -> desvincularPropiedad("456");

    z -> agegarPropiedad(prop1);
    z -> agegarPropiedad(prop2);
    List* mens = z ->listarPropMens("");
    for (IIterator *iter = mens -> getIterator(); iter -> hasCurrent(); iter -> next()){
        mensajesPropiedad *men =(mensajesPropiedad *) iter -> getCurrent();
        cout << men->getPropiedad()->getCodigo() << " - " << men->getCantMensajes() << endl;
    }

    z -> desvincularPropiedad("123");
    z -> desvincularPropiedad("456");

    prop1->~propiedad();
    prop2->~propiedad();
    dir->~direccion();
    ed1->~edificio();
    ed2->~edificio();
    z->~zona();
    dep->~departamento();
}

/*
clear; g++ -o temp ICollection/interfaces/ICollectible.cpp ICollection/interfaces/ICollection.cpp ICollection/interfaces/IDictionary.cpp ICollection/interfaces/IIterator.cpp ICollection/interfaces/IKey.cpp ICollection/interfaces/OrderedKey.cpp ICollection/collections/List.cpp ICollection/collections/ListIterator.cpp ICollection/collections/ListNode.cpp ICollection/collections/OrderedDictionary.cpp ICollection/collections/OrderedDictionaryEntry.cpp ICollection/String.cpp main.cpp DataTypes/direccion.cpp DataTypes/dtDepartamento.cpp DataTypes/dtEdificio.cpp DataTypes/dtInmobiliaria.cpp DataTypes/dtMensaje.cpp DataTypes/dtPropiedad.cpp DataTypes/dtPropiedadInmo.cpp DataTypes/dtRespuesta.cpp DataTypes/dtZona.cpp DataTypes/fecha.cpp DataTypes/mensajesPropiedad.cpp DataTypes/propZona.cpp DataTypes/registroMensajes.cpp DataTypes/zonasDep.cpp administrador.cpp apartamento.cpp casa.cpp chat.cpp departamento.cpp edificio.cpp inmobiliaria.cpp interesado.cpp mensaje.cpp propiedad.cpp sistema.cpp usuario.cpp zona.cpp

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
    pruebaSistema();
    return 0;
}