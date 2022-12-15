#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <vector>
#define DF      "\x1B[39m"
#define RED 	"\x1B[31m"
#define	GREEN 	"\x1B[32m"
#include "pokemon.hpp"

using namespace std;



class Partida{
public:

    Partida(string);

    void setPrincipal();

    void setSalvaje(int,int);

    bool setLugar(int);

    void savePokemon(string);

    bool capturar();

    int generaRuta(int &nivel);

    void showMap();

    void mostrarPokemons();

    void mostrarUnPokemon(int);

    void changePrincipal(int);

    bool compVida();

    bool ataquePrincipal(int);

    void ataqueSalvaje();

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

    void interfazCaptura(Partida &jugador);

    int interfazLucha(Partida &jugador);

    void interfazVerPokemons(Partida &jugador);

    int pedirOpt();

    int opt;
};