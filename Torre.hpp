/*#include "Pieza.hpp"
#include <string>
using namespace std;
#ifndef TORRE_H
#define TORRE_H

class Torre : public Pieza{
public:
    Torre(int pos_x, int pos_y, char caracter_pieza,string color) : Pieza(){
        this->posicion_x = pos_x;
        this->posicion_y = pos_y;
        this->caracter_pieza = caracter_pieza;
        this->color = color;
    }
    ~Torre();
   /* Torre(int posX, int posY, Pieza ***tablero, char simbolo, string color) : Pieza(posX, posY, tablero, color)
    {
        caracter_pieza = simbolo;
    }*/

    /*bool valid(int f, int c){
        int cont = 0;
        if (f == posicion_x || c == posicion_y){
            for (int i = 0; i < f; i++){
                for (int j = 0; j < c; j++){
                    if (tablero[i][j].getColor() == "blanco" || tablero[i][j].getColor() == "negro"){
                        cont++;
                    }
                }
            }
            if (cont == 0){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }*/

#include "Pieza.hpp"
#include <iostream>
#ifndef TORRE_H
#define TORRE_H
class Torre : public Pieza{
    public: 
    Torre(int pos_x, int pos_y, char caracter_pieza,string color):Pieza(){
        this->posicion_x = pos_x;
        this->posicion_y = pos_y;
        this->caracter_pieza = caracter_pieza;
        this->color = color;
    }
    virtual char getCaracter(){return caracter_pieza;}
    bool Validar_Movimiento(int x, int y){return true;} //Polimorfismo
    ~Torre(){}
};
#endif