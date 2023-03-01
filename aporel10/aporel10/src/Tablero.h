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
	int coger = 1;//se usar� como una "maquina de estados para coger la posicion a la que nos queremos mover"
	int x_org=0, y_org=0;
	Pieza* tab[columnas][filas];
	Tablero();
	~Tablero();
	void dibuja();
	bool hay_pieza(int, int);
	void quien_soy(Pieza*);
	void coger_posiciones(int, int, int, int);
};