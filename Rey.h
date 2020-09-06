#include "Pieza.h"
#ifndef REY_H
#define REY_H
#include <string>

class Rey : public Pieza{
    private:
        int posicion_x;
        int posicion_y;
        char caracter_pieza;
        std::string color_pieza;
    public:
        Rey(int,int,char,std::string);
        virtual bool validar_movimiento(char,int,int,int,int,Pieza***);
        virtual char getCaracter();
        virtual std::string getColor();
        ~Rey();
};

#endif