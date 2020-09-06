#include "Caballo.h"
#include <string>
#include <iostream>
using namespace std;

Caballo::Caballo(int posicion_x, int posicion_y, char caracter_pieza,string color_pieza): Pieza(){
    this->posicion_x = posicion_x;
    this->posicion_y = posicion_y;
    this->caracter_pieza = caracter_pieza;
    this->color_pieza = color_pieza;
}

char Caballo::getCaracter() {return caracter_pieza;}

string Caballo::getColor(){return color_pieza;}

Caballo::~Caballo(){}//Destructor

bool Caballo::validar_movimiento(char caballo, int x_inicial, int y_inicial, int x_final, int y_final, Pieza*** tablero){
    bool temp = true;

    char busqueda1;
    //Validar para que el caracter de busqueda no tire nullptrexception
    if(tablero[x_inicial][y_inicial] == NULL){
        busqueda1 = ' ';
    } else {
        busqueda1 = tablero[x_inicial][y_inicial]->getCaracter();
    }

    if(busqueda1 == caballo){
        // TODO: Validar que la posición a la que el usuario quiere mover la pieza sea válida
        char busqueda2;
        if( tablero[x_final][y_final] == NULL){
            busqueda2 = ' ';
        } else {
            busqueda2 = tablero[x_final][y_final]->getCaracter(); 
        }

        if(busqueda2 == ' '){
            //Busqueda si posicion a la q se quiere mover el caballo es valida
            if(caballo == 'N'){
                //Caso Jugador 1
                //Arriba y derecha
                if(x_inicial - 2  == x_final && y_inicial + 1 == y_final){
                    temp = true;
                } else if(x_inicial - 2 == x_final && y_inicial - 1 == y_final){
                    //Arriba e izquierda
                    temp = true;
                } else if(y_inicial + 2 == y_final && x_inicial - 1 == x_final){
                    //Derecha y Arriba
                    temp = true;
                } else if(y_inicial + 2 == y_final && x_inicial + 1 == x_final){
                    //Derecha y Abajo
                    temp = true;
                } else if(x_inicial + 2 == x_final && y_inicial + 1 ==  y_final ){
                    //Abajo y Derecha
                    temp = true;
                } else if(x_inicial + 2 == x_final && y_inicial - 1 == y_final){
                    //Abajo e Izquierda
                    temp = true;
                } else if(y_inicial - 2 == y_final && x_inicial + 1 == x_final){
                    //Izquierda y Abajo
                    temp = true;
                } else if(y_inicial - 2 == y_final && x_inicial - 1 == x_final){
                    //Izquierda y Arriba
                    temp = true;
                } else {
                    //Movimiento invalido
                    temp = false;
                    cout << "Esa posicion es inalcanzable por el caballo\n\n";
                }
            } else {
                //Caso Jugador 2
                if(x_inicial + 2  == x_final && y_inicial + 1 == y_final){
                    //Arriba y Derecha
                    temp = true;
                } else if(x_inicial + 2 == x_final && y_inicial - 1 == y_final){
                    //Arriba e izquierda
                    temp = true;
                } else if(y_inicial + 2 == y_final && x_inicial - 1 == x_final){
                    //Derecha y Arriba
                    temp = true;
                } else if(y_inicial +    2 == y_final && x_inicial + 1 == x_final){
                    //Derecha y Abajo
                    temp = true;
                } else if(x_inicial - 2 == x_final && y_inicial + 1 ==  y_final ){
                    //Abajo y Derecha
                    temp = true;
                } else if(x_inicial - 2 == x_final && y_inicial - 1 == y_final){
                    //Abajo e Izquierda
                    temp = true;
                } else if(y_inicial - 2 == y_final && x_inicial - 1 == x_final){
                    //Izquierda y Abajo
                    temp = true;
                } else if(y_inicial - 2 == y_final && x_inicial + 1 == x_final){
                    //Izquierda y Arriba
                    temp = true;
                } else {
                    //Movimiento Invalido
                    temp = false;
                    cout << "Esa posicion es inalcanzable por el caballo\n\n";
                }
            }
        } else {
            //Busqueda en la posicion si hay pieza opuesta para comer
            if(tablero[x_final][y_final]->getColor() == "negro"){
                if(caballo == 'N'){
                //Turno de Jugador 1
                //Arriba y derecha
                if(x_inicial - 2  == x_final && y_inicial + 1 == y_final){
                    temp = true;
                } else if(x_inicial - 2 == x_final && y_inicial - 1 == y_final){
                    //Arriba e izquierda
                    temp = true;
                } else if(y_inicial + 2 == y_final && x_inicial - 1 == x_final){
                    //Derecha y Arriba
                    temp = true;
                } else if(y_inicial + 2 == y_final && x_inicial + 1 == x_final){
                    //Derecha y Abajo
                    temp = true;
                } else if(x_inicial + 2 == x_final && y_inicial + 1 ==  y_final ){
                    //Abajo y Derecha
                    temp = true;
                } else if(x_inicial + 2 == x_final && y_inicial - 1 == y_final){
                    //Abajo e Izquierda
                    temp = true;
                } else if(y_inicial - 2 == y_final && x_inicial + 1 == x_final){
                    //Izquierda y Abajo
                    temp = true;
                } else if(y_inicial - 2 == y_final && x_inicial - 1 == x_final){
                    //Izquierda y Arriba
                    temp = true;
                } else {
                    //Movimiento invalido
                    temp = false;//La posicion de movimiento no es valida o no hay pieza
                }
                if(temp)
                    cout << "Se comio la pieza del contrincante\n\n";

                } else {
                    //Caso Jugador 2
                    cout << "hola-El peón no puede moverse a esa posición porque hay una pieza de su mismo color (negro)." << endl;
                }
            } else {
                //Color Blanco
                if(caballo == 'P'){
                    //Caso Jugador 1
                    cout << "El peón no puede moverse a esa posición porque hay una pieza de su mismo color (blanco)." << endl;
                } else {
                    //Caso Jugador 2
                    if(x_inicial + 2  == x_final && y_inicial + 1 == y_final){
                        //Arriba y Derecha
                        temp = true;
                    } else if(x_inicial + 2 == x_final && y_inicial - 1 == y_final){
                        //Arriba e izquierda
                        temp = true;
                    } else if(y_inicial + 2 == y_final && x_inicial - 1 == x_final){
                        //Derecha y Arriba
                        temp = true;
                    } else if(y_inicial +    2 == y_final && x_inicial + 1 == x_final){
                        //Derecha y Abajo
                        temp = true;
                    } else if(x_inicial - 2 == x_final && y_inicial + 1 ==  y_final ){
                        //Abajo y Derecha
                        temp = true;
                    } else if(x_inicial - 2 == x_final && y_inicial - 1 == y_final){
                        //Abajo e Izquierda
                        temp = true;
                    } else if(y_inicial - 2 == y_final && x_inicial - 1 == x_final){
                        //Izquierda y Abajo
                        temp = true;
                    } else if(y_inicial - 2 == y_final && x_inicial + 1 == x_final){
                        //Izquierda y Arriba
                        temp = true;
                    } else {
                        //Movimiento Invalido
                        temp = false;
                    }

                    if(temp)
                        cout << "Se comio la pieza del contrincante\n\n";
                }
            }
        } 
     } else {
        if (busqueda1 == 'n' || busqueda1 == 'N'){
            cout << "En esa posición hay un caballo, pero no es de su color." << endl;
        }else if (busqueda1 == ' '){
            cout << "En esa posición no hay nada." << endl;
        }else{
            cout << "En esa posición no hay un caballo, hay un: " << busqueda1 << "." << endl;
        }
        temp = false;
    }
    return temp;

}