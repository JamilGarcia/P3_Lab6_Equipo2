#include <iostream>
#include <string>
#include "Pieza.hpp"
using namespace std;

class Reina : public Pieza{
    private: 
    //Ingresar Variables Privadas
   
     
    public: 
    //Ingresar Variables Publicas
    Reina(int posX, int posY, char Simb)
    {
    }
    ~Reina(){
        //Destructor
    }

    bool Validar_Movimiento(); //Polimorfismo
    string Mandar_Posicion();
};

