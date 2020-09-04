#include "Pieza.hpp"
#ifndef PEON_H
#define PEON_H

class Peon : public Pieza {
    public:
    Peon(Pieza::int,int);
    virtual bool validar_movimiento(int x, int y);
    ~Peon();
};
 
#endif