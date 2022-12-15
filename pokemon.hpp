#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <sstream>
#define DF "\x1B[39m"

using namespace std;


class Movimiento {
public:

    Movimiento();

    void setInfo(string,int);
    
    string getName();

    int getPrecision();

    ~Movimiento();


    string nombre;
    int precision;
    
};

class MovDaño : public Movimiento {
public:

    MovDaño();
    void setInfo(int,int,string,string);
    int getPotencia();
    string getTipo();
    ~MovDaño();

    int potencia;
    string tipo;
};

class MovEstado : public Movimiento {
public:

    MovEstado();
    void setInfo(string,int,string);
    string getEstadistica();
    ~MovEstado();

    string estadistica;

};

class Pokemon {
public:

    Pokemon() ;
    
    void setInfo(int idPoke, string especiePoke,int nivelPok, int vidaPok,int ataquePok, int defensaPok, string tipo1Pok, string tipo2Pok,string colorPok);
    
    void showInfo();

    string getEspecie();

    int getNivel();

    int getVida();

    int getAtaque();

    int getDefensa();

    string getInfo();

    void showSprite(int);

    void curar();

    void daño(int);

    bool compStab(int);

    ~Pokemon();

    MovDaño Mov1[2];
    MovEstado Mov2[2];

private:
    int iD;
    string especie;
    int nivel;
    int vidaMax;
    int vida;
    int ataque;
    int defensa;
    string tipo1;
    string tipo2;
    string color;
};