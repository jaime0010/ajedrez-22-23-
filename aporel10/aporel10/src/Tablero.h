#pragma once

#include <iostream>
#include "freeglut.h"
#include "Peon.h"

#define filas 8
#define columnas 8


class Tablero
{
public:
	Pieza* tab[filas][columnas];
	Tablero();
	~Tablero();
	void dibuja();
};