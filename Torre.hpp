#include "Pieza.hpp"
#include <iostream>
#ifndef TORRE_H
#define TORRE_H
class Torre : public Pieza{
public:
    Torre(int pos_x, int pos_y, char caracter_pieza, string color, Pieza ***tablero) : Pieza(){
        this->posicion_x = pos_x;
        this->posicion_y = pos_y;
        this->caracter_pieza = caracter_pieza;
        this->color = color;
        this->tablero = tablero;
    }
    virtual char getCaracter() { return caracter_pieza; }

    virtual bool validar_movimiento(int pos_x, int pos_y){
        bool temp = true;
        int cont = 0;
        if (tablero[pos_x][pos_y] == NULL){
            if (posicion_x > pos_x && posicion_y == pos_y){//Movimiento izquierda
                for (int i = posicion_x; i < pos_x; i--){
                    if (tablero[i][pos_y]->getColor() == "blanco" || tablero[i][pos_y]->getColor() == "negro"){
                        cont++;
                    }
                }
            }else if (posicion_x < pos_x && posicion_y == pos_y){ //Movimiento derecha
                for (int i = pos_x; i < posicion_x; i++){
                    if (tablero[i][pos_y]->getColor() == "blanco" || tablero[i][pos_y]->getColor() == "negro"){
                        cont++;
                    }
                }
            }else if (posicion_x == pos_x && posicion_y > pos_y){ //Movimiento abajo
                for (int i = posicion_y; i < pos_y; i--){
                    if (tablero[pos_x][i]->getColor() == "blanco" || tablero[pos_y][i]->getColor() == "negro"){
                        cont++;
                    }
                }
            }else if (posicion_x == pos_x && posicion_y < pos_y){ //Movimiento arriba
                for (int i = pos_y; i < posicion_y; i++){
                    if (tablero[pos_x][i]->getColor() == "blanco" || tablero[pos_x][i]->getColor() == "negro"){
                        cont++;
                    }
                }
            }else{ //Movimiento invalido
                return false;
            }
        }else{
            if (tablero[pos_x][pos_y]->getColor() != color){
                return true;
            }else{
                return false;
            }
        }

        if(cont > 0){
            return false;
        }

        return temp;
    }
    ~Torre() {}
};
#endif

