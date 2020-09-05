#include "Pieza.hpp"
#include <string>
using namespace std;
#ifndef ALFIL_H
#define ALFIL_H
class Alfil : public Pieza{
public:
    Alfil(int pos_x, int pos_y, char caracter_pieza,string color) : Pieza(){
        this->posicion_x = pos_x;
        this->posicion_y = pos_y;
        this->caracter_pieza = caracter_pieza;
        this->color = color;
    }

    /*bool valid(int f, int c){
        if ((f + 2 == posicion_x && c + 2 == posicion_y) || (f - 2 == posicion_x && c - 2 == posicion_y) ||
            (f + 2 == posicion_x && c - 2 == posicion_y) || (f - 2 == posicion_x && c + 2 == posicion_y)){
            if (tablero[f][c]->getColor() != tablero[posicion_x][posicion_y]->getColor()){
                return true;
            }
        }else{
            return false;
        }
    }*/
    ~Alfil() {}
};
#endif

