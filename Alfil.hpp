#include <iostream>
#include <string>
#include "Pieza.hpp"
using namespace std;

class Alfil : public Pieza{
    private: 
    //Ingresar Variables Privadas
    public: 
    //Ingresar Variables Publicas
    Alfil(int posX, int posY, char Simb)
    {
    }

    ~Alfil(){
        //Destructor
    }

    bool Validar_Movimiento(); //Polimorfismo
    string Mandar_Posicion();
};