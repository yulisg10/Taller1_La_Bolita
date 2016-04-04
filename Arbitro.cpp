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
	cout<<endl;

	if(d>=0){
		Tablero tablero1(d);
		tablero = tablero1;


		imprimirTablero();

		juegoEnCurso = true;

		while(juegoEnCurso)
		{
			filaBolita = rand()%d;
			columnaBolita = rand()%d;

			int x;
			int y;
			bool adivinar = false;

			//Permite que la Ubicación aleatoria de la Bolita quede Constante y no Cambie cada vez que Imprime el Tablero
			while(!adivinar){

				//Indica la ubicación de la Bolita Oculta
				//cout<<endl;
				//cout<<"Posicion de la Bolita: "<<filaBolita<<" "<<columnaBolita<<endl;

				cout<<endl;
				cout<<"Ingrese una posicion en Fila: ";
				cin>> x;
				cout<<"Ingrese una posicion en Columna: ";
				cin>> y;
				validarIntento(x,y);
				adivinar = (filaBolita == x) && (columnaBolita == y);
			}
		}
		cout<<endl;
		cout<<"Enhorabuena!!! Haz adivinado la ubicacion de la Pelota"<<endl;
		cout<<"Tu Puntaje es: "<< puntaje<<endl;
		system("pause");
	}
	else{
		cout<<"Reinicie el Programa."<<endl;
		system("pause");
		exit(0);
	}
}

void Arbitro::imprimirTablero() {
    //Debe implementar un metodo que imprima el tablero en pantalla
    //Recuerde que el usuario no puede conocer la posicion de la bolita

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
    //Debe implmentar un metodo que calcula la distancia entre la posicion (fila, columna)
    //Y la posicion real de la bolita
    return floor(sqrt(( (fila - filaBolita)*(fila - filaBolita)) + ((columna - columnaBolita)*(columna - columnaBolita)) )); //Floor retorna un número entero, a pesar que el resultado sea un decimal
}

bool Arbitro::validarIntento(int fila, int columna){
    //Este metodo debe validar el intento del usuario, debe informarle si fue correcto o no
    //Retorna verdadero si el intento es correcto y falso si no lo es
    //En caso de no serlo debe realizar los cambios correspondientes a las variables miembro
    //Y debe informar por pantalla cual fue la distancia del fallo y el puntaje restante

	if(fila>=0 && columna>=0){}
	else{
		cout<<endl;
		cout<<endl;
		cout<<"Reinicie el Programa"<<endl;
		system("pause");
		exit(0);
	}

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
			cout<<endl;
			cout<<"Intento Fallido, vuelve a intentarlo"<<endl;
			cout<<"Puntos restantes: "<<puntaje<<endl;
			cout<<"La Distancia es: "<<calcularDistancia(fila, columna)<<endl;
		}

		//Si Fila y Columna SUPERA la Dimensión establecida, no mostrará el ASTERISCO en la Posición que Indico el Usuario
		if(fila > tablero.getDimension() || columna > tablero.getDimension()){
			cout<<endl;
			system("pause"); //Función (Presionse Tecla Para Continuar...)
			system("cls"); //Limpiar Pantalla (Funciona En Consola .exe) Debe incluir la Librería stdlib.h
			imprimirTablero();
		}
		else{
			cout<<endl;
			system("pause");
			char ubicacionUsuario = '*';
			tablero.setCasilla(fila, columna, ubicacionUsuario);
			system("cls");
			imprimirTablero();
		}
	}
}




