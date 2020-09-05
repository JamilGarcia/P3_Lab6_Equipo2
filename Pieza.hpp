#pragma once
#include <string>
#include <iostream>
using namespace std;

class Pieza{
protected:
    char caracter_pieza;
    int posicion_x;
    int posicion_y;
    Pieza*** tablero;
    string color;
    virtual validar_movimiento(int,int){return true}
public:
    Pieza(){} //Constructor
    char getCaracter(){return caracter_pieza;}
    string getColor(){return color;}
    //void getTablero(Pieza ***tablero){this->tablero = tablero;}
    ~Pieza(){}//Destructro

 virtual bool validar_posicion(int pos_x_incicial,int pos_y_inicial, int pos_x_final, int pos_y_final, Pieza*** tablero) {
         bool validacion = true;

        if(validar_Posicion_Original(pos_x_incicial,pos_y_inicial)){
            if(validarDentro(pos_x_final,pos_y_final)) {
                //Posiciones estan dentro de la matriz
                if(validar_movimiento(pos_x_final,pos_y_final)){

                }
            } else {
                cout <<"Movimiento Invalido\n";
            } else {
                cout <<"Movimiento Invalido\n";
            }
        }
         
         return validacion;
    }
    bool validarDentro(int x, int y){
        if ((x >= 0 && x < 8) && (y >= 0 && y < 8)){
            return true;
        }
        return false;
    }
    bool validar_Posicion_Original(int x, int y){
        if ((x >= 0 && x < 8) && (y >= 0 && y < 8)){
            return true;
        }
        return false;
    }

};
    /*virtual bool validar_movimiento(int x, int y, Pieza ***tablero){
        bool temp = true;
        if (validarDentro(x, y)){
            if (validarP(x, y)){
                if (Pieza *p = tablero[posicion_x][posicion_y]){
                    delete p;
                    tablero[x][y] = NULL;
                }
                tablero[x][y] = tablero[posicion_x][posicion_y];
                tablero[posicion_x][posicion_y] = NULL;
                posicion_x = x;
                posicion_y = y;
                return true;
            }else{
                cout << "Movimiento no valido" << endl;
                temp = false;
            }
        }
        return temp;
    }*/

    /*bool validarDentro(int x, int y){
        if ((x >= 0 && x < 8) && (y >= 0 && y < 8)){
            return true;
        }
        return false;
    }*/
