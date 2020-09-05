#include "Pieza.hpp"
#include <string>
using namespace std;
#ifndef REINA_H
#define REINA_H
class Reina : public Pieza{
public:
    Reina(int pos_x, int pos_y, char caracter_pieza,string color) : Pieza(){
        this->posicion_x = pos_x;
        this->posicion_y = pos_y;
        this->caracter_pieza = caracter_pieza;
        this->color = color;
    }

    /*bool valid(int f, int c){
        if ((f + 1 == posicion_x && c + 1 == posicion_y) || (f - 1 == posicion_x && c - 1 == posicion_y) ||
            (f + 1 == posicion_x && c - 1 == posicion_y) || (f - 1 == posicion_x && c + 1 == posicion_y))
        {
            return true;
        }
        else{
            return false;
        }
    }*/
    ~Reina();
};

#endif

