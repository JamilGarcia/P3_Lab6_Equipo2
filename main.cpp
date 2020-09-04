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
            imprimir_Tablero_Jugador1(tablero, nombre_jugador1, nombre_jugador2);
            // Libera la matriz
            for (int i = 0; i < 8; i++){
                delete[] tablero[i];
                tablero[i] = NULL;
            }
            delete[] tablero;
            break;
        }
        case 2:
        {
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
                
            }  else {
                if(j == 7){
                    cout << "| " << tablero[i][j]->getCaracter() << "|";
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
    tablero[0][1] = new Caballo(0, 1, 'n');
    tablero[0][6] = new Caballo(0, 6, 'n');
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
    tablero[7][1] = new Caballo(7, 1, 'n');
    tablero[7][6] = new Caballo(7, 6, 'n');
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