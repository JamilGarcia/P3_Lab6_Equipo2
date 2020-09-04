#include <iostream>
#include <string>
#include <vector>
#include "Pieza.hpp"
#include "Alfil.hpp"
#include "Caballo.hpp"
#include "Peon.hpp"
#include "Reina.hpp"
#include "Rey.hpp"
#include "Torre.hpp"

using namespace std;

void ImprimirTablero(Alfil Al, Caballo Co, Peon Pn, Reina Ra, Rey Ry, Torre Te)
{
    //Explicacion: Se pide como atributo cada pieza usada, para que asi mas adelante por medio de un string se pueda mandar cual es la posicion actual
    //y poderla imprimir de un solo. Porque string? Pues, aunque sea string solo mandaria dos caracteres el primero seria X y el segundo seria Y.
    //Porque no usar char[2]? Porque es mas facil trabajar con string, o asi lo veo yo.
    //Nota: Tengo como idea hacer esto, no lo he intentado asi que no se si funcionará, por mi parte hay permiso de usar otra idea.
    //Nota 2: Se me acaba de ocurrir usar un vector Pieza para meter todas las piezas dentro y asi no usar el monton de variables desde el principio. (esta es nota para mi para recordarme despues)
    //Actualizacion De Nota 2: Me gustó mas el metodo de la nota 2, supongo que funciona pero por cualquier cosa dejo este aqui tambien por si acaso y para que no se me olvide la idea.
    char Matriz[7][7];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Matriz[i][j] = '_';
        }
    }
    string tempPosAl = Al.Mandar_Posicion();
    string tempPosCo = Co.Mandar_Posicion();
    string tempPosPn = Pn.Mandar_Posicion();
    string tempPosRa = Ra.Mandar_Posicion();
    string tempPosRy = Ry.Mandar_Posicion();
    string tempPosTe = Te.Mandar_Posicion();
}

//Prueba de la nota 2, ignorar
void ImprimirTabl(vector<Pieza> PZ)
{
    char Matriz[7][7];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Matriz[i][j] = '_';
        }
    }

    for (int i = 0; i < PZ.size(); i++)
    {
        int tempX = PZ.at(i).PosActX();
        int tempY = PZ.at(i).PosActY();
        char pieza = PZ.at(i).SimboloPieza();
        Matriz[tempX][tempY] = pieza;
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << "[" << Matriz[i][j] << "]";
        }
        cout << endl;
    }
}

void  CrearTablero()
{
    //Creacion De Blancas
}

vector <Pieza> LPZ; 

Pieza*** tablero;

int main()
{
    tablero = new Pieza**[8];
	for(int i=0; i<8;i++){
		tablero[i]=new Pieza*[8];
		for(int j=0; j<8;j++){
			tablero[i][j]=NULL;
		}
	}	
}

