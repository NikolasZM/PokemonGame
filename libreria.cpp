#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "libreria.hpp"

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

cuenta::cuenta(){
    nombre = " ";
    contraseña = " ";
    edad = 0;
}

void cuenta::añadirTexto(string nombre){
    ofstream usuarios;

    usuarios.open("usuarios.txt", ios::app); 

    usuarios << nombre << endl;  
            
    usuarios.close();  

}

bool cuenta::comprobarArchivo(string ubicacion){
    ifstream archivo(ubicacion);
    return archivo.good();
}

void cuenta::admin(){
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

void cuenta::crearCuenta(){

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

void cuenta::login(){

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

bool cuenta::compAdmin(){
    if(nombre == "admin"){
        return true;
    }else{
        return false;
    }
}

vector<string> cuenta::mostrarCuentas(){
            
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

void cuenta::eliminarCuentas(){
            
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

cuenta::~cuenta(){
    nombre = ""
    contraseña = ""
    edad = 0
}

