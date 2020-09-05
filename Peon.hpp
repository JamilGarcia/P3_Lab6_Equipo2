#include "Pieza.hpp"
#include <string>
using namespace std;
#ifndef PEON_H
#define PEON_H
class Peon : public Pieza{
public:
    bool primer_movimiento;
    Peon(int pos_x, int pos_y, char caracter_pieza,string color) : Pieza(){
        this->posicion_x = pos_x;
        this->posicion_y = pos_y;
        this->caracter_pieza = caracter_pieza;
        this->color = color;
        this->primer_movimiento = true;
    }

    bool validar_Posiciones(int x_inicial, int y_inicial,int x_final, int y_final ) {
        if((x_inicial >= 0 && x_inicial < 8) && (y_inicial >= 0 && y_inicial < 8) && (x_final >= 0 && x_final < 8) && (y_final >= 0 && y_final < 8)  ){
            return true;
        } else {
            return false;
        }
    }
    virtual bool validar_movimiento(int x_inicial,int y_inicial, int x_final, int y_final, Pieza*** tablero){
        bool temp = true;
        //boolean de primer movimiento
        if(x_inicial == 6 || x_inicial == 1){
            this->primer_movimiento = false;
        }
        //Validar si la posicion_inicial es valida y la posicion_final es valida
        if(validar_Posiciones(x_inicial,y_inicial,x_final,y_final) ) {
                if(tablero[x_final][y_final] == NULL){
                    //Validar si es el primer movimiento del peon
                    if(primer_movimiento == true && x_inicial == 6){
                        //Caso para Jugador 1
                        if(tablero[x_inicial - 2][y_inicial] == tablero[x_final][y_final]){
                            temp = false;//Se puede mover 2 posiciones para arriba
                        } else if(tablero[x_inicial - 1][y_inicial] == tablero[x_final][y_final]) {
                            temp = false;//Se puede mover 1 posicion para arrriba  
                        } 
                    } else if(primer_movimiento == true && x_inicial == 1){
                        //Caso Primer Movimiento del peon Jugador 2
                        if(tablero[x_inicial + 2][y_inicial] == tablero[x_final][y_final]){
                            temp = false;//Se puede mover 2 posiciones para arriba
                        } else if(tablero[x_inicial +1][y_inicial] == tablero[x_final][y_final]){
                            temp = false;//Se puede mover 1 posicion para arriba
                        }   
                    } else {
                        //No esta en la posicion inicial e intenta moverse al espacio null
                        temp = false;
                    }
                } else if(tablero[x_final][y_final] != NULL && tablero[x_final][y_final]->getColor() != this->color) {
                    //Es un enemigo, validar por color opuesto
                    if(primer_movimiento == true && x_inicial == 6){
                        //Caso para Jugador 1
                        if(tablero[x_inicial - 2][y_inicial] == tablero[x_final][y_final]){
                            temp = false;//Se puede mover 2 posiciones para arriba
                        } else if(tablero[x_inicial - 1][y_inicial] == tablero[x_final][y_final]) {
                            temp = false;//Se puede mover 1 posicion para arrriba
                        } 
                    } else if(primer_movimiento == true && x_inicial == 6){
                        //Caso Primer Movimiento del peon Jugador 2
                        if(tablero[x_inicial + 2][y_inicial] == tablero[x_final][y_final]){
                            temp = false;//Se puede mover 2 posiciones para arriba
                        } else if(tablero[x_inicial +1][y_inicial] == tablero[x_final][y_final]){
                            temp = false;//Se puede mover 1 posicion para arriba
                        }   
                    } else {
                        //No esta en la posicion inicial e intenta moverse al espacio null
                        if(tablero[x_inicial - 1][y_inicial] == tablero[x_final][y_final]){
                            temp = false;//Caso Jugador 1
                        } else if(tablero[x_inicial + 1][y_inicial] == tablero[x_final][y_final]){
                            temp = false;//Caso Jugador 2
                        }
                    }
                } else if(tablero[x_final][y_final] != NULL && tablero[x_final][y_final]->getColor() == this->color){
                    temp = true;//No puede comer a un compañero  
                }
        } else {
            temp = true;
        }
        return temp;
    }
    ~Peon() {}
};
#endif