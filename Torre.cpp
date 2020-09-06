#include "Torre.h"
#include <string>
#include <iostream>
using namespace std;

Torre::Torre(int posicion_x, int posicion_y, char caracter_pieza, string color_pieza): Pieza(){
    this->posicion_x = posicion_x;
    this->posicion_y = posicion_y;
    this->caracter_pieza = caracter_pieza;
    this->color_pieza = color_pieza;
}

char Torre::getCaracter() {return caracter_pieza;}

string Torre::getColor(){return color_pieza;}

Torre::~Torre(){}//Destructor

bool Torre::validar_movimiento(char torre, int x_inicial, int y_inicial, int x_final, int y_final, Pieza*** tablero){
    bool temp = true;

    char busqueda1;
    //Validar para que el caracter de busqueda no tire nullptrexception
    if(tablero[x_inicial][y_inicial] == NULL){
        busqueda1 = ' ';
    } else {
        busqueda1 = tablero[x_inicial][y_inicial]->getCaracter();
    }

    if(busqueda1 == torre){
        // TODO: Validar que la posición a la que el usuario quiere mover la pieza sea válida
        char busqueda2;
        if( tablero[x_final][y_final] == NULL){
            busqueda2 = ' ';
        } else {
            busqueda2 = tablero[x_final][y_final]->getCaracter(); 
        }

        if(busqueda2 == ' '){
            //Busca si el espacio final es valido
            if(torre == 'R'){
                temp = validarTorre(torre,x_inicial, y_inicial,x_final,y_final,tablero);
            } else {
                //Caso Jugador 2
                temp = validarTorre(torre,x_inicial, y_inicial,x_final,y_final,tablero);
            }
        } else {
            //Busqueda cuando hay una pieza para comer
            if(tablero[x_final][y_final]->getColor() == "negro"){
                if(torre == 'R'){
                    //Turno Jugador 1
                    temp = validarTorre(torre,x_inicial, y_inicial,x_final,y_final,tablero);
                    if(temp) 
                        cout << "Se comio la pieza del contrincante";
                }else {
                    //Caso Jugador 2
                    cout << "hola-La torre no puede moverse a esa posición porque hay una pieza de su mismo color (negro)." << endl;
                }
            } else {
                //turno de Jugador 2
                if(torre == 'R'){
                    //Caso Jugador 1
                    cout << "La torre no puede moverse a esa posición porque hay una pieza de su mismo color (blanco)." << endl;
                } else {
                    //Caso Jugador 2
                    temp = validarTorre(torre,x_inicial, y_inicial,x_final,y_final,tablero);
                    if(temp) 
                            cout << "Se comio la pieza del contrincante";
                }
            }
        }
    }else {
        if (busqueda1 == 'r' || busqueda1 == 'R'){
            cout << "En esa posición hay una torre, pero no es de su color." << endl;
        }else if (busqueda1 == ' '){
            cout << "En esa posición no hay nada." << endl;
        }else{
            cout << "En esa posición no hay una torre, hay un: " << busqueda1 << "." << endl;
        }
        temp = false;
    }
    return temp;
}


bool Torre::validarTorre(char torre, int x_inicial, int y_inicial, int x_final, int y_final, Pieza*** tablero){
    bool sub_temporal = true;
    if(torre == 'R'){
        //Caso Jugador 1
        int contador_piezas_jug1 = 0;
        string direccion_busqueda = " ";
        //Determinar la direccion para para la busqueda de la posicion
        //Arriba
        if(x_final < x_inicial && y_inicial == y_final){
            direccion_busqueda = "Arriba";

        } else if(y_final > y_inicial && x_inicial == x_final){
            //Derecha
            direccion_busqueda = "Derecha";
        } else if(y_final < y_inicial && x_inicial == x_final){
            //Izquiera
            direccion_busqueda = "Izquierda";
        } else if(x_final > x_inicial && y_inicial == y_final){
            //Abajo
            direccion_busqueda = "Abajo";
        } else {
            direccion_busqueda = "invalido";
            //do nothing, puso una direccion invalida
        }

        //Dependiendo de la direccion buscar en la matriz
        if(direccion_busqueda == "Arriba"){
            //Busca por piezas arriba de la inicial
            for (int i = x_inicial - 1; i > x_final; i--){
                if(tablero[i][y_inicial] != NULL){
                    contador_piezas_jug1++;
                }
            }
        } else if(direccion_busqueda == "Derecha"){
            //Busca a la derecha de la pieza
            for (int j = y_inicial + 1; j < y_final; j++){
                if(tablero[x_inicial][j] != NULL){
                    contador_piezas_jug1++;
                }
            }
        } else if(direccion_busqueda == "Izquierda"){
            //Busca a la izquierda de la pieza
            for (int j = y_inicial - 1; j > y_final; j--){
                if(tablero[x_inicial][j] != NULL){
                    contador_piezas_jug1++;
                }
            }
        } else if(direccion_busqueda == "Abajo"){
            //Busca abajo de la pieza
            for (int i = x_inicial + 1; i < x_final; i++){
                if(tablero[i][y_inicial] != NULL){
                    contador_piezas_jug1++;
                }
            }
         } else {
            //La posicion final mandada no es valida
            cout << "La torre no puede llegar a esa posicion\n\n";
            sub_temporal = false;
            contador_piezas_jug1 = 1;
        }

        if(contador_piezas_jug1 == 0){
            //Puede avanzar porque no hay piezas en el camino
            sub_temporal = true;
        } else {
            //Encontro minimo 1 pieza en el camino asi que no puede avanzar
            sub_temporal = false;
            if(direccion_busqueda != "invalido")
                cout << "La torre no se puede mover ya que hay piezas en el camino\n\n";
            } 
    } else {
        //Caso Jugador 2
        int contador_piezas_jug2 = 0;
        string direccion_busqueda = " ";
        //Determinar la direccion para para la busqueda de la posicion
        //Arriba
        if(x_final > x_inicial && y_inicial == y_final){
            direccion_busqueda = "Arriba";

        } else if(y_final > y_inicial && x_inicial == x_final){
            //Derecha
            direccion_busqueda = "Derecha";
        } else if(y_final < y_inicial && x_inicial == x_final){
            //Izquiera
            direccion_busqueda = "Izquierda";
        } else if(x_final < x_inicial && y_inicial == y_final){
            //Abajo
            direccion_busqueda = "Abajo";
        } else {
            direccion_busqueda = "invalido";
            //do nothing, puso una direccion invalida
        }
        //Dependiendo de la direccion buscar en la matriz
        if(direccion_busqueda == "Arriba"){
            //Busca por piezas arriba de la inicial
            for (int i = x_inicial + 1; i < x_final; i++){
                if(tablero[i][y_inicial] != NULL){
                    contador_piezas_jug2++;
                }
            }
        } else if(direccion_busqueda == "Derecha"){
            //Busca a la derecha de la pieza
            for (int j = y_inicial + 1; j < y_final; j++){
                if(tablero[x_inicial][j] != NULL){
                    contador_piezas_jug2++;
                }
            }
        } else if(direccion_busqueda == "Izquierda"){
            //Busca a la izquierda de la pieza
            for (int j = y_inicial - 1; j > y_final; j--){
                if(tablero[x_inicial][j] != NULL){
                        contador_piezas_jug2++;
                }
            }
        } else if(direccion_busqueda == "Abajo"){
            //Busca abajo de la pieza
            for (int i = x_inicial - 1; i > x_final; i--){
                if(tablero[i][y_inicial] != NULL){
                    contador_piezas_jug2++;
                }
            }
        } else {
            //La posicion final mandada no es valida
            cout << "La torre no puede llegar a esa posicion\n\n";
            sub_temporal = false;
            contador_piezas_jug2 = 1;
        }

        if(contador_piezas_jug2 == 0){
            //Puede avanzar porque no hay piezas en el camino
            sub_temporal = true;
        } else {
            //Encontro minimo 1 pieza en el camino asi que no puede avanzar
            sub_temporal = false;
            if(direccion_busqueda != "invalido")
                cout << "La torre no se puede mover ya que hay piezas en el camino\n\n";
        }
    }
    return sub_temporal;
}