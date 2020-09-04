#include <iostream>
#include <string>
#include "Pieza.hpp"
using namespace std;

class Peon : public Pieza{
    private: 
    //Ingresar Variables Privadas
    public: 
    //Ingresar Variables Publicas
    Peon(int posX, int posY, char Simb)
    {
    }
    ~Peon(){
        //Destructor
    }

    bool Validar_Movimiento(); //Polimorfismo
    string Mandar_Posicion();
};