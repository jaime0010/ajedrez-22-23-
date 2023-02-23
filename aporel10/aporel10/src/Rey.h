#pragma once

#include "Pieza.h"
#include "freeglut.h"
#include "ETSIDI.h";

class Rey :public Pieza
{
public:
	Rey(Color c) :Pieza(c, PEON) {};
	void dibuja();
	bool validarmovimientos();


};