#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <vector>
#define DF      "\x1B[39m"
#include "pokemon.hpp"

using namespace std;



class Partida{
public:

    Partida(string);

    void setPrincipal();

    void setSalvaje(int,int);

    void setLugar();

    void savePokemon(string);

    bool menuCaptura(string &infoPoke);

    int generaRuta(int &nivel);

    void showMap();

    void mostrarPokemons();

    bool batalla(int);

    string crearInicial();

    void introPoke();

    ~Partida();

    string nombre;
    string lugar;
    char delimitador;
    string basePokemon[151][8];
    string rutasInfo[31][13];
    vector<string> coleccionPokemon;

    Pokemon salvaje;
    Pokemon principal;


};

int perdirOpt();

class InterfazPartida {
public:

    InterfazPartida();

    void logoPoke();

    void interfazJuego(Partida &jugador);

    string interfazCaptura(Partida &jugador);

    int interfazLucha(Partida &jugador);

    int pedirOpt();

    int opt;
};