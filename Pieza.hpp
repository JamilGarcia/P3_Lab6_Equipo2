#pragma once
class Pieza {

    protected:
    char caracter_pieza;
    int posicion_x;
    int posicion_y;
    public:
        Pieza();//Constructor
        char getCaracter();
        virtual bool validar_movimiento(int x, int y);
        ~Pieza();
};