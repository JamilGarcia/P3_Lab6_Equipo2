#include "Pieza.hpp"
#ifndef CABALLO_H
#define CABALLO_H
class Caballo : public Pieza{
    public: 
    Caballo(Pieza::int,int);
    bool Validar_Movimiento(int x, int y);
    ~Caballo();
};

#endif
