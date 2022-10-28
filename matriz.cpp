#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;
#define	GREEN 	"\x1B[32m"
#define	DF 		"\x1B[39m"

class matriz{
public:
    int **mat;
    int filas;
    int columnas;
    matriz(int f = 0, int c = 0){
        filas = f;
        columnas = c;
        if ((f > 0)&&(c > 0)){
            mat = new int*[filas];      
            for(int i{0}; i < filas; ++i){
                mat[i] = new int[columnas];
            }
            }else {
                mat = nullptr;
            }
            for(int i{0}; i < filas; ++i){
                for(int a{0}; a < columnas; ++a){
                    mat[i][a]= 0;
                }
            }
    }

    void getTamaño(){
        cout << "\n\nfilas: " << filas << "\nColumnas: " << columnas << "\n" << "___________" << "\n\n";
    }

	void funcion_01() {		//funcion_01
		srand(time(NULL));
		for (int i{0};i<filas;++i) {
			for (int j{0};j<columnas;++j) {
				mat[i][j]=rand() % 100;
			}
		}
		cout<<GREEN<<"\nMatriz Creada\n"<<DF;
	}

	void imprimirMat() {		//funcion_02
		for (int i{0};i<filas;++i) {
			cout<<"| ";
			for (int j{0};j<colum;++j) {	
				cout<<setw(3)<<mat[i][j]<<" ";
			}
			cout<<"|\n";
		}
	}

void funcion_03() {
	int fil,col,x;
	cout<<"\nIngresa el valor de las filas.";
	cin>>fil;
	cout<<"\nIngresa el valor de las columnas.";
	cin>>col;
	cout<<"\nIngresa el nuevo valor.";
	cin>>x;
	mat[fil][col]=x;
	cout<<GREEN<<"\nEl valor fue modificado exitosamente.\n"<<DF;

}

void funcion_04(){
	for(int f{0}; fila < filas ; ++fila){
		for(int c{0}; columna < columnas ; ++columna){

			if(f == c){
				mat[f][c] = 0;
			}

		}
	}
	cout<<GREEN<<"\nLa digonal es igual a 0.\n"<<DF;
}

	funcion_05() {
		while (true) {
		int a,b,c;
        int a1{0},b1{0},c1{0};
            cout<<"\nIngresa el primer numero a buscar\n>>";
            cin>>a;
            cout<<"\nIngresa el segundo numero a buscar\n>>";
            cin>>b;
            cout<<"\nIngresa el tercer numero a buscar\n>>";
            cin>>c;
		if ((0<=a<100)&&(0<=b<100)&&(0<=c<100)) {
    	for (int i{0};i<filas;++i) {
        for (int j{0};j<columnas;++j) {
            if (mat[i][j]==a) {
                ++a1;
            }else if (mat[i][j]==b) {
                ++b1;
            }else if (mat[i][j]==c) {
                ++c1;
            }else {
                continue;
            }
        }
    }
    break;
	}else {
		cout<<"\nUn valor ingresado no es valido, recuerda que los numeros deben estar entre 0 y 99\n";
		continue	
	}
	}
	        cout<< GREEN <<"El numero "<< DF <<a<<" se repite "<<a1<<" veces.\n";
            cout<< GREEN <<"El numero "<< DF <<b<<" se repite "<<b1<<" veces.\n";
            cout<< GREEN <<"El numero "<< DF <<c<<" se repite "<<c1<<" veces.\n";
}

void funcion_06(int a,int b,int mat[10][10]) {
        int a,b;
        cout<<"\nIngresa el numero de 2 cifras a buscar.\n>>";
        cin>>a;
        cout<<"\nIngresa el numero entre 100 y 200 que será su reemplazo.\n>>";
        cin>>b;
        while(true) {
		if ((0<=a)&&(a<100)&&(99<b)&&(b<201)) {
		int aux{0};
		for (int i{0};i<filas;++i) {
	        for (int j{0};j<columnas;++j) {
      		if (mat[i][j]==a) {
	      		mat[i][j]=b;
      			++aux;
      		}
      		}
    	}  
    	if (aux==0) {
    		cout<<GREEN<<"\nNo se encontro ningun valor de ese tipo."<<DF;
    	}else {
	    	cout<<GREEN<<"\nLos valores fueron cambiados"<<DF;
	    }
		break;
		}else {
			cout<<"\nUno o mas valores son incorrectos, recuerda que el primer numero debe estar entre 0 y 99, y el segundo numero entre 100 y 200\n";
			continue;
		}
	}
	}

	void funcion_07(){

	int aux{0};

	for(int f{0}; f < filas ; ++f){
		for(int c{0}; c < columnas ; ++c){
			if (mat[f][c]%5 == 0){
				mat[f][c] *= 10;
				++aux;
			}
		}
	}

	if(aux == 0 ){
		cout<<GREEN<<"\nNo hay multiplos de 5\n"<<DF;
	}else{
		cout<<GREEN<<"\nTodos los multiplos de 5 son multiplicados por 10\n"<<DF;
	}

}

void funcion_08(){

	int aux[10][10];

	for(int fila{0}; fila < 10 ; ++fila){
		for(int columna{0}; columna < 10 ; ++columna){
			aux[fila][columna] = mat[columna][fila];
		}
	}

	for(int fila{0}; fila < 10 ; ++fila){
		for(int columna{0}; columna < 10 ; ++columna){
			mat[fila][columna] = aux[fila][columna];
		}
	}


	cout<<GREEN<<"\nLa matriz fue transpuesta\n"<<DF;
}

    void borrarMat(){

            for(int i{0}; i < columnas; ++i){

                delete []mat[i];
            
            }
            
        delete []mat;



    }

};

int main(){

    matriz uno(4,4);
    uno.getTamaño();
    uno.imprimirMat();
    uno.borrarMat();

}