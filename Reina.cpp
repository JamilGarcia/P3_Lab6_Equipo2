#include "Reina.h"
#include <string>
#include <iostream>
using namespace std;

Reina::Reina(int posicion_x, int posicion_y, char caracter_pieza,string color_pieza): Pieza(){
    this->posicion_x = posicion_x;
    this->posicion_y = posicion_y;
    this->caracter_pieza = caracter_pieza;
    this->color_pieza = color_pieza;
}

char Reina::getCaracter() {return caracter_pieza;}

string Reina::getColor(){return color_pieza;}

Reina::~Reina(){}//Destructor

bool Reina::validar_movimiento(char reina, int x_inicial, int y_inicial, int x_final, int y_final, Pieza*** tablero){
    bool temp = true;
    char busqueda1;
    //Validar para que el caracter de busqueda no tire nullptrexception
    if(tablero[x_inicial][y_inicial] == NULL){
        busqueda1 = ' ';
    } else {
        busqueda1 = tablero[x_inicial][y_inicial]->getCaracter();
    }

    if(busqueda1 == reina){
        // TODO: Validar que la posición a la que el usuario quiere mover la pieza sea válida
        char busqueda2;
        if( tablero[x_final][y_final] == NULL){
            busqueda2 = ' ';
        } else {
            busqueda2 = tablero[x_final][y_final]->getCaracter(); 
        }

        if(busqueda2 == ' '){
            //Buscar si espacio vacio es valido
            if(reina == 'Q'){
                //Caso Jugador 1
                temp = validarReina('Q',x_inicial,y_inicial,x_final,y_final,tablero);
            } else {
                //Caso Jugador 2
                temp = validarReina('q',x_inicial,y_inicial,x_final,y_final,tablero);
            }
        } else {
            //Buscar cuando hay quiere comer una pieza
            if(tablero[x_final][y_final]->getColor() == "negro"){
                if(reina == 'Q'){
                    //Turno Jugador 1
                    temp = validarReina('Q',x_inicial,y_inicial,x_final,y_final,tablero);
                    if(temp) 
                        cout << "Se comio la pieza del contrincante";
                } else {
                    //Turno de Jugador 2
                    cout << "La Reina no puede moverse a esa posición porque hay una pieza de su mismo color (negro)." << endl;
                    temp = false;
                }
            } else {
                //Caso para piezas blancas
                if(reina == 'B'){
                    //Caso Jugador 1
                    cout << "La Reina no puede moverse a esa posición porque hay una pieza de su mismo color (blanco)." << endl;
                    temp = false;
                } else {
                    //Caso Jugador 2
                    temp = validarReina('q',x_inicial,y_inicial,x_final,y_final,tablero);
                    if(temp) 
                        cout << "Se comio la pieza del contrincante";
                }
            }
        }
    } else {
        if (busqueda1 == 'q' || busqueda1 == 'Q'){
            cout << "En esa posición hay un Reina, pero no es de su color." << endl;
        }else if (busqueda1 == ' '){
            cout << "En esa posición no hay nada." << endl;
        }else{
            cout << "En esa posición no hay un Reina, hay un: " << busqueda1 << "." << endl;
        }
        temp = false;
    }
    return true;
}

bool Reina::validarReina(char reina, int x_inicial, int y_inicial, int x_final, int y_final, Pieza*** tablero){
    bool sub_temporal = true;

    if(reina == 'Q'){
        //Caso Jugador 1
        int contador_piezas_jug1 = 0;
        string direccion_reina = " ";
        //Determinar la direccion
        //Arriba
        if(x_final < x_inicial && y_inicial == y_final){
            direccion_reina = "Arriba";
            //cout << "Arriba\n";
        } else if(y_final > y_inicial && x_inicial == x_final){
            //Derecha
            direccion_reina = "Derecha";
            cout << "Derecha\n";
        } else if(y_final < y_inicial && x_inicial == x_final){
            //Izquiera
            direccion_reina = "Izquierda";
            cout << "Izquierda\n";
        } else if(x_final > x_inicial && y_inicial == y_final){
            //Abajo
            direccion_reina = "Abajo";
            cout << "Abajo\n";
        } else if(x_final < x_inicial && y_final > y_inicial){
            //Esquina derecha arriba
            direccion_reina = "derecha_superior";
            cout << direccion_reina << endl;
        } else if(x_final > x_inicial && y_final > y_inicial){
            //Esquina Derecha abajo
            direccion_reina = "derecha_inferior";
            cout << direccion_reina << endl;
        } else if(x_final > x_inicial && y_final < y_inicial){
            //Esquina Izquierda abajo
            direccion_reina = "izquierda_inferior";
            cout << direccion_reina << endl;
        } else if(x_final < x_inicial && y_final < y_inicial){
            //Esquina Izquierda arriba
            direccion_reina = "izquierda_superior";
            cout << direccion_reina << endl;
        } else {
            //Posicionamiento Invalida
            direccion_reina = "invalida";
        }

        //Dependiendo de la direccion buscar en la matriz
        if(direccion_reina == "Arriba"){
            //Busca por piezas arriba de la inicial
            for (int i = x_inicial - 1; i > x_final; i--){
                if(tablero[i][y_inicial] != NULL){
                    contador_piezas_jug1++;
                }
            }
        } else if(direccion_reina == "Derecha"){
            //Busca a la derecha de la pieza
            for (int j = y_inicial + 1; j < y_final; j++){
                if(tablero[x_inicial][j] != NULL){
                    contador_piezas_jug1++;
                }
            }
        } else if(direccion_reina == "Izquierda"){
            //Busca a la izquierda de la pieza
            for (int j = y_inicial - 1; j > y_final; j--){
                if(tablero[x_inicial][j] != NULL){
                    contador_piezas_jug1++;
                }
            }
        } else if(direccion_reina == "Abajo"){
            //Busca abajo de la pieza
            for (int i = x_inicial + 1; i < x_final; i++){
                if(tablero[i][y_inicial] != NULL){
                    contador_piezas_jug1++;
                }
            }
        } else if(direccion_reina == "derecha_superior"){
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
        } else if(direccion_reina == "derecha_inferior"){
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
        } else if(direccion_reina == "izquierda_inferior"){
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
        } else if(direccion_reina =="izquierda_superior" ){
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
            cout << "La Reina no puede llegar a esa posicion\n\n";
            sub_temporal = false;
            contador_piezas_jug1 = 1;
        }

        //Determinacion si se puede mover
        if(contador_piezas_jug1 == 0){
            //Puede avanzar porque no hay piezas en el camino
            sub_temporal = true;
        } else {
            //Encontro minimo 1 pieza en el camino asi que no puede avanzar
            sub_temporal = false;
            if(direccion_reina != "invalida")
                cout << "La Reina no se puede mover ya que hay piezas en el camino\n\n";
        } 
    } else {
        //Caso Jugador 2
        int contador_piezas_jug2 = 0;
        string direccion_reina = " ";
        //Determinar la direccion
        //Arriba
        if(x_final > x_inicial && y_inicial == y_final){
            direccion_reina = "Arriba";
        } else if(y_final > y_inicial && x_inicial == x_final){
            //Derecha
            direccion_reina = "Derecha";
        } else if(y_final < y_inicial && x_inicial == x_final){
            //Izquiera
            direccion_reina = "Izquierda";
        } else if(x_final < x_inicial && y_inicial == y_final){
            //Abajo
            direccion_reina = "Abajo";
        } else if(x_final > x_inicial && y_final > y_inicial){
            //Esquina Derecha(Arriba y Derecha)
            direccion_reina = "derecha_superior";
        } else if(x_final < x_inicial && y_final > y_inicial){
            //Esquina Derecha inferior
            direccion_reina = "derecha_inferior";
        } else if(x_final < x_inicial && y_final < y_inicial){
            //Esquina Izquierda Inferior
            direccion_reina = "izquierda_inferior";
        } else if(x_final > x_inicial && y_final < y_inicial){
            //Esquina Izquierda Superior
            direccion_reina = "izquierda_superior";
        } else {
            //Posicionamiento Invalida
            direccion_reina = "invalida";
        }

        //Determinar si hay piezas en el camino de la reina
        if(direccion_reina == "Arriba"){
            //Busca por piezas arriba de la inicial
            for (int i = x_inicial + 1; i < x_final; i++){
                if(tablero[i][y_inicial] != NULL){
                    contador_piezas_jug2++;
                }
            }
        } else if(direccion_reina == "Derecha"){
            //Busca a la derecha de la pieza
            for (int j = y_inicial + 1; j < y_final; j++){
                if(tablero[x_inicial][j] != NULL){
                    contador_piezas_jug2++;
                }
            }
        } else if(direccion_reina == "Izquierda"){
            //Busca a la izquierda de la pieza
            for (int j = y_inicial - 1; j > y_final; j--){
                if(tablero[x_inicial][j] != NULL){
                        contador_piezas_jug2++;
                }
            }
        } else if(direccion_reina == "Abajo"){
            //Busca abajo de la pieza
            for (int i = x_inicial - 1; i > x_final; i--){
                if(tablero[i][y_inicial] != NULL){
                    contador_piezas_jug2++;
                }
            }
        } else if(direccion_reina == "derecha_superior"){
            //Esquina Derecha Superior
            int contador_derecha_sup= 1;
            for ( int i = x_inicial + 1; i < x_final; i++){
                for ( int j = y_inicial + 1;j < y_final ; j++){
                    if(j == y_inicial + contador_derecha_sup && i == x_inicial + contador_derecha_sup){
                        contador_derecha_sup++;
                        //Busca en el camino antes de la posicion final
                        if(tablero[i][j] != NULL){
                            contador_piezas_jug2++;
                        }
                    }   
                }
            }
        } else if(direccion_reina == "derecha_inferior"){
            //Esquina Derecha Inferior
            int contador_derecha_inf = 1;
            for ( int i = x_inicial - 1; i > x_final; i--){
                for ( int j = y_inicial + 1;j < y_final ; j++){
                    if(j == y_inicial + contador_derecha_inf && i == x_inicial - contador_derecha_inf){
                        contador_derecha_inf++;
                        //cout << "[" << i << "," << j << "]" << endl;
                        //Busca en el camino antes de la posicion final
                        if(tablero[i][j] != NULL){
                            contador_piezas_jug2++;
                        }
                    }   
                }
            }
        } else if(direccion_reina == "izquierda_inferior"){
            //Esquina Izquierda Inferior
            int contador_izq_inferior = 1;
            for ( int i = x_inicial + - 1; i > x_final; i--){
                for ( int j = y_inicial - 1;j > y_final ; j--){
                    if(j == y_inicial - contador_izq_inferior && i == x_inicial - contador_izq_inferior){
                        //cout << "[" << i << "," << j << "]" << endl;
                        contador_izq_inferior++;
                        //Busca en el camino antes de la posicion final
                        if(tablero[i][j] != NULL){
                            contador_piezas_jug2++;
                        }
                    }   
                }
            }
        } else if(direccion_reina =="izquierda_superior" ){
            //Esquina Izquierda Superior
            int contador_izq_superior = 1;
            for ( int i = x_inicial  + 1; i < x_final; i++){
                for ( int j = y_inicial - 1;j > y_final ; j--){
                    if(j == y_inicial - contador_izq_superior && i == x_inicial + contador_izq_superior){
                        //cout << "[" << i << "," << j << "]" << endl;
                        contador_izq_superior++;
                        //Busca en el camino antes de la posicion final
                        if(tablero[i][j] != NULL){
                            contador_piezas_jug2++;
                        }
                    }   
                }
            }
        } else {
            //Posicion Final Invalida
            cout << "La Reina no puede llegar a esa posicion\n\n";
            sub_temporal = false;
            contador_piezas_jug2 = 1;
        }

        if(contador_piezas_jug2 == 0){
            //Puede avanzar porque no hay piezas en el camino
            sub_temporal = true;
        } else {
            //Encontro minimo 1 pieza en el camino asi que no puede avanzar
            sub_temporal = false;
            if(direccion_reina != "invalida")
                cout << "La Reina no se puede mover ya que hay piezas en el camino\n\n";
        }


    }
    return sub_temporal;
}