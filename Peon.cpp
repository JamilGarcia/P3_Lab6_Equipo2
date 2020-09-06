#include "Peon.h"
#include <string>
#include <iostream>
using namespace std;
Peon::Peon(int pos_x, int pos_y, char caracter_pieza, string color_pieza){
    posicion_x = pos_x;
    posicion_y = pos_y;
    this->caracter_pieza = caracter_pieza;
    this->color_pieza = color_pieza;
}
char Peon::getCaracter(){ return caracter_pieza;}

string Peon::getColor() { return color_pieza; }

int Peon::getTurno() {return this->turno;}
Peon::~Peon() {}

bool Peon::validar_movimiento(char peon, int x_inicial, int y_inicial, int x_final, int y_final, Pieza ***tablero){
    // TODO: Validar que la posición en la que el usuario dice que está la pieza sea válida
    bool temp = true;
    char busqueda1;
    //Validar para que el caracter de busqueda no tire nullptrexception
    if(tablero[x_inicial][y_inicial] == NULL){
        busqueda1 = ' ';
    } else {
            busqueda1 = tablero[x_inicial][y_inicial]->getCaracter();
    }
    if (busqueda1 == peon){
        // TODO: Validar que la posición a la que el usuario quiere mover la pieza sea válida
        char busqueda2;
        if( tablero[x_final][y_final] == NULL){
            busqueda2 = ' ';
        } else {
            busqueda2 = tablero[x_final][y_final]->getCaracter(); 
        }
        if (busqueda2 == ' '){
            // El peón quiere moverse hacia adelante
            if (peon == 'P'){
                // Turno del jugador 1
                if (x_inicial - 1 == x_final && y_inicial == y_final){
                    this->turno++;
                    temp = true;
                } else if(x_inicial ==  6 && (x_inicial - 2 == x_final )) {
                    //Caso de Primer Movimiento Para 2 espacios adelante 
                    temp =true;
                } else if(x_inicial == 3 && y_inicial - 1 == y_final){
                    //Caso comer al paso por lado izquierdo
                    temp = true;
                } else if(x_inicial == 3 && y_inicial + 1 == y_final){
                    //Caso comer al paso por lado derecho
                    temp = true;
                }else {
                    temp = false;
                }
            }else{
                // Turno del jugador 2
                if (x_inicial + 1 == x_final){
                    this->turno++;
                    temp = true;
                } else if(x_inicial == 1 && (x_inicial + 2 == x_final)){
                    //Caso de Primer Movimiento Para 2 espacios adelante 
                    temp = true;
                } else if(x_inicial == 5 && y_inicial - 1 == y_final){
                    //Caso comer al paso por lado izquierdo
                    temp = true;
                } else if(x_inicial == 5 && y_inicial + 1 == y_final){
                    //Caso comer al paso por lado derecho
                    temp = true;
                }else {
                    temp = false;
                }
            }
        } else{
            // El peon quiere moverse en diagonal (comer)
            if (tablero[x_final][y_final]->getColor() == "negro"){
                if (peon == 'P'){
                    // Turno del jugador 1
                    if (x_inicial - 1 == x_final && (y_inicial - 1 == y_final || y_inicial + 1 == y_final)){
                        // TODO: Comer
                        cout << "El peon se comio a otro\n\n"; 
                        temp = true;
                        //return true;
                    }
                }else{
                    cout << "El peón no puede moverse a esa posición porque hay una pieza de su mismo color (negro)." << endl;
                    temp = false;
                }
            }else{
                if (peon == 'P'){
                    cout << "El peón no puede moverse a esa posición porque hay una pieza de su mismo color (blanco)." << endl;
                    temp = false;
                }else{
                    // Turno del jugador 2
                    if (x_inicial + 1 == x_final && (y_inicial - 1 == y_final || y_inicial + 1 == y_final)){
                        // TODO: Comer
                        cout << "El peon se comio a otro\n\n";
                        temp = false;
                    }
                }
            }
        }
    } else {
        if (busqueda1 == 'p' || busqueda1 == 'P'){
            cout << "En esa posición hay un peón, pero no es de su color." << endl;
        }else if (busqueda1 == ' '){
            cout << "En esa posición no hay nada." << endl;
        }else{
            cout << "En esa posición no hay un peón, hay un: " << busqueda1 << "." << endl;
        }
        temp = false;
        //return false;
    }
    return temp;
}
