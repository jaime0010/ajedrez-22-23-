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
	Pieza* tab[columnas][filas];
	Tablero();
	~Tablero();
	void dibuja();
	void get_cor(int, int);
	bool hay_pieza(int, int);
	void quien_soy(Pieza*);
};