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

    //} //Polimorfismo Obligado

    /*virtual string Mandar_Posicion()
    {
        string pos;
        return pos;
    } //Polimorfismo Pensado Para Imprimir mas adelante*/

    /*virtual int Mandar_X(char pos)
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
    } //Polimorfismo De Nota2*/

