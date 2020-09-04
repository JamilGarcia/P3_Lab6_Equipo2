#include <iostream>
#include <string>
using namespace std;

class Pieza
{
private:
    //Ingresar variables privadas
    char simboloP; 
    int PosX, PosY;
public:
    //Ingresar Variables publicas
    Pieza();
    Pieza(int posX, int posY, char Simb) //Constructor
    {
        PosX = posX; 
        PosY = posY; 
        simboloP = Simb; 
    }

    ~Pieza() //Destructor
    {
    }
    virtual bool Validar_Movimiento()
    {

    } //Polimorfismo Obligado

    virtual string Mandar_Posicion()
    {
        string pos;
        return pos;
    } //Polimorfismo Pensado Para Imprimir mas adelante

    virtual int Mandar_X(char pos)
    {
        if (pos == 'a')
        {
            return 0;
        }
        else if (pos == 'b')
        {
            return 1;
        }
        else if (pos == 'c')
        {
            return 2;
        }
        else if (pos == 'd')
        {
            return 3;
        }
        else if (pos == 'e')
        {
            return 4;
        }
        else if (pos == 'f')
        {
            return 5;
        }
        else if (pos == 'g')
        {
            return 6;
        }
        else if (pos == 'h')
        {
            return 7;
        };

    } //Polimorfismo De Nota2

    virtual int Mandar_Y(int pos)
    {
        return pos; 
    } //Polimorfismo De Nota2

    virtual int PosActX(){
        return PosX; 
    }

    virtual int PosActY(){
        return PosY;
    }

    virtual char SimboloPieza()
    {
        return simboloP;
    } //Polimorfismo De Nota2
};