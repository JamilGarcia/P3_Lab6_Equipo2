#include "Pieza.hpp"
#ifndef CABALLO_H
#define CABALLO_H
class Caballo : public Pieza{
    public: 
    Caballo(int pos_x, int pos_y, char caracter_pieza):Pieza(){
        this->posicion_x = pos_x;
        this->posicion_y = pos_y;
        this->caracter_pieza = caracter_pieza;
    }
    virtual char getCaracter(){return caracter_pieza;}
    bool Validar_Movimiento(int x, int y){return true;}
    ~Caballo(){}
};

#endif
