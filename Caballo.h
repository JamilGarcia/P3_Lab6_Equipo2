#include "Pieza.h"
#ifndef CABALLO_H
#define CABALLO_H
class Caballo : public Pieza {
    private:
        int posicion_x;
        int posicion_y;
        char caracter_pieza;
        std::string color_pieza;
    public:
        Caballo(int,int,char,std::string);
        virtual bool validar_movimiento(char,int,int,int,int,Pieza***);
        virtual char getCaracter();
        virtual std::string getColor();
        ~Caballo();
};
#endif