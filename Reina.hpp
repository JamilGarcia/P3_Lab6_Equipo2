#include "Pieza.hpp"
#include <string>
using namespace std;
#ifndef REINA_H
#define REINA_H
class Reina : public Pieza{
public:
    Reina(int pos_x, int pos_y, char caracter_pieza,string color) : Pieza(){
        this->posicion_x = pos_x;
        this->posicion_y = pos_y;
        this->caracter_pieza = caracter_pieza;
        this->color = color;
    }
    /*Reina(int posX, int posY, Pieza ***tablero, char simbolo, string color) : Pieza(posX, posY, tablero, color)
    {
        caracter_pieza = simbolo;
    }*/

    /*bool valid(int f, int c){
        if ((f + 1 == posicion_x && c + 1 == posicion_y) || (f - 1 == posicion_x && c - 1 == posicion_y) ||
            (f + 1 == posicion_x && c - 1 == posicion_y) || (f - 1 == posicion_x && c + 1 == posicion_y))
        {
            return true;
        }
        else{
            return false;
        }
    }*/
    ~Reina();
};

#endif
/*#include "Pieza.hpp"
#ifndef REINA_H
#define REINA_H
class Reina : public Pieza{
    public: 
    Reina(int pos_x, int pos_y, char caracter_pieza):Pieza(){
        this->posicion_x = pos_x;
        this->posicion_y = pos_y;
        this->caracter_pieza = caracter_pieza;
    }
    virtual char getCaracter(){return caracter_pieza;}
    bool Validar_Movimiento(int x, int y){return true;} //Polimorfismo
    ~Reina();
};

#endif*/
