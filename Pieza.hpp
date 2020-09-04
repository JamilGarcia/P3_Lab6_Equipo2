#pragma once
class Pieza {
    protected:
    char caracter_pieza;
    int posicion_x;
    int posicion_y;
    public:
        Pieza(){}//Constructor
        char getCaracter(){return caracter_pieza;}
        virtual bool validar_movimiento(int, int) {
            return true;
        }
        ~Pieza(){}
};