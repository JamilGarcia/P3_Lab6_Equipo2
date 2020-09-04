#include <iostream>
#include <string>
#include "Pieza.hpp"
using namespace std;

class Rey : public Pieza{
    private: 
    //Ingresar Variables Privadas
    public: 
    //Ingresar Variables Publicas
    Rey(int posX, int posY, char Simb)
    {
    }
    ~Rey(){
        //Destructor
    }

    bool Validar_Movimiento(); //Polimorfismo
    string Mandar_Posicion();
};