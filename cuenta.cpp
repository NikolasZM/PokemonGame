#include <bits/stdc++.h>
using namespace std;

int perdirNum(int &opt, string texto){
    while(true){
        cout << texto;
        cin >> opt;
        if( !cin.good() ){
            cin.clear();
            cin.ignore();
            cout << "Solo valores numericos" << "\n";
            system("cls");
        }else{
            return opt;
        }
    }
}

class cuenta
{

    public:
        string nombre;
        string contraseña;
        int edad;

        cuenta(){
            nombre = " ";
            contraseña = " ";
            edad = 0;
        }

        void añadirTexto(string nombre){
            ofstream usuarios;

            usuarios.open("usuarios.txt", ios::app); 

            usuarios << nombre << endl;  
                
            usuarios.close();
        }

        bool comprobarArchivo(string ubicacion){
            ifstream archivo(ubicacion);
            return archivo.good();
        }

        void admin(){
            string nombreContraseña{"admin"};
            string direccion{"admin/datosCuenta.txt"};

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

            while(true){

                cout << "Ingrese su nombre: ";
                cin >> nombre;

                crearCarpeta = "MD " + nombre;
                direccion1 = nombre + "/datos.txt";
                direccion2 = nombre + "/datosCuenta.txt";

                if(system(crearCarpeta.c_str())){
                    continue;
                }else{
                    break;
                }
            }

            añadirTexto(nombre);

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

                if( !cin.good() ){
                    cin.clear();
                    cin.ignore();
                    cout << "Solo numeros\n";
                    continue;
                }

                if (edad > 7){
                    break;
                }else{
                    cout << "Solo para mayores de 7 años" << "\n";
                }
            }

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

        bool compAdmin(){
            if(nombre == "admin"){
                return true;
            }else{
                return false;
            }
        }

        vector<string> mostrarCuentas(){
            
            int i{0};
            vector<string> cuentas;
            string l;

            ifstream usuarios("usuarios.txt");
            while(getline(usuarios, l)){
                cuentas.push_back(l);

                cout << "[" << i+1 << "]" << cuentas[i] << "\n";
                ++i;
                
            }

            return cuentas;

        }

        void eliminarCuentas(){
            
            vector<string> cuentas = mostrarCuentas();
            int cuenta;
            string borrar1;
            string borrar2;
            string aux;
            string l;

            while(true){
                cout << "Escriba el numero de la cuenta que desea borrar: ";
                cin >> cuenta;

                if( !cin.good() ){
                    cin.clear();
                    cin.ignore();
                    cout << "Solo valores numericos" << "\n";
                    system("cls");
                }

                if(cuenta-1 < cuentas.size())
                {
                    borrar1 = "del " + cuentas[cuenta-1];
                    borrar2 = "rmdir " + cuentas[cuenta-1];
                    
                    system(borrar1.c_str());
                    system(borrar2.c_str());
                    system("del usuarios.txt");
                    

                    cuentas.erase(cuentas.begin()+ cuenta - 1);

                    cout <<"tamaño: "<< cuentas.size();

                    for(int i{0}; i <= cuentas.size(); ++i){

                        if((i == cuentas.size())&&(i != 0)){
                            break;
                        }    

                        añadirTexto(cuentas[i]);

                    }


                    break;
                }else{
                    cout << "Seleccione una opcion valida";
                }

            
            }

        }

};


int main()
{
    system("cls");

    int opt{0};
    bool bandera{false};
    string texto = "Ingrese:\n\t[0]Login\n\t[1]Crear Cuenta\n\t[Otro]salir\n\n>>>> ";

    perdirNum(opt, texto);     

    cuenta inicio;
    inicio.admin();

    switch (opt)
    {
    case 0:
        inicio.login();
        bandera = inicio.compAdmin();
        break;
    case 1:
        inicio.crearCuenta();
        break;
    default:
        return 0;
    }

    if (bandera)
    {
    
        system("cls");

        opt = 0;
        texto = "Que desea hacer:\n\t[0]Ver cuentas\n\t[1]Eliminar cuenta\n\t[2]Entrar a la cuenta\n\t[Otro]Salir\n\t>>>> ";

        perdirNum(opt, texto);

        switch (opt)
        {
        case 0:
            system("cls");
            inicio.mostrarCuentas();
            break;
        case 1:
            inicio.eliminarCuentas();
            break;
        case 2:
            break;
        default:
            break;
        }
    }

}

