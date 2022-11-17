#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;



class cuenta
{

    public:
        string nombre;
        string contrasena;
        int edad;

        cuenta();

        void anadirTexto(string nombre);

        bool comprobarArchivo(string ubicacion);
        
        bool compAdmin();

        void login(bool &sesion, string &nameC);

        string getName();

        ~cuenta();

};

class admin : public cuenta
{

    public:

        admin();

        vector<string> mostrarCuentas();

        void eliminarCuentas();
    
        ~admin();

};

class usuario : public cuenta
{
    public:
        string crearCarpeta;
        string direccion1;
        string direccion2;
        string contrasenaConf;

        usuario();

        void crearCuenta(string &nameC);

        ~usuario();
};

class interfazCuenta
{

    public:

        string texto;
        int opt;
        bool bandera;
        bool user;

        interfazCuenta();

        int perdirNum(int &opt, string texto);

        void interfazInicio(usuario jugador, cuenta inicio, admin admin, bool &sesion,string &nameC,bool &inicial);

        void interfazAdmin(admin admin);

};