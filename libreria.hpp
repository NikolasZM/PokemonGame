#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int perdirNum(int &opt, string texto);


class cuenta
{

    public:
        string nombre;

        cuenta();

        void añadirTexto(string nombre);

        bool comprobarArchivo(string ubicacion);

        void admin();

        void crearCuenta();

        void login();

        bool compAdmin();

        vector<string> mostrarCuentas();

        void eliminarCuentas();

        ~cuenta();

    private:
        string contraseña;
        int edad;
};
