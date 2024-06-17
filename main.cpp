#include "factory.h"
#include "ISistema.h"

// FUNCIONALIDADES PRINCIPALES:
void iniciarSesion(ISistema *s);
void cerrarSesion(ISistema *s);
void altaInmobiliaria(ISistema *s);
void altaInteresado(ISistema *s);
void altaEdificio(ISistema *s);

// FUNCIONALIDADES AUXILIARES:
string ingresarZona(ISistema *s);

int main() {
    ISistema *s = factory::getSistema();
    system("clear");
    cout << "\n\tBienvenido";
    bool continuar = true;
    while(continuar){
        cout << "\n\nQue es lo que desesa hacer?" << endl;

        cout << "1) Iniciar sesión" << endl;
        cout << "2) Cerrar sesión" << endl;
        cout << "3) Alta Inmobiliaria \x1B[95m(admin)\033[0m\t" << endl;
        cout << "4) Alta Interesado \x1B[95m(admin)\033[0m\t" << endl;
        cout << "5) Alta Edificio \x1B[93m(inmobiliaria)\033[0m\t" << endl;

        cout << "e) Salir\n\n\n\x1B[36m(char):\033[0m Ingrese una de las opciones dadas:";


        char e;
        cin >> e;
        cout << endl;
        switch(e){
            case '1': iniciarSesion(s); break;
            case '2': cerrarSesion(s); break;
            case '3': altaInmobiliaria(s); break;
            case '4': altaInteresado(s); break;
            case '5': altaEdificio(s); break;
            case 'e': continuar = false; break;
            default: cout << "Opción no válida\n"; break;
        }
    }
    return 0;
}


// Errores: cout <<"\n\x1B[91mError:\033[0m\t" << e.what();
// Todo OK: cout << "Se ha registrado como \x1B[92m" << correo << "\033[0m\n";
// Tipo de dato: \x1B[36m(String):\033[0m 

void iniciarSesion(ISistema *s){
    try{
        s -> sesionAbierta();
        cout << "\x1B[36m(string):\033[0m Ingrese su correo electrónico: ";
        string correo;
        cin >> correo;
        bool x = s -> enviarCorreo(correo);
        if(x){
            while(x){
                string contr;
                string repContr;
                cout << "\n\x1B[36m(string):\033[0m Ingrese su nueva contraseña: ";
                cin >> contr;
                cout << endl << "\x1B[36m(string):\033[0m Repita la contraseña: ";
                cin >> repContr;
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
                string contr;
                cout << "\n\x1B[36m(string):\033[0m Ingrese su contraseña: ";
                cin >> contr;
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
        cin >> correo;
        cout << "\n\x1B[36m(string):\033[0m Ingerese la ciudad en la que se ubica la nueva inmobiliaria: ";
        cin >> ciudad;
        cout << "\n\x1B[36m(string):\033[0m Ingerese la calle en la que se ubica la nueva inmobiliaria: ";
        cin >> calle;
        cout << "\n\x1B[36m(string):\033[0m Ingerese el numero en el que se ubica la nueva inmobiliaria: ";
        cin >> numero;
        cout << "\n\x1B[36m(string):\033[0m Ingerese el nombre de la nueva inmobiliaria: ";
        cin >> nombre;
        direccion *dir = new direccion(ciudad, calle, numero);
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
        cin >> correo;
        cout << "\n\x1B[36m(string):\033[0m Ingerese el nombre del nuevo interesado: ";
        cin >> nombre;
        cout << "\n\x1B[36m(string):\033[0m Ingerese el apellido del nuevo interesado: ";
        cin >> apellido;
        cout << "\n\x1B[36m(integer):\033[0m Ingerese la edad del nuevo interesado: ";
        cin >> edad;
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
        cin >> z;
        if (z == "1"){
            z = ingresarZona(s);
        }
        s -> seleccionarZona(z);

        string nombre;
        int cantPisos, gastosComunes;
        cout << "\n\n\x1B[36m(string):\033[0m Ingresa el nombre del nuevo edificio: ";
        cin >> nombre;
        cout << "\n\x1B[36m(integer):\033[0m Ingresa la cantidad de pisos del nuevo edificio: ";
        cin >> cantPisos;
        cout << "\n\x1B[36m(integer):\033[0m Ingresa los gastos comunes del nuevo edificio: ";
        cin >> gastosComunes;
        s -> ingresarEdificio(nombre, cantPisos, gastosComunes);
        cout << "Se ha registrado el edificio \x1B[92m" << nombre << "\033[0m en la zona \x1B[92m" << z << "\033[0m\n";
    }catch(exception& e){
        cout <<"\n\x1B[91mError:\033[0m\t" << e.what();
    }
}


// AUXILIARES:
string ingresarZona(ISistema *s){
    try{
        string nombre, codigo;
        cout << "\n\n\x1B[36m(string):\033[0m Ingrese el nombre de la nueva zona: ";
        cin >> nombre;
        cout << "\n\x1B[36m(string):\033[0m Ingrese el codigo de la nueva zona: ";
        cin >> codigo;
        s -> ingresarZona(nombre, codigo);
        cout << "Se ha ingresado la zona \x1B[92m" << nombre << "\033[0m\n";
        return codigo;
    }catch(exception& e){
        cout <<"\n\x1B[91mError:\033[0m\t" << e.what();
    }
    return "";
}