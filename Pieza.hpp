#pragma once
#include <string>
#include <iostream>
using namespace std;

class Pieza{
protected:
    char caracter_pieza;
    int posicion_x;
    int posicion_y;
    string color;
    Pieza*** tablero;
    
public:
    Pieza(){} //Constructor
    char getCaracter(){return caracter_pieza;}
    string getColor(){return color;}
    virtual bool validar_movimiento(int x_pos,int pos_y){return true;}
    virtual bool validar_movimiento(int x_inicial,int y_inicial, int x_final, int y_final, Pieza*** tablero){return true;}
    ~Pieza(){}//Destructro
    virtual bool validar_posicion(int pos_x_incicial, int pos_y_inicial, int pos_x_final, int pos_y_final, Pieza ***tablero){
        bool validacion = true;

        if (validar_Posicion_Original(pos_x_incicial, pos_y_inicial)){
            if (validarDentro(pos_x_final, pos_y_final)){
                //Posiciones estan dentro de la matriz
                if (validar_movimiento(pos_x_final, pos_y_final)){
                    tablero[pos_x_final][pos_y_final] = tablero[pos_x_incicial][pos_y_inicial];
                    tablero[pos_x_incicial][pos_y_inicial] = NULL;
                    pos_x_final = posicion_x;
                    pos_y_final = posicion_y;
                    return true;
                }
            }else{
                cout << "Movimiento Invalido\n";
            }
        }
        return validacion;
    }
    bool validarDentro(int x, int y){
        if ((x >= 0 && x < 8) && (y >= 0 && y < 8))
        {
            return true;
        }
        return false;
    }
    bool validar_Posicion_Original(int x, int y){
        if ((x >= 0 && x < 8) && (y >= 0 && y < 8))
        {
            return true;
        }
        return false;
    }
};
