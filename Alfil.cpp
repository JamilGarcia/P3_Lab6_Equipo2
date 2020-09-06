#include "Alfil.h"
#include <string>
#include <iostream>
using namespace std;

Alfil::Alfil(int posicion_x, int posicion_y, char caracter_pieza,string color_pieza): Pieza(){
    this->posicion_x = posicion_x;
    this->posicion_y = posicion_y;
    this->caracter_pieza = caracter_pieza;
    this->color_pieza = color_pieza;
}

char Alfil::getCaracter() {return caracter_pieza;}

string Alfil::getColor(){return color_pieza;}

Alfil::~Alfil(){}//Destructor

bool Alfil::validar_movimiento(char alfil, int x_inicial, int y_inicial, int x_final, int y_final, Pieza*** tablero){
    bool temp = true;

    char busqueda1;
    if(tablero[x_inicial][y_inicial] == NULL){
        busqueda1 = ' ';
    } else {
        busqueda1 = tablero[x_inicial][y_inicial]->getCaracter();
    }

    if(busqueda1 == alfil){
        // TODO: Validar que la posición a la que el usuario quiere mover la pieza sea válida
        char busqueda2;
        if( tablero[x_final][y_final] == NULL){
            busqueda2 = ' ';
        } else {
            busqueda2 = tablero[x_final][y_final]->getCaracter(); 
        }

        if(busqueda2 == ' '){
            //Validar si se puede mover al espacio vacio
            if(alfil == 'B'){
                //Caso Jugador 1
                temp = validarAlfil('B',x_inicial,y_inicial,x_final,y_final,tablero);
            } else {
                //Caso Jugador 2
                temp = validarAlfil('b',x_inicial,y_inicial,x_final,y_final,tablero);
            }
        } else {
            //Caso cuando hay una pieza opuesta
        }

    }else {
        if (busqueda1 == 'b' || busqueda1 == 'B'){
            cout << "En esa posición hay un alfin, pero no es de su color." << endl;
        }else if (busqueda1 == ' '){
            cout << "En esa posición no hay nada." << endl;
        }else{
            cout << "En esa posición no hay un alfin, hay un: " << busqueda1 << "." << endl;
        }
        temp = false;
    }
    return temp;
}

bool Alfil::validarAlfil(char alfil, int x_inicial, int y_inicial, int x_final, int y_final, Pieza*** tablero){
    bool sub_temporal = true;
    if(alfil == 'B'){
        //Turno de Jugador 1
        int contador_piezas_jug1 = 0;
        string direccion_alfil = " ";
        //Determinar Direccion de Alfil

        //Esquina Derecha(Arriba y Derecha)
        if(x_final < x_inicial && y_final > y_inicial){
            direccion_alfil = "derecha_superior";
        } else if(x_final > x_inicial && y_final > y_inicial){
            //Esquina Derecha inferior
            direccion_alfil = "derecha_inferior";
        } else if(x_final > x_inicial && y_final < y_inicial){
            //Esquina Izquierda Inferior
            direccion_alfil = "izquiera_inferior";
        } else if(x_final < x_inicial && y_final < y_inicial){
            //Esquina Izquierda Inferior
            direccion_alfil = "izquiera_superior";
        } else {
            //Posicionamiento Invalida
            direccion_alfil = "invalida";
        }

        //Dependiendo de la direccion buscar en diagonal
        if(direccion_alfil == "derecha_superior"){
            //Esquina Derecha Superior
            int contador_derecha_sup= 1;
            for ( int i = x_inicial -1; i > x_final; i--){
                for ( int j = y_inicial + 1;j < y_final ; j++){
                    if(j == y_inicial + contador_derecha_sup && i == x_inicial - contador_derecha_sup){
                        contador_derecha_sup++;
                        //Busca en el camino antes de la posicion final
                        if(tablero[i][j] != NULL){
                            contador_piezas_jug1++;
                        }
                    }   
                }
            }
        } else if(direccion_alfil == "derecha_inferior"){
            //Esquina Derecha Inferior
            int contador_derecha_inf = 1;
            for ( int i = x_inicial +1; i < x_final; i++){
                for ( int j = y_inicial + 1;j < y_final ; j++){
                    if(j == y_inicial + contador_derecha_inf && i == x_inicial + contador_derecha_inf){
                        contador_derecha_inf++;
                        //Busca en el camino antes de la posicion final
                        if(tablero[i][j] != NULL){
                            contador_piezas_jug1++;
                        }
                    }   
                }
            }
        } else if(direccion_alfil == "izquiera_inferior"){
            //Esquina Izquierda Inferior
            int contador_izq_inferior = 1;
            for ( int i = x_inicial +1; i < x_final; i++){
                for ( int j = y_inicial - 1;j > y_final ; j--){
                    if(j == y_inicial - contador_izq_inferior && i == x_inicial + contador_izq_inferior){
                        //cout << "[" << i << "," << j << "]" << endl;
                        contador_izq_inferior++;
                        //Busca en el camino antes de la posicion final
                        if(tablero[i][j] != NULL){
                            contador_piezas_jug1++;
                        }
                    }   
                }
            }
        } else if(direccion_alfil =="izquiera_superior" ){
            //Esquina Izquierda Superior
            int contador_izq_superior = 1;
            for ( int i = x_inicial  - 1; i > x_final; i--){
                for ( int j = y_inicial - 1;j > y_final ; j--){
                    if(j == y_inicial - contador_izq_superior && i == x_inicial - contador_izq_superior){
                        cout << "[" << i << "," << j << "]" << endl;
                        contador_izq_superior++;
                        //Busca en el camino antes de la posicion final
                        if(tablero[i][j] != NULL){
                            contador_piezas_jug1++;
                        }
                    }   
                }
            }
        } else {
            //Posicion Final Invalida
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
            if(direccion_alfil != "invalida")
                cout << "El alfil no se puede mover ya que hay piezas en el camino\n\n";
        } 

    } else {
        //Turno de Jugador 2
        int contador_piezas_jug2 = 0;
        string direccion_alfil = " ";
        //Determinar Direccion de Alfil

        //Esquina Derecha(Arriba y Derecha)
        if(x_final > x_inicial && y_final > y_inicial){
            direccion_alfil = "derecha_superior";
        } else if(x_final < x_inicial && y_final > y_inicial){
            //Esquina Derecha inferior
            direccion_alfil = "derecha_inferior\n";
        } else if(x_final < x_inicial && y_final < y_inicial){
            //Esquina Izquierda Inferior
            direccion_alfil = "izquiera_inferior";
        } else if(x_final > x_inicial && y_final < y_inicial){
            //Esquina Izquierda Superior
            direccion_alfil = "izquiera_superior";
        } else {
            //Posicionamiento Invalida
            direccion_alfil = "invalida";
        }

        //Dependiendo de la direccion buscar en diagonal
        /*if(direccion_alfil == "derecha_superior"){
            //Esquina Derecha Superior
            int contador_derecha_sup= 1;
            for ( int i = x_inicial -1; i > x_final; i--){
                for ( int j = y_inicial + 1;j < y_final ; j++){
                    if(j == y_inicial + contador_derecha_sup && i == x_inicial - contador_derecha_sup){
                        contador_derecha_sup++;
                        //Busca en el camino antes de la posicion final
                        if(tablero[i][j] != NULL){
                            contador_piezas_jug1++;
                        }
                    }   
                }
            }
        } else if(direccion_alfil == "derecha_inferior"){
            //Esquina Derecha Inferior
            int contador_derecha_inf = 1;
            for ( int i = x_inicial +1; i < x_final; i++){
                for ( int j = y_inicial + 1;j < y_final ; j++){
                    if(j == y_inicial + contador_derecha_inf && i == x_inicial + contador_derecha_inf){
                        contador_derecha_inf++;
                        //Busca en el camino antes de la posicion final
                        if(tablero[i][j] != NULL){
                            contador_piezas_jug1++;
                        }
                    }   
                }
            }
        } else if(direccion_alfil == "izquiera_inferior"){
            //Esquina Izquierda Inferior
            int contador_izq_inferior = 1;
            for ( int i = x_inicial +1; i < x_final; i++){
                for ( int j = y_inicial - 1;j > y_final ; j--){
                    if(j == y_inicial - contador_izq_inferior && i == x_inicial + contador_izq_inferior){
                        //cout << "[" << i << "," << j << "]" << endl;
                        contador_izq_inferior++;
                        //Busca en el camino antes de la posicion final
                        if(tablero[i][j] != NULL){
                            contador_piezas_jug1++;
                        }
                    }   
                }
            }
        } else if(direccion_alfil =="izquiera_superior" ){
            //Esquina Izquierda Superior
            int contador_izq_superior = 1;
            for ( int i = x_inicial  - 1; i > x_final; i--){
                for ( int j = y_inicial - 1;j > y_final ; j--){
                    if(j == y_inicial - contador_izq_superior && i == x_inicial - contador_izq_superior){
                        cout << "[" << i << "," << j << "]" << endl;
                        contador_izq_superior++;
                        //Busca en el camino antes de la posicion final
                        if(tablero[i][j] != NULL){
                            contador_piezas_jug1++;
                        }
                    }   
                }
            }
        } else {
            //Posicion Final Invalida
            cout << "La torre no puede llegar a esa posicion\n\n";
            sub_temporal = false;
            contador_piezas_jug1 = 1;
        }
        */
        if(contador_piezas_jug2 == 0){
            //Puede avanzar porque no hay piezas en el camino
            sub_temporal = true;
        } else {
            //Encontro minimo 1 pieza en el camino asi que no puede avanzar
            sub_temporal = false;
            if(direccion_alfil != "invalida")
                cout << "El alfil no se puede mover ya que hay piezas en el camino\n\n";
        }

    }
    return sub_temporal;
}