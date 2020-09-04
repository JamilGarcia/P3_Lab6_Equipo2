#include "Pieza.hpp"
#ifndef REY_H
#define REY_H
class Rey : public Pieza{
    public: 
    Rey(){}
    bool Validar_Movimiento(int x, int y){return true;} //Polimorfismo
    ~Rey(){}
};
#endif

