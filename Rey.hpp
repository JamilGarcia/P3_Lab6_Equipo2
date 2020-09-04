#include "Pieza.hpp"
#ifndef REY_H
#define REY_H
class Alfil : public Pieza{
    public: 
    REY(Pieza::int,int);
    bool Validar_Movimiento(int x, int y); //Polimorfismo
    ~REY();
};
#endif

