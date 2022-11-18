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
/*
void Pokemon::getSprite1(){
    char s=219;
    string pintar = "\x1b"+color;
    cout <<pintar<<setw(sangria)<<s<<s<<s<<"\t\t"<<DF<<especie<<"\n";
    cout <<pintar<<setw(sangria)<<s<<s<<s<<"\t\t"<<DF<<"Nivel: "<<nivel<<"\n";
    cout <<pintar<<setw(sangria)<<s<<s<<s<<" \n"<<DF<<"\n";
}
*/
string Pokemon::getEspecie() {
    return especie;
}

string Pokemon::getDataInfo() {
    char i = ',';
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

    cout <<pintar<<setw(sangria)<<"███"<<"\t\t"<<DF<<especie<<"\n";
    cout <<pintar<<setw(sangria)<<"███"<<"\t\t"<<DF<<"Nivel "<<nivel<<"\n";
    cout <<pintar<<setw(sangria)<<"███"<<"\t\t"<<DF<<"Vida: "<<vida<<"\n";
    cout<<"======================\n";
}

Pokemon::~Pokemon() {}


//CLASS PARTIDA





Partida::Partida(string nameC) {
        nombre = nameC;
        lugar = "Ruta 1";
        delimitador = ',';
        //cout << "Objeto partida creado\n";
        string nameArchivo = "DatosC.csv";
        ifstream archivo(nameArchivo.c_str());
        string linea;
        int i{0};

        getline(archivo,linea);

        while(getline(archivo,linea)) {
            stringstream stream(linea);

            for (int j{0};j<8;j++) {
                string auxiliar;
                getline(stream,auxiliar,delimitador);
                basePokemon[i][j] = auxiliar;
            }

        i++;
        }
        archivo.close();

        nameArchivo = "rutas.csv";
        ifstream rutas(nameArchivo.c_str());
        i=0;
        getline(rutas,linea);
        

        while(getline(rutas,linea)) {
            
            stringstream stream(linea);

            for (int j{0};j<10;j++) {
                string auxiliar;
                getline(stream,auxiliar,delimitador);
                rutasInfo[i][j] = auxiliar;
            }
        i++;
        }
        rutas.close();
        string direccion = nombre+"/datos.txt";
        ifstream coleccion(direccion);

        while(getline(coleccion,linea)) {
            coleccionPokemon.push_back(linea);
        }

}


void Partida::getBase() {
    for (int i{0};i<coleccionPokemon.size();i++) {
        cout << coleccionPokemon[i] <<" | \n";
    }

}


void Partida::setPrincipal() {
        
        stringstream stream(coleccionPokemon[0]);
        string id,especie,nivel,tipo1,tipo2,vida,ataque,defensa,color;
        getline(stream,id,delimitador);
        getline(stream,especie,delimitador);
        getline(stream,nivel,delimitador);
        getline(stream,tipo1,delimitador);
        getline(stream,tipo2,delimitador);
        getline(stream,vida,delimitador);
        getline(stream,ataque,delimitador);
        getline(stream,defensa,delimitador);
        getline(stream,color);
        int idInt=stoi(id);
        int vidaInt=stoi(vida),ataqueI=stoi(ataque),defensaI=stoi(defensa),nivelI=stoi(nivel);
        principal.setInfo(idInt,especie,nivelI,vidaInt,ataqueI,defensaI,tipo1,tipo2,color);
}

void Partida::savePokemon(string infoPokemon) {

    coleccionPokemon.push_back(infoPokemon);

}

void Partida::setSalvaje(int niv, int idSal) {
    for (int i{0};i<151;i++) {
        string id,especie,tipo1,tipo2,vida,ataque,defensa,color;
        id = basePokemon[i][0];
        int idInt=stoi(id);
        //cout << "idSal = " << idSal << "\n";
        if (idSal == idInt) {
            especie = basePokemon[i][1];
            tipo1 = basePokemon[i][2];
            tipo2 = basePokemon[i][3];
            vida = basePokemon[i][4];
            ataque = basePokemon[i][5];
            defensa = basePokemon[i][6];
            color = basePokemon[i][7];
            int vidaInt=stoi(vida), ataqueI=stoi(ataque), defensaI=stoi(defensa);
            salvaje.setInfo(idInt,especie,niv,vidaInt,ataqueI,defensaI,tipo1,tipo2,color);
            break;
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

bool Partida::menuCaptura(string &dataSalvaje) {
    srand(time(NULL));
    int randomNumber = rand() % 11;
    if (randomNumber>6) {
        cout<<salvaje.getEspecie()<<" fue capturado.\n";
        dataSalvaje = salvaje.getDataInfo();
        return true;
    }else {
        cout<<salvaje.getEspecie()<<" se escapó\n";
        return false;
    }        
}




int Partida::generaRuta(int &nivel) {
    for (int i{0};i<2;i++) {

        string nombreRuta = rutasInfo[i][0];

        if (nombreRuta==lugar) {

            int random = stoi(rutasInfo[i][1]);
            int lista[random];
            nivel = stoi(rutasInfo[i][2]);

            for (int j{0};j<random;j++) {
                int idPoke=stoi(rutasInfo[i][j+3]);
                lista[j] = idPoke;
            }

            srand(time(NULL));
            int f = rand() % random ;
            int pokeSalvaje;
            pokeSalvaje = lista[f];
            return pokeSalvaje;

        }else {
            continue;
        }

    }
}

Partida::~Partida() {
    //cout << "Objeto "<<nombre<<" destruido\n";
    string direccion = nombre+"/datos.txt";
    ofstream savePoke(direccion);

    for (int i{0};i<coleccionPokemon.size();i++) {
        savePoke << coleccionPokemon[i] << "\n";
    }

    savePoke.close();
}




string Partida::crearInicial() {

    int elegido{0};
    int j{0};
    Pokemon inicial[3];

    for (int i{0};i<151;i++) {
        string id,especie,tipo1,tipo2,vida,ataque,defensa,color;
        id = basePokemon[i][0];
        if (id=="1"||id=="4"||id=="7") {
            especie = basePokemon[i][1];
            tipo1 = basePokemon[i][2];
            tipo2 = basePokemon[i][3];
            vida = basePokemon[i][4];
            ataque = basePokemon[i][5];
            defensa = basePokemon[i][6];
            color = basePokemon[i][7];
            int idInt=stoi(id), vidaInt=stoi(vida), ataqueI=stoi(ataque), defensaI=stoi(defensa);
            inicial[j].setInfo(idInt,especie,5,vidaInt,ataqueI,defensaI,tipo1,tipo2,color);
            //inicial[i].getInfo();
            cout<<"["<<j+1<<"]\n";
            inicial[j].getSprite(2);
            j++;
        }else {
            continue;
        }
    }

    string eleccion;
    while (true) {
        cout<<"Cual Eliges?";
        int elegido = perdirOpt();
        
        if (elegido==1||elegido==2||elegido==3) {
            eleccion = inicial[elegido-1].getDataInfo();
            break;
        }else {
            continue;
        }
    }
    return eleccion;
}

void Partida::mostrarPokemons() {
    for (int i{0} ; i< coleccionPokemon.size(); i++) {
        Pokemon auxiliar;
        stringstream stream(coleccionPokemon[i]);
        string id,especie,nivel,tipo1,tipo2,vida,ataque,defensa,color;
        getline(stream,id,delimitador);
        getline(stream,especie,delimitador);
        getline(stream,nivel,delimitador);
        getline(stream,tipo1,delimitador);
        getline(stream,tipo2,delimitador);
        getline(stream,vida,delimitador);
        getline(stream,ataque,delimitador);
        getline(stream,defensa,delimitador);
        getline(stream,color);
        int idInt=stoi(id);
        int vidaInt=stoi(vida),ataqueI=stoi(ataque),defensaI=stoi(defensa),nivelI=stoi(nivel);
        auxiliar.setInfo(idInt,especie,nivelI,vidaInt,ataqueI,defensaI,tipo1,tipo2,color);
        cout<<"======================\n["<<i+1<<"]\n";

        auxiliar.getSprite(2);
    }
}


//FUNCIONES GLOBALES


void InterfazPartida::logoPoke() {
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

void Partida::introPoke() {
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
    string Inicial = crearInicial();
    savePokemon(Inicial);
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

//InterfazPartida


InterfazPartida::InterfazPartida() {
    opt = 0;
}




void InterfazPartida::interfazJuego(Partida &jugador) {
    
    bool flag{true};

    while (flag) {
        switch (opt) {
        case 0:
            system("cls");
            cout<<"Menu de Interacción\n==========" << jugador.lugar << "==========\n";
            cout<<"\t[1]Capturar Pokemons.\n\t[2]Ver Pokemons.\n\t[3]Mapa.\n\t[4]Salir.\n>>> ";
            opt = pedirOpt();
            break;
        case 1: {
            int nivelRuta;
            int idSalvaje;

            idSalvaje = jugador.generaRuta(nivelRuta);
            jugador.setSalvaje(nivelRuta,idSalvaje);
            jugador.captura();
            string infoCaptura = interfazCaptura(jugador);
            system("pause");
            if (infoCaptura == "") {
                opt = 0;
                continue;
            }else {
                jugador.savePokemon(infoCaptura);
                opt = 0;
            }
            break;
        }
        case 2:
            cout << "=======Tus Pokemons son:==========\n";
            jugador.mostrarPokemons();
            opt = 0;
            system("pause");
            break;

        case 3:
            cout<<"El mapa aún no está disponible.\n";
            opt = 0;
            system("pause");
            break;
        default:
            flag = false;
            break;
        }
    }
}




int InterfazPartida::pedirOpt(){
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


string InterfazPartida::interfazCaptura(Partida &jugador) {
    string infoPoke;
    opt = 0;
    while (true) {
    switch(opt) {
        case 0:
        cout<<"Que deseas hacer?\n";
        cout<<"\t[1]Luchar.\n\t[2]Pokemon.\n\t[3]Capturar.\n\t[4]Huir.\n>>>";
        opt = pedirOpt();
        break;
        case 1:
        cout<<"Luchar aún no está disponible\n";
        opt = 0;
        break;
        case 2:
        cout<<"Cambiar de Pokemon aún no está disponible\n"; 
        opt = 0;
        break;
        case 3:
            if (jugador.menuCaptura(infoPoke)) {
                return infoPoke;
            }else {
                opt=0;
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
