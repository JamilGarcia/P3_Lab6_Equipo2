#include "Reina.h"
#include <string>
#include <iostream>
using namespace std;

Reina::Reina(int posicion_x, int posicion_y, char caracter_pieza,string color_pieza): Pieza(){
    this->posicion_x = posicion_x;
    this->posicion_y = posicion_y;
    this->caracter_pieza = caracter_pieza;
    this->color_pieza = color_pieza;
}

char Reina::getCaracter() {return caracter_pieza;}

string Reina::getColor(){return color_pieza;}

Reina::~Reina(){}//Destructor

bool Reina::validar_movimiento(char reina, int x_inicial, int y_inicial, int x_final, int y_final, Pieza*** tablero){
    bool temp = true;
    char busqueda1;
    //Validar para que el caracter de busqueda no tire nullptrexception
    if(tablero[x_inicial][y_inicial] == NULL){
        busqueda1 = ' ';
    } else {
        busqueda1 = tablero[x_inicial][y_inicial]->getCaracter();
    }

    if(busqueda1 == reina){
        // TODO: Validar que la posición a la que el usuario quiere mover la pieza sea válida
        char busqueda2;
        if( tablero[x_final][y_final] == NULL){
            busqueda2 = ' ';
        } else {
            busqueda2 = tablero[x_final][y_final]->getCaracter(); 
        }

        if(busqueda2 == ' '){
            //Buscar si espacio vacio es valido
            if(reina == 'Q'){
                //Caso Jugador 1
                temp = validarReina('Q',x_inicial,y_inicial,x_final,y_final,tablero);
            } else {
                //Caso Jugador 2
                temp = validarReina('Q',x_inicial,y_inicial,x_final,y_final,tablero);
            }
        }
    }

    return true;
}