//
// Created by rodri on 5/6/2019.
//

#ifndef PROYECTO_DE_SUNKEN_DECLARAR_FUNCIONES_H
#define PROYECTO_DE_SUNKEN_DECLARAR_FUNCIONES_H
void imprimir(char **matriz,int estilo);
void hacertablero(char **&matriz,int estilo,int a);
int validarficha(int estilo,int f,int c,char **matriz);
int validarmovimiento(int estilo,int fichaf,int  fichac,int  movf,int movc,char **matriz);
void mover(int validm,int fichaf,int  fichac,int  movf,int movc,char **&matriz);
void menu(char **&matriz,int estilo,int a);

#endif //PROYECTO_DE_SUNKEN_DECLARAR_FUNCIONES_H
