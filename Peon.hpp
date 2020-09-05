#include "Pieza.hpp"
#include <string>
using namespace std;
#ifndef PEON_H
#define PEON_H
class Peon : public Pieza{
public:
    Peon(int pos_x, int pos_y, char caracter_pieza,string color) : Pieza(){
        this->posicion_x = pos_x;
        this->posicion_y = pos_y;
        this->caracter_pieza = caracter_pieza;
        this->color = color;
    }
    /*Peon(int posX, int posY, Pieza ***tablero, char simbolo, string color) : Pieza(posX, posY, tablero, color){
        caracter_pieza = simbolo;
    }*/

    /*bool valid(int f, int c){
        if ((f + 1 == posicion_x) || ((color == "blanco" && ((f - 1 == posicion_x && c - 1 == posicion_y) ||
                                                             (f - 1 == posicion_x && c + 1 == posicion_y))) ||
                                      (color == "negro" && ((f + 1 == posicion_x && c - 1 == posicion_y) ||
                                                            (f + 1 == posicion_x && c + 1 == posicion_y))))){
            if (tablero[f][c]->getColor() != tablero[posicion_x][posicion_y]->getColor()){
                return true;
            }
        }else{
            return false;
        }
    }*/
    ~Peon() {}
};
#endif
/*#include "Pieza.hpp"
#ifndef PEON_H
#define PEON_H

class Peon : public Pieza {
    public:
    Peon(int pos_x, int pos_y, char caracter_pieza):Pieza(){
        this->posicion_x = pos_x;
        this->posicion_y = pos_y;
        this->caracter_pieza = caracter_pieza;
    }
    virtual char getCaracter(){return caracter_pieza;}
    virtual bool validar_movimiento(int x, int y){return true;}
    ~Peon(){}
};
 
#endif*/