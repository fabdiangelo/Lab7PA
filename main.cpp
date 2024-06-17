#include "factory.h"
#include "ISistema.h"

void iniciarSesion(ISistema *s);
void cerrarSesion(ISistema *s);
void altaInmobiliaria(ISistema *s);
void altaInteresado(ISistema *s);

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

        cout << "e) Salir" << endl;

        char e;
        cin >> e;
        switch(e){
            case '1': iniciarSesion(s); break;
            case '2': cerrarSesion(s); break;
            case '3': altaInmobiliaria(s); break;
            case '4': altaInteresado(s); break;
            case 'e': continuar = false; break;
            default: cout << "Opción no válida\n"; break;
        }
    }
    return 0;
}


// Errores: cout <<"\n\x1B[91mError:\033[0m\t" << e.what();
// Todo OK: cout << "Se ha registrado como \x1B[92m" << correo << "\033[0m\n";

void iniciarSesion(ISistema *s){
    cout << "Ingrese su correo electrónico: ";
    string correo;
    cin >> correo;
    cout << endl;
    try{
        bool x = s -> enviarCorreo(correo);
        if(x){
            while(x){
                string contr;
                string repContr;
                cout << "Ingrese su nueva contraseña: ";
                cin >> contr;
                cout << endl << "Repita la contraseña: ";
                cin >> repContr;
                cout << endl;
                try {
                    s -> establecerContra(contr, repContr);
                    x = false;
                    cout << "Se ha registrado como \x1B[92m" << correo << "\033[0m\n";
                }catch (exception& e){
                    cout <<"\n\x1B[91mError:\033[0m\t" << e.what();
                    cout << "Presione 1 para volver a intentarlo, o presione culaquier otra tecla para salir: ";
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
                cout << "Ingrese su contraseña: ";
                cin >> contr;
                cout << endl;
                try {
                    s -> verificarContra(contr);
                    x = true;
                    cout << "Se ha registrado como \x1B[92m" << correo << "\033[0m\n";
                }catch (exception& e){
                    cout <<"\n\x1B[91mError:\033[0m\t" << e.what();
                    cout << "Presione 1 para volver a intentarlo, o presione culaquier otra tecla para salir: ";
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
        cout << "Ingerese el correo de la nueva inmobiliaria: ";
        cin >> correo;
        cout << "Ingerese la ciudad en la que se ubica la nueva inmobiliaria: ";
        cin >> ciudad;
        cout << "Ingerese la calle en la que se ubica la nueva inmobiliaria: ";
        cin >> calle;
        cout << "Ingerese el numero en el que se ubica la nueva inmobiliaria: ";
        cin >> numero;
        cout << "Ingerese el nombre de la nueva inmobiliaria: ";
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
        cout << "Ingerese el correo del nuevo interesado: ";
        cin >> correo;
        cout << "Ingerese el nombre del nuevo interesado: ";
        cin >> nombre;
        cout << "Ingerese el apellido del nuevo interesado: ";
        cin >> apellido;
        cout << "Ingerese la edad del nuevo interesado: ";
        cin >> edad;
        s -> ingresarInteresado(correo, edad, nombre, apellido);
        cout << "\nSe ha registrado al interesado \x1B[92m" << nombre << " " << apellido << "\033[0m\n";
    }catch (exception & e){
        cout <<"\n\x1B[91mError:\033[0m\t" << e.what();
    }
}
