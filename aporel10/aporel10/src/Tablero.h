#pragma once

#include <iostream>
#include "freeglut.h"
#include "Peon.h"
#include "Rey.h"
#include "Reina.h"
#include "Torre.h"
#include "Alfil.h"
#include "Caballo.h"

#define filas 8
#define columnas 8


class Tablero
{
 public:
	int coger = 1;	//se usará como una "maquina de estados para coger la posicion a la que nos queremos mover"
					//1 = esperando a casilla de destino; -1 = esperando a casilla de origen
	int x_org=0, y_org=0;
	Pieza* tab[columnas][filas];	//Matriz de punteros a piezas
	Tablero();
	~Tablero();
	void dibuja();
	bool hay_pieza(int, int);
	void quien_soy(Pieza*);
	void coger_posiciones(int, int, int, int);
};