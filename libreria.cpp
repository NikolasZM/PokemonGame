#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "libreria.hpp"

using namespace std;

// Class cuenta

cuenta::cuenta(){
    nombre = " ";
    contrasena = " ";
    edad = 0;
}

cuenta::cuenta(string _nombre){

    nombre = _nombre;

}

void cuenta::anadirTexto(string nombre){
    ofstream usuarios;

    usuarios.open("usuarios.txt", ios::app); 

    usuarios << nombre << endl;  
            
    usuarios.close();  
}

bool cuenta::comprobarArchivo(string ubicacion){
    ifstream archivo(ubicacion);
    return archivo.good();
}

void cuenta::login(bool &sesion, string &nameC){

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

        cout << "Ingrese su contrasena: ";
        cin >> contrasena;


        ifstream datosCuenta(direccion);
        while (getline(datosCuenta, l)){
            comprobar.push_back(l);
        }

        if (contrasena == comprobar[1]){
            sesion = true;
            nameC=nombre;
            break;
        }else{
            cout << "Contrasena incorrecta vuelva a intentar\n";
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

string cuenta::getName() {
    return nombre;
}

cuenta::~cuenta(){
    nombre = "";
    contrasena = "";
    edad = 0;
}

//  Class Usuario
usuario::usuario(){
    string crearCarpeta{" "};
    string direccion1{" "};
    string direccion2{" "};
    string contrasenaConf{" "};
    
}

usuario::~usuario(){
    string crearCarpeta{" "};
    string direccion1{" "};
    string direccion2{" "};
    string contrasenaConf{" "};
}

void usuario::crearCuenta(string &nameC){



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

    anadirTexto(nombre);

    while(true){
        cout << "Ingrese su contrasena: ";
        cin >> contrasena;
        cout << "Vuelva a ingresar su contrasena: ";
        cin >> contrasenaConf;
        if (contrasena == contrasenaConf){
            break;
        }
        cout << "Las contrasenas deben ser iguales" << "\n";
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
            cout << "Solo para mayores de 7 anos" << "\n";
        }
    }

    ofstream datos(direccion1);
    datos.close();

    ofstream datosCuenta(direccion2);

    datosCuenta << nombre << "\n";
    datosCuenta << contrasena << "\n";

    datosCuenta.close();

    nameC = nombre;
}


//  Class Admin

admin::admin(){
    string nombreContrasena{"admin"};
    string direccion{"admin/datosCuenta.txt"};
    string l;

    ifstream usuarios("usuarios.txt");
    while(getline(usuarios, l))
    {

        cuentas.push_back(l);
    }

    if (comprobarArchivo(direccion)){
        return;
    }else{
        system("MD admin");

        ofstream datosCuenta(direccion);

            datosCuenta << nombreContrasena << "\n";
            datosCuenta << nombreContrasena << "\n";

        datosCuenta.close();
        anadirTexto(nombreContrasena);
    }
}

void admin::mostrarCuentas(){
            


    for (int i{1}; i < cuentas.size(); ++i)
    {
        cout << "[" << i << "]" << cuentas[i] << "\n";
    }

}

void admin::eliminarCuentas(){
            
    int cuenta;
    string borrar1;
    string borrar2;
    string aux;
    string l;

    mostrarCuentas();

    while(true){
        cout << "Escriba el numero de la cuenta que desea borrar: ";
        cin >> cuenta;

        if( !cin.good() ){
            cin.clear();
            cin.ignore();
            cout << "Solo valores numericos" << "\n";
            system("cls");
        }

        if(cuenta < cuentas.size())
        {
            borrar1 = "del " + cuentas[cuenta];
            borrar2 = "rmdir " + cuentas[cuenta];
            
            system(borrar1.c_str());
            system(borrar2.c_str());
            system("del usuarios.txt");
                    

            cuentas.erase(cuentas.begin()+ cuenta);

            for(int i{0}; i <= cuentas.size(); ++i){

                if((i == cuentas.size())&&(i != 0)){
                    break;
                }    

                anadirTexto(cuentas[i]);

            }


            break;
        }else{
            cout << "Seleccione una opcion valida";
        }

            
    }
}

void admin::entrarCuenta(bool &sesion, string &nameC){

    int cuenta;

    mostrarCuentas();

    while(true){
        cout << "Escriba el numero de la cuenta que desea ingresar: ";
        cin >> cuenta;

        if( !cin.good() ){
            cin.clear();
            cin.ignore();
            cout << "Solo valores numericos" << "\n";
            system("cls");
        }

        nombre = cuentas[cuenta];
        sesion = true;
        nameC=nombre;
        
        break;

    }


}

admin::~admin(){
}


// Class interfazCuenta

interfazCuenta::interfazCuenta(){
    texto = " ";
    opt = 0;
    bandera = false;
}

int interfazCuenta::perdirNum(int &opt, string texto){
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

void interfazCuenta::interfazInicio(usuario jugador,cuenta inicio, admin admin, bool &sesion, string &nameC, bool &inicial){

    texto = "Ingrese:\n\t[1]Login\n\t[2]Crear Cuenta\n\t[Otro]salir\n\n>>>> ";

    perdirNum(opt, texto);     

    switch (opt-1)
    {
    case 0:
        inicio.login(sesion,nameC);
        bandera = inicio.compAdmin();
        break;
    case 1:
        jugador.crearCuenta(nameC);
        sesion=true;
        inicial = true;
        break;
    default:
        break;
    }
}

void interfazCuenta::interfazAdmin(admin admin, bool &sesion, string &nameC){
    if (bandera)
    {
    
        system("cls");

        opt = 0;
        texto = "Que desea hacer:\n\t[1]Ver cuentas\n\t[2]Eliminar cuenta\n\t[3]Entrar a la cuenta\n\t[Otro]Salir\n\t>>>> ";

        perdirNum(opt, texto);

        switch (opt-1)
        {
        case 0:
            system("cls");
            admin.mostrarCuentas();
            break;
        case 1:
            admin.eliminarCuentas();
            break;
        case 2:
            admin.entrarCuenta(sesion, nameC);
            break;
        default:
            break;
        }

    }
}