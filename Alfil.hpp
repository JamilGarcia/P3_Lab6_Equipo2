#include "Pieza.hpp"
#ifndef ALFIL_H
#define ALFIL_H
class Alfil : public Pieza{
    public: 
    Alfil(int pos_x, int pos_y, char caracter_pieza):Pieza(){
        this->posicion_x = pos_x;
        this->posicion_y = pos_y;
        this->caracter_pieza = caracter_pieza;
    }
    virtual char getCaracter(){return caracter_pieza;}
    bool Validar_Movimiento(int x, int y){return true;} //Polimorfismo
    ~Alfil(){}
};
#endif

