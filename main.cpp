#include "factory.h"
#include "ISistema.h"

void iniciarSesion(ISistema *s);

int main() {
    ISistema *s = factory::getSistema();
    system("clear");
    bool continuar = true;
    while(continuar){
        cout << "\n\tBienvenido\n\n";
        cout << "Que es lo que desesa hacer?" << endl;

        cout << "1) Iniciar sesión" << endl;

        cout << "e) Salir" << endl;

        char e;
        cin >> e;
        switch(e){
            case '1': iniciarSesion(s);
            break;
            case 'e': continuar = false;
            break;
            default:
                cout << "Opción no válida" << endl;
            break;
        }
    }
    return 0;
}


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
                    cout << "Se ha registrado como \x1B[21m" << correo << "\033[0m\n";
                }catch (exception& e){
                    cout <<"\x1B[91mError:\033[0m\t" << e.what();
                    cout << "Presione 1 para volver a intentarlo, o presione culaquier otra tecla para salir: ";
                    char continuar;
                    cin >> continuar;
                    if (continuar != '1'){
                        x = false;
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
                    cout << "Se ha registrado como \x1B[21m" << correo << "\033[0m\n";
                }catch (exception& e){
                    cout <<"\x1B[91mError:\033[0m\t" << e.what();
                    cout << "Presione 1 para volver a intentarlo, o presione culaquier otra tecla para salir: ";
                    char continuar;
                    cin >> continuar;
                    if (continuar != '1'){
                        x = false;
                    }
                }
            }
        }
    }catch (exception& e){
        cout <<"\x1B[91mError:\033[0m\t" << e.what();
    }
}
