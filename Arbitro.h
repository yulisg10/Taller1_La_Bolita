//Debe escribir una cabecera de archivo con la plantilla CRC: Clase, Responsabilidad y Colaboracion
/*
 *  Clase: Arbitro
 *
 *  Responsabilidad: El Árbitro inicia el juego, se encarga de construir los elementos necesarios
 *  para el procedimiento del juego. Con el fin de capturar los datos requeridos por el usuario
 *  para dicho funcionamiento.
 *
 *  Colaboración: La clase Arbitro utiliza la clase Tablero para establecer la matriz creada por el usuario.
 */

#ifndef ARBITRO_H_
#define ARBITRO_H_

#include "Tablero.h"

class Arbitro {
private:
	Tablero tablero;
    bool juegoEnCurso;
    double puntaje;
    int filaBolita;
    int columnaBolita;
public:
    Arbitro();
    ~Arbitro();
    void iniciarJuego();
    void imprimirTablero();
    bool validarIntento(int fila, int columna);
    int calcularDistancia(int fila, int columna);
};

#endif /* ARBITRO_H_ */

