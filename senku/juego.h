#pragma once
#include <iostream>
#include <string>
#include "partidaFrancesa.h"
#include "partidaDiamante.h"
#include "partidaInglesa.h"
using namespace std;

class Juego{
private:
	// Partidas de los 03 tipos solicitados (como minimo)
	PartidaFrancesa p1;
	PartidaDiamante p2;
	PartidaInglesa p3;
public:
	Juego(){}
	~Juego(){}
	void menu(){
		cout << "Menu - Juego Senku\n";
		cout << "-------------------------------------\n";
		cout << "1. Estilo frances\n";
		cout << "2. Estilo diamante\n";
		cout << "3. Estilo ingles\n";
		cout << "-------------------------------------\n";
		cout << "0. Salir del Programa\n\n";
		cout << "Seleccionar la opcion: ";
	}

	void iniciar(){
		string opcion;
		do{
			system("CLS");
			menu();
			getline(cin, opcion);
			if(opcion == "1"){
				system("CLS");
                this->p1.llenarTablero();
                this->p1.iniciar();
			}else if(opcion == "2"){
				system("CLS");
                this->p2.llenarTablero();
                this->p2.iniciar();
			}else if(opcion == "3"){
				system("CLS");
                this->p3.llenarTablero();
                this->p3.iniciar();
			}else if(opcion == "0"){
				system("CLS");
				cout << "Hasta pronto" << endl;
				system("PAUSE");
			}else{
				system("CLS");
				cout << "Error! Opcion invalida" << endl;
				system("PAUSE");
			}
		}while(opcion != "0");
	}
};
