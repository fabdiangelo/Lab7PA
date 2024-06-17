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
    }else{
        IKey * k = new String(correo.c_str());
        usuario *user =(usuario*) usuarios -> find(k);
        if(user == NULL){
            throw invalid_argument("Ningun administrador ha registrado este correo, contáctese con administración y vuelva a intentarlo\n");
        }else{
            usuarioActual = user;
            return user -> getContrasenia() == "";
        }
    }
}

void sistema::establecerContra(string contra, string repContra){
    if(contra == repContra){
        usuarioActual -> setContrasenia(contra);
    }else{
        throw invalid_argument ("Las contraseñas ingresadas no coinciden\n");
    }
}

void sistema::verificarContra(string contra){
    if(contra != usuarioActual -> getContrasenia()){
        throw invalid_argument ("La contrasenia o el usuario es incorrecto\n");
    }
}

void sistema::cerrarSesion(){
    if(this -> usuarioActual == NULL){
        throw invalid_argument ("No había una sesión iniciada\n");
    }else{
        this -> usuarioActual = NULL;
    }
}

dtRespuesta* sistema::ingresarInmobiliaria(string correo, direccion * dir, string nombre){
    inmobiliaria *inmo = new inmobiliaria(correo, "", nombre, dir);
    IKey *k = new String(inmo -> getCorreo().c_str());
    this -> usuarios -> add(k, inmo);
    return new dtRespuesta("Todo OK");
}

dtRespuesta* sistema::ingresarInteresado(string correo, int edad, string nombre, string apellido){
    interesado *inter = new interesado(correo, "", edad, nombre, apellido);
    IKey *k = new String(inter -> getCorreo().c_str());
    this -> usuarios -> add(k, inter);
    return new dtRespuesta("Todo OK");
}

void sistema::listarDepartamentos(){
    cout << "Departamentos:" << endl;
    for(IIterator* iter = departamentos -> getIterator(); iter -> hasCurrent(); iter -> next()){
        departamento *dep = (departamento*) iter -> getCurrent();
        cout << dep;
    }
}

void sistema::seleccionarDepartamento(string depSelec){
    IKey *k = new String(depSelec.c_str());
    departamento *dep = (departamento*) departamentos -> find(k);
    if(dep == NULL){
        cout << "Se ingresó un departamento no válido" << endl;
    }else{
        this -> departamentoActual = dep;
    }
}

void sistema::ingresarZona(string nombre, string codigo){
    if(this -> departamentoActual == NULL){
        cout << "Debes seleccionar un departamento antes" << endl;
    }else{
        departamentoActual -> agregarZona(nombre, codigo);
    }
}

void sistema::listarZonas(){
    if(departamentoActual == NULL){
        cout << "Debes seleccionar un departamento antes" << endl;
    }else{
        cout << "Departamento: " << departamentoActual -> getNombre() << endl;
        cout << "Zonas:" << endl;
        for(IIterator* iter = departamentoActual -> getZonas() -> getIterator(); iter -> hasCurrent(); iter -> next()){
            zona *z = (zona*) iter -> getCurrent();
            cout << z;
        }
    }
}

void sistema::seleccionarZona(string zonaSeleccionada){
    IKey *k = new String(zonaSeleccionada.c_str());
    zona *z = (zona*) departamentoActual -> getZonas() -> find(k);
    if(z == NULL){
        cout << "Se ingresó una zona no válida" << endl;
    }else{
        this -> zonaActual = z;
    }
}

void sistema::ingresarEdificio(string nombre, int cantPisos, int gastosComunes){
    if(this -> zonaActual == NULL){
        cout << "Debe seleccionar una zona antes de poder ingresar un edificio" << endl;
    }else{
        edificio* ed = new edificio(nombre, cantPisos, gastosComunes);
        this -> zonaActual -> agegarEdificio(ed);
    }
}

void sistema::listarEdificios(){
    if(zonaActual == NULL){
        cout << "Debes seleccionar una zona antes" << endl;
    }else{
        cout << "Departamento: " << departamentoActual -> getNombre() << endl;
        cout << "Zona: " << zonaActual -> getNombre() << endl;
        cout << "Edificios:" << endl;
        for(IIterator* iter = zonaActual -> listarEdificios() -> getIterator(); iter -> hasCurrent(); iter -> next()){
            edificio *ed = (edificio*) iter -> getCurrent();
            cout << ed;
        }
    }
}

void sistema::seleccionarEdificio(string edSelec){
    IKey *k = new String(edSelec.c_str());
    edificio *ed = (edificio*) zonaActual -> listarEdificios() -> find(k);
    if(ed == NULL){
        cout << "Se ingresó una zona no válida" << endl;
    }else{
        this -> edificioActual = ed;
    }
}

void sistema::ingresarDatosApartamento(string codigo, int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2){
    inmobiliaria* inmo = (inmobiliaria*) this -> usuarioActual;
    if(inmo == NULL || zonaActual == NULL || edificioActual == NULL){
        cout << "Debe ingresar con una inmobiliaria y un edificio" << endl;
    }else{
        inmo -> IngresarDatosApartamento(codigo, cantAmb, cantDorm, cantBa, garage, dir, m2, this -> zonaActual, this -> edificioActual);
    }
}

void sistema::ingresarDatosCasa(string codigo, int cantAmb, int cantDorm, int cantBa, bool garage, direccion* dir, int m2, int m2V){
    inmobiliaria* inmo = (inmobiliaria*) this -> usuarioActual;
    if(inmo == NULL || zonaActual == NULL){
        cout << "Debe ingresar con una inmobiliaria y un edificio" << endl;
    }else{
        inmo -> IngresarDatosCasa(codigo, cantAmb, cantDorm, cantBa, garage, dir, m2, m2V, this -> zonaActual);
    }
}

void sistema::ingresarPrecioAlquiler(string codigo, int valorAlqui){
    inmobiliaria* inmo = (inmobiliaria*) this -> usuarioActual;
    if(inmo == NULL){
        cout << "debes ingresar como una inmobiliaria" << endl;
    }else{
        inmo -> IngresarPrecioAlquiler(codigo, valorAlqui);
    }
}

void sistema::ingresarPrecioVenta(string codigo, int valorVenta){
    inmobiliaria* inmo = (inmobiliaria*) this -> usuarioActual;
    if(inmo == NULL){
        cout << "debes ingresar como una inmobiliaria" << endl;
    }else{
        inmo -> IngresarPrecioVenta(codigo, valorVenta);
    }
}

void sistema::finalizarAlta(){
    this -> departamentoActual = NULL;
    this -> zonaActual = NULL;
    this -> edificioActual = NULL;
}

void sistema::listarPropiedades(string zonaSeleccionada){
    if(departamentoActual == NULL){
        cout << "Debes seleccionar un departamento antes" << endl;
    }else{
        cout << "Departamento: " << departamentoActual -> getNombre() << endl;
        this -> seleccionarZona(zonaSeleccionada);
        cout << "Zona: " << zonaActual -> getNombre() << endl;

        cout << "Apartamentos:" << endl;
        for(IIterator* iter = zonaActual -> listarEdificios() -> getIterator(); iter -> hasCurrent(); iter -> next()){
            edificio *ed = (edificio*) iter -> getCurrent();
            if(ed ->getApartamentos() ->getSize() > 0){
                cout << ed;
                IIterator *iterProp = ed -> getApartamentos() -> getIterator();
                while(iterProp -> hasCurrent()){
                    apartamento* ap = (apartamento*) iterProp -> getCurrent();
                    cout << "  " << ap;
                    iterProp -> next();
                }
            }
        }
        cout << "Casas:" << endl;
        for(IIterator* iter = zonaActual -> listarPropiedades() -> getIterator(); iter -> hasCurrent(); iter -> next()){
            casa *c = (casa*) iter -> getCurrent();           
            if(c != NULL){
                cout << c;
            }
        }
    }
}

void sistema::infoPropInmo(string propiedadSelec){
    IKey *k = new String(propiedadSelec.c_str());
    propiedad *prop = (propiedad*) zonaActual -> listarPropiedades() -> find(k);
    if(prop == NULL){
        cout << "Se ingresó una propiedad no válida" << endl;
    }else{
        dtPropiedadInmo *dt = new dtPropiedadInmo(prop -> getCodigo(), prop -> getCantAmbientes(), prop -> getCantDormitorios(), prop -> getCantBanios(), prop -> getGarage(), prop -> getM2Edificados(), prop -> getDireccion(), prop -> getPrecioVenta() > 0, prop -> getPrecioAlquiler() > 0, prop -> getInmobiliaria());
        cout << dt;
        dt -> ~dtPropiedadInmo();
    }
}

void sistema::ingresarCodigoProp(string codigo){
    inmobiliaria *inmo = (inmobiliaria* ) usuarioActual;
    if(inmo == NULL){
        cout << "debes ingresar como un usuario inmobiliaria" << endl;
    }else{
        propiedad* prop = inmo -> encontrarPropiedad(codigo);
        if(prop == NULL){
            cout << "debes ingresar el código de una propiedad previamente registrada" << endl;
        }else{
            // modificar
        }
    }
}

void sistema::borrarProp(string codigo){
    inmobiliaria *inmo = (inmobiliaria* ) usuarioActual;
    if(inmo == NULL){
        cout << "Debes ingresar como un usuario inmobiliaria" << endl;
    }else{
        inmo -> BorrarPropiedad(codigo);
    }
}

void sistema::listarPropMens(string zonaSeleccionada){
    seleccionarZona(zonaSeleccionada);
    List* lista = zonaActual -> listarPropMens(this -> usuarioActual -> getCorreo());

    IIterator *iter = lista -> getIterator();
    while(iter -> hasCurrent()){
        cout << iter -> getCurrent();
        iter -> next();
    }
}

void sistema::listarMensajes(string propSeleccionada){
    propiedad *prop = this -> zonaActual -> seleccionarPropiedad(propSeleccionada);
    registroMensajes *mensj = prop -> MostrarMensajes(this -> usuarioActual -> getCorreo());
    List *lista = mensj -> getMensajes();
    
    IIterator *iter = lista -> getIterator();
    while(iter -> hasCurrent()){
        cout << iter -> getCurrent();
        iter -> next();
    }
}

void sistema::crearChat(string propSeleccionada){
    propiedad *prop = this -> zonaActual -> seleccionarPropiedad(propSeleccionada);
    prop -> CrearChat(this -> usuarioActual -> getCorreo());
}

dtRespuesta* sistema::ingresarMensaje(string mensaje){
    if (this->usuarioActual == NULL) {
        cout << "Debe iniciar sesión para enviar un mensaje" << endl;
        return new dtRespuesta("Error: sesión no iniciada");
    }
    if (this->zonaActual == NULL) {
        cout << "Debe seleccionar una zona antes de enviar un mensaje" << endl;
        return new dtRespuesta("Error: zona no seleccionada");
    }
    // if (this->propiedadActual == NULL) {
    //     cout << "Debe seleccionar una propiedad antes de enviar un mensaje" << endl;
    //     return new dtRespuesta("Error: propiedad no seleccionada");
    // }
    // string emisor = this->usuarioActual->getCorreo();
    // string receptor = this->propiedadActual->getInmobiliaria()->getCorreo();
    // Mensaje *mensaje = new Mensaje(emisor, receptor, mensaje);
    // this->propiedadActual->agregarMensaje(mensaje);
    return new dtRespuesta("Mensaje enviado correctamente");
}

void sistema::listarMensajesRecientes(){
}

dtInmobiliaria* sistema::mostrarDatosInmo(){
    return NULL;
}

dtPropiedad* sistema::mostrarPropiedad(){
    return NULL;
}