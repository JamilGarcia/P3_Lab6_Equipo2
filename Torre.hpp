#include <iostream>
#include <string>
#include "Pieza.hpp"
using namespace std;

class Torre : public Pieza
{
private:
    //Ingresar Variables Privadas
public:
    //Ingresar Variables Publicas
    Torre(int posX, int posY, char Simb)
    {
    }
    ~Torre()
    {
        //Destructor
    }

    bool Validar_Movimiento(); //Polimorfismo
    string Mandar_Posicion();
};