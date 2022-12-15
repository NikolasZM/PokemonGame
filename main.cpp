#include "libreria.hpp"
#include "partida.hpp"

int main() 
{
    system("cls");

    //Login

    cuenta inicio;
    admin admin;
    usuario jugador;
    bool sesion{false};
    bool inicial{false};
    bool bandera{false};
    string auxName;

    interfazCuenta interfazC;
    
    interfazC.interfazInicio(jugador, inicio, admin, sesion, auxName, inicial);

    interfazC.interfazAdmin(admin,sesion,auxName);

    bandera = inicio.compAdmin();

    //juego

    if ((sesion) && (!bandera)) {
        
        
        Partida jugador1(auxName);
        
        InterfazPartida interfazJ;
        
        interfazJ.logoPoke();
        
       

        
        if (inicial) {
       
            jugador1.introPoke();
        }

        jugador1.setPrincipal();

        interfazJ.interfazJuego(jugador1);


    }else {
        cout<<"Bye.";
    }  


}
