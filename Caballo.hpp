#include <iostream>
#include <string>
#include "Pieza.hpp"
using namespace std;

class Caballo : public Pieza
{
private:
    //Ingresar Variables Privadas
    

public:
    //Ingresar Variables Publicas
    Caballo(int posX, int posY, char Simb)
    {
        
    }

    ~Caballo()
    {
        //Destructor
    }

    bool Validar_Movimiento(); //Polimorfismo
    string Mandar_Posicion();
};
