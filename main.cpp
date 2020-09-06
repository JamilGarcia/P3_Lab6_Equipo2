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

Pieza ***inicializar_Piezas(Pieza ***);
void imprimir_Tablero_Jugador1(Pieza ***, string, string);
void imprimir_Tablero_Jugador2(Pieza ***);
int main()
{

<<<<<<< HEAD
=======

int main(){
>>>>>>> b6585aa4738ca4be13d9322378e6b9f5a1d3084b
    string nombre_jugador1;
    string nombre_jugador2;
    cout << "Jugar Ajedrez" << endl;

    char seguir = 's';
    while (seguir == 's')
    {
        cout << "Opciones de Ajedrez" << endl
             << "[1] Jugar" << endl
             << "[2] Salir" << endl
             << "Seleccione una opcion: ";
        int opcion_usuario;
        cin >> opcion_usuario;
        cout << endl;
        switch (opcion_usuario)
        {
        case 1:
        {
            //Jugar
            cout << "Ingrese nombre del jugador 1: ";
            cin >> nombre_jugador1;
            cout << endl;
            cout << "Ingrese nombre del jugador 2: ";
            cin >> nombre_jugador2;
            cout << endl;

            Pieza ***tablero;
            tablero = new Pieza **[8];
            for (int i = 0; i < 8; i++)
            {
                tablero[i] = new Pieza *[8];
                for (int j = 0; j < 8; j++)
                {
                    tablero[i][j] = NULL;
                }
            }
            tablero = inicializar_Piezas(tablero);
            //Determinar Turno
            int turno = 1;
            string movimiento;
            string movimiento_jugador2;
            bool terminar_partida = true;
            bool resultado_movimiento_player1 = true;
            bool resultado_movimiento_player2 = true;
            while(terminar_partida == true){
                if(turno % 2 != 0){
                    while(resultado_movimiento_player1 == true){
                        resultado_movimiento_player1 = true;
                        //Turno de Jugador 1
                        cout << "Turno Jugador 1" << endl;
                        imprimir_Tablero_Jugador1(tablero, nombre_jugador1, nombre_jugador2);
                        cout << "Ingrese: ";
                        cin >> movimiento;

                        if(movimiento == "bai"){
                            terminar_partida = false;
                            resultado_movimiento_player2 = false;
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
                            //Llamar a metodo validar_movimiento
                            char pieza = movimiento[0];
                            switch(pieza){
                                case 'P':{
                                    Peon* peon = dynamic_cast<Peon*>(tablero[posicion_x_1][posicion_y_1]);
                                    resultado_movimiento_player1 = peon->validar_movimiento(posicion_x_1, posicion_y_1,posicion_x_2,posicion_y_2, tablero);
                                    if(resultado_movimiento_player1 == false){
                                        tablero[posicion_x_1][posicion_y_1] = NULL;
                                        tablero[posicion_x_2][posicion_y_2] = new Peon(posicion_x_2,posicion_y_2, 'P', "blanco");
                                    } else 
                                        cout << "Movimiento Invalido\n\n";
                                    break;
                                }
                                case 'N':
                                    Caballo* caballo = dynamic_cast<Caballo*> (tablero[posicion_x_1][posicion_y_1]);
                                    resultado_movimiento_player1 = caballo->validar_movimiento(posicion_x_2,posicion_y_2);
                                    if(resultado_movimiento_player1 == false){
                                        tablero[posicion_x_1][posicion_y_1] = NULL;
                                        tablero[posicion_x_2][posicion_y_2] = new Caballo(posicion_x_2,posicion_y_2, 'N', "blanco");
                                    } else 
                                        cout << "Movimiento Invalido\n\n";
                                break;
                                case 'B':
                                    Alfil* alfil = dynamic_cast<Alfil*> (tablero[posicion_x_1][posicion_y_1]);
                                    resultado_movimiento_player1 = alfil->validar_movimiento(posicion_x_2,posicion_y_2);
                                    if(resultado_movimiento_player1 == false){
                                        tablero[posicion_x_1][posicion_y_1] = NULL;
                                        tablero[posicion_x_2][posicion_y_2] = new Alfil(posicion_x_2,posicion_y_2, 'B', "blanco");
                                    } else 
                                        cout << "Movimiento Invalido\n\n";
                                    break;
                                case 'R':
                                    Torre* torre = dynamic_cast<Torre*> (tablero[posicion_x_1][posicion_y_1]);
                                    resultado_movimiento_player1 = torre->validar_movimiento(posicion_x_2,posicion_y_2);
                                    if(resultado_movimiento_player1 == false){
                                        tablero[posicion_x_1][posicion_y_1] = NULL;
                                        tablero[posicion_x_2][posicion_y_2] = new Torre(posicion_x_2,posicion_y_2, 'R', "blanco");
                                    } else 
                                        cout << "Movimiento Invalido\n\n";
                                    break;
                                case 'Q':
                                    Reina* reina = dynamic_cast<Reina*> (tablero[posicion_x_1][posicion_y_1]);
                                    resultado_movimiento_player1 = reina->validar_movimiento(posicion_x_2,posicion_y_2);
                                    if(resultado_movimiento_player1 == false){
                                        tablero[posicion_x_1][posicion_y_1] = NULL;
                                        tablero[posicion_x_2][posicion_y_2] = new Reina(posicion_x_2,posicion_y_2, 'Q', "blanco");
                                    } else 
                                        cout << "Movimiento Invalido\n\n";
                                    break;
                                case 'K':
                                    Rey* rey = dynamic_cast<Rey*> (tablero[posicion_x_1][posicion_y_1]);
                                    resultado_movimiento_player1 = rey->validar_movimiento(posicion_x_2,posicion_y_2);
                                    if(resultado_movimiento_player1 == false){
                                        tablero[posicion_x_1][posicion_y_1] = NULL;
                                        tablero[posicion_x_2][posicion_y_2] = new Rey(posicion_x_2,posicion_y_2, 'K', "blanco");
                                    } else 
                                        cout << "Movimiento Invalido\n\n";
                                    break;
                                default:
                                    cout << "Movimiento Invalido" << endl;
                            }
                        }
                    }
                    movimiento = ""; 
                    cout << endl;
                    turno++;
                } else {
                    //Turno de Jugador 2
                    while(resultado_movimiento_player2 == true){
                        resultado_movimiento_player2= true;
                        cout << "Turno Jugador 2" << endl;
                        imprimir_Tablero_Jugador2(tablero, nombre_jugador1, nombre_jugador2);
                        cout << "Ingrese: ";
                        cin >> movimiento_jugador2;
                        if(movimiento == "bai"){
                            terminar_partida = false;
                            resultado_movimiento_player2 = false;
                            cout << "*Partida finalizada, " << nombre_jugador2 <<" abandonó*\n" << endl;
                        } else {
                            int posicion_x_1, posicion_y_1, posicion_x_2,posicion_y_2;
                            string coordenada_inicial = movimiento_jugador2.substr(2,3);
                            string coordenada_movimiento = movimiento_jugador2.substr(5,6);
                            coordenada_inicial = coordenada_inicial.substr(0,2);
                            posicion_y_1 = conseguir_posicionY(coordenada_inicial, true);//Conseguimos coordenada y inicial de la pieza
                            posicion_x_1 = conseguir_posicionX(coordenada_inicial, true);//Conseguimos coordenada x inicial de la pieza
                            //Coordenadas de posicion a intentar mover
                            posicion_x_2 = conseguir_posicionX(coordenada_movimiento, true);
                            posicion_y_2 = conseguir_posicionY(coordenada_movimiento, true);
                            //Llamar a metodo validar_movimiento
                            char pieza = movimiento_jugador2[0];
                            switch(pieza){
                                case 'p':{
                                    Peon* peon = dynamic_cast<Peon*>(tablero[posicion_x_1][posicion_y_1]);
                                    resultado_movimiento_player2 = peon->validar_movimiento(posicion_x_1, posicion_y_1,posicion_x_2,posicion_y_2, tablero);
                                    if(resultado_movimiento_player2 == false){
                                        tablero[posicion_x_1][posicion_y_1] = NULL;
                                        tablero[posicion_x_2][posicion_y_2] = new Peon(posicion_x_2,posicion_y_2, 'p', "negro");
                                    } else 
                                        cout << "Movimiento Invalido\n\n";
                                    break;
                                }
                                case 'n':
                                Caballo* caballo = dynamic_cast<Caballo*> (tablero[posicion_x_1][posicion_y_1]);
                                    resultado_movimiento_player2 = caballo->validar_movimiento(posicion_x_2,posicion_y_2);
                                    if(resultado_movimiento_player2 == false){
                                        tablero[posicion_x_1][posicion_y_1] = NULL;
                                        tablero[posicion_x_2][posicion_y_2] = new Caballo(posicion_x_2,posicion_y_2, 'n', "negro");
                                    } else 
                                        cout << "Movimiento Invalido\n\n";
                                    break;
                                case 'b':
                                    Alfil* alfil = dynamic_cast<Alfil*> (tablero[posicion_x_1][posicion_y_1]);
                                    resultado_movimiento_player2 = alfil->validar_movimiento(posicion_x_2,posicion_y_2);
                                    if(resultado_movimiento_player2 == false){
                                        tablero[posicion_x_1][posicion_y_1] = NULL;
                                        tablero[posicion_x_2][posicion_y_2] = new Alfil(posicion_x_2,posicion_y_2, 'b', "negro");
                                    } else 
                                        cout << "Movimiento Invalido\n\n";
                                    break;
                                case 'r':
                                Torre* torre = dynamic_cast<Torre*> (tablero[posicion_x_1][posicion_y_1]);
                                    resultado_movimiento_player2 = torre->validar_movimiento(posicion_x_2,posicion_y_2);
                                    if(resultado_movimiento_player2 == false){
                                        tablero[posicion_x_1][posicion_y_1] = NULL;
                                        tablero[posicion_x_2][posicion_y_2] = new Torre(posicion_x_2,posicion_y_2, 'r', "negro");
                                    } else 
                                        cout << "Movimiento Invalido\n\n";
                                    break;
                                case 'q':
                                Reina* reina = dynamic_cast<Reina*> (tablero[posicion_x_1][posicion_y_1]);
                                    resultado_movimiento_player2 = reina->validar_movimiento(posicion_x_2,posicion_y_2);
                                    if(resultado_movimiento_player2 == false){
                                        tablero[posicion_x_1][posicion_y_1] = NULL;
                                        tablero[posicion_x_2][posicion_y_2] = new Reina(posicion_x_2,posicion_y_2, 'q', "negro");
                                    } else 
                                        cout << "Movimiento Invalido\n\n";
                                    break;
                                case 'k':
                                Rey* rey = dynamic_cast<Rey*> (tablero[posicion_x_1][posicion_y_1]);
                                    resultado_movimiento_player2 = rey->validar_movimiento(posicion_x_2,posicion_y_2);
                                    if(resultado_movimiento_player2 == false){
                                        tablero[posicion_x_1][posicion_y_1] = NULL;
                                        tablero[posicion_x_2][posicion_y_2] = new Rey(posicion_x_2,posicion_y_2, 'k', "negro");
                                    } else 
                                        cout << "Movimiento Invalido\n\n";
                                    break;
                                default:
                                    cout << "Movimiento Invalido" << endl;
                            }
                        }
                    }
                    movimiento_jugador2 = ""; 
                    cout << endl;
                    turno++;
                }
            }
            // Libera la matriz
	        for(int i = 0; i < 8; i++){
		        delete[] tablero[i];
		        tablero[i] = NULL;
	        }
	        delete[] tablero;
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
            temporal_x = 7;
            break;
        case '2':
            temporal_x = 6;
            break;
        case '3':
            temporal_x = 5;
            break;
        case '4':
            temporal_x = 4;
            break;
        case '5':
            temporal_x = 3;
            break;
        case '6':
            temporal_x = 2;
            break;
        case '7':
            temporal_x = 1;
            break;
        case '8':
            temporal_x = 0;
            break;
        default:
            temporal_x = 9;
            break;
        }
    }
    return temporal_x;
}

void imprimir_Tablero_Jugador1(Pieza ***tablero, string nombre_jugador1, string nombre_jugador_2){
    cout << nombre_jugador1 << endl;
    int contador_columna = 8;
    for (int i = 0; i < 8; i++){
        cout << "______________________________________________" <<  endl;
        for (int j = 0; j < 8; j++){
            if(tablero[i][j] == NULL) {
                if(j== 7){
                    cout << "|  |";
                } else {
                    cout << "|   | ";
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
                        cout << "|   |";
                    } else {
                        cout << "|   | ";
                    }
                } else {
                    cout << "| " << tablero[i][j]->getCaracter() << " | ";
                }
                
            }
        }
        cout << endl;
    }

    cout << " [a]   [b]   [c]   [d]   [e]   [f]   [g]   [h]";
    cout << endl;
}
Pieza ***inicializar_Piezas(Pieza ***tablero){
    //Inicializar Piezas negras
    tablero[0][0] = new Torre(0, 0, 'r');
    tablero[0][7] = new Torre(0, 7, 'r');
    //Inicializar Caballos Negros
    tablero[0][1] = new Caballo(0, 1, 'n',"negro", tablero);
    tablero[0][6] = new Caballo(0, 6, 'n',"negro", tablero);
    //Inicializar Alfin Negro
    tablero[0][2] = new Alfil(0, 2, 'b');
    tablero[0][5] = new Alfil(0, 5, 'b');
    //Inicializar Rey Negro
    tablero[0][4] = new Rey(0, 4, 'k');
    //Inicializar Reina Negro
    tablero[0][3] = new Reina(0, 3, 'q');

    //Peones Negros
    for (int i = 0; i < 8; i++){
        tablero[1][i] = new Peon(1, i, 'p');
    }

    //Inicializar Piezas Blancas
    //Torres Blancas
    tablero[7][0] = new Torre(7, 0, 'r');
    tablero[7][7] = new Torre(7, 7, 'r');
    //Inicializar Caballos Blancas
    tablero[7][1] = new Caballo(7, 1, 'N',"blanco",tablero);
    tablero[7][6] = new Caballo(7, 6, 'N',"blanco",tablero);
    //Inicializar Alfin Blancas
    tablero[7][2] = new Alfil(7, 2, 'b');
    tablero[7][5] = new Alfil(7, 5, 'b');

    //Inicializar Rey Blancas
    tablero[7][4] = new Rey(7, 4, 'k');
    //Inicializar Reina Blanca
    tablero[7][3] = new Reina(7, 3, 'q');

    //Peones Blancas
    for (int i = 0; i < 8; i++)
    {
        tablero[6][i] = new Peon(6, i, 'p');
    }
    return tablero;
}
