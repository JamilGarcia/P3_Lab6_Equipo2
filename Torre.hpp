#include "Pieza.hpp"
#include <iostream>
#ifndef TORRE_H
#define TORRE_H
class Torre : public Pieza{
    public: 
    Torre(int pos_x, int pos_y, char caracter_pieza):Pieza(){
        this->posicion_x = pos_x;
        this->posicion_y = pos_y;
        this->caracter_pieza = caracter_pieza;
    }
    bool Validar_Movimiento(int x, int y){return true;} //Polimorfismo
    ~Torre(){}
};
#endif

