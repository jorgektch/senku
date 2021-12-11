#include <iostream>
#include <string>
#include "partida.h"
using namespace std;

class Juego{
	private:
		int estado;
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
                    PartidaFrancesa p;
                    p.iniciar();
                    system("PAUSE");
				}else if(opcion == "2"){
					system("CLS");
                    //PartidaDiamante p;
                    //p.iniciar();
                    system("PAUSE");
				}else if(opcion == "3"){
					system("CLS");
                    //PartidaInglesa p;
                    //p.iniciar();
                    system("PAUSE");
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
