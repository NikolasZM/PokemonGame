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

        void crearCuenta();
        
        bool compAdmin();

        void login();

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

class interfazCuenta
{

    public:

        string texto;
        int opt;
        bool bandera;
        bool user;

        interfazCuenta();

        int perdirNum(int &opt, string texto);

        void interfazInicio(cuenta inicio, admin admin);

        void interfazAdmin(admin admin);

};