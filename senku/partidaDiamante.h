#pragma once
#include "partida.h"

class PartidaDiamante: public Partida { // Herencia
private:
public:
    // Constructor
    PartidaDiamante(int filas = 9, int columnas = 9): Partida(filas, columnas){
        llenarTablero(); // Llenado del tablero
    }
    // Destructor
    ~PartidaDiamante(){}

    // Funcion que llena el tablero con 'O' para fichas y '+' para el espacio vacio
    void llenarTablero(){
        // Reinicio del numero de fichas del tablero
        this->fichas = 0;
        // Llenado de fichas
        for (int i = 0; i < this->filas; i++) {
            for (int j = 0; j < this->columnas; j++) {
                if((3 <= j && j <= 5) || (3 <= i && i <= 5)){
                    this->tablero[i][j] = 'O';
                    this->fichas++; // Actualizacion del numero de fichas
                }
            }
        }
        // Llenado de posicion vacia
        this->tablero[4][4] = '+';
        this->fichas--; // Actualizacion del numero de fichas
    }
};