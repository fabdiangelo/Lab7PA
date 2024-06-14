#include "inmobiliaria.h"

// CONSTRUCTOR:
inmobiliaria::inmobiliaria(string correo, string contrasenia, string nom, direccion* dir) : usuario(correo, contrasenia){
    this -> nombre = nom;
    this -> dir = dir;
    this -> propiedades = new OrderedDictionary();
}

// DESTRUCTOR:
inmobiliaria::~inmobiliaria(){
    cout << "destruct de inmobiliaria" << endl;
}

// GETTERS:
string inmobiliaria::getNombre(){
    return this -> nombre;
}

direccion* inmobiliaria::getDireccion(){
    return this -> dir;
}

// SETTERS:
void inmobiliaria::setNombre(string nom){
    this -> nombre = nom;
}

void inmobiliaria::setDireccion(direccion* dir){
    this -> dir = dir;
}

// FUNCIONALIDAD:
propiedad* inmobiliaria::IngresarDatosApartamento(string cod, int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2, zona* z, edificio* ed){
    propiedad *prop = new apartamento(cod, cantAmb, cantDorm, cantBa, garage, dir, m2, z, ed, this);
    IKey *k = new String(cod.c_str());
    this -> propiedades -> add (k, prop);
    return prop;
}

propiedad* inmobiliaria::IngresarDatosCasa(string cod, int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2, int m2V, zona* z){
    propiedad *ca = new casa(cod, cantAmb, cantDorm, cantBa, garage, dir, m2, m2V, z, this);
    IKey *k = new String(cod.c_str());
    this -> propiedades -> add (k, ca);
    return ca;
}

void inmobiliaria::IngresarPrecioAlquiler(string codigo, int precio){
    IKey *k = new String(codigo.c_str());
    if(this -> propiedades -> member(k)){
        propiedad* prop =(propiedad*) this -> propiedades -> find(k);
        prop -> setPrecioAlquiler(precio);
    }else{
        cout << "No se encontró una propiedad con codigo " << codigo << " dentro de la zona con nombre " << this -> getNombre() << endl;
    }
}

void inmobiliaria::IngresarPrecioVenta(string codigo, int precio){
    IKey *k = new String(codigo.c_str());
    if(this -> propiedades -> member(k)){
        propiedad* prop =(propiedad*) this -> propiedades -> find(k);
        prop -> setPrecioVenta(precio);
    }else{
        cout << "No se encontró una propiedad con codigo " << codigo << " dentro de la zona con nombre " << this -> getNombre() << endl;
    }
}

void inmobiliaria::BorrarPropiedad(string codigo){
    IKey *k = new String(codigo.c_str());
    if(this -> propiedades -> member(k)){
        propiedades -> remove (k);
    }else{
        cout << "No se encontró una propiedad con codigo " << codigo << " dentro de la zona con nombre " << this -> getNombre() << endl;
    }
}

void inmobiliaria::ModificarDatosApartamento(string codigo, int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2, int precioAlquiler, int precioVenta){
    IKey *k = new String(codigo.c_str());
    if(this -> propiedades -> member(k)){
        apartamento* prop =(apartamento*) this -> propiedades -> find(k);
        prop -> setCantAmbientes(cantAmb);
        prop -> setCantDormitorios(cantDorm);
        prop -> setCantBanios(cantBa);
        prop -> setGarage(garage);
        prop -> setDireccion(dir);
        prop -> setM2Edificados(m2);
        prop -> setPrecioAlquiler(precioAlquiler);
        prop -> setPrecioVenta(precioVenta);
        prop -> setM2Totales(m2);
    }else{
        cout << "No se encontró una propiedad con codigo " << codigo << " dentro de la zona con nombre " << this -> getNombre() << endl;
    }
}

void inmobiliaria::ModifiarDatosCasa(string codigo, int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2, int precioAlquiler, int precioVenta, int m2V){
    IKey *k = new String(codigo.c_str());
    if(this -> propiedades -> member(k)){
        casa* prop =(casa*) this -> propiedades -> find(k);
        prop -> setCantAmbientes(cantAmb);
        prop -> setCantDormitorios(cantDorm);
        prop -> setCantBanios(cantBa);
        prop -> setGarage(garage);
        prop -> setDireccion(dir);
        prop -> setM2Edificados(m2);
        prop -> setPrecioAlquiler(precioAlquiler);
        prop -> setPrecioVenta(precioVenta);
        prop -> setM2Verdes(m2V);
        prop -> setM2Totales(m2 + m2V);
    }else{
        cout << "No se encontró una propiedad con codigo " << codigo << " dentro de la zona con nombre " << this -> getNombre() << endl;
    }
}

void inmobiliaria::MostrarDatos(){
    cout << "Nombre: " << this -> getNombre() << endl;
    cout << "Mail: " << this -> getCorreo() << endl;
    direccion * dir = this -> getDireccion();
    cout << "Direccion: " << dir -> getCiudad() << ", " << dir -> getCalle() << " Nro " << dir -> getNumero() << endl;
    cout << "Propiedades:" << endl;

    IDictionary *lista = new OrderedDictionary(); // guarda zonasDep

    for (IIterator* pi = this -> propiedades -> getIterator(); pi -> hasCurrent(); pi -> next()){
        propiedad *prop =(propiedad *) pi -> getCurrent();
        zona *z= prop -> getZona();
        IKey *kDep = new String(z -> getDepartamento() -> getNombre().c_str()); // obtengo la clave del dep de la prop
        
        if(!lista -> member(kDep)){ // busca si no existe el dep en lista
            zonasDep* zonDep = new zonasDep(z -> getDepartamento());
            lista -> add (kDep, zonDep);
        }
        
        zonasDep *zonDep =(zonasDep*) lista -> find(kDep); // encuentra al dep
        IKey *kZona = new String(z -> getCodigo().c_str());
        
        if(!zonDep -> getZonas() -> member(kZona)){ // busca si no existe la zona dentro del dep
            zonDep -> agregarZona(z);
        }
        propZona *proZona = (propZona*) zonDep -> getZonas() -> find(kZona); // encuentra la zona
        proZona -> agregarProp(prop); // añade la prop a la zona
    }

    for(IIterator* iterDep = lista -> getIterator(); iterDep -> hasCurrent(); iterDep -> next()){
        zonasDep *zonaDep = (zonasDep*) iterDep -> getCurrent();
        cout << "  - Departamento: " << zonaDep -> getDepartamento() -> getNombre() << endl;

        IIterator* iterZona = zonaDep -> getZonas() -> getIterator();
        while(iterZona -> hasCurrent()){
            propZona *proZon = (propZona *) iterZona -> getCurrent();
            cout << "    - Zona: " << proZon -> getZona() -> getNombre() << endl;

            IIterator* iterProp = proZon -> getPropiedades() -> getIterator();
            while(iterProp -> hasCurrent()){
                propiedad * prop = (propiedad*) iterProp -> getCurrent();
                cout << "      - Propiedad: " << prop -> getCodigo() << endl;
                iterProp -> next();
            }
            iterZona -> next();
        }
    }
}

propiedad* inmobiliaria::encontrarPropiedad(string codigo){
    IKey *k = new String(codigo.c_str());
    return (propiedad*) this -> propiedades -> find(k);
}
