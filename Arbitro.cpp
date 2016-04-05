//Debe crear una cabecera de archivo tal como se indicó en clase
/*
 *  Clase: Arbitro
 *
 *  Responsabilidad:
 *  Se encarga de gestionar todas las funciones requeridas para la ejecución del juego.
 *  Se realiza la dimensión del Tablero dependiendo del número ingresado por el jugador.
 *  Solicita el ingreso de coordenadas a través de mensajes en pantalla.
 *  Se valida los intentos de posición en hallar la Bolita, la cual si fallan, se repite la solicitud hasta encontrarla.
 *  La posición de la Bolita está en forma aleatoria que el jugador debe adivinar dónde se encuentra.
 *  Indica la Distancia que se encuentra ubicado la Bolita, cada vez que se falle en el intento (Como una Pista).
 *
 *  Colaboración: La clase Arbitro necesita de la clase Tablero para efectuar el tamaño del tablero
 *  y ocultar la posición de la Bolita.
 */

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Arbitro.h"
using namespace std;


Arbitro::Arbitro() {
    juegoEnCurso = false;
    puntaje = 100.0;
    srand(time(NULL));
    filaBolita = 0;
    columnaBolita = 0;
}

Arbitro::~Arbitro() {
    // TODO Auto-generated destructor stub
}

void Arbitro::iniciarJuego() {
    //Debe implementar un metodo que se encargue de iniciar el juego y controlar su desarrollo
    //Este metodo debe recibir las entradas del usuario, imprimir el tablero y validar los intentos

	int d;

	cout << "Ingrese un numero para la Dimension del Tablero: ";
	cin >> d;

	if(d!=0){
		Tablero tablero1(d);
		tablero = tablero1;

		imprimirTablero();

		juegoEnCurso = true;

		while(juegoEnCurso)
		{
			int x;
			int y;
			bool adivinar = false;

			filaBolita = rand()%d;
			columnaBolita = rand()%d;

			while(!adivinar){
				//Indica la ubicación de la Bolita Oculta
				//cout<<endl;
				//cout<<"Posicion de la Bolita: "<<filaBolita<<" "<<columnaBolita<<endl;

				cout<<endl;

				cout<<"Ingrese una posicion en Fila: ";
				cin>> x;
				cout<<"Ingrese una posicion en Columna: ";
				cin>> y;

				char letra;

				if(x!=letra && y!=letra){
					validarIntento(x,y);
					adivinar = (filaBolita == x) && (columnaBolita == y);
				}
				else{
					cout<<endl;
					cout<<endl;
					cout<<"Dato invalido."<<endl;
					cout<<"Reinicie el Programa."<<endl;
					system("pause");
					exit(0);
				}
			}
		}
		cout<<endl;
		cout<<"Enhorabuena!!! Haz adivinado la ubicacion de la Pelota"<<endl;
		cout<<"Tu Puntaje es: "<< puntaje<<endl;
		system("pause");
	}
	else{
		cout<<endl;
		cout<<"Dato invalido."<<endl;
		cout<<"Reinicie el Programa."<<endl;
		system("pause");
		exit(0);
	}
}

void Arbitro::imprimirTablero() {
    //Debe implementar un metodo que imprima el tablero en pantalla
    //Recuerde que el usuario no puede conocer la posicion de la bolita

	cout<<endl;
	cout<<"  ";

	for(int tab=0; tab < tablero.getDimension(); tab++){
		cout<<"  "<<tab;
	}
	cout<<endl;

	for(int fila=0; fila < tablero.getDimension(); fila++){
		if(fila > 9 ){
			cout<< fila <<"  ";
		}
		else{
			cout<< fila <<"   ";
		}

	   for(int columna=0; columna < tablero.getDimension(); columna++){
		   if(columna>9){
			   cout<<tablero.getCasilla(fila, columna)<<"   ";
		   }
		   else{
			   cout<<tablero.getCasilla(fila, columna)<<"  ";
		   }
	   }
	   cout<<endl;
	}
}

int Arbitro::calcularDistancia(int fila, int columna){
    //Debe implementar un metodo que calcula la distancia entre la posicion (fila, columna)
    //Y la posicion real de la bolita
    return floor(sqrt(( (fila - filaBolita)*(fila - filaBolita)) + ((columna - columnaBolita)*(columna - columnaBolita)) )); //Floor retorna un nÃºmero entero, a pesar que el resultado sea un decimal
}

bool Arbitro::validarIntento(int fila, int columna){
    //Este metodo debe validar el intento del usuario, debe informarle si fue correcto o no
    //Retorna verdadero si el intento es correcto y falso si no lo es
    //En caso de no serlo debe realizar los cambios correspondientes a las variables miembro
    //Y debe informar por pantalla cual fue la distancia del fallo y el puntaje restante


	int validar =  (tablero.getDimension() - 1);

	if((fila<0 || columna<0)||(fila>validar || columna>validar))
	{
		cout<<endl;
		cout<< "Te has salido del  margen del tablero"<<endl;
		cout<< "Ingresa un valor valido"<<endl;

	}
	else{
		if((fila == filaBolita)&&(columna == columnaBolita)){
			juegoEnCurso=false;
		}
		else{
			//100  - 100   /(N * N) Dimensión Digitado por el Usuario
			puntaje = floor(puntaje-puntaje/(tablero.getDimension() * tablero.getDimension()));

			int puntos = puntaje;

			if(puntos == 0){
				cout<<endl;
				cout<<"Haz perdido el Juego."<<endl;
				cout<< "Tu Puntaje es: "<<puntaje<<endl;
				system("pause");
				exit(0);
			}
			else{
				system("cls");
				cout<<endl;
				cout<<"Intento Fallido, vuelve a intentarlo"<<endl;
				cout<<"Puntos restantes: "<<puntaje<<endl;
				cout<<"La Distancia es: "<<calcularDistancia(fila, columna)<<endl;
				char bolita = 'O';
				tablero.setCasilla(fila, columna, bolita);
				system("pause");
				//system("cls");
				imprimirTablero();
			}
		}
	}
}
