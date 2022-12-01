#include <iostream>
using namespace std;

void msg(){
    cout << "HHAAAA TOMEN NIKO Y JEAN, SOY BACK-END AHORA";
}

int main(){
    int atq = 10;
    int dfs = 15;
    int mv = 3;
    char A;

    int vida = 50;

    cin >> A;

    if(A == true){
        int dno = (vida+dfs)/atq;
        vida -= dno;
        cout << &vida;
        mv+=1;

        if(mv == 3){
            cout << "Sin Moves papi";
            msg();
        }
    }

    return 0;
}
