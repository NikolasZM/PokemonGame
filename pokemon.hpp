#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

#define GREEN "\x1B[32m"
#define OTRO    "\x1B[30m"
#define DF      "\x1B[39m"

class Pokemon {
public:
    Pokemon() ;
    ~Pokemon() ;
    void setInfo(string especiePoke,int nivelPok, int vidaPok,int ataquePok, int defensaPok, string tipo1Pok, string tipo2Pok,string colorPok);
    void getInfo() ;
    void getSprite();
private:
    string especie;
    int nivel;
    string tipo1;
    string tipo2;
    string color;
    int vida;
    int ataque;
    int defensa;
};

void crearInicial(string archivoData);