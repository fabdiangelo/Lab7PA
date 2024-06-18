#include "factory.h"
#include "ISistema.h"
#include <cctype>
#include <algorithm>
#include <limits>

// FUNCIONALIDADES PRINCIPALES:
void iniciarSesion(ISistema *s);
void cerrarSesion(ISistema *s);
void altaInmobiliaria(ISistema *s);
void altaInteresado(ISistema *s);
void altaEdificio(ISistema *s);
void altaPropiedad(ISistema *s);
void consultarPropiedad(ISistema *s);
void modificarPropiedad(ISistema *s);
void eliminarPropiedad(ISistema *s);
void mensajeInteresado(ISistema *s);
void mensajeInmobiliaria(ISistema * s);

// FUNCIONALIDADES AUXILIARES:
string ingresarZona(ISistema *s);
string ingresarEdificio(ISistema *s);
direccion *crearDireccion(string objeto);

// PRECARGA DE DATOS:
void precarga(ISistema* s);

int main() {
    ISistema *s = factory::getSistema();
    system("clear");
    precarga(s);
    cout << "\n\tBienvenido";
    bool continuar = true;
    while(continuar){
        cout << "\n\nQue es lo que desesa hacer?" << endl;

        cout << "1) Iniciar sesión" << endl;
        cout << "2) Cerrar sesión" << endl;
        cout << "3) Alta Inmobiliaria \x1B[95m(admin)\033[0m" << endl;
        cout << "4) Alta Interesado \x1B[95m(admin)\033[0m" << endl;
        cout << "5) Alta Edificio \x1B[93m(inmobiliaria)\033[0m" << endl;
        cout << "6) Alta Propiedad \x1B[93m(inmobiliaria)\033[0m" << endl;
        cout << "7) Consultar Propiedad" << endl;
        cout << "8) Modificar Propiedad \x1B[93m(inmobiliaria)\033[0m" << endl;
        cout << "9) Eliminar Propiedad \x1B[93m(inmobiliaria)\033[0m" << endl;
        cout << "10) Enviar Mensaje \x1B[94m(interesado)\033[0m" << endl;
        cout << "11) Enviar Mensaje \x1B[93m(inmobiliaria)\033[0m" << endl;

        cout << "e) Salir\n\n\n\x1B[36m(string):\033[0m Ingrese una de las opciones dadas: ";
        string e;
        getline(cin, e, '\n');
        cout << endl;

        if(e == "1") iniciarSesion(s);
        else if(e == "2") cerrarSesion(s);
        else if(e == "3") altaInmobiliaria(s);
        else if(e == "4") altaInteresado(s);
        else if(e == "5") altaEdificio(s);
        else if(e == "6") altaPropiedad(s);
        else if(e == "7") consultarPropiedad(s);
        else if(e == "8") modificarPropiedad(s);
        else if(e == "9") eliminarPropiedad(s);
        else if(e == "10") mensajeInteresado(s);
        else if(e == "11") mensajeInmobiliaria(s);
        else if(e == "e") continuar = false;
        else cout << "\x1B[91mError:\033[0m\tOpción no válida\n";
    }
    return 0;
}



// Errores: cout <<"\n\x1B[91mError:\033[0m\t" << e.what();
// Todo OK: cout << "Se ha registrado como \x1B[92m" << correo << "\033[0m\n";
// Tipo de dato: \x1B[36m(String):\033[0m 

// PRINCIPALES:
void iniciarSesion(ISistema *s){
    try{
        s -> sesionCerrada();
        cout << "\x1B[36m(string):\033[0m Ingrese su correo electrónico: ";
        string correo;
        getline(cin, correo, '\n');
        bool x = s -> enviarCorreo(correo);
        if(x){
            while(x){
                string contr;
                string repContr;
                cout << "\n\x1B[36m(string):\033[0m Ingrese su nueva contraseña: ";
                getline(cin, contr, '\n');
                cout << endl << "\x1B[36m(string):\033[0m Repita la contraseña: ";
                getline(cin, repContr, '\n');
                cout << endl;
                try {
                    s -> establecerContra(contr, repContr);
                    x = false;
                    cout << "Se ha registrado como \x1B[92m" << correo << "\033[0m\n";
                }catch (exception& e){
                    cout <<"\n\x1B[91mError:\033[0m\t" << e.what();
                    cout << "\n\x1B[36m(char):\033[0m Presione 1 para volver a intentarlo, o presione culaquier otra tecla para salir: ";
                    char continuar;
                    cin >> continuar;
                    if (continuar != '1'){
                        x = false;
                        s -> cerrarSesion();
                    }
                }
            }
        }else{
            while(!x){
                cout << "\n\x1B[36m(string):\033[0m Ingrese su contraseña: ";
                string contr;
                getline(cin, contr, '\n');
                cout << endl;
                try {
                    s -> verificarContra(contr);
                    x = true;
                    cout << "Se ha registrado como \x1B[92m" << correo << "\033[0m\n";
                }catch (exception& e){
                    cout <<"\n\x1B[91mError:\033[0m\t" << e.what();
                    cout << "\n\x1B[36m(char):\033[0m Presione 1 para volver a intentarlo, o presione culaquier otra tecla para salir: ";
                    char continuar;
                    cin >> continuar;
                    if (continuar != '1'){
                        x = false;
                        s -> cerrarSesion();
                        break;
                    }
                }
            }
        }
    }catch (exception& e){
        cout <<"\n\x1B[91mError:\033[0m\t" << e.what();
    }
}
void cerrarSesion(ISistema *s){
    try {
        s -> cerrarSesion();
        cout << "\x1B[92mLa sesión se ha cerrado\033[0m\n";
    }catch (exception& e){
        cout <<"\n\x1B[91mError:\033[0m\t" << e.what();
    }
}
void altaInmobiliaria(ISistema *s){
    try{
        s -> confirmarAdmin();
        string correo, nombre, ciudad, calle, numero;
        cout << "\n\x1B[36m(string):\033[0m Ingerese el correo de la nueva inmobiliaria: ";
        getline(cin, correo, '\n');
        direccion *dir = crearDireccion("la nueva inmobiliaria");
        cout << "\n\x1B[36m(string):\033[0m Ingerese el nombre de la nueva inmobiliaria: ";
        getline(cin, nombre, '\n');
        s -> ingresarInmobiliaria(correo, dir, nombre);
        cout << "\nSe ha registrado a la inmobiliairia \x1B[92m" << nombre << "\033[0m\n";
    }catch (exception & e){
        cout <<"\n\x1B[91mError:\033[0m\t" << e.what();
    }
}
void altaInteresado(ISistema *s){
    try{
        s -> confirmarAdmin();
        string correo, nombre, apellido;
        int edad;
        cout << "\n\x1B[36m(string):\033[0m Ingerese el correo del nuevo interesado: ";
        getline(cin, correo, '\n');
        cout << "\n\x1B[36m(string):\033[0m Ingerese el nombre del nuevo interesado: ";
        getline(cin, nombre, '\n');
        cout << "\n\x1B[36m(string):\033[0m Ingerese el apellido del nuevo interesado: ";
        getline(cin, apellido, '\n');
        cout << "\n\x1B[36m(integer):\033[0m Ingerese la edad del nuevo interesado: ";
        cin >> edad;
        if( !cin.good() ){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            throw invalid_argument("El campo solicitado debía ser de tipo 'int'\n");
        }
        s -> ingresarInteresado(correo, edad, nombre, apellido);
        cout << "\nSe ha registrado al interesado \x1B[92m" << nombre << " " << apellido << "\033[0m\n";
    }catch (exception & e){
        cout <<"\n\x1B[91mError:\033[0m\t" << e.what();
    }
}
void altaEdificio(ISistema *s){
    try{
        s -> confirmarInmobiliaria();
        s -> listarDepartamentos();
        cout << "\n\x1B[36m(char):\033[0m Ingresa el departamento en el que quieras asignar al edificio: ";
        char d;
        cin >> d;
        if(d >= 97){
            d -= 32;
        }
        string dep (1, d);
        s -> seleccionarDepartamento(dep);
        s -> listarZonas();
        cout << "\n\x1B[36m(string):\033[0m Ingresa la zona en la que quieras asignar al edificio, o presiona 1 para ingresar una zona nueva: ";
        string z;
        getline(cin, z, '\n');
        transform(z.begin(), z.end(), z.begin(), ::toupper);
        if (z == "1"){
            z = ingresarZona(s);
        }
        s -> seleccionarZona(z);

        ingresarEdificio(s);
        cout << "\033[0m en la zona \x1B[92m" << z << "\033[0m\n";
    }catch(exception& e){
        cout <<"\n\x1B[91mError:\033[0m\t" << e.what();
    }
    s -> finalizarAlta();
}
void altaPropiedad(ISistema *s){
    try{
        s -> confirmarInmobiliaria();
        s -> listarDepartamentos();
        cout << "\n\x1B[36m(char):\033[0m Ingresa el departamento en el que quieras asignar al edificio: ";
        char d;
        cin >> d;
        if(d >= 97){
            d -= 32;
        }
        string dep (1, d);
        s -> seleccionarDepartamento(dep);
        s -> listarZonas();
        cout << "\n\x1B[36m(string):\033[0m Ingresa la zona en la que quieras asignar al edificio, o presiona 1 para ingresar una zona nueva: ";
        string z;
        getline(cin, z, '\n');
        transform(z.begin(), z.end(), z.begin(), ::toupper);
        if (z == "1"){
            z = ingresarZona(s);
        }
        s -> seleccionarZona(z);

        cout << "\n\x1B[36m(char):\033[0m Ingrese 0 si desesa dar de alta a una casa y 1 si desea dar de alta a un apartamento: ";
        char casaApart;
        cin >> casaApart;

        string codigo;
        if(casaApart == '1'){ // Apartamento
            s -> listarEdificios();
            cout << "\n\x1B[36m(string):\033[0m Ingresa el edificio en la que quieras asignar al apartamento, o presiona 1 para ingresar un edificio nuevo: ";
            string ed;
            getline(cin, ed, '\n');
            transform(ed.begin(), ed.end(), ed.begin(), ::toupper);
            if(ed == "1"){
                ed = ingresarEdificio(s);
                cout << "\033[0m en la zona \x1B[92m" << z << "\033[0m\n";
            }
            s -> seleccionarEdificio(ed);

            int cantAmb, cantDorm, cantBa, m2;
            bool garage;
            cout << "\n\n\x1B[36m(string):\033[0m Ingresa el codigo del nuevo apartamento: ";
            getline(cin, codigo, '\n');
            cout << "\n\x1B[36m(integer):\033[0m Ingresa la cantidad de ambientes del nuevo apartamento: ";
            cin >> cantAmb;
            if( !cin.good() ){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw invalid_argument("El campo solicitado debía ser de tipo 'int'\n");
            }
            cout << "\n\x1B[36m(integer):\033[0m Ingresa la cantidad de dormitorios del nuevo apartamento: ";
            cin >> cantDorm;
            if( !cin.good() ){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw invalid_argument("El campo solicitado debía ser de tipo 'int'\n");
            }
            cout << "\n\x1B[36m(integer):\033[0m Ingresa la cantidad de ambientes del nuevo apartamento: ";
            cin >> cantBa;
            if( !cin.good() ){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw invalid_argument("El campo solicitado debía ser de tipo 'int'\n");
            }
            cout << "\n\x1B[36m(bool):\033[0m Indica si el nuevo apartamento tiene garage (1 | 0): ";
            cin >> garage;
            if( !cin.good() ){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw invalid_argument("El campo solicitado debía ser de tipo 'bool' (0 | 1)\n");
            }
            direccion *dir = crearDireccion("el nuevo apartamento");
            cout << "\n\x1B[36m(integer):\033[0m Ingresa la cantidad de metros cuadrados del nuevo apartamento: ";
            cin >> m2;
            if( !cin.good() ){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw invalid_argument("El campo solicitado debía ser de tipo 'int'\n");
            }
            s -> ingresarDatosApartamento(codigo, cantAmb, cantDorm, cantBa, garage, dir, m2);
        }else if(casaApart == '0'){ // Casa
            int cantAmb, cantDorm, cantBa, m2, m2V;
            bool garage;
            cout << "\n\n\x1B[36m(string):\033[0m Ingresa el codigo de la nueva casa: ";
            getline(cin, codigo, '\n');
            cout << "\n\x1B[36m(integer):\033[0m Ingresa la cantidad de ambientes de la nueva casa: ";
            cin >> cantAmb;
            if( !cin.good() ){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw invalid_argument("El campo solicitado debía ser de tipo 'int'\n");
            }
            cout << "\n\x1B[36m(integer):\033[0m Ingresa la cantidad de dormitorios de la nueva casa: ";
            cin >> cantDorm;
            if( !cin.good() ){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw invalid_argument("El campo solicitado debía ser de tipo 'int'\n");
            }
            cout << "\n\x1B[36m(integer):\033[0m Ingresa la cantidad de ambientes de la nueva casa: ";
            cin >> cantBa;
            if( !cin.good() ){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw invalid_argument("El campo solicitado debía ser de tipo 'int'\n");
            }
            cout << "\n\x1B[36m(bool):\033[0m Indica si la nueva casa tiene garage (1 | 0): ";
            cin >> garage;
            if( !cin.good() ){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw invalid_argument("El campo solicitado debía ser de tipo 'bool' (0 | 1)\n");
            }
            direccion *dir = crearDireccion("la nueva casa");
            cout << "\n\x1B[36m(integer):\033[0m Ingresa la cantidad de metros cuadrados de la nueva casa: ";
            cin >> m2;
            if( !cin.good() ){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw invalid_argument("El campo solicitado debía ser de tipo 'int'\n");
            }
            cout << "\n\x1B[36m(integer):\033[0m Ingresa la cantidad de metros cuadrados verdes de la nueva casa: ";
            cin >> m2V;
            if( !cin.good() ){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw invalid_argument("El campo solicitado debía ser de tipo 'int'\n");
            }
            s -> ingresarDatosCasa(codigo, cantAmb, cantDorm, cantBa, garage, dir, m2, m2V);
        }else{
            throw invalid_argument("Opción no válida\n");
        }

        cout << "\n\x1B[36m(char):\033[0m Ingrese 0 si desesa asignarle un valor de alquiler, 1 si desesa asignarle un valor de venta, o 2 si desesa asignarle un valor tanto de venta como de alquiler: ";
        char tipo;
        cin >> tipo;
        if (tipo == '0' || tipo == '2'){
            cout << "\n\n\x1B[36m(integer):\033[0m Ingresa el precio de alquiler: ";
            int valorAlq;
            cin >> valorAlq;
            if( !cin.good() ){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw invalid_argument("El campo solicitado debía ser de tipo 'int'\n");
            }
            s -> ingresarPrecioAlquiler(codigo, valorAlq);
        }
        if (tipo == '1' || tipo == '2'){
            cout << "\n\n\x1B[36m(integer):\033[0m Ingresa el precio de venta: ";
            int valorvent;
            cin >> valorvent;
            if( !cin.good() ){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw invalid_argument("El campo solicitado debía ser de tipo 'int'\n");
            }
            s -> ingresarPrecioAlquiler(codigo, valorvent);
        }
        if(tipo != '0' && tipo != '1' && tipo != '2'){
            throw invalid_argument("Opción no válida\n");
        }
        cout << "\nSe ha registrado la propiedad \x1B[92m" << codigo << "\033[0m\n";
    }catch(exception& e){
        cout <<"\n\x1B[91mError:\033[0m\t" << e.what();
    }
    s -> finalizarAlta();
}
void consultarPropiedad(ISistema *s){
    try{
        s -> sesionAbierta();
        s -> listarDepartamentos();
        cout << "\n\x1B[36m(char):\033[0m Ingresa el departamento en el que se ubique la propiedad: ";
        char d;
        cin >> d;
        if(d >= 97){
            d -= 32;
        }
        string dep (1, d);
        s -> seleccionarDepartamento(dep);
        if(!s -> depTieneZona()){
            throw invalid_argument("No hay zonas registradas en este departamento");
        }
        s -> listarZonas();
        cout << "\n\x1B[36m(string):\033[0m Ingresa la zona en el que se ubique la propiedad: ";
        string z;
        getline(cin, z, '\n');
        transform(z.begin(), z.end(), z.begin(), ::toupper);
        s -> seleccionarZona(z);
        if(!s -> zonaTieneProp()){
            throw invalid_argument("No hay propiedades registradas en esta zona");
        }
        s -> listarPropiedades();
        cout << "\n\x1B[36m(string):\033[0m Ingresa la propiedad de la que quieres obtener más información: ";
        string prop;
        getline(cin, prop, '\n');
        transform(prop.begin(), prop.end(), prop.begin(), ::toupper);
        s -> infoPropInmo(prop);
    }catch (exception &e){
        cout <<"\n\x1B[91mError:\033[0m\t" << e.what();
    }
    s -> finalizarAlta();
}
void modificarPropiedad(ISistema *s){
    try{
        s -> confirmarInmobiliaria();
        s -> imprimirPropsInmo();
        cout << "\n\x1B[36m(string):\033[0m Ingresa el código de la propiedad que desesas modificar: ";
        string codigo;
        getline(cin, codigo, '\n');
        transform(codigo.begin(), codigo.end(), codigo.begin(), ::toupper);
        bool esCasa = s -> ingresarCodigoProp(codigo);

        int cantAmb, cantDorm, cantBa, m2, precioAlq, precioVenta;
        bool garage;
        cout << "\n\x1B[36m(integer):\033[0m Ingresa la nueva cantidad de ambientes de la propiedad: ";
        cin >> cantAmb;
        if( !cin.good() ){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            throw invalid_argument("El campo solicitado debía ser de tipo 'int'\n");
        }
        cout << "\n\x1B[36m(integer):\033[0m Ingresa la nueva cantidad de dormitorios de la propiedad: ";
        cin >> cantDorm;
        if( !cin.good() ){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            throw invalid_argument("El campo solicitado debía ser de tipo 'int'\n");
        }
        cout << "\n\x1B[36m(integer):\033[0m Ingresa la nueva cantidad de ambientes de la propiedad: ";
        cin >> cantBa;
        if( !cin.good() ){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            throw invalid_argument("El campo solicitado debía ser de tipo 'int'\n");
        }
        cout << "\n\x1B[36m(bool):\033[0m Indica si la propiedad tiene garage (1 | 0): ";
        cin >> garage;
        if( !cin.good() ){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            throw invalid_argument("El campo solicitado debía ser de tipo 'bool' (0 | 1)\n");
        }
        cout << "\n\x1B[36m(integer):\033[0m Ingresa la nueva cantidad de metros cuadrados de la propiedad: ";
        cin >> m2;
        if( !cin.good() ){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            throw invalid_argument("El campo solicitado debía ser de tipo 'int'\n");
        }
        cout << "\n\x1B[36m(integer):\033[0m Ingresa el nuevo precio de venta de la propiedad (o 0 en caso de no tenerlo): ";
        cin >> precioVenta;
        if( !cin.good() ){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            throw invalid_argument("El campo solicitado debía ser de tipo 'int'\n");
        }
        cout << "\n\x1B[36m(integer):\033[0m Ingresa el nuevo precio de alquiler de la propiedad (o 0 en caso de no tenerlo): ";
        cin >> precioAlq;
        if( !cin.good() ){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            throw invalid_argument("El campo solicitado debía ser de tipo 'int'\n");
        }
        if(esCasa){
            int m2v;
            cout << "\n\x1B[36m(integer):\033[0m Ingresa la nueva cantidad de metros cuadrados verdes de la propiedad: ";
            cin >> m2v;
            if( !cin.good() ){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw invalid_argument("El campo solicitado debía ser de tipo 'int'\n");
            }
            s -> modificarCasa(codigo, cantAmb, cantDorm, cantBa, garage, m2, m2v, precioAlq, precioVenta);
        }else{
            s -> modificarApartamento(codigo, cantAmb, cantDorm, cantBa, garage, m2, precioAlq, precioVenta);
        }
        cout << "\n\nSe ha modificado la propiedad \x1B[92m" << codigo << "\033[0m con éxito\n";
    }catch (exception& e){
        cout <<"\n\x1B[91mError:\033[0m\t" << e.what();
    }
}
void eliminarPropiedad(ISistema *s){
    try{
        s -> confirmarInmobiliaria();
        cout << "\n\x1B[36m(string):\033[0m Ingresa el código de la propiedad que desesas eliminar: ";
        string codigo;
        getline(cin, codigo, '\n');
        transform(codigo.begin(), codigo.end(), codigo.begin(), ::toupper);
        s -> borrarProp(codigo);
    }catch (exception& e){
        cout <<"\n\x1B[91mError:\033[0m\t" << e.what();
    }
}
void mensajeInteresado(ISistema *s){
    try{
        s -> confirmarInteresado();
        s -> listarDepartamentos();
        cout << "\n\x1B[36m(char):\033[0m Ingresa el departamento en el que se ubique la propiedad: ";
        char d;
        cin >> d;
        if(d >= 97){
            d -= 32;
        }
        string dep (1, d);
        s -> seleccionarDepartamento(dep);
        if(!s -> depTieneZona()){
            throw invalid_argument("No hay zonas registradas en este departamento");
        }
        s -> listarZonas();
        cout << "\n\x1B[36m(string):\033[0m Ingresa la zona en el que se ubique la propiedad: ";
        string z;
        getline(cin, z, '\n');
        transform(z.begin(), z.end(), z.begin(), ::toupper);
        s -> seleccionarZona(z);
        if(!s -> zonaTieneProp()){
            throw invalid_argument("No hay propiedades registradas en esta zona");
        }
        s -> listarPropMens();
        cout << "\n\x1B[36m(string):\033[0m Ingresa la propiedad a la que quieras enviar un mensaje: ";
        string prop;
        getline(cin, prop, '\n');
        transform(prop.begin(), prop.end(), prop.begin(), ::toupper);
        s -> listarMensajes(prop);
        cout << "\n\x1B[36m(string):\033[0m Ingresa el mensaje que quieras enviar, o pulsa 'e' para abortar: ";
        string mens;
        getline(cin, mens, '\n');
        if(mens != "e"){
            s -> ingresarMensaje(mens, prop);
            cout << "\nSe envío el mensaje \x1B[92m" << mens << "\033[0m con éxito\n";
        }
    }catch(exception &e){
        cout <<"\n\x1B[91mError:\033[0m\t" << e.what();
    }
    s -> finalizarAlta();
}
void mensajeInmobiliaria(ISistema * s){

}

// AUXILIARES:
string ingresarZona(ISistema *s){
    try{
        string nombre, codigo;
        cout << "\n\n\x1B[36m(string):\033[0m Ingrese el nombre de la nueva zona: ";
        getline(cin, nombre, '\n');
        cout << "\n\x1B[36m(string):\033[0m Ingrese el codigo de la nueva zona: ";
        getline(cin, codigo, '\n');
        transform(codigo.begin(), codigo.end(), codigo.begin(), ::toupper);
        s -> ingresarZona(nombre, codigo);
        cout << "\nSe ha ingresado la zona \x1B[92m" << nombre << "\033[0m\n";
        return codigo;
    }catch(exception& e){
        cout <<"\n\x1B[91mError:\033[0m\t" << e.what();
    }
    return "";
}
string ingresarEdificio(ISistema *s){
    string nombre;
    int cantPisos, gastosComunes;
    cout << "\n\n\x1B[36m(string):\033[0m Ingresa el nombre del nuevo edificio: ";
    getline(cin, nombre, '\n');
    cout << "\n\x1B[36m(integer):\033[0m Ingresa la cantidad de pisos del nuevo edificio: ";
    if( !cin.good() ){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        throw invalid_argument("El campo solicitado debía ser de tipo 'int'\n");
    }
    cin >> cantPisos;
    cout << "\n\x1B[36m(integer):\033[0m Ingresa los gastos comunes del nuevo edificio: ";
    if( !cin.good() ){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        throw invalid_argument("El campo solicitado debía ser de tipo 'int'\n");
    }
    cin >> gastosComunes;
    s -> ingresarEdificio(nombre, cantPisos, gastosComunes);
    cout << "\nSe ha registrado el edificio \x1B[92m" << nombre;
    return nombre;
}
direccion *crearDireccion(string objeto){
    string ciudad, calle, numero;
    cout << "\n\x1B[36m(string):\033[0m Ingerese la ciudad en la que se ubica " + objeto + ": ";
    getline(cin, ciudad, '\n');
    cout << "\n\x1B[36m(string):\033[0m Ingerese la calle en la que se ubica " + objeto + ": ";
    getline(cin, calle, '\n');
    cout << "\n\x1B[36m(string):\033[0m Ingerese el numero en el que se ubica " + objeto + ": ";
    getline(cin, numero, '\n');
    return new direccion(ciudad, calle, numero);
}

// PRECARGA DE DATOS:
void precarga(ISistema* s){
    s -> enviarCorreo("admin");
    direccion *dir= new direccion("ciudad", "calle", "numero");
    s -> ingresarInmobiliaria("inmo1", dir, "inmo1");
    s -> ingresarInmobiliaria("inmo2", dir, "inmo2");
    s -> ingresarInmobiliaria("inmo3", dir, "inmo3");
    s -> ingresarInteresado("inter1", 18, "interesado", "1");
    s -> ingresarInteresado("inter2", 20, "interesado", "2");
    s -> ingresarInteresado("inter3", 30, "interesado", "3");
    s -> ingresarInteresado("inter4", 40, "interesado", "4");

    s -> cerrarSesion();
    s -> enviarCorreo("inmo1");
    s -> establecerContra("inmo1", "inmo1");
    s -> seleccionarDepartamento("L");
    s -> ingresarZona("zona1", "L1");
    s -> ingresarZona("zona2", "L2");
    s -> ingresarZona("zona3", "L3");
    s -> ingresarZona("zona4", "L4");
    s -> seleccionarZona("L1");
    s -> ingresarEdificio("ed1", 1, 1111);
    s -> ingresarEdificio("ed2", 2, 2222);
    s -> seleccionarEdificio("ed1");
    s -> ingresarDatosApartamento("ap1", 1, 1, 1, true, dir, 1);
    s -> seleccionarEdificio("ed2");
    s -> ingresarDatosApartamento("ap2", 2, 2, 2, false, dir, 2);
    s -> ingresarDatosCasa("ca1", 1, 1, 1, true, dir, 1, 1);
    s -> ingresarDatosCasa("ca2", 2, 2, 2, false, dir, 2, 2);
    s -> ingresarPrecioVenta("ap1", 11111);
    s -> ingresarPrecioAlquiler("ap2", 2222);
    s -> ingresarPrecioVenta("ca1", 111111);
    s -> ingresarPrecioAlquiler("ca2", 22222);
    s -> seleccionarZona("L2");
    s -> ingresarEdificio("ed1", 3, 3333);
    s -> seleccionarEdificio("ed1");
    s -> ingresarDatosApartamento("ap3", 1, 1, 1, true, dir, 1);
    s -> ingresarDatosApartamento("ap4", 2, 2, 2, false, dir, 2);
    s -> ingresarDatosApartamento("ap5", 3, 3, 3, true, dir, 3);
    s -> ingresarDatosApartamento("ap6", 3, 4, 4, false, dir, 4);
    s -> ingresarPrecioVenta("ap1", 11111);
    s -> ingresarPrecioAlquiler("ap2", 2222);
    s -> ingresarPrecioVenta("ap3", 33333);
    s -> ingresarPrecioAlquiler("ap3", 3333);
    s -> seleccionarZona("L3");
    s -> ingresarEdificio("ed1", 4, 4444);
    s -> seleccionarEdificio("ed1");
    s -> ingresarDatosApartamento("ap7", 1, 1, 1, true, dir, 1);
    s -> ingresarDatosCasa("ca3", 1, 1, 1, false, dir, 1, 1);
    s -> ingresarDatosCasa("ca4", 2, 2, 2, true, dir, 2, 2);
    s -> ingresarPrecioVenta("ap1", 11111);
    s -> ingresarPrecioVenta("ca1", 111111);
    s -> ingresarPrecioAlquiler("ca2", 22222);
    s -> cerrarSesion();

    s -> enviarCorreo("inmo2");
    s -> establecerContra("inmo2", "inmo2");
    s -> seleccionarDepartamento("M");
    s -> ingresarZona("zona1", "M1");
    s -> ingresarZona("zona2", "M2");
    s -> ingresarZona("zona3", "M3");
    s -> ingresarZona("zona4", "M4");
    s -> seleccionarZona("M1");
    s -> ingresarEdificio("ed1", 1, 1111);
    s -> ingresarEdificio("ed2", 2, 2222);
    s -> seleccionarEdificio("ed1");
    s -> ingresarDatosApartamento("ap1", 1, 1, 1, false, dir, 1);
    s -> ingresarDatosCasa("ca1", 1, 1, 1, true, dir, 1, 1);
    s -> ingresarDatosCasa("ca2", 2, 2, 2, false, dir, 2, 2);
    s -> ingresarPrecioVenta("ap1", 11111);
    s -> ingresarPrecioAlquiler("ca1", 111111);
    s -> seleccionarDepartamento("L");
    s -> seleccionarZona("L1");
    s -> seleccionarEdificio("ed1");
    s -> ingresarDatosApartamento("ap8", 1, 1, 1, true, dir, 1);
    s -> ingresarDatosCasa("ca5", 1, 1, 1, false, dir, 1, 1);
    s -> cerrarSesion();

    s -> enviarCorreo("inmo3");
    s -> establecerContra("inmo3", "inmo3");
    s -> cerrarSesion();
    s -> finalizarAlta();

    s -> enviarCorreo("inter1");
    s -> establecerContra("inter1", "inter1");
    s -> cerrarSesion();
    s -> enviarCorreo("inter2");
    s -> establecerContra("inter2", "inter2");
    s -> cerrarSesion();
    s -> enviarCorreo("inter3");
    s -> establecerContra("inter3", "inter3");
    s -> cerrarSesion();
    s -> enviarCorreo("inter4");
    s -> establecerContra("inter4", "inter4");
    s -> cerrarSesion();
}
