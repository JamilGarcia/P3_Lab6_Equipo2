#include "Pieza.hpp"
#ifndef REY_H
#define REY_H
class Rey : public Pieza{
    public: 
    Rey(int pos_x, int pos_y, char caracter_pieza):Pieza(){
        this->posicion_x = pos_x;
        this->posicion_y = pos_y;
        this->caracter_pieza = caracter_pieza;
    }
    bool Validar_Movimiento(int x, int y){return true;} //Polimorfismo
    ~Rey(){}
};
#endif

