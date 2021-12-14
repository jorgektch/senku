#pragma once
#include <iostream>
#include <string>
using namespace std;

class Partida{
protected:
    char estado = 'i'; // Estado del juego ('i': inicio, 'g': gano, 'g': perdio, 's': salio)
    int filas; // Numero de filas del tablero
    int columnas; // Numero de columnas del tablero
    char **tablero;  // Tablero como matriz dinamica de caracteres ('O': ficha, '+': espacio vacio ocupable, ' ': espacio no ocupable)
    int fichas; // Numero de fichas del tablero
public:
    // Constructor
    Partida(int filas, int columnas){
        // Inicializacion del numero de filas, columnas y fichas del tablero
        this->filas = filas;
        this->columnas = columnas;
        // Dimensionamiento del tablero (matriz dinamica)
        this->tablero = new char*[this->filas];
        for (int i = 0; i < this->filas; i++) {
            this->tablero[i] = new char[this->columnas];
        }
        // Inicializacion del tablero vacio
        for (int i = 0; i < this->filas; i++) {
            for (int j = 0; j < this->columnas; j++) {
                this->tablero[i][j] = ' ';
            }
        }
    }
    // Destructor
    ~Partida(){
        for (int i = 0; i < this->filas; i++) {
            delete [] this->tablero[i];
        }
        delete [] this->tablero;
    }

    // Funcion que imprime los caracteres del tablero
    void mostrarTablero(){
    	// Titulo
    	cout << "   SENKU (" << this->fichas << " fichas)"<< "\n   -";
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

    // Funcion que valida que una posicion este dentro de los limites tablero
    bool validarPosicion(int fila, int columna){
        if(0<=fila && fila<=this->filas-1 && 0<=columna && columna<=this->columnas-1){
            return true;
        }else{
            return false;
        }
    }

    // Funcion que valida si una posicion puede ser considerada como origen
    bool validarPosicionOrigen(int fila_o, int columna_o){
        if(validarPosicion(fila_o, columna_o) == true){
            if(this->tablero[fila_o][columna_o] == 'O'){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }

    // Funcion que valida si una posicion puede ser considerada como destino
    bool validarPosicionDestino(int fila_d, int columna_d){
        if(validarPosicion(fila_d, columna_d) == true){
            if(this->tablero[fila_d][columna_d] == '+'){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
    
    // Funcion que valida un movimiento de fila_o, columna_o hacia fila_d, columna_d
    bool validarMovimiento(int fila_o, int columna_o, int fila_d, int columna_d){
        if(validarPosicionDestino(fila_d, columna_d) == true){
            if(fila_o == fila_d){ // Misma fila
                if(columna_d == columna_o-2 && tablero[fila_o][columna_o-1] == 'O'){ // Hacia la izquierda
                    return true;
                }else if(columna_d == columna_o+2 && tablero[fila_o][columna_o+1] == 'O'){ // Hacia la derecha
                    return true;
                }else{
                    return false;
                }
            }else if(columna_o == columna_d){ // Misma columna
                if(fila_d == fila_o-2 && tablero[fila_o-1][columna_o] == 'O'){ // Hacia la arriba
                    return true;
                }else if(fila_d == fila_o+2 && tablero[fila_o+1][columna_o] == 'O'){ // Hacia la abajo
                    return true;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
    
    // Funcion que realiza un movimiento de fila_o, columna_o hacia fila_d, columna_d
    void realizarMovimiento(int fila_o, int columna_o, int fila_d, int columna_d){
        this->tablero[fila_o][columna_o] = '+';
        this->tablero[(fila_o+fila_d)/2][(columna_o+columna_d)/2] = '+';
        this->tablero[fila_d][columna_d] = 'O';
        this->fichas--;
    }
    
    // Funcion que valida si una cadena es n umerica o no
    bool esNumero(string cadena){
        for(int i=0; i<cadena.size(); i++){
            char c = cadena[i];
            if(c != '0' && c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '7' && c != '8' && c != '9'){
                return false;
            }
        }
        return true;
    }

    // Funcion que registra un movimiento validando las posiciones y el movimiento mismo
    void registrarMovimiento(){
        string fila_o_s, columna_o_s, fila_d_s, columna_d_s;
        int fila_o, columna_o, fila_d, columna_d;
        cout << "-----------------------\n";
        cout << "Realizar de movimiento (Ingresa 'x' para salir)\n";
        cout << "-----------------------\n";
        cout << "Ubicacion de origen\n";
        cout << "Fila   : "; getline(cin, fila_o_s);
        if(fila_o_s != "x"){
            cout << "Columna: "; getline(cin, columna_o_s);
            if(esNumero(fila_o_s) == true && esNumero(columna_o_s) == true){ // Validacion de posiciones de origen numericas
                fila_o = stoi(fila_o_s);
                columna_o = stoi(columna_o_s);
                if(validarPosicionOrigen(fila_o-1, columna_o-1) == true){
                    cout << "Ubicacion de destino\n";
                    cout << "Fila   : "; getline(cin, fila_d_s);
                    cout << "Columna: "; getline(cin, columna_d_s);
                    // Validacion de movimiento
                    if(esNumero(fila_d_s) == true && esNumero(columna_d_s) == true){ // Validacion de posiciones de destino numericas
                        fila_d = stoi(fila_d_s);
                        columna_d = stoi(columna_d_s);
                        if(validarMovimiento(fila_o-1, columna_o-1, fila_d-1, columna_d-1) == true){
                            realizarMovimiento(fila_o-1, columna_o-1, fila_d-1, columna_d-1);
                        }else{
                            cout << "-----------------------\n";
                            cout << "Error! Movimiento invalido\n";
                            system("PAUSE");
                        }
                    }else{
                        cout << "-----------------------\n";
                        cout << "Error! Valores invalidos\n";
                        system("PAUSE");
                    }
                }else{
                    cout << "-----------------------\n";
                    cout << "Error! Ubicacion de origen invalida\n";
                    system("PAUSE");
                }
            }else{
                cout << "-----------------------\n";
                cout << "Error! Valores invalidos\n";
                system("PAUSE");
            }
        }else{
            this->estado = 's';
        }
    }
    
    // Funciona que evalua el cambio de estado de la partida
    void actualizarEstado(){
        if(this->fichas == 1){ // Si queda una sola ficha, el jugador gana
            this->estado = 'g';
        }else{  // Si queda mas de una sola ficha, el jugador debe poder mover alguna ficha
            int movibles = 0; // Contador de ficha movibles inicializado en cero
            for (int i = 0; i < this->filas; i++) {
                for (int j = 0; j < this->columnas; j++) {
                    if(validarPosicionOrigen(i, j) == true){ // Validacion de ficha de origen
                        bool puedeMoverse = false;
                        // Movimientos posibles
                        if(validarMovimiento(i, j, i, j-2) == true){ // Validando movimiento hacia izquierda
                            puedeMoverse = true;
                        }else if(validarMovimiento(i, j, i, j+2) == true){ // Validando movimiento hacia derecha
                            puedeMoverse = true;
                        }else if(validarMovimiento(i, j, i-2, j) == true){ // Validando movimiento hacia arriba
                            puedeMoverse = true;
                        }else if(validarMovimiento(i, j, i+2, j) == true){ // Validando movimiento hacia abajo
                            puedeMoverse = true;
                        }
                        // Actualizacion del contador de fichas que se pueden mover
                        if(puedeMoverse == true){
                            movibles++;
                        }
                    }
                }
            }
            if(movibles == 0){ // Si ninguna ficha es movible, el jugador pierde
                this->estado = 'p';
            }
        }
    }

    // Funcion que inicializa el juego
    void iniciar(){
        // Si la partida anterior termino en estado 'g', 'p' o 's', lo actualiza a 'i' para iniciar nuevamente
        if(this->estado == 'g' || this->estado == 'p' || this->estado == 's'){
            this->estado = 'i';
        }
        while(this->estado == 'i'){
            system("CLS");
            this->mostrarTablero();
            this->registrarMovimiento();
            this->actualizarEstado();
            if(this->estado == 'g'){ // Si es usuario gano
                system("CLS");
                this->mostrarTablero();
                cout << "-----------------------\n";
                cout << "Ganaste! Felicidades\n";
                system("PAUSE");
            }else if(this->estado == 'p'){ // Si el usuario perdio
                system("CLS");
                this->mostrarTablero();
                cout << "-----------------------\n";
                cout << "Perdiste! Puedes volver a intentarlo\n";
                system("PAUSE");
            }else{ // Si aun no gana, ni pierde, ni ha salido del juego
                
            }
        }
    }
};