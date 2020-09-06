#include "Pieza.h"
#include <string>
#ifndef PEON_H
#define PEON_H

class Peon : public Pieza{
    private:
        int posicion_x;
        int posicion_y;
        char caracter_pieza;
        std::string color_pieza;
    public:
        Peon(int,int,char,std::string);
        virtual bool validar_movimiento(char,int,int,int,int,Pieza***);
        virtual char getCaracter();
        virtual std::string getColor();
        ~Peon();
};
#endif