#include <iostream>
#include <string>
#include "Pieza.hpp"
#include "Caballo.hpp"
#include "Torre.hpp"
#include "Alfil.hpp"
#include "Peon.hpp"
#include "Reina.hpp"
#include "Rey.hpp"

using namespace std;

Pieza*** inicializar_Piezas(Pieza ***);
void imprimir_Tablero_Jugador1(Pieza ***, string, string);
void imprimir_Tablero_Jugador2(Pieza ***, string,string);
int conseguir_posicionX(string,bool);
int conseguir_posicionY(string,bool);

int main(){
    string nombre_jugador1;
    string nombre_jugador2;
    cout << "Jugar Ajedrez" << endl;

    char seguir = 's';
    while (seguir == 's'){
        cout << "Opciones de Ajedrez" << endl
             << "[1] Jugar" << endl
             << "[2] Salir" << endl
             << "Seleccione una opcion: ";
        int opcion_usuario;
        cin >> opcion_usuario;
        cout << endl;
        switch (opcion_usuario){
        case 1:{
            //Jugar
            cout << "Ingrese nombre del jugador 1: ";
            cin >> nombre_jugador1;
            cout << endl;
            cout << "Ingrese nombre del jugador 2: ";
            cin >> nombre_jugador2;
            cout << endl;

            Pieza ***tablero;
            tablero = new Pieza **[8];
            for (int i = 0; i < 8; i++){
                tablero[i] = new Pieza *[8];
                for (int j = 0; j < 8; j++){
                    tablero[i][j] = NULL;
                }
            }
            tablero = inicializar_Piezas(tablero);
            //Determinar Turno
            int turno = 1;
            string movimiento;
            bool terminar_partida = true;
            while(terminar_partida == true){
                if(turno % 2 != 0){
                    //Turno de Jugador 1
                    cout << "Turno Jugador 1" << endl;
                    imprimir_Tablero_Jugador1(tablero, nombre_jugador1, nombre_jugador2);
                    cout << "Ingrese: ";
                    cin >> movimiento;

                    if(movimiento == "bai"){
                        terminar_partida = false;
                        cout << "*Partida finalizada, " << nombre_jugador1 <<" abandonó*\n" << endl;
                    } else {
                        int posicion_x_1, posicion_y_1, posicion_x_2,posicion_y_2;
                        string coordenada_inicial = movimiento.substr(2,3);
                        string coordenada_movimiento = movimiento.substr(5,6);
                        coordenada_inicial = coordenada_inicial.substr(0,2);
                        posicion_y_1 = conseguir_posicionY(coordenada_inicial, false);//Conseguimos coordenada y inicial de la pieza
                        posicion_x_1 = conseguir_posicionX(coordenada_inicial, false);//Conseguimos coordenada x inicial de la pieza
                        //Coordenadas de posicion a intentar mover
                        posicion_x_2 = conseguir_posicionX(coordenada_movimiento, false);
                        posicion_y_2 = conseguir_posicionY(coordenada_movimiento, false);
                        cout << posicion_x_2 << ";" << posicion_y_2 << endl;

                        //Llamar a metodo validar_movimiento
                        Pieza* pieza_seleccionada = tablero[posicion_x_1][posicion_y_1];
                        pieza_seleccionada->validar_movimiento(posicion_x_1, posicion_y_1, posicion_x_2, posicion_y_2, tablero);
                        cout << endl;
                        turno++;
                    }
                } else {
                    //Turno de Jugador 2
                    cout << "Turno Jugador 2" << endl;
                    imprimir_Tablero_Jugador2(tablero,nombre_jugador1,nombre_jugador2);
                    cout << "Ingrese: ";
                    cin >> movimiento;

                    if(movimiento == "bai"){
                        terminar_partida = false;
                        cout << "*Partida finalizada, " << nombre_jugador2 <<" abandonó*\n" << endl;
                    } else {
                        turno++;
                    }
                    
                }
            }
            break;
        }
        case 2:{
            cout << "Fin del Programa";
            seguir = 'n';
            break;
        }
        default:
            cout << "Opcion Invalida";
        }
    }
    return 0;
}

int conseguir_posicionY(string posicion_pieza, bool color){
    int temporal_y = 0;
    char caracter_y = posicion_pieza[0];
    if(color == false){
        //Coordenadas de Blancos
        switch (caracter_y){
        case 'a':
            temporal_y = 0;
            break;
        case 'b':
            temporal_y = 1;
            break;
        case 'c':
            temporal_y = 2;
            break;
        case 'd':
            temporal_y = 3;
            break;
        case 'e':
            temporal_y = 4;
            break;
        case 'f':
            temporal_y = 5;
            break;
        case 'g':
            temporal_y = 6;
            break;
        case 'h':
            temporal_y = 7;
            break;    
        default:
        temporal_y = 9;
            break;
        }
    } else {
        //Coordenadas de Negros
        switch (caracter_y){
        case 'h':
            temporal_y = 0;
            break;
        case 'g':
            temporal_y = 1;
            break;
        case 'f':
            temporal_y = 2;
            break;
        case 'e':
            temporal_y = 3;
            break;
        case 'd':
            temporal_y = 4;
            break;
        case 'c':
            temporal_y = 5;
            break;
        case 'b':
            temporal_y = 6;
            break;
        case 'a':
            temporal_y = 7;
            break;    
        default:
            temporal_y = 9;
            break;
        }
    }

    return temporal_y;
}
int conseguir_posicionX(string posicion_pieza,bool color){
    int temporal_x = 0;
    char caracter_x = posicion_pieza[1];
    if(color == false) {
        //Blancos
        switch (caracter_x){
        case '8':
            temporal_x = 0;
            break;
        case '7':
            temporal_x = 1;
            break;
        case '6':
            temporal_x = 2;
            break;
        case '5':
            temporal_x = 3;
            break;
        case '4':
            temporal_x = 4;
            break;
        case '3':
            temporal_x = 5;
            break;
        case '2':
            temporal_x = 6;
            break;
        case '1':
            temporal_x = 7;
            break;
        default:
            temporal_x = 9;
            break;
        }
    } else {
        //Negros
        switch (caracter_x){
        case '1':
            temporal_x = 0;
            break;
        case '2':
            temporal_x = 1;
            break;
        case '3':
            temporal_x = 2;
            break;
        case '4':
            temporal_x = 3;
            break;
        case '5':
            temporal_x = 4;
            break;
        case '6':
            temporal_x = 5;
            break;
        case '7':
            temporal_x = 6;
            break;
        case '8':
            temporal_x = 7;
            break;
        default:
            temporal_x = 9;
            break;
        }
    }
    return temporal_x;
}

void imprimir_Tablero_Jugador1(Pieza*** tablero, string nombre_jugador1, string nombre_jugador_2){
    cout << "   "<< nombre_jugador_2 << endl;
    int contador_columna = 8;
    for (int i = 0; i < 8; i++){
        for (int j = -1; j < 8; j++){
            if(j == -1){
                cout << "[" << contador_columna << "] ";
                contador_columna--; 
            } else {
                if(tablero[i][j] == NULL) {
                    if(j== 7){
                        cout << "|   |";
                    } else {
                        cout << "|   | ";
                    }
                } else {
                    if(j == 7){
                        cout << "| " << tablero[i][j]->getCaracter() << " |";
                    } else {
                        cout << "| " << tablero[i][j]->getCaracter() << " | ";
                    }
                }
            }
        }
        cout << endl;
    }
    cout << "     [a]   [b]   [c]   [d]   [e]   [f]   [g]   [h]" << endl;
    cout << "   " <<nombre_jugador1 << endl;
}

void imprimir_Tablero_Jugador2(Pieza ***tablero, string nombre_jugador1, string nombre_jugador_2){
    cout << "   "<<nombre_jugador1 << endl;
    int contador_columna = 1;

    for (int i = 7; i >= 0; i--){
        for (int j = -1; j < 8; j++){
            if(j == -1){
                cout << "[" << contador_columna << "]";
                contador_columna++;
            } else {
                if(tablero[i][j] == NULL) {
                    if(j== 7){
                        cout << "|  |";
                    } else {
                        cout << "|   | ";
                    }
                } else {
                    if(j == 7){
                        cout << "| " << tablero[i][j]->getCaracter() << " |";
                    } else {
                        cout << "| " << tablero[i][j]->getCaracter() << " | ";
                    }
                }
            }
        }
        cout << endl;
    }
    cout << "    [h]   [g]   [f]   [e]   [d]   [c]   [b]   [a]" << endl;
    cout << "   " <<nombre_jugador_2 << endl;
}

Pieza*** inicializar_Piezas(Pieza*** tablero){
    //Inicializar Piezas negras
    tablero[0][0] = new Torre(0, 0, 'r',"negro");
    tablero[0][7] = new Torre(0, 7, 'r', "negro");
    //Inicializar Caballos Negros
    tablero[0][1] = new Caballo(0, 1, 'n',"negro");
    tablero[0][6] = new Caballo(0, 6, 'n',"negro");
    //Inicializar Alfin Negro
    tablero[0][2] = new Alfil(0, 2, 'b',"negro");
    tablero[0][5] = new Alfil(0, 5, 'b',"negro");
    //Inicializar Rey Negro
    tablero[0][4] = new Rey(0, 4, 'k',"negro");
    //Inicializar Reina Negro
    tablero[0][3] = new Reina(0, 3, 'q',"negro");

    //Peones Negros
    for (int i = 0; i < 8; i++){
        tablero[1][i] = new Peon(1, i, 'p',"negro");
    }

    //Inicializar Piezas Blancas
    //Torres Blancas
    tablero[7][0] = new Torre(7, 0, 'R',"blanco");
    tablero[7][7] = new Torre(7, 7, 'R',"blanco");
    //Inicializar Caballos Blancas
    tablero[7][1] = new Caballo(7, 1, 'N',"blanco");
    tablero[7][6] = new Caballo(7, 6, 'N',"blanco");
    //Inicializar Alfin Blancas
    tablero[7][2] = new Alfil(7, 2, 'B',"blanco");
    tablero[7][5] = new Alfil(7, 5, 'B',"blanco");

    //Inicializar Rey Blancas
    tablero[7][4] = new Rey(7, 4, 'K',"blanco");
    //Inicializar Reina Blanca
    tablero[7][3] = new Reina(7, 3, 'Q',"blanco");

    //Peones Blancas
    for (int i = 0; i < 8; i++){
        tablero[6][i] = new Peon(6, i, 'P',"blanco");
    }
    return tablero;
}