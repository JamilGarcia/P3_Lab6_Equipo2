#include "Pieza.hpp"
#ifndef PEON_H
#define PEON_H

class Peon : public Pieza {
    public:
    Peon(){}
    virtual bool validar_movimiento(int x, int y){return true;}
    ~Peon(){}
};
 
#endif