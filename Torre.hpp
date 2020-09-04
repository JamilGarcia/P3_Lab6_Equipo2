#include "Pieza.hpp"
#ifndef TORRE_H
#define TORRE_H
class Torre : public Pieza{
    public: 
    Torre();
    bool Validar_Movimiento(int x, int y); //Polimorfismo
    ~Torre();
};
#endif