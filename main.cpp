#include <bits/stdc++.h>
using namespace std;

class cuenta
{

    public:
        string nombre{" "};
        string contraseña{" "};
        int edad{0};

        bool comprobarArchivo(string ubicacion){
            ifstream archivo(ubicacion);
            return archivo.good();
        }

        void admin(){
            string nombreContraseña{"admin"};
            string direccion{"admin/datos.txt"};

            if (comprobarArchivo(direccion)){
                return;
            }else{
                system("MD admin");

                ofstream datosCuenta(direccion);

                    datosCuenta << nombreContraseña << "\n";
                    datosCuenta << nombreContraseña << "\n";

                datosCuenta.close();
            }

        }

        void crearCuenta(){

            string crearCarpeta{" "};
            string direccion1{" "};
            string direccion2{" "};
            string contraseñaConf{" "};

            system("cls");

            cout << "Ingrese su nombre: ";
            cin >> nombre;

            while(true){
                cout << "Ingrese su contraseña: ";
                cin >> contraseña;
                cout << "Vuelva a ingresar su contraseña: ";
                cin >> contraseñaConf;
                if (contraseña == contraseñaConf){
                    break;
                }
                cout << "Las contraseñas deben ser iguales" << "\n";
            }

            while(true){
                cout << "Ingrese su edad: ";
                cin >> edad;
                if (edad > 7){
                    break;
                }
                cout << "Solo para mayores de 7 años" << "\n";
            }


            crearCarpeta = "MD " + nombre;
            direccion1 = nombre + "/datos.txt";
            direccion2 = nombre + "/datosCuenta.txt";

            system(crearCarpeta.c_str());

            ofstream datos(direccion1);
            datos.close();

            ofstream datosCuenta(direccion2);

                datosCuenta << nombre << "\n";
                datosCuenta << contraseña << "\n";

            datosCuenta.close();

        }

        void login(){

            string direccion{" "};
            string l{" "};
            vector<string> comprobar;

            while(true){

                system("cls");

                cout << "Ingrese su nombre: ";
                cin >> nombre;

                direccion = nombre + "/datosCuenta.txt";

                if (!comprobarArchivo(direccion)){
                    cout << "Nombre incorrecto vuelva a intentar\n" ;
                    system("pause");
                    continue;
                }

                cout << "Ingrese su contraseña: ";
                cin >> contraseña;


                ifstream datosCuenta(direccion);
                while (getline(datosCuenta, l)){
                    comprobar.push_back(l);
                }

                if (contraseña == comprobar[1]){
                    break;
                }else{
                    cout << "Contraseña incorrecta vuelva a intentar\n";
                    system("pause");
                    continue;
                }
            }

        }

};

int main()
{
    system("cls");

    int opt{0};

    cuenta inicio;
    inicio.admin();

    cout << "Ingrese:\n[0] Login\n[1]Crear Cuenta\n\n>>>>";
    cin >> opt;

    switch (opt)
    {
    case 1:
        inicio.crearCuenta();
        break;
    case 0:
        inicio.login();
    default:
        return 0;
    }

}

