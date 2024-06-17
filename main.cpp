#include "factory.h"
#include "ISistema.h"

void iniciarSesion(ISistema *s);
void cerrarSesion(ISistema *s);

int main() {
    ISistema *s = factory::getSistema();
    system("clear");
    cout << "\n\tBienvenido";
    bool continuar = true;
    while(continuar){
        cout << "\n\nQue es lo que desesa hacer?" << endl;

        cout << "1) Iniciar sesión" << endl;
        cout << "2) Cerrar sesión" << endl;

        cout << "e) Salir" << endl;

        char e;
        cin >> e;
        switch(e){
            case '1': iniciarSesion(s); break;
            case '2': cerrarSesion(s); break;
            case 'e': continuar = false; break;
            default: cout << "Opción no válida\n"; break;
        }
    }
    return 0;
}


// Errores: cout <<"\x1B[91mError:\033[0m\t" << e.what();
// Todo OK cout << "Se ha registrado como \x1B[92m" << correo << "\033[0m\n";

void iniciarSesion(ISistema *s){
    cout << "Ingrese su correo electrónico " << endl;
    string correo;
    cin >> correo;
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
                    cout <<"\x1B[91mError:\033[0m\t" << e.what();
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
                    cout <<"\x1B[91mError:\033[0m\t" << e.what();
                    cout << "Presione 1 para volver a intentarlo, o presione culaquier otra tecla para salir: ";
                    char continuar;
                    cin >> continuar;
                    if (continuar != '1'){
                        x = false;
                        s -> cerrarSesion();
                    }
                }
            }
        }
    }catch (exception& e){
        cout <<"\x1B[91mError:\033[0m\t" << e.what();
    }
}
void cerrarSesion(ISistema *s){
    try {
        s -> cerrarSesion();
        cout << "\x1B[92mLa sesión se ha cerrado\033[0m\n";
    }catch (exception& e){
        cout <<"\x1B[91mError:\033[0m\t" << e.what();
    }
}