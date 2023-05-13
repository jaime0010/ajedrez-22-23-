#pragma once

#include "Pieza.h"
#include "freeglut.h"
#include "ETSIDI.h";
#include<iostream>

class Rey :public Pieza
{
public:
	Rey(Color c,EstiloModoJuego modo) :Pieza(c, REY, modo) {};
	void dibuja();
	bool validar_mov(Vector2D*, Vector2D*, Tablero&);
	void getTipoPieza();

};