#include "libreria.hpp"
#include "pokemon.hpp"

int main(){
    system("cls");

    int opt{0};
    bool bandera{false};
    bool user{false};
    string texto = "Ingrese:\n\t[1]Login\n\t[2]Crear Cuenta\n\t[Otro]salir\n\n>>>> ";

    perdirNum(opt, texto);     

    cuenta inicio;
    inicio.admin();

    switch (opt-1)
    {
    case 0:
        inicio.login();
        bandera = inicio.compAdmin();
        user = true;
        break;
    case 1:
        inicio.crearCuenta();
        break;
    default:
        return 0;
    }

    if (bandera)
    {
    
        system("cls");

        opt = 0;
        texto = "Que desea hacer:\n\t[1]Ver cuentas\n\t[2]Eliminar cuenta\n\t[3]Entrar a la cuenta\n\t[Otro]Salir\n\t>>>> ";

        perdirNum(opt, texto);

        switch (opt-1)
        {
        case 0:
            system("cls");
            inicio.mostrarCuentas();
            break;
        case 1:
            inicio.eliminarCuentas();
            break;
        case 2:
            break;
        default:
            break;
        }
    }

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
    system("cls");

    

    if (!user){
        cout<<"Bienvenido al mundo de los pokemons, mi nombre es Pepito, pero todo el mundo me llama profesor Pokemon.\n"<<flush;

        system("pause");
        system("cls");

        cout<<"Y esto son los que llamamos Pokemons: \n";
        cout<<"                 .\"-,.__\n";
        cout<<"                 `.     `.  ,\n";
        cout<<"              .--'  .._,'\"-' `.\n";
        cout<<"             .    .'         `'\n";
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
        crearInicial(pokemonArchivo);
        cout<<"Cual eliges?\n";
        
    }

}