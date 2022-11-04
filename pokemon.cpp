//Intro 219 ███
#include "pokemon.hpp"
using namespace std;


Pokemon::Pokemon() {
    especie= "Misigno";
    nivel = 0;
    vida=0;
    ataque = 0;
    defensa = 0;
    tipo1="No";
    tipo2="No";
    color="";
}
void Pokemon::setInfo(string especiePoke,int nivelPok, int vidaPok,int ataquePok, int defensaPok, string tipo1Pok, string tipo2Pok,string colorPok) {
    especie=especiePoke;
    nivel=nivelPok;
    vida=vidaPok;
    ataque=ataquePok;
    defensa=defensaPok;
    tipo1=tipo1Pok;
    tipo2=tipo2Pok;
    color=colorPok;
}
void Pokemon::getInfo() {
    cout<<"======================\nEspecie: "<<especie<<"\nTipo1: "<<tipo1<<"\nTipo2: "<<tipo2<<"\nVida: "<<vida<<"\nAtaque: "<<ataque<<"\nDefensa: "<<defensa<<"\n======================\n";
}
void Pokemon::getSprite() {
    //███
    char s=219;
    string pintar = "\x1b"+color;
    cout <<pintar<<s<<s<<s<<"███\t\t"<<DF<<especie<<"\n";
    cout <<pintar<<s<<s<<s<<"███\t\t"<<DF<<"Vida: "<<vida<<"\n";
    cout <<pintar<<s<<s<<s<<"███ \n"<<DF<<"\n";
}

Pokemon::~Pokemon() {
    cout<<especie<<" destruida.";
}

void crearInicial(string archivoData) {

  ifstream archivo(archivoData.c_str());
  string linea;
  char del = ';';
  Pokemon inicial[3];
  getline(archivo, linea);
  int i=0;
  while (getline(archivo, linea)) {         //Crear iniciales
    stringstream stream(linea);
    string id,especie,tipo1,tipo2,vida,ataque,defensa,color;
    getline(stream,id,del);
    if (id=="1"||id=="4"||id=="7") {
        getline(stream,especie,del);
        getline(stream,tipo1,del);
        getline(stream,tipo2,del);
        getline(stream,vida,del);
        getline(stream,ataque,del);
        getline(stream,defensa,del);
        getline(stream,color);
        int idInt=stoi(id);
        int vidaInt=stoi(vida),ataqueI=stoi(ataque),defensaI=stoi(defensa);
        inicial[i].setInfo(especie,5,vidaInt,ataqueI,defensaI,tipo1,tipo2,color);
        //inicial[i].getInfo();
        inicial[i].getSprite();
        i++;
    }else {
        continue;
    }
  }
  archivo.close();
}