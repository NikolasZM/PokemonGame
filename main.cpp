#include "libreria.hpp"
#include "pokemon.hpp"

int main() {
    system("cls");

    cuenta inicio;
    admin admin;
    usuario jugador;
    bool sesion{false};
    bool inicial{false};
    bool bandera{false};
    string auxName;

    interfazCuenta interfazC;
    
    interfazC.interfazInicio(jugador, inicio, admin, sesion, auxName, inicial);

    interfazC.interfazAdmin(admin, sesion, auxName);

    bandera = inicio.compAdmin();

    //juego

    if ((sesion) && (!bandera)) {
        logoPoke();
        
        Partida jugador1(auxName);
        
        if (inicial) {
            jugador1.introPoke();
        }
        jugador1.setPrincipal();
        while(true) {
            //jugador1.getBase();
            int opt = jugador1.menuJuego();
            switch(opt-1) {
                case 0: {
                int nivelRuta;
                int idSalvaje;

                idSalvaje = jugador1.generaRuta(nivelRuta);
                jugador1.setSalvaje(nivelRuta,idSalvaje);
                jugador1.captura();
                string infoCaptura = jugador1.menuCaptura();

                if (infoCaptura == "") {
                    continue;
                }else {
                    jugador1.savePokemon(infoCaptura);
                }
                break;
                }

                case 1:
                    cout << "=======Tus Pokemons son:==========\n";
                    jugador1.mostrarPokemons();
                break;

                case 2:
                    cout<<"Esta opcion aún no está disponible.\n";
                break;

                default:
                return 0;
                break;
            }
        }

    }else {
        cout<<"Bye.";
    }
}