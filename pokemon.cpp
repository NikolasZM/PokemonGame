//pokemon.cpp
#include "pokemon.hpp"
using namespace std;


//CLASS MOVIMIENTO

Movimiento::Movimiento(){
    nombre = "";
    precision = 100;
}

void Movimiento::setInfo(string nameM, int preM) {
    nombre = nameM;
    precision = preM;
}

string Movimiento::getName() {
    return nombre;
}

int Movimiento::getPrecision() {
    return precision;
}

Movimiento::~Movimiento(){}

//========

MovDaño::MovDaño() {
    potencia = 1;
    tipo = "";
}

void MovDaño::setInfo(int pot ,int prec, string nom,string tip) {
    potencia = pot;
    tipo = tip;
    Movimiento::setInfo(nom,prec);
}

int MovDaño::getPotencia() {
    return potencia;
}

string MovDaño::getTipo() {
    return tipo;
}

MovDaño::~MovDaño(){}

//=========

MovEstado::MovEstado() {
    estadistica = "";
}

void MovEstado::setInfo(string nom,int prec, string stat) {
    estadistica = stat;
    Movimiento::setInfo(nom,prec);
}

string MovEstado::getEstadistica() {
    return estadistica;
}

MovEstado::~MovEstado(){}


//CLASS POKEMON


Pokemon::Pokemon() {
    iD = 0;
    especie = "Misigno";
    nivel = 0;
    vidaMax =0;
    vida = 0;
    ataque = 0;
    defensa = 0;
    tipo1 = "No";
    tipo2 = "No";
    color = "";
    Mov1[0].setInfo(40,100,"Placaje","Normal");
    Mov1[1].setInfo(80,60,"Sofoco","Fuego");
    Mov2[0].setInfo("Fortaleza",100,"defensa");
    Mov2[1].setInfo("Danza Espada",100,"ataque");
}

void Pokemon::setInfo(int idPoke,string especiePoke,int nivelPok, int vidaPok,int ataquePok, int defensaPok, string tipo1Pok, string tipo2Pok,string colorPok) {
    iD = idPoke;
    especie=especiePoke;
    nivel=nivelPok;
    vidaMax=vidaPok;
    vida=vidaMax;    
    ataque=ataquePok;
    defensa=defensaPok;
    tipo1=tipo1Pok;
    tipo2=tipo2Pok;
    color=colorPok;
}

void Pokemon::showInfo() {
    cout<<"======================\nEspecie: "<<especie<<"\nNivel: "<<nivel<<"\nTipo1: "<<tipo1<<"\nTipo2: "<<tipo2<<"\nVida: ";
    cout<<vida<<"/"<<vidaMax<<"\nAtaque: "<<ataque<<"\nDefensa: "<<defensa<<"\n======================\n";
}

string Pokemon::getEspecie() {
    return especie;
}

int Pokemon::getNivel() {
    return nivel;
}

int Pokemon::getVida() {
    return vida;
}

int Pokemon::getAtaque() {
    return ataque;
}

int Pokemon::getDefensa() {
    return defensa;
}

string Pokemon::getInfo() {
    char i = ',';
    ostringstream info;
    info << to_string(iD) <<i<< especie <<i<< to_string(nivel) <<i<< tipo1 <<i<< tipo2 <<i<< to_string(vida) <<i<< to_string(ataque) <<i<< to_string(defensa) <<i<< color;
    return info.str();
}

void Pokemon::showSprite(int sangria) {
    char s=219;
    string pintar = "\x1b"+color;
    
    cout <<pintar<<setw(sangria)<<s<<s<<s<<"\t\t"<<DF<<especie<<"\n";
    cout <<pintar<<setw(sangria)<<s<<s<<s<<"\t\t"<<DF<<"Nivel "<<nivel<<"\n";
    cout <<pintar<<setw(sangria)<<s<<s<<s<<"\t\t"<<DF<<"Vida: "<<vida<<"/"<<vidaMax<<"\n"; 
    cout<<"======================\n";
    
    /*
    cout <<pintar<<setw(sangria)<<"███"<<"\t\t"<<DF<<especie<<"\n";
    cout <<pintar<<setw(sangria)<<"███"<<"\t\t"<<DF<<"Nivel "<<nivel<<"\n";
    cout <<pintar<<setw(sangria)<<"███"<<"\t\t"<<DF<<"Vida: "<<vida<<"/"<<vidaMax<<"\n"; 
    cout<<"======================\n";
    */
}

void Pokemon::curar() {
    vida = vidaMax;
}

void Pokemon::daño(int daño) {
    vida = vida - daño;
    if (vida < 0) {
        vida = 0;
    }else {}
}

bool Pokemon::compStab(int nMov) {
    if ((Mov1[nMov].getTipo() == tipo1) || (Mov1[nMov].getTipo() == tipo2)) {
        return true;
    }else {
        return false;
    }
}


Pokemon::~Pokemon() {}