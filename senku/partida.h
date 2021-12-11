#include <iostream>
using namespace std;

class Partida{
    protected:
        char estado = 'i'; // i: juego iniciado, g: gano, g: perdio
        int filas;
        int columnas;
        char **tablero;
    public:
        Partida(int filas, int columnas){
            this->filas = filas;
            this->columnas = columnas;
            /* Dimensionamiento del tablero */
            this->tablero = new char*[this->filas];
            for (int i = 0; i < this->filas; i++) {
                this->tablero[i] = new char[this->columnas];
            }
            /* Inicializacion del tablero vacio */
            for (int i = 0; i < this->filas; i++) {
                for (int j = 0; j < this->columnas; j++) {
                    this->tablero[i][j] = ' ';
                }
            }
        }
        ~Partida(){
            for (int i = 0; i < this->filas; i++) {
                delete [] this->tablero[i];
            }
            delete [] this->tablero;
        }

        void mostrarTablero(){
        	// Titulo
        	for (int j = 0; j < this->columnas; j++) {
				cout << " ";
			}
        	cout << " SENKU\n   -";
        	for (int j = 0; j < this->columnas; j++) {
				cout << "--";
			}
			// Columnas
        	cout << "\n  |";
        	for (int j = 0; j < this->columnas; j++) {
				cout << " " << j+1;
			}
			cout << "\n--|-";
			for (int j = 0; j < this->columnas; j++) {
				cout << "--";
			}
			cout << "\n";
			// Filas
            for (int i = 0; i < this->filas; i++) {
            	cout << i+1 << " |";
                for (int j = 0; j < this->columnas; j++) {
                    cout << " " << this->tablero[i][j];
                }
                cout << "\n";
            }
        }
        void llenarTablero(){}
        void iniciar(){}
};

class PartidaFrancesa: public Partida {
    private:
        // int filas;
        // int columnas;
        // char **tablero;
    public:
        PartidaFrancesa(int filas = 7, int columnas = 7): Partida(filas, columnas){}
        ~PartidaFrancesa(){}

        void llenarTablero(){
            for (int i = 0; i < this->filas; i++) {
                for (int j = 0; j < this->columnas; j++) {
                	//if(i <= j+4 && i >= -j+2 && -i >= j-10 && -i <= -j+4){
                	if(j <= -i+10 && j <= i+4 && i-4 <= j && -i+2 <= j){
                		this->tablero[i][j] = 'O';
					}
                }
            }
            this->tablero[3][3] = '+';
        }
        
        bool validarPosicionOrigen(int fila_o, int columna_o){
        	return true;
		}
		
        bool validarMovimiento(int fila_o, int columna_o, int fila_d, int columna_d){
        	return true;
		}
		
		void realizarMovimiento(int fila_o, int columna_o, int fila_d, int columna_d){
        	
		}
        
		void registrarMovimiento(){
			int fila_o, columna_o, fila_d, columna_d;
			cout << "-----------------------\n";
			cout << "Registrar de movimiento\n";
			cout << "-----------------------\n";
            cout << "Ubicacion de origen\n";
            cout << "Fila   : "; cin >> fila_o;
            cout << "Columna: "; cin >> columna_o;
            if(validarPosicionOrigen(fila_o, columna_o) == true){
	            cout << "Ubicacion de destino\n";
	            cout << "Fila   : "; cin >> fila_d;
	            cout << "Columna: "; cin >> columna_d;
	            // Validacion de movimiento
	            if(validarMovimiento(fila_o, columna_o, fila_d, columna_d) == true){
	            	realizarMovimiento(fila_o, columna_o, fila_d, columna_d);
	            	cout << "-----------------------\n";
	            	cout << "Movimiento registrado\n";
	            	system("PAUSE");
				}else{
					cout << "-----------------------\n";
					cout << "Error! Movimiento invalido\n";
					system("PAUSE");
				}
			}else{
				cout << "-----------------------\n";
				cout << "Error! Ubicacion de origen invalida\n";
				system("PAUSE");
			}
		}
		
		void actualizarEstado(){
			
		}
        void iniciar(){
            llenarTablero();
            while(this->estado == 'i'){
            	system("CLS");
            	this->mostrarTablero();
	            this->registrarMovimiento();
	            actualizarEstado();
	            if(this->estado == 'g'){
	            	cout << "Ganaste! Felicidades\n";
				}else if(this->estado == 'p'){
					cout << "Perdiste! Puedes volver a intentarlo\n";
				}
			}
        }
};
/*
class PartidaDiamante: public Partida {
    private:
        int filas;
        int columnas;
        char **tablero;
    public:
        PartidaDiamante(int filas = 9, int columnas = 9): Partida(filas, columnas){
            llenarTablero();
        }
        ~PartidaDiamante(){}

        void llenarTablero(){
            for (int i = 0; i < this->filas; i++) {
                for (int j = 0; j < this->columnas; j++) {
                    tablero[i][j] = 0;
                }
            }
        }
        void iniciar(){

        }
};

class PartidaInglesa: public Partida {
    private:
        int filas;
        int columnas;
        char **tablero;
    public:
        PartidaInglesa(int filas = 8, int columnas = 8): Partida(filas, columnas){
            llenarTablero();
        }
        ~PartidaInglesa(){}

        void llenarTablero(){
            for (int i = 0; i < this->filas; i++) {
                for (int j = 0; j < this->columnas; j++) {
                    tablero[i][j] = 0;
                }
            }
        }
        void iniciar(){

        }
};
 */
