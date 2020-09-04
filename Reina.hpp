#include "Pieza.hpp"
#ifndef REINA_H
#define REINA_H
class Reina : public Pieza{
    public: 
    Reina(int pos_x, int pos_y, char caracter_pieza):Pieza(){
        this->posicion_x = pos_x;
        this->posicion_y = pos_y;
        this->caracter_pieza = caracter_pieza;
    }
    bool Validar_Movimiento(int x, int y){return true;} //Polimorfismo
    ~Reina();
};

#endif
