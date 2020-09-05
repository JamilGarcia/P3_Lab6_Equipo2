#include "Pieza.hpp"
#include <string>
using namespace std;
#ifndef ALFIL_H
#define ALFIL_H
class Alfil : public Pieza{
public:
    Alfil(int pos_x, int pos_y, char caracter_pieza,string color) : Pieza(){
        this->posicion_x = pos_x;
        this->posicion_y = pos_y;
        this->caracter_pieza = caracter_pieza;
        this->color = color;
    }

    /*Alfil(int posX, int posY, Pieza ***tablero, char simbolo, string color) : Pieza(posX, posY, tablero, color)
    {
        caracter_pieza = simbolo;
    }*/

    /*bool valid(int f, int c){
        if ((f + 2 == posicion_x && c + 2 == posicion_y) || (f - 2 == posicion_x && c - 2 == posicion_y) ||
            (f + 2 == posicion_x && c - 2 == posicion_y) || (f - 2 == posicion_x && c + 2 == posicion_y)){
            if (tablero[f][c]->getColor() != tablero[posicion_x][posicion_y]->getColor()){
                return true;
            }
        }else{
            return false;
        }
    }*/
    ~Alfil() {}
};
#endif
/*#include "Pieza.hpp"
#ifndef ALFIL_H
#define ALFIL_H
class Alfil : public Pieza{
    public: 
    Alfil(int pos_x, int pos_y, char caracter_pieza):Pieza(){
        this->posicion_x = pos_x;
        this->posicion_y = pos_y;
        this->caracter_pieza = caracter_pieza;
    }
    virtual char getCaracter(){return caracter_pieza;}
    bool Validar_Movimiento(int x, int y){return true;} //Polimorfismo
    ~Alfil(){}
};
#endif*/