#pragma once
#include <string>
class Pieza{
    public:
        Pieza();
        virtual bool validar_movimiento(char,int,int,int,int,Pieza***);
        virtual char getCaracter();
        virtual std::string getColor();
        ~Pieza();
};