#include <iostream>
#include "funciones.hpp"
using namespace std;

int main(){
    int estilo,a=0;
    char **matriz= nullptr;

    cout << "Menu Juego Senku"<< endl;
    cout << "-----------------" << endl;
    cout << "1. Estilo Aleman" << endl;
    cout << "2. Estilo Ingles" << endl;
    cout << "3. Estilo Diamante" << endl;
    cout << "--------------------" << endl;
    cout << "0. Salir del juego" << endl;
    cin >> estilo;
    if ( estilo == 0){
        cout << "Vuelva pronto" << endl;
    }
    else if (estilo == 1){
        estilo=estilo+7;
        matriz = new char*[estilo];
        for(int i = 0; i < estilo; i++){
            matriz[i] = new char[estilo];
        }
        for (int i = 0; i < estilo; i++) {
            for (int j = 0; j < estilo; j++) {
                matriz[i][j] = '0';
            }
        }
        cout<<endl;
        menu(matriz,estilo,a);
    }
    else if (estilo == 2){
        estilo=estilo+8;
        matriz = new char*[estilo];
        for(int i = 0; i < estilo; i++){
            matriz[i] = new char[estilo];
        }
        for (int i = 0; i < estilo; i++) {
            for (int j = 0; j < estilo; j++) {
                matriz[i][j] = '0';
            }

        }
        cout<<endl;
        menu(matriz,estilo,a);
    }
    else if (estilo == 3){
        a=a+1;
        estilo=estilo+7;
        matriz = new char*[estilo];
        for(int i = 0; i < estilo; i++){
            matriz[i] = new char[estilo];
        }
        for (int i = 0; i < estilo; i++) {
            for (int j = 0; j < estilo; j++) {
                matriz[i][j] = '0';
            }

        }
        cout<<endl;
        menu(matriz,estilo,a);
    }
    else{
        cout << "Regresa pronto"<<endl;
    }
    return (0);
}

