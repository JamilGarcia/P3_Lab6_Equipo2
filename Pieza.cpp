#include "Pieza.hpp"
Pieza::Pieza() {
    this->caracter_pieza = ' ';
    //this->tablero = tablero;
}

char Pieza::getCaracter() {
    return this->caracter_pieza;
}

Pieza::~Pieza(){}