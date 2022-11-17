#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <vector>
using namespace std;

#define DF      "\x1B[39m"

class Pokemon {
public:

    Pokemon() ;
    
    ~Pokemon() ;
    
    void setInfo(int idPoke, string especiePoke,int nivelPok, int vidaPok,int ataquePok, int defensaPok, string tipo1Pok, string tipo2Pok,string colorPok);
    
    void getInfo() ;
    
    void getSprite(int sangria);
    
    string getDataInfo();
    
    string getEspecie();
    
private:
    int iD;
    string especie;
    int nivel;
    string tipo1;
    string tipo2;
    string color;
    int vida;
    int ataque;
    int defensa;
};



class Partida{
public:

    string nombre;
    Pokemon salvaje;
    Pokemon principal;
    string lugar;
    char delimitador;
    vector<string> coleccionPokemon;
    
    string basePokemon[151][8];
    string rutasInfo[2][10];
    


    Partida(string nameC);

    void setPrincipal();

    void getBase();

    void savePokemon(string infoPokemon);

    void setSalvaje(int niv, int salv) ;

    void captura();

    string menuCaptura();

    int menuJuego ();

    int generaRuta(int &nivel);

    void introPoke();

    string crearInicial();

    void mostrarPokemons();

    ~Partida();
};


//string crearInicial(string archivoData);

void logoPoke();

//void introPoke(Partida &player);

int perdirOpt();