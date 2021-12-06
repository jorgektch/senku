//
// Created by rodri on 5/6/2019.
#include "funciones.hpp"
#include <iostream>
using namespace std;


void imprimir(char **matriz,int estilo){
    for (int i = 0; i < estilo; i++) {
        for (int j = 0; j < estilo; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
}
void hacertablero(char **&matriz,int estilo,int a){
    char str1[] = " ";
    int nfilas=1;
    int ncolu=1;
    if (estilo==8){
        for (int i=0; i<estilo; i++) {
            for (int j = 0; j < estilo; j++) {
                if (i == 0 && j == 0) {
                    matriz[i][j] = str1[0];
                } else if (i == 4 && j == 4) {
                    matriz[i][j] = '+';
                } else if (i == 0 && j != 0) {
                    matriz[i][j] = nfilas + '0';
                    nfilas = nfilas + 1;
                } else if (j == 0 && i != 0) {
                    matriz[i][j] = ncolu + '0';
                    ncolu = ncolu + 1;
                } else if ((i == 1 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 1) || (i == 2 && j == 2) ||
                           (i == 6 && j == 1) || (i == 6 && j == 2) || (i == 7 && j == 1) || (i == 7 && j == 2) ||
                           (i == 1 && j == 6) || (i == 1 && j == 7) || (i == 2 && j == 6) || (i == 2 && j == 7) ||
                           (i == 6 && j == 6) || (i == 6 && j == 7) || (i == 7 && j == 6) || (i == 7 && j == 7)) {
                    matriz[i][j] = str1[0];
                } else {
                    matriz[i][j] = '0';
                }

            }
            cout << endl;
        }
    }
    else if (estilo==10&&a==0){
        for (int i=0; i<estilo; i++) {
            for (int j = 0; j < estilo; j++) {
                if (i == 0 && j == 0) {
                    matriz[i][j] = str1[0];
                } else if (i == 5 && j == 5) {
                    matriz[i][j] = '+';
                } else if (i == 0 && j != 0) {
                    matriz[i][j] = nfilas + '0';
                    nfilas = nfilas + 1;
                } else if (j == 0 && i != 0) {
                    matriz[i][j] = ncolu + '0';
                    ncolu = ncolu + 1;
                } else if ((i == 1 && j == 1) || (i == 1 && j == 2) || (i == 1 && j == 3) || (i == 2 && j == 1) || (i == 2 && j == 2) || (i == 2 && j == 3) || (i == 3 && j == 1) || (i == 3 && j == 2) || (i == 3 && j == 3) ||
                           (i == 7 && j == 1) || (i == 7 && j == 2) || (i == 7 && j == 3) || (i == 8 && j == 1) || (i == 8 && j == 2) || (i == 8 && j == 3) || (i == 9 && j == 1) || (i == 9 && j == 2) || (i == 9 && j == 3) ||
                           (i == 1 && j == 7) || (i == 1 && j == 8) || (i == 1 && j == 9) || (i == 2 && j == 7) || (i == 2 && j == 8) || (i == 2 && j == 9)|| (i == 3 && j == 7) || (i == 3 && j == 8) || (i == 3 && j == 9) ||
                           (i == 7 && j == 7) || (i == 7 && j == 8) || (i == 7 && j == 9) || (i == 8 && j == 7) || (i == 8 && j == 8) || (i == 8 && j == 9) || (i == 9 && j == 7) || (i == 9 && j == 8) || (i == 9 && j == 9) ) {
                    matriz[i][j] = str1[0];
                } else {
                    matriz[i][j] = '0';
                }

            }
            cout << endl;
        }

    }
    else if (estilo==10&&a==1) {
        for (int i = 0; i < estilo; i++) {
            for (int j = 0; j < estilo; j++) {
                if (i == 0 && j == 0) {
                    matriz[i][j] = str1[0];
                } else if (i == 5 && j == 5) {
                    matriz[i][j] = '+';
                } else if (i == 0 && j != 0) {
                    matriz[i][j] = nfilas + '0';
                    nfilas = nfilas + 1;
                } else if (j == 0 && i != 0) {
                    matriz[i][j] = ncolu + '0';
                    ncolu = ncolu + 1;
                } else if ((i == 1 && j == 1) || (i == 1 && j == 2) || (i == 1 && j == 3) || (i == 1 && j == 4) ||
                           (i == 2 && j == 1) || (i == 2 && j == 2) || (i == 2 && j == 3) || (i == 3 && j == 1) ||
                           (i == 3 && j == 2) || (i == 4 && j == 1) ||
                           (i == 6 && j == 1) || (i == 7 && j == 1) || (i == 7 && j == 2) || (i == 8 && j == 1) ||
                           (i == 8 && j == 2) || (i == 8 && j == 3) || (i == 9 && j == 1) || (i == 9 && j == 2) ||
                           (i == 9 && j == 3) || (i == 9 && j == 4) ||
                           (i == 1 && j == 6) || (i == 1 && j == 7) || (i == 1 && j == 8) || (i == 1 && j == 9) ||
                           (i == 2 && j == 7) || (i == 2 && j == 8) || (i == 2 && j == 9) || (i == 3 && j == 8) ||
                           (i == 3 && j == 9) || (i == 4 && j == 9) ||
                           (i == 6 && j == 9) || (i == 7 && j == 8) || (i == 7 && j == 9) || (i == 8 && j == 7) ||
                           (i == 8 && j == 8) || (i == 8 && j == 9) || (i == 9 && j == 6) || (i == 9 && j == 7) ||
                           (i == 9 && j == 8) || (i == 9 && j == 9)) {
                    matriz[i][j] = str1[0];
                } else {
                    matriz[i][j] = '0';
                }
            }
            cout << endl;
        }
    }
}
int validarficha(int estilo,int f,int c,char **matriz){
    if(f<estilo&&c<estilo){
        if(matriz[f][c]=='0'){
            return(1);
        }
        else{
            return(0);
        }
    }
    else{
        return(0);
    }
}

int validarmovimiento(int estilo,int fichaf,int  fichac,int  movf,int movc,char **matriz){
    if(movf<estilo&&movc<estilo){
        if(matriz[movf][movc]=='+'){
            if(fichaf+2==movf && fichac==movc && matriz[fichaf+1][fichac]=='0'){
                return(1);
            }
            else if(fichaf-2==movf && fichac==movc && matriz[fichaf-1][fichac]=='0'){
                return(2);
            }
            else if(fichaf==movf && fichac+2==movc && matriz[fichaf][fichac+1]=='0'){
                return(3);
            }
            else if(fichaf==movf && fichac-2==movc && matriz[fichaf][fichac-1]=='0'){
                return(4);
            }
            else{
                return(0);
            }
        }
        else if(movf==12&&movc==12){
            return(12);
        }
        else{
            return(0);
        }
    }
    else{
        return(0);
    }
}






void mover(int validm,int fichaf,int  fichac,int  movf,int movc,char **&matriz){
    char a;
    a=matriz[fichaf][fichac];
    matriz[fichaf][fichac]=matriz[movf][movc];
    matriz[movf][movc]=a;
    if (validm==1){
        matriz[fichaf+1][fichac]='+';
    }
    else if(validm==2){
        matriz[fichaf-1][fichac]='+';
    }
    else if(validm==3){
        matriz[fichaf][fichac+1]='+';
    }
    else if(validm==4){
        matriz[fichaf][fichac-1]='+';
    }
}

int cuentafichas(char **matriz, int estilo){
    int fila, columna, a = 0;
    for (fila= 0; fila < estilo; fila++)
    {
        for (columna = 0; columna < estilo; columna++)
        {
            if(matriz[fila][columna] == '0')
            {
                a++;
            }
        }
    }

    if (a == 1){
        return (1);
    }
    else{
        return(0);
    }
}



void menu(char **&matriz,int estilo,int a) {
    int x, fichaf, fichac, movf, movc, ganado=0, validf, validm, pasos=0;
    hacertablero(matriz,estilo,a);
    imprimir(matriz,estilo);
    cout << "********BIENVENIDOS A SENKU*********" << endl;
    cout << "Ingresar 1 si quieren jugar o cualquier otro numero si quieren salir " << endl;
    cin >> x;
    if (x == 1) {
        imprimir(matriz,estilo);
        cout << "Si quieres parar el juego en cualquier momento colocar 12 en todos los parametros"<<endl;
        while (ganado != 1) {
            ganado=cuentafichas(matriz,estilo);
            cout << "Ingresa ficha a mover:" << endl;
            cout << "Fila: ";
            cin >> fichaf;
            cout << "Columna: ";
            cin >> fichac;
            if(fichaf==12 && fichac==12){
                cout<<"termino el juego";
                break;
            }
            validf = validarficha(estilo,fichaf, fichac, matriz);
            if (validf == 1) {
                cout << "Ficha valida"<<endl;
                cout << "Ingresar fila a mover: ";
                cin >> movf;
                cout << "Ingresar columna a mover: ";
                cin >> movc;
                validm=validarmovimiento(estilo,fichaf, fichac, movf, movc, matriz);
                if(validm == 1||validm == 2||validm == 3||validm == 4) {
                    cout << "Movimiento valido" << endl;
                    mover(validm, fichaf, fichac, movf, movc, matriz);
                    imprimir(matriz,estilo);
                    pasos++;
                }
                else if(validm == 12){
                    cout<<"termino el juego";
                    break;
                }
                else{
                    cout << "Movimiento invalido"<<endl;
                }
            }
            else{
                cout << "Ficha invalida"<<endl;
            }
        }
        if(ganado == 1) {
            cout << " HAS GANADO !!!!!! Felicitaciones";
        }
    }
    else {
        cout << "Hasta pronto";
    }
    // Elimino cada vector de la matriz
    for (int i = 0; i < estilo; i++) {
        delete[] matriz[i];
    }
    // Elimino el vector principal
    delete[] matriz;
}

//
