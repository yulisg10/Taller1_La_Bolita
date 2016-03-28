//Debe escribir una cabecera de archivo con las indicaciones dadas en clase
/*
 *  Clase: Tablero
 *
 *  Responsabilidad: Posee funciones para generar la dimensión del tablero y guardar las coordenadas
 *  de ubicación cada vez que el programa le solicite al usuario ingresar los datos requeridos para
 *  ocultar y hallar la Bolita.
 *
 *  Colaboración: La clase Tablero utiliza la clase Arbitro para reicibir las coordenadas implementadas por el jugador.
 */
#include <iostream>
#include "Tablero.h"

using namespace std;

Tablero::Tablero() {
    //Debe realizar la inicializacion por defecto de las variables miembro de la clase Tablero
	casillas = 0;
	dimension = NULL; //Esto es un Puntero que no indica nada
}

Tablero::Tablero(int n) { //Le entra una variable n tiene que hacer cosas n*n dimensión
    //Debe realizar la inicializacion de las variables miembro de la clase Tablero considerando una entrada n
	dimension = n;

	casillas = new char*[n];
	for (int i = 0; i < n; i++){
		casillas[i] = new char[n];
		for (int j = 0; j < n; j++){
			casillas[i][j] = 'X';
		}
	}
}

Tablero::~Tablero() {
    // TODO Auto-generated destructor stub
}

char Tablero::getCasilla(int x, int y) {
    //Debe devolver el valor de la posicion (x,y) del tablero

	return casillas[x][y];

}

void Tablero::setCasilla(int x, int y, char value) {
    //Debe asignarle un valor de entrada "value" a una casilla del tablero (x,y)
	casillas[x][y] = value;
}

int Tablero::getDimension() {
    //Debe devolver la dimension del Tablero
	return dimension;
}


