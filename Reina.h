#include "Pieza.h"
#ifndef REINA_H
#define REINA_H
#include <string>

class Reina : public Pieza{
    private:
        int posicion_x;
        int posicion_y;
        char caracter_pieza;
        std::string color_pieza;
    public:
        Reina(int,int,char,std::string);
        virtual bool validar_movimiento(char,int,int,int,int,Pieza***);
        virtual char getCaracter();
        virtual std::string getColor();
        bool validarReina(char,int,int,int,int,Pieza***);
        ~Reina();
};

#endif