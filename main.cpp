#include <iostream>
#include <string>
#include "Pieza.hpp"
#include "Caballo.hpp"
#include "Torre.hpp"
/*#include "Alfil.hpp"

#include "Peon.hpp"
#include "Reina.hpp"
#include "Rey.hpp"*/

using namespace std;

Pieza*** inicializar_Piezas(Pieza***);
int main() {

    string nombre_jugador1;
    string nombre_jugador2;
    cout << "Jugar Ajedrez" << endl;

    char seguir = 's';
    while(seguir =='s') {
        cout << "Opciones de Ajedrez" << endl
        << "[1] Jugar" << endl
        << "[2] Salir" << endl
        << "Seleccione una opcion: ";
        int opcion_usuario;
        cin >> opcion_usuario;
        cout << endl;
        switch(opcion_usuario){
            case 1:{
                //Jugar
                cout << "Ingrese nombre del jugador 1: ";
                cin >> nombre_jugador1;
                cout << endl;
                cout << "Ingrese nombre del jugador 2: ";
                cin >> nombre_jugador2;
                cout << endl;

                Pieza***  tablero;
                tablero = new Pieza**[8];
	            for(int i=0; i<8;i++){
		            tablero[i]=new Pieza* [8];
		            for(int j=0; j<8;j++){
			            tablero[i][j]= NULL;
		            }
	            }	
                tablero = inicializar_Piezas(tablero);
                // Libera la matriz
                for (int i = 0; i < 8; i++){
                    delete[] tablero[i];
                    tablero[i] = NULL;
                }
                    delete[] tablero;
                break;
            }
            case 2: {
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

Pieza*** inicializar_Piezas(Pieza*** tablero){
    //Inicializar Piezas negras
    tablero[0][0] =  new Torre(0,0,'r');
    cout << "puso Torre1" << endl;
    tablero[0][7] =  new Torre(0,7,'r');
    cout << "puso Torre2" << endl;
    //Inicializar Caballos Negros
    tablero[0][1] = new Caballo(0,1,'n');
    cout << "puso Caballo1" << endl;
    tablero[0][6] = new Caballo(0,6,'n');
    cout << "puso Caballo2" << endl;
    //Inicializar Alfin Negro
    //tablero[0][2] = new Alfin();
    //tablero[0][5] = new Alfin();

    //Inicializar Rey Negro
    //tablero[0][4] = new Rey();
    //Inicializar Reina
    //tablero[0][3] = new Reina();

    //Inicializar Blancas
    //Inicializar Piezas Blancas
    //tablero[7][0] =  new Torre();//Torres
    //tablero[7][7] = new Torre();

    //Inicializar Caballos Blancas
    //tablero[7][1] = new Caballo();
    //tablero[7][6] = new Caballo();
    //Inicializar Alfin Negro
    //tablero[7][2] = new Alfin();
    //tablero[7][5] = new Alfin();

    //Inicializar Rey Negro
    //tablero[7][4] = new Rey();
    //Inicializar Reina
    //tablero[7][3] = new Reina();
    return tablero;
}