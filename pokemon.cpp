//pokemon.cpp
#include "pokemon.hpp"
using namespace std;


//CLASS MOVIMIENTO


Movimiento::Movimiento(){
    nombre = "";
    potencia = 0;
    tipo = "";
}

void Movimiento::setInfo(string nameM, int potM, string tipoM) {
    nombre = nameM;
    potencia = potM;
    tipo = tipoM;
}

string Movimiento::getName() {
    return nombre;
}

int Movimiento::getPotencia() {
    return potencia;
}

string Movimiento::getTipo() {
    return tipo;
}

Movimiento::~Movimiento(){}


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
    info << to_string(iD) <<i<< especie <<i<< to_string(nivel) <<i<< tipo1 <<i<< tipo2 <<i<< to_string(ataque) <<i<< to_string(defensa) <<i<< to_string(vida) <<i<< color;
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
    if ((Mov[nMov].getTipo() == tipo1) || (Mov[nMov].getTipo() == tipo2)) {
        return true;
    }else {
        return false;
    }
}


Pokemon::~Pokemon() {}