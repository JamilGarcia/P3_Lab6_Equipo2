#include "Pieza.h"
#ifndef TORRE_H
#define TORRE_H
#include <string>

class Torre : public Pieza{
    private:
        int posicion_x;
        int posicion_y;
        char caracter_pieza;
        std::string color_pieza;
    public:
        Torre(int,int,char,std::string);
        virtual bool validar_movimiento(char,int,int,int,int,Pieza***);
        virtual char getCaracter();
        virtual std::string getColor();
        bool validarTorre(char,int,int,int,int,Pieza***);
        ~Torre();
};
#endif