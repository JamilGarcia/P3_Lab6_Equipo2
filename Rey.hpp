#include "Pieza.hpp"
#include <string>
using namespace std;
#ifndef REY_H
#define REY_H
class Rey : public Pieza
{
public:
    Rey(int pos_x, int pos_y, char caracter_pieza, string color, Pieza*** tablero) : Pieza(){
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
            if (posicion_x == pos_x + 1 && posicion_y == pos_y){//Movimiento izquierda
                if (tablero[pos_x][pos_y]->getColor() == "blanco" || tablero[pos_x][pos_y]->getColor() == "negro"){
                    cont++;
                }
            }else if (posicion_x == pos_x - 1 && posicion_y == pos_y){ //Movimiento derecha
                for (int i = pos_x; i < posicion_x; i++){
                    if (tablero[i][pos_y]->getColor() == "blanco" || tablero[i][pos_y]->getColor() == "negro"){
                        cont++;
                    }
                }
            }else if (posicion_x == pos_x && posicion_y == pos_y + 1){ //Movimiento abajo

                if (tablero[pos_x][pos_y]->getColor() == "blanco" || tablero[pos_y][pos_y]->getColor() == "negro"){
                    cont++;
                }
            }else if (posicion_x == pos_x && posicion_y == pos_y - 1){ //Movimiento arriba

                if (tablero[pos_x][pos_y]->getColor() == "blanco" || tablero[pos_x][pos_y]->getColor() == "negro"){
                    cont++;
                }
            }else if (posicion_x == pos_x - 1 && posicion_y == pos_y - 1){ // Movimiento diagonal arriba derecha
                if (pos_x == pos_y){s
                    if (tablero[pos_x][pos_y]->getColor() == "blanco" || tablero[pos_x][pos_y]->getColor() == "negro"){
                        cont++;
                    }
                }else{
                    return false;
                }
            }else if (posicion_x == pos_x + 1 && posicion_y == pos_y - 1){ // Movimiento diagonal arriba izquierda
                if (pos_x == pos_y){
                    if (tablero[pos_x][pos_y]->getColor() == "blanco" || tablero[pos_x][pos_y]->getColor() == "negro"){
                        cont++;
                    }
                }else{
                    return false;
                }
            }else if (posicion_x == pos_x + 1 && posicion_y == pos_y + 1){ // Movimiento diagonal abajo izquierda
                if (pos_x == pos_y){
                    if (tablero[pos_x][pos_y]->getColor() == "blanco" || tablero[pos_x][pos_y]->getColor() == "negro"){
                        cont++;
                    }
                }else{
                    return false;
                }
            }else if (posicion_x == pos_x - 1 && posicion_y == pos_y + 1){ // Movimiento diagonal abajo izquierda
                if (pos_x == pos_y){
                    if (tablero[pos_x][pos_y]->getColor() == "blanco" || tablero[pos_x][pos_y]->getColor() == "negro"){
                        cont++;
                    }
                }else{
                    return false;
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

        if (cont > 0)
        {
            return false;
        }

        return temp;
    }
    ~Rey();
};

#endif
