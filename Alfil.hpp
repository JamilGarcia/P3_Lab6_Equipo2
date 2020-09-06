#include "Pieza.hpp"
#include <string>
using namespace std;
#ifndef ALFIL_H
#define ALFIL_H
class Alfil : public Pieza{
public:
    Alfil(int pos_x, int pos_y, char caracter_pieza, string color,Pieza*** tablero) : Pieza(){
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
            if (posicion_x > pos_x && posicion_y < pos_y) {//Movimiento lateral arriba izquierda
                for (int i = posicion_x; i < pos_x; i--){
                    for (int j = posicion_y; j < pos_y; j++){
                        if (i == j){
                            if (tablero[i][j]->getColor() == "blanco" || tablero[i][j]->getColor() == "negro"){
                                cont++;
                            }
                        }
                    }
                }
            }else if (posicion_x > pos_x && posicion_y > pos_y){ //Movimiento lateral abajo izquierda
                for (int i = posicion_x; i < pos_x; i--){
                    for (int j = posicion_y; j < pos_y; j--){
                        if (i == j){
                            if (tablero[i][j]->getColor() == "blanco" || tablero[i][j]->getColor() == "negro"){
                                cont++;
                            }
                        }
                    }
                }
            }else if (posicion_x < pos_x && posicion_y < pos_y){ //Movimiento lateral arriba derecha
                for (int i = posicion_x; i < pos_x; i++){
                    for (int j = posicion_y; j < pos_y; j++){
                        if (i == j){
                            if (tablero[i][j]->getColor() == "blanco" || tablero[i][j]->getColor() == "negro"){
                                cont++;
                            }
                        }
                    }
                }
            }else if (posicion_x < pos_x && posicion_y > pos_y){ //Movimiento lateral abajo derecha
                for (int i = posicion_x; i < pos_x; i++){
                    for (int j = posicion_y; j < pos_y; j--){
                        if (i == j){
                            if (tablero[i][j]->getColor() == "blanco" || tablero[i][j]->getColor() == "negro"){
                                cont++;
                            }
                        }
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
        if (cont > 0){
            return false;
        }
        return temp;
    }
    ~Alfil() {}
};
#endif

