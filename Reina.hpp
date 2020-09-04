#include "Pieza.hpp"
#ifndef REINA_H
#define REINA_H
class Reina : public Pieza{
    public: 
    Reina();
    bool Validar_Movimiento(int x, int y); //Polimorfismo
    ~Reina();
};

#endif
