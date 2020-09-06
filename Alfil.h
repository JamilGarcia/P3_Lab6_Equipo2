#include "Pieza.h"
#ifndef ALFILH
#define ALFIL_H
class Alfil : public Pieza {
    private:
        int posicion_x;
        int posicion_y;
        char caracter_pieza;
        std::string color_pieza;
    public:
        Alfil(int,int,char,std::string);
        virtual bool validar_movimiento(char,int,int,int,int,Pieza***);
        virtual char getCaracter();
        virtual std::string getColor();
        bool validarAlfil(char,int,int,int,int,Pieza***);
        ~Alfil();
};
#endif