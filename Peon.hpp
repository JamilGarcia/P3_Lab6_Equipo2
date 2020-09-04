#include "Pieza.hpp"
#ifndef PEON_H
#define PEON_H

class Peon : public Pieza {
    public:
    Peon(int pos_x, int pos_y, char caracter_pieza):Pieza(){
        this->posicion_x = pos_x;
        this->posicion_y = pos_y;
        this->caracter_pieza = caracter_pieza;
    }
    virtual bool validar_movimiento(int x, int y){return true;}
    ~Peon(){}
};
 
#endif