#include "Pieza.hpp"
#include <string>
using namespace std;
#ifndef CABALLO_H
#define CABALLO_H
class Caballo : public Pieza{
public:
    Caballo(int pos_x, int pos_y, char caracter_pieza, string color,Pieza*** tablero) : Pieza(){
        this->posicion_x = pos_x;
        this->posicion_y = pos_y;
        this->caracter_pieza = caracter_pieza;
        this->color = color;
        this->tablero = tablero;
    }
    virtual bool validar_movimiento(int pos_x, int pos_y){
        bool temp = true;
        int cont = 0;
        if (tablero[pos_x][pos_y] == NULL){
            if (posicion_x == pos_x + 2 && posicion_y == pos_y - 1) {//Movimiento izquierda arriba inferior{
                if (tablero[pos_x][pos_y]->getColor() == "blanco" || tablero[pos_x][pos_y]->getColor() == "negro"){
                    cont++;
                }
            }else if (posicion_x == pos_x + 2 && posicion_y == pos_y + 1){ //Movimiento izquierda abajo superior
                if (tablero[pos_x][pos_y]->getColor() == "blanco" || tablero[pos_x][pos_y]->getColor() == "negro"){
                    cont++;
                }
            }else if (posicion_x == pos_x + 1 && posicion_y == pos_y + 2){ //Movimiento izquierda abajo inferior

                if (tablero[pos_x][pos_y]->getColor() == "blanco" || tablero[pos_y][pos_y]->getColor() == "negro"){
                    cont++;
                }
            }else if (posicion_x == pos_x - 1 && posicion_y == pos_y + 2){ //Movimiento derecha abajo inferior

                if (tablero[pos_x][pos_y]->getColor() == "blanco" || tablero[pos_x][pos_y]->getColor() == "negro"){
                    cont++;
                }
            }else if (posicion_x == pos_x - 2 && posicion_y == pos_y + 1){ //Movimiento derecha abajo superior

                if (tablero[pos_x][pos_y]->getColor() == "blanco" || tablero[pos_x][pos_y]->getColor() == "negro"){
                    cont++;
                }
            }else if (posicion_x == pos_x - 2 && posicion_y == pos_y - 1){ //Movimiento derecha arriba inferior

                if (tablero[pos_x][pos_y]->getColor() == "blanco" || tablero[pos_x][pos_y]->getColor() == "negro"){
                    cont++;
                }
            }else if (posicion_x == pos_x - 1 && posicion_y == pos_y - 2){ //Movimiento derecha arriba inferior
                if (tablero[pos_x][pos_y]->getColor() == "blanco" || tablero[pos_x][pos_y]->getColor() == "negro"){
                    cont++;
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
        if (cont > 0){
            return false;
        }
        return temp;
    }
    ~Caballo() {}
};
#endif