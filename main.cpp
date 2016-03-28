//============================================================================
// Name          : Taller_La_Bolita.cpp
// Código_1		 : 1561806-2711
// Author_1      : Rubén Darío Holguín Castro
// Código_2 	 : 1561798-2711
// Author_2		 : Yuliana Sarria García
// Version       : 2.0
// Copyright     :
// Description   : Crea un Árbitro e indica el inicio del juego.
//============================================================================
// Nota: este código compila sin ningún tipo de problemas en Windows debido
// que contiene system("pause"); system("cls");. A la hora de compilar en Linux
// posee algunos problemas con dichas funciones anteriormente.
// Debido a que los dos se ha manejado con Linux y Windows entonces para tener en
// cuenta esa observación.

#include <iostream>
#include "Arbitro.h"
using namespace std;

int main() {
   Arbitro arbitro = Arbitro();
   arbitro.iniciarJuego();

	return 0;
}
