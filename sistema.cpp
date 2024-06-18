#include "sistema.h"

// CONSTRUCTOR:
sistema * sistema::instance = NULL;

sistema * sistema::getInstance() {
    if (instance == NULL)
        instance = new sistema();
    return instance;
}

sistema::sistema(){
    this -> departamentos = new OrderedDictionary();
    this -> usuarios = new OrderedDictionary();
    this -> usuarioActual = NULL;
    this -> departamentoActual = NULL;
    this -> zonaActual = NULL;
    this -> edificioActual = NULL;

    administrador *admin = new administrador("admin", "admin");
    IKey *key = new String(admin -> getCorreo().c_str());
    usuarios -> add(key, admin);

    departamento* canelones = new departamento("Canelones", 'A');
    departamento* maldonado = new departamento("Maldonado", 'B');
    departamento* rocha = new departamento("Rocha", 'C');
    departamento* treintaYTres = new departamento("Treinta y Tres", 'D');
    departamento* cerroLargo = new departamento("Cerro Largo", 'E');
    departamento* rivera = new departamento("Rivera", 'F');
    departamento* artigas = new departamento("Artigas", 'G');
    departamento* salto = new departamento("Salto", 'H');
    departamento* paysandu = new departamento("Paysandú", 'I');
    departamento* rioNegro = new departamento("Rio Negro", 'J');
    departamento* soriano = new departamento("Soriano", 'K');
    departamento* colonia = new departamento("Colonia", 'L');
    departamento* sanJose = new departamento("San José", 'M');
    departamento* flores = new departamento("Flores", 'N');
    departamento* florida = new departamento("Florida", 'O');
    departamento* lavalleja = new departamento("Lavalleja", 'P');
    departamento* durazno = new departamento("Durazno", 'Q');
    departamento* tacuarembo = new departamento("Tacuarembó", 'R');
    departamento* montevideo = new departamento("Montevideo", 'S');
    IKey *k = new String("A");
    departamentos -> add(k, canelones);
    k = new String("B");
    departamentos -> add(k, maldonado);
    k = new String("C");
    departamentos -> add(k, rocha);
    k = new String("D");
    departamentos -> add(k, treintaYTres);
    k = new String("E");
    departamentos -> add(k, cerroLargo);
    k = new String("F");
    departamentos -> add(k, rivera);
    k = new String("G");
    departamentos -> add(k, artigas);
    k = new String("H");
    departamentos -> add(k, salto);
    k = new String("I");
    departamentos -> add(k, paysandu);
    k = new String("J");
    departamentos -> add(k, rioNegro);
    k = new String("K");
    departamentos -> add(k, soriano);
    k = new String("L");
    departamentos -> add(k, colonia);
    k = new String("M");
    departamentos -> add(k, sanJose);
    k = new String("N");
    departamentos -> add(k, flores);
    k = new String("O");
    departamentos -> add(k, florida);
    k = new String("P");
    departamentos -> add(k, lavalleja);
    k = new String("Q");
    departamentos -> add(k, durazno);
    k = new String("R");
    departamentos -> add(k, tacuarembo);
    k = new String("S");
    departamentos -> add(k, montevideo);
}

// DESTRUCTOR:
sistema::~sistema(){
    cout << "¡NO HAY SISTEMA!" << endl;
}

// FUNCIONALIDADES:
bool sistema::enviarCorreo(string correo){
    if(this -> usuarioActual != NULL){
        throw invalid_argument("Ya hay una sesión iniciada, cierre la seisón actual y vuelva a intentarlo\n");
    }
    IKey * k = new String(correo.c_str());
    usuario *user =(usuario*) usuarios -> find(k);
    delete k;
    if(user == NULL){
        throw invalid_argument("Ningun administrador ha registrado este correo, contáctese con administración y vuelva a intentarlo\n");
    }
    usuarioActual = user;
    return user -> getContrasenia() == "";
}

void sistema::establecerContra(string contra, string repContra){
    if(contra != repContra){
        throw invalid_argument ("Las contraseñas ingresadas no coinciden\n");
    }
    usuarioActual -> setContrasenia(contra);
}

void sistema::verificarContra(string contra){
    if(contra != usuarioActual -> getContrasenia()){
        throw invalid_argument ("La contrasenia o el usuario es incorrecto\n");
    }
}

void sistema::sesionCerrada(){
    if (usuarioActual != NULL){
        throw invalid_argument ("Ya hay sesión iniciada, cierre sesión y vuelva a intentarlo\n");
    }
}

void sistema::sesionAbierta(){
    if (usuarioActual == NULL){
        throw invalid_argument ("No hay sesión iniciada, inicie sesión y vuelva a intentarlo\n");
    }
}

void sistema::cerrarSesion(){
    this -> sesionAbierta();
    this -> usuarioActual = NULL;
}

void sistema::confirmarAdmin(){
    if(usuarioActual == NULL || usuarioActual -> getCorreo() != "admin"){
        throw invalid_argument("Debes registrarte como administrador para realizar esta acción\n");
    }
}

void sistema::confirmarInmobiliaria(){
    if(usuarioActual == NULL || ! dynamic_cast<inmobiliaria*>(usuarioActual)){
        throw invalid_argument("Debes registrarte como inmobiliaira para realizar esta acción\n");
    }
}

void sistema::confirmarInteresado(){
    if(usuarioActual == NULL || ! dynamic_cast<interesado*>(usuarioActual)){
        throw invalid_argument("Debes registrarte como interesado para realizar esta acción\n");
    }
}

void sistema::ingresarInmobiliaria(string correo, direccion * dir, string nombre){
    if(correo == "" || nombre == "" || dir->getCalle() == "" || dir->getCiudad() == "" || dir->getNumero() == ""){
        throw invalid_argument("Alguno de los datos ingresados no es válido\n");
    }
    IIterator *iter = this -> usuarios -> getIterator();
    while(iter -> hasCurrent()){
        inmobiliaria* inmo = (inmobiliaria*) iter -> getCurrent();
        if(inmo != NULL){
            try{
                direccion * dir = inmo -> getDireccion();
                if(inmo -> getNombre() == nombre){
                    throw invalid_argument("nombre duplicado");
                }
            }catch(exception& e){
                if(strcmp(e.what(), "nombre duplicado") == 0){
                    throw invalid_argument("Ya se ha ingresado una inmobiliaria con este nombre\n");
                }
            }
        }
        iter -> next();
    }
    delete iter;

    IKey *k = new String(correo.c_str());
    if(this -> usuarios -> member(k)){
        delete k;
        throw invalid_argument("Ya se ha ingresado un usuario con este correo\n");
    }

    inmobiliaria *inmo = new inmobiliaria(correo, "", nombre, dir);
    this -> usuarios -> add(k, inmo);
}

void sistema::ingresarInteresado(string correo, int edad, string nombre, string apellido){
    if(correo == "" || nombre == "" || apellido == "" || edad < 18){
        throw invalid_argument("Alguno de los datos ingresados no es válido\n");
    }
    IKey *k = new String(correo.c_str());
    if(this -> usuarios -> member(k)){
        throw invalid_argument("Ya se ha ingresado un usuario con este correo\n");
    }
    interesado *inter = new interesado(correo, "", edad, nombre, apellido);
    this -> usuarios -> add(k, inter);
}

void sistema::listarDepartamentos(){
    cout << "Departamentos:" << endl;
    IIterator* iter = departamentos -> getIterator();
    while(iter -> hasCurrent()){
        departamento *dep = (departamento*) iter -> getCurrent();
        cout << dep;
        iter -> next();
    }
    delete iter;
}

void sistema::seleccionarDepartamento(string depSelec){
    IKey *k = new String(depSelec.c_str());
    if(!departamentos -> member(k)){
        delete k;
        throw invalid_argument("Se ingresó un departamento no válido\n");
    }
    departamento *dep = (departamento*) departamentos -> find(k);
    this -> departamentoActual = dep;
}

void sistema::ingresarZona(string nombre, string codigo){
    if(this -> departamentoActual == NULL){
        throw invalid_argument("Debes seleccionar un departamento antes de poder realizar esta acción\n");
    }
    departamentoActual -> agregarZona(nombre, codigo);
}

void sistema::listarZonas(){
    if(departamentoActual == NULL){
        throw invalid_argument("Debes seleccionar un departamento antes de poder realizar esta acción\n");
    }
    cout << "\nDepartamento: " << departamentoActual -> getNombre() << endl;
    cout << "Zonas:" << endl;
    if (departamentoActual -> getZonas() -> getSize() == 0){
        cout << "\tNo hay zonas registradas en este departamento" << endl;
    }else{
        IIterator* iter = departamentoActual -> getZonas() -> getIterator();
        while(iter -> hasCurrent()){
            zona *z = (zona*) iter -> getCurrent();
            cout << z;
            iter -> next();
        }
        delete iter;
    }
}

void sistema::seleccionarZona(string zonaSeleccionada){
    IKey *k = new String(zonaSeleccionada.c_str());
    if(!departamentoActual -> getZonas() -> member(k)){
        delete k;
        throw invalid_argument("Se ingresó una zona no válida\n");
    }
    zona *z = (zona*) departamentoActual -> getZonas() -> find(k);
    this -> zonaActual = z;
}

void sistema::ingresarEdificio(string nombre, int cantPisos, int gastosComunes){
    if(this -> zonaActual == NULL){
        throw invalid_argument("Debe ingresar una zona antes de poder realizar esta acción\n");
    }
    this -> zonaActual -> agegarEdificio(nombre, cantPisos, gastosComunes);
}

void sistema::listarEdificios(){
    if(zonaActual == NULL){
        throw invalid_argument("Debe ingresar una zona antes de poder realizar esta acción\n");
    }
    cout << "\nDepartamento: " << departamentoActual -> getNombre() << endl;
    cout << "Zona: " << zonaActual -> getNombre() << endl;
    cout << "Edificios:" << endl;
    if(zonaActual -> listarEdificios() -> getSize() == 0){
        cout << "\tNo hay edificios registrados en esta zona\n";
    }else{
        IIterator* iter = zonaActual -> listarEdificios() -> getIterator();
        while(iter -> hasCurrent()){
            edificio *ed = (edificio*) iter -> getCurrent();
            cout << ed;
            iter -> next();
        }
        delete iter;
    }
}

void sistema::seleccionarEdificio(string edSelec){
    IKey *k = new String(edSelec.c_str());
    if(!zonaActual -> listarEdificios() -> member(k)){
        delete k;
        throw invalid_argument("Se ingresó un edificio no válido\n");
    }
    edificio *ed = (edificio*) zonaActual -> listarEdificios() -> find(k);
    this -> edificioActual = ed;
}

void sistema::ingresarDatosApartamento(string codigo, int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2){
    confirmarInmobiliaria();
    if( zonaActual == NULL || edificioActual == NULL){
        throw invalid_argument("Debe seleccionar un edificio para continuar con el proceso\n");
    }
    IKey *k = new String(codigo.c_str());
    if (zonaActual -> listarPropiedades() -> member(k)){
        delete k;
        throw invalid_argument("Ya existe una propiedad con este código");
    }
    delete k;
    ((inmobiliaria*) usuarioActual) -> IngresarDatosApartamento(codigo, cantAmb, cantDorm, cantBa, garage, dir, m2, this -> zonaActual, this -> edificioActual);
    
}

void sistema::ingresarDatosCasa(string codigo, int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2, int m2V){
    confirmarInmobiliaria();
    if(zonaActual == NULL){
        throw invalid_argument("Debes seleccionar una zona para continuar con el proceso\n");
    }
    ((inmobiliaria*) usuarioActual) -> IngresarDatosCasa(codigo, cantAmb, cantDorm, cantBa, garage, dir, m2, m2V, this -> zonaActual);
}

void sistema::ingresarPrecioAlquiler(string codigo, int valorAlqui){
    confirmarInmobiliaria();
    ((inmobiliaria*) usuarioActual) -> IngresarPrecioAlquiler(codigo, valorAlqui);
}

void sistema::ingresarPrecioVenta(string codigo, int valorVenta){
    confirmarInmobiliaria();
    ((inmobiliaria*) usuarioActual) -> IngresarPrecioVenta(codigo, valorVenta);
}

void sistema::finalizarAlta(){
    this -> departamentoActual = NULL;
    this -> zonaActual = NULL;
    this -> edificioActual = NULL;
}

void sistema::listarPropiedades(){
    if(zonaActual == NULL){
        throw invalid_argument("Debe seleccionar una zona para continuar con el proceso\n");
    }
    cout << "\nDepartamento: " << departamentoActual -> getNombre() << endl;
    cout << "Zona: " << zonaActual -> getNombre() << endl;
    cout << "Apartamentos:" << endl;
    if(zonaActual -> listarEdificios() -> getSize() == 0){
        cout << "\tNo hay edificios en esta zona\n";
    }else{
        IIterator* iter = zonaActual -> listarEdificios() -> getIterator();
        while(iter -> hasCurrent()){
            edificio *ed = (edificio*) iter -> getCurrent();
            if(ed -> getApartamentos() -> getSize() > 0){
                cout << ed;
                IIterator *iterProp = ed -> getApartamentos() -> getIterator();
                while(iterProp -> hasCurrent()){
                    apartamento* ap = (apartamento*) iterProp -> getCurrent();
                    cout << "\t\t" << ap;
                    iterProp -> next();
                }
                delete iterProp;
            }
            iter -> next();
        }
        delete iter;
    }
    cout << "Casas:" << endl;
    if(zonaActual -> listarPropiedades() -> getSize() == 0){
        cout << "\tNo hay propiedades en esta zona\n";
    }else{
        for(IIterator* iter = zonaActual -> listarPropiedades() -> getIterator(); iter -> hasCurrent(); iter -> next()){
            if(dynamic_cast<casa*>(iter -> getCurrent())){
                casa *c = (casa*) iter -> getCurrent();           
                if(c != NULL){
                    cout << c;
                }
            }
        }
    }
}

void sistema::infoPropInmo(string propiedadSelec){
    propiedad* prop = zonaActual -> seleccionarPropiedad(propiedadSelec);
    if(prop == NULL){
        throw invalid_argument("Se ingresó una propiedad no válida\n");
    }
    dtPropiedadInmo *dt = new dtPropiedadInmo(prop -> getCodigo(), prop -> getCantAmbientes(), prop -> getCantDormitorios(), prop -> getCantBanios(), prop -> getGarage(), prop -> getM2Edificados(), prop -> getDireccion(), prop -> getPrecioVenta() > 0, prop -> getPrecioAlquiler() > 0, prop -> getInmobiliaria());
    cout << dt;
    dt -> ~dtPropiedadInmo();
}

bool sistema::depTieneZona(){
    if(this -> departamentoActual == NULL){
        throw invalid_argument("Debes seleccionar un departamento antes de poder realizar esta acción\n");
    }
    return this -> departamentoActual -> getZonas() -> getSize() > 0;
}

bool sistema::zonaTieneProp(){
    if(this -> zonaActual == NULL){
        throw invalid_argument("Debes seleccionar una zona antes de poder realizar esta acción\n");
    }
    return this -> zonaActual -> listarPropiedades() -> getSize() > 0;
}

bool sistema::ingresarCodigoProp(string codigo){
    confirmarInmobiliaria();
    inmobiliaria *inmo = (inmobiliaria* ) usuarioActual;
    propiedad* prop = inmo -> encontrarPropiedad(codigo);
    if(prop == NULL){
        throw invalid_argument("Se ingresó una propiedad no válida\n");
    }
    return dynamic_cast<casa*>(prop);
}

void sistema::imprimirPropsInmo(){
    confirmarInmobiliaria();
    IIterator *iterDep = departamentos -> getIterator();
    while (iterDep -> hasCurrent()){
        departamento *dep = (departamento *) iterDep -> getCurrent();
        IIterator *iterZ = dep -> getZonas() -> getIterator();
        while(iterZ -> hasCurrent()){
            zona* z = (zona*) iterZ -> getCurrent();
            IIterator* iterProp = z -> listarPropiedades() -> getIterator();
            while(iterProp -> hasCurrent()){
                propiedad* prop = (propiedad *) iterProp -> getCurrent();
                if(prop -> getInmobiliaria() == usuarioActual -> getCorreo()){
                    cout << prop;
                }
                iterProp -> next();
            }
            delete iterProp;
            iterZ -> next();
        }
        delete iterZ;
        iterDep -> next();
    }
    delete iterDep;
}

void sistema::modificarApartamento(string codigo, int cantAmb, int cantDorm, int cantBa, bool garage, int m2, int precioAlq, int precioVenta){
    inmobiliaria *inmo = (inmobiliaria* ) usuarioActual;
    inmo -> ModificarDatosApartamento(codigo, cantAmb, cantDorm, cantBa, garage, m2, precioAlq, precioVenta);
}

void sistema::modificarCasa(string codigo, int cantAmb, int cantDorm, int cantBa, bool garage, int m2, int m2V, int precioAlq, int precioVenta){
    inmobiliaria *inmo = (inmobiliaria* ) usuarioActual;
    inmo -> ModificarDatosApartamento(codigo, cantAmb, cantDorm, cantBa, garage, m2, precioAlq, precioVenta);
}

void sistema::borrarProp(string codigo){
    inmobiliaria *inmo = (inmobiliaria* ) usuarioActual;
    inmo -> BorrarPropiedad(codigo);
}

void sistema::listarPropMens(){
    IIterator *iter = zonaActual -> listarPropMens(this -> usuarioActual -> getCorreo()) -> getIterator();
    cout << endl;
    while(iter -> hasCurrent()){
        cout << (mensajesPropiedad *) iter -> getCurrent();
        iter -> next();
    }
}

void sistema::listarMensajes(string propSeleccionada){
    propiedad *prop = this -> zonaActual -> seleccionarPropiedad(propSeleccionada);
    registroMensajes *mensj = prop -> MostrarMensajes(this -> usuarioActual -> getCorreo());
    if(mensj == NULL){
        crearChat(propSeleccionada);
        mensj = prop -> MostrarMensajes(this -> usuarioActual -> getCorreo());
    }
    cout << mensj;
}

void sistema::crearChat(string propSeleccionada){
    propiedad *prop = this -> zonaActual -> seleccionarPropiedad(propSeleccionada);
    prop -> CrearChat(this -> usuarioActual -> getCorreo());
}

void sistema::ingresarMensaje(string mensaje, string codigo){
    confirmarInteresado();
    if (this -> zonaActual == NULL) {
        throw invalid_argument("Debe seleccionar una zona válida\n");
    }
    IKey* k = new String(codigo.c_str());
    propiedad* prop = (propiedad*) zonaActual -> listarPropiedades() -> find(k);
    prop -> IngresarMensaje(usuarioActual -> getCorreo(), usuarioActual->getCorreo() + ": " + mensaje);
    delete k;
}

void sistema::listarMensajesRecientes(){
    confirmarInmobiliaria();
    IDictionary *chatsInmo = new OrderedDictionary();
    IIterator *iterDep = departamentos -> getIterator();
    while (iterDep -> hasCurrent()){
        departamento *dep = (departamento *) iterDep -> getCurrent();
        IIterator *iterZ = dep -> getZonas() -> getIterator();
        while(iterZ -> hasCurrent()){
            zona* z = (zona*) iterZ -> getCurrent();
            IIterator* iterProp = z -> listarPropiedades() -> getIterator();
            while(iterProp -> hasCurrent()){
                propiedad* prop = (propiedad *) iterProp -> getCurrent();
                if(prop -> getInmobiliaria() == usuarioActual -> getCorreo()){
                    IIterator *iterChat = prop -> getChats() -> getIterator();
                    while(iterChat -> hasCurrent()){
                        chat* c = (chat *) iterChat -> getCurrent();
                        IKey *k = new String ((c -> ultimoMens()).c_str());
                        chatsInmo -> add(k, c);
                        iterChat -> next();
                    }
                    delete iterChat;
                }
                iterProp -> next();
            }
            delete iterProp;
            iterZ -> next();
        }
        delete iterZ;
        iterDep -> next();
    }
    delete iterDep;
    IIterator *iter = chatsInmo -> getIterator();
    while(iter -> hasCurrent()){
        chat * c= (chat *) iter -> getCurrent();
        cout << c -> getPropiedad() << "\tINTERESADO: " << c -> getInteresado() << "\n" << c -> ObtenerRegistro() << endl;
        iter -> next();
    }
    delete iter;
}

void sistema::enviarMensajeA(string codigo, string correo, string mensaje){
    confirmarInmobiliaria();
    IKey *k = new String(codigo.c_str());
    IDictionary *chatsInmo = new OrderedDictionary();
    IIterator *iterDep = departamentos -> getIterator();
    while (iterDep -> hasCurrent()){
        departamento *dep = (departamento *) iterDep -> getCurrent();
        IIterator *iterZ = dep -> getZonas() -> getIterator();
        while(iterZ -> hasCurrent()){
            zona* z = (zona*) iterZ -> getCurrent();
            if(z -> listarPropiedades() -> member(k)){
                propiedad* prop = (propiedad *) z -> listarPropiedades() -> find(k);
                delete k;
                departamentoActual = dep;
                zonaActual = z;
                prop -> IngresarMensaje(correo, usuarioActual -> getCorreo() + ": " + mensaje);
            }
            iterZ -> next();
        }
        delete iterZ;
        iterDep -> next();
    }
    delete iterDep;
}

dtInmobiliaria* sistema::mostrarDatosInmo(){
    return NULL;
}

dtPropiedad* sistema::mostrarPropiedad(){
    return NULL;
}