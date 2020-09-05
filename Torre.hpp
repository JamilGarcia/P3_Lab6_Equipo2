
/*
public:
    /*bool valid(int f, int c){
        int cont = 0;
        if (f == posicion_x || c == posicion_y){
            for (int i = 0; i < f; i++){
                for (int j = 0; j < c; j++){
                    if (tablero[i][j].getColor() == "blanco" || tablero[i][j].getColor() == "negro"){
                        cont++;
                    }
                }
            }
            if (cont == 0){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }*/

#include "Pieza.hpp"
#include <iostream>
#ifndef TORRE_H
#define TORRE_H
class Torre : public Pieza{
    public: 
    Torre(int pos_x, int pos_y, char caracter_pieza,string color,Pieza***tablero):Pieza(){
        this->posicion_x = pos_x;
        this->posicion_y = pos_y;
        this->caracter_pieza = caracter_pieza;
        this->color = color;
        this->tablero = tablero;
    }
    virtual char getCaracter(){return caracter_pieza;}

    virtual bool validar_movimiento(int pos_x, int pos_y){
        boole temp = true;
        int contador = 0;  

        if(tablero[pos_x][pos_y] == NULL){

            for (int i = 0; i < 8; i++){
                for (int j = 0; j < 8; j++){
                    if() {

                    }
                }
                
            }
            
        } else if(tablero[pos_x][pos_y]->getColor() = color) {
            //do nothing se come la pieza
        } else {
            temp = false;
        }
        return temp;
    } 
    ~Torre(){}
};
#endif