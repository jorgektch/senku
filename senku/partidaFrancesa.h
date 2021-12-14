#pragma once
#include "partida.h"

class PartidaFrancesa: public Partida { // Herencia
private:
public:
    // Constructor
    PartidaFrancesa(int filas = 7, int columnas = 7): Partida(filas, columnas){
        llenarTablero(); // Llenado del tablero
    }
    // Destructor
    ~PartidaFrancesa(){}

    // Funcion que llena el tablero con 'O' para fichas y '+' para el espacio vacio
    void llenarTablero(){
        // Reinicio del numero de fichas del tablero
        this->fichas = 0;
        // Llenado de fichas
        for (int i = 0; i < this->filas; i++) {
            for (int j = 0; j < this->columnas; j++) {
                //if(i <= j+4 && i >= -j+2 && -i >= j-10 && -i <= -j+4){
                if(j <= -i+10 && j <= i+4 && i-4 <= j && -i+2 <= j){
                    this->tablero[i][j] = 'O';
                    this->fichas++; // Actualizacion del numero de fichas
                }
            }
        }
        // Llenado de posicion vacia
        this->tablero[3][3] = '+';
        this->fichas--; // Actualizacion del numero de fichas
    }
};