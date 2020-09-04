#include "Pieza.hpp"
#ifndef ALFIL_H
#define ALFIL_H
class Alfil : public Pieza{
    public: 
    Alfil(Pieza::int,int);
    bool Validar_Movimiento(int x, int y); //Polimorfismo
    ~Alfil();
};
#endif

