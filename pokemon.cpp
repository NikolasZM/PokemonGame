//Intro 219 ███   CAP9 14/11
#include "pokemon.hpp"
using namespace std;

//CLASS POKEMON

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

void Pokemon::setInfo(int idPoke,string especiePoke,int nivelPok, int vidaPok,int ataquePok, int defensaPok, string tipo1Pok, string tipo2Pok,string colorPok) {
    iD = idPoke;
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
    cout<<"======================\nEspecie: "<<especie<<"\nTipo1: "<<tipo1<<"\nTipo2: "<<tipo2<<"\nVida: ";
    cout<<vida<<"\nAtaque: "<<ataque<<"\nDefensa: "<<defensa<<"\n======================\n";
}

string Pokemon::getEspecie() {
    return especie;
}

string Pokemon::getDataInfo() {
    char i = ';';
    string strId = to_string(iD);
    string strNivel = to_string(nivel);
    string strAtaque= to_string(ataque);
    string strDefensa= to_string(defensa);
    string strVida= to_string(vida);
    string info = strId+i+especie+i+strNivel+i+tipo1+i+tipo2+i+strAtaque+i+strDefensa+i+strVida+i+color;
    return info;
}

void Pokemon::getSprite(int sangria) {
    //███
    char s=219;
    string pintar = "\x1b"+color;
    cout <<pintar<<setw(sangria)<<s<<s<<s<<"\t\t"<<DF<<especie<<"\n";
    cout <<pintar<<setw(sangria)<<s<<s<<s<<"\t\t"<<DF<<"Vida: "<<vida<<"\n";
    cout <<pintar<<setw(sangria)<<s<<s<<s<<" \n"<<DF<<"\n";
}

Pokemon::~Pokemon() {}


//CLASS PARTIDA


Partida::Partida(string nameC) {
        nombre = nameC;
        cantidad=0;
        lugar = "Ruta 1";
}

void Partida::setPrincipal() {
        string direccion = nombre+"/datos.txt";
        ifstream archivo(direccion.c_str());
        string linea;
        char del = ';';
        getline(archivo, linea);
        stringstream stream(linea);
        string id,especie,nivel,tipo1,tipo2,vida,ataque,defensa,color;
        getline(stream,id,del);
        getline(stream,especie,del);
        getline(stream,nivel,del);
        getline(stream,tipo1,del);
        getline(stream,tipo2,del);
        getline(stream,vida,del);
        getline(stream,ataque,del);
        getline(stream,defensa,del);
        getline(stream,color);
        int idInt=stoi(id);
        int vidaInt=stoi(vida),ataqueI=stoi(ataque),defensaI=stoi(defensa),nivelI=stoi(nivel);
        principal.setInfo(idInt,especie,nivelI,vidaInt,ataqueI,defensaI,tipo1,tipo2,color);
}

void Partida::savePokemon(string infoPokemon) {
    string direccion = nombre+"/datos.txt";
    ofstream guardar;
    guardar.open(direccion, ios::app);
    guardar << infoPokemon << endl;  
    guardar.close();  
}

void Partida::setSalvaje(int niv, int idSal) {

        string nameArchivo = "DatosC.csv";
        ifstream archivo(nameArchivo.c_str());
        string linea;
        char del = ';';
        getline(archivo,linea);
        while (getline(archivo,linea)) {
            stringstream stream(linea);
            string id,especie,tipo1,tipo2,vida,ataque,defensa,color;
            getline(stream,id,del);
            int idInt = stoi(id);
            if (idInt==idSal) {
                getline(stream,especie,del);
                getline(stream,tipo1,del);
                getline(stream,tipo2,del);
                getline(stream,vida,del);
                getline(stream,ataque,del);
                getline(stream,defensa,del);
                getline(stream,color);                
                int vidaInt=stoi(vida),ataqueI=stoi(ataque),defensaI=stoi(defensa);
                salvaje.setInfo(idInt,especie,niv,vidaInt,ataqueI,defensaI,tipo1,tipo2,color);
                
            }else {
                continue;
            }
        }
}

void Partida::captura() {
    cout<<"Un "<<salvaje.getEspecie()<<" salvaje apareció: \n";
    salvaje.getSprite(35);
    cout<<"\n\n\n";
    principal.getSprite(2);
}

string Partida::menuCaptura() {
    int opt{0};
    while (true) {
    switch(opt) {
        case 0:
        cout<<"Que deseas hacer?\n";
        cout<<"\t[1]Luchar.\n\t[2]Pokemon.\n\t[3]Capturar.\n\t[4]Huir.\n>>>";
        opt = perdirOpt();
        break;
        case 1:
        cout<<"Esta opcion aún no está disponible\n";
        opt = 0;
        break;
        case 2:
        cout<<"Esta opcion aún no está disponible\n"; 
        opt = 0;
        break;
        case 3:
        {
            srand(time(NULL));
            int randomNumber = rand() % 10;
            if (randomNumber>7) {
                cout<<salvaje.getEspecie()<<" fue capturado.\n";
                return salvaje.getDataInfo();
            }else {
                cout<<salvaje.getEspecie()<<" se escapó\n";
            }
            opt = 0;
            break;
        }
        case 4:
        cout<<"Escapaste con éxito\n";
        return "";
        default:
        break;
    }
    }
}


int Partida::menuJuego () {
    cout<<"Menu de Interacción\n";
    cout << "==========" << lugar << "==========\n";
    cout<<"\t[1]Capturar Pokemons.\n\t[2]Ver Pokemons.\n\t[3]Mapa.\n\t[4]Salir.\n>>>";
    int opt = perdirOpt();
    return opt;
}

int Partida::generaRuta(int &nivel) {
    
    string direccion = "rutas.csv";
    ifstream archivo(direccion.c_str());
    string linea;
    getline(archivo,linea);
    
    char del = ';';
    while (getline(archivo,linea)) {
        stringstream stream(linea);
        string lugarLista,randomStr,nivelRuta;
        getline(stream,lugarLista,del);
        if (lugarLista==lugar) {
            
            getline(stream,randomStr,del);
            
            int random = stoi(randomStr);
            
            int lista[random-1];
            getline(stream,nivelRuta,del);
            nivel = stoi(nivelRuta);

            for (int i{0};i<random-1;i++) {
                string idPokemon;
                getline(stream,idPokemon,del);
                int idPokeInt = stoi(idPokemon);
                lista[i] = idPokeInt; 
            }
            srand(time(NULL));
            int randomLimit = random-2;
            
            int f = rand() % randomLimit ;
            
            int pokeSalvaje;
            pokeSalvaje = lista[f];
            return pokeSalvaje;
        }else {
            continue;
        }
    }
}

Partida::~Partida() {}


//FUNCIONES GLOBALES


string crearInicial(string archivoData) {

  ifstream archivo(archivoData.c_str());
  string linea;
  char del = ';';
  int elegido{0};
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
        inicial[i].setInfo(idInt,especie,5,vidaInt,ataqueI,defensaI,tipo1,tipo2,color);
        //inicial[i].getInfo();
        cout<<"["<<i+1<<"]\n";
        inicial[i].getSprite(2);
        i++;
    }else {
        continue;
    }
  }
  
    string eleccion{""};
    while(true) {
    switch(elegido) {
    case 0:
        cout<<"Cual Eliges?";
        cin>>elegido;
        break;
    case 1:
        eleccion="1;Bulbasaur;5;Planta;Veneno;45;49;49;[38;2;57;148;148m";
        break;
    case 2:
        eleccion="4;Charmander;5;Fuego;;39;52;43;[38;2;255;148;65m";
        break;
    case 3:
        eleccion="7;Squirtle;5;Agua;;44;48;65;[38;2;180;230;238m";
        break;
    default:
        cout<<"Escoja una opción correcta.";
        elegido=0;
        break;
    }
    if (eleccion=="") {
        continue;
    }else {
        break;
    }
    }
  archivo.close();
  cout<<eleccion;
  return eleccion;
}

void logoPoke() {
    system("cls");
    cout<<"\a";
    cout<<"\n                                  ,'\\   \n";
    cout<<"    _.----.        ____         ,'  _\\   ___    ___     ____\n";
    cout<<"_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`.\n";
    cout<<"\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |\n";
    cout<<" \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |\n";
    cout<<"   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |\n";
    cout<<"    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |\n";
    cout<<"     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |\n";
    cout<<"      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |\n";
    cout<<"       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |\n";
    cout<<"        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |\n";
    cout<<"                                `'                            '-._| \n"<<flush;
    system("pause");    
}

void introPoke(Partida &player) {
    cout<<"Bienvenido al mundo de los pokemons, mi nombre es Pepito, pero todo el mundo me llama profesor Pokemon.\n"<<flush;
    system("pause");
    system("cls");
    cout<<"Y esto son los que llamamos Pokemons: \n";
    cout<<"                 .\"-,.__\n";
    cout<<"                 `.     `.  ,\n";
    cout<<"              .'         `'\n";
    cout<<"             `.   /          ,'\n";
    cout<<"               `  '--.   ,-\"'\n";
    cout<<"                `\"`   |  \\ \n";
    cout<<"                   -. \\, |\n";
    cout<<"                    `--Y.'      ___.\n";
    cout<<"                         \\     L._, \\\n";
    cout<<"               _.,        `.   <  <\\                _\n";
    cout<<"             ,' '           `, `.   | \\            ( `\n";
    cout<<"          ../, `.            `  |    .\\`.           \\ \\_\n";
    cout<<"         ,' ,..  .           _.,'    ||\\l            )  '\".\n";
    cout<<"        , ,'   \\           ,'.-.`-._,'  |           .  _._`.\n";
    cout<<"      ,' /      \\ \\        `' ' `--/   | \\          / /   ..\\\n";
    cout<<"    .'  /        \\ .         |\\__ - _ ,'` `        / /     `.`.\n";
    cout<<"    |  '          ..         `-...-\"  |  `-'      / /        . `.\n";
    cout<<"    | /           |L__           |    |          / /          `. `.\n";
    cout<<"   , /            .   .          |    |         / /             ` `\n";
    cout<<"  / /          ,. ,`._ `-_       |    |  _   ,-' /               ` \\\n";
    cout<<" / .           \"`_/. `-_ \\_,.  ,'    +-' `-'  _,        ..,-.    \\`.\n";
    cout<<".  '         .-f    ,'   `    '.       \\__.---'     _   .'   '     \\ \\\n";
    cout<<"' /          `.'    l     .' /          \\..      ,_|/   `.  ,'`     L`\n";
    cout<<"|'      _.-""` `.    \\ _,'  `            \\ `.___`.'\"`-.  , |   |    | \\\n";
    cout<<"||    ,'      `. `.   '       _,...._        `  |    `/ '  |   '     .|\n";
    cout<<"||  ,'          `. ;.,.---' ,'       `.   `.. `-'  .-' /_ .'    ;_   ||\n";
    cout<<"|| '              V      / /           `   | `   ,'   ,' '.    !  `. ||\n";
    cout<<"||/            _,-------7 '              . |  `-'    l         /    `||\n";
    cout<<". |          ,' .-   ,' ||               | .-.        `.      .'     ||\n";
    cout<<" `'        ,'    `\".'    |               |    `.        '. -.'       `'\n";
    cout<<"          /      ,'      |               |,'    \\-.._,.'/'\n";
    cout<<"          .     /        .               .       \\    .''\n";
    cout<<"        .`.    |         `.             /         :_,'.'\n";
    cout<<"          \\ `...\\   _     ,'-.        .'         /_.-'\n";
    cout<<"           `-.__ `,  `'   .  _.>----''.  _  __  /\n";
    cout<<"                .'        /\"'          |  \"'   '_\n";
    cout<<"               /_|.-'\\ ,\".             '.'`__'-( \\\n";
    cout<<"                 / ,\"'\"\\,'               `/  `-.|\"\n";
    system("pause");
    system("cls");
    cout<<"Es hora de que escojas a tu primer pokemon...\n";
    string pokemonArchivo = "DatosC.csv";
    string Inicial = crearInicial(pokemonArchivo);
    player.savePokemon(Inicial);
    system("cls");
    cout<<"Ahora si que tu aventura comience.";
}

int perdirOpt(){
    while(true){
        int opt;
        cin >> opt;
        if( !cin.good() ){
            cin.clear();
            cin.ignore();
            cout << "Solo valores numericos" << "\n";
            system("cls");
        }else{
            return opt;
        }
    }
}

