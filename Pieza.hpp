#pragma once
class Pieza {
    protected:
    char caracter_pieza;
    int posicion_x;
    int posicion_y;
    public:
        Pieza(){}//Constructor
        virtual char getCaracter(){return caracter_pieza;}
        virtual bool validar_movimiento(int, int) {
            return true;
        }
        ~Pieza(){}
};
/*
#pragma once
class Pieza
{
protected:
    char caracter_pieza;
    int posicion_x;
    int posicion_y;
    Pieza ***tablero;
    string color;
    virtual bool validarP(int,int)=0;

public:
    Pieza(); //Constructor
    Pieza(int posX, int posY, Pieza*** tablero, string color){
        posicion_x = posX;
        posicion_y = posY; 
        this->tablero = tablero;
        this->color = color; 
    }

    char getCaracter()
    {
        return caracter_pieza;
    }

    string Pieza::getColor()
    {
        return color;
    }

    void getTablero(Pieza ***tablero)
    {
        this->tablero = tablero;
    }

    virtual bool validar_movimiento(int x, int y, Pieza ***tablero)
    {

        cout << "x: " << posicion_x << " y: " << posicion_y << " xx: " << x << " yy: " << y << endl;
        if (validarDentro(x, y))
        {
            if (validarP(x, y))
            {
                if (Pieza *p = tablero[posicion_x][posicion_y])
                {
                    delete p;
                    tablero[x][y] = NULL;
                }
                tablero[x][y] = tablero[posicion_x][posicion_y];
                tablero[posicion_x][posicion_y] = NULL;
                posicion_x = x;
                posicion_y = y;
                return true;
            }
            else
            {
                cout << "Movimiento no valido" << endl;
            }
        }
        return false;
    }

    bool Pieza::validarDentro(int x, int y)
    {
        if ((x >= 0 && x < 8) && (y >= 0 && y < 8))
        {
            return true;
        }
        return false;
    }
    ~Pieza();
};*/