#include "Rey.h"
#include <iostream>
#include <string>
using namespace std;

Rey::Rey(int posicion_x, int posicion_y, char caracter_pieza,string color_pieza){
    this->posicion_x = posicion_x;
    this->posicion_y = posicion_y;
    this->caracter_pieza = caracter_pieza;
    this->color_pieza = color_pieza;
}

char Rey::getCaracter() { return caracter_pieza;}

string Rey::getColor() { return color_pieza;}

Rey::~Rey(){}//Destructor

bool Rey::validar_movimiento(char rey, int x_inicial, int y_inicial, int x_final, int y_final, Pieza*** tablero){
    bool temp = true;

    // TODO: Validar que la posición en la que el usuario dice que está la pieza sea válida
    char busqueda1;
    //Validar para que el caracter de busqueda no tire nullptrexception
    if(tablero[x_inicial][y_inicial] == NULL){
        busqueda1 = ' ';
    } else {
            busqueda1 = tablero[x_inicial][y_inicial]->getCaracter();
    }

    if(busqueda1 == rey){
        // TODO: Validar que la posición a la que el usuario quiere mover la pieza sea válida
        char busqueda2;
        if( tablero[x_final][y_final] == NULL){
            busqueda2 = ' ';
        } else {
            busqueda2 = tablero[x_final][y_final]->getCaracter(); 
        }
        if(busqueda2 == ' '){
            //El espacio es valido para moverse
            if(rey == 'K'){
                //Caso Jugador 1
                //Arriba
                if(x_inicial - 1 == x_final){ 
                    temp = true;
                } else if(x_inicial - 1 == x_final && y_inicial + 1 == y_final){
                    //Arriba y Derecha
                    temp = true;
                } else if(y_inicial + 1 == y_final){
                    //Derecha
                    temp = true;
                } else if(x_inicial + 1 == x_final && y_inicial + 1 == y_final){
                    //Abajo y Derecha
                    temp = true;
                } else if(x_inicial + 1 == x_final){
                    //Abajo
                    temp = true;
                } else if(x_inicial + 1 == x_final && y_inicial - 1 == y_final){
                    //Abajo e Izquierda
                    temp =true;
                } else if(y_inicial - 1 == y_final){
                    //Izquiera
                    temp = true;
                } else if(x_inicial - 1 == x_final && y_inicial - 1 == y_final){
                    //Arriba e Izquiera
                    temp = true;
                } else {
                    cout << "Esa posicion es inalcanzable por el caballo\n\n";
                    temp = false;
                }
            } else {
                //Caso Jugador 2
                //Arriba
                if(x_inicial + 1 == x_final){ 
                    temp = true;
                } else if(x_inicial + 1 == x_final && y_inicial + 1 == y_final){
                    //Arriba y Derecha
                    temp = true;
                } else if(y_inicial + 1 == y_final){
                    //Derecha
                    temp = true;
                } else if(x_inicial -1 == x_final && y_inicial + 1 == y_final){
                    //Abajo y Derecha
                    temp = true;
                } else if(x_inicial - 1 == x_final){
                    //Abajo
                    temp = true;
                } else if(x_inicial - 1 == x_final && y_inicial - 1 == y_final){
                    //Abajo e Izquierda
                    temp =true;
                } else if(y_inicial - 1 == y_final){
                    //Izquiera
                    temp = true;
                } else if(x_inicial + 1 == x_final && y_inicial - 1 == y_final){
                    //Arriba e Izquiera
                    temp = true;
                } else {
                    cout << "Esa posicion es inalcanzable por el caballo\n\n";
                    temp = false;
                }

            }
        } else {
            //Caso Para comer una pieza
            if(tablero[x_final][y_final]->getColor() == "negro"){
                if(rey == 'K'){
                    //Turno de Jugador 1
                    //Arriba
                    if(x_inicial - 1 == x_final){ 
                        temp = true;
                    } else if(x_inicial - 1 == x_final && y_inicial + 1 == y_final){
                        //Arriba y Derecha
                        temp = true;
                    } else if(y_inicial + 1 == y_final){
                        //Derecha
                        temp = true;
                    } else if(x_inicial + 1 == x_final && y_inicial + 1 == y_final){
                        //Abajo y Derecha
                        temp = true;
                    } else if(x_inicial + 1 == x_final){
                        //Abajo
                        temp = true;
                    } else if(x_inicial + 1 == x_final && y_inicial - 1 == y_final){
                        //Abajo e Izquierda
                        temp =true;
                    } else if(y_inicial - 1 == y_final){
                        //Izquiera
                        temp = true;
                    } else if(x_inicial - 1 == x_final && y_inicial - 1 == y_final){
                        //Arriba e Izquiera
                        temp = true;
                    } else {
                        cout << "Esa posicion es inalcanzable por el caballo\n\n";
                        temp = false;
                    }
                } else {
                    //Turno de Jugador 2
                    cout << "El Rey no puede moverse a esa posición porque hay una pieza de su mismo color (negro)." << endl;
                }
            } else {
                //Caso para comer piezas blancas
                if(rey == 'K'){
                    cout << "El Rey no puede moverse a esa posición porque hay una pieza de su mismo color (blanco)." << endl;
                } else {
                    //Turno de Jugador 2
                    //Arriba
                    if(x_inicial + 1 == x_final){ 
                        temp = true;
                    } else if(x_inicial + 1 == x_final && y_inicial + 1 == y_final){
                        //Arriba y Derecha
                        temp = true;
                    } else if(y_inicial + 1 == y_final){
                        //Derecha
                        temp = true;
                    } else if(x_inicial -1 == x_final && y_inicial + 1 == y_final){
                        //Abajo y Derecha
                        temp = true;
                    } else if(x_inicial - 1 == x_final){
                        //Abajo
                        temp = true;
                    } else if(x_inicial - 1 == x_final && y_inicial - 1 == y_final){
                        //Abajo e Izquierda
                        temp =true;
                    } else if(y_inicial - 1 == y_final){
                        //Izquiera
                        temp = true;
                    } else if(x_inicial + 1 == x_final && y_inicial - 1 == y_final){
                        //Arriba e Izquiera
                        temp = true;
                    } else {
                        cout << "Esa posicion es inalcanzable por el caballo\n\n";
                        temp = false;
                    }
                }
            }
        }
    }else {
        if (busqueda1 == 'k' || busqueda1 == 'K'){
            cout << "En esa posición hay un Rey, pero no es de su color." << endl;
        }else if (busqueda1 == ' '){
            cout << "En esa posición no hay nada." << endl;
        }else{
            cout << "En esa posición no hay un Rey, hay un: " << busqueda1 << "." << endl;
        }
        temp = false;
    }
    return temp;
}