#include "Pieza.hpp"
#ifndef ALFIL_H
#define ALFIL_H
class Alfil : public Pieza{
    public: 
    Alfil(){}
    bool Validar_Movimiento(int x, int y){return true;} //Polimorfismo
    ~Alfil(){}
};
#endif