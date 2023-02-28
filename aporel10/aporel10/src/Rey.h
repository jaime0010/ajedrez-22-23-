#pragma once

#include "Pieza.h"
#include "freeglut.h"
#include "ETSIDI.h";

class Rey :public Pieza
{
public:
	Rey(Color c) :Pieza(c, REY) {};
	void dibuja();
	bool validarmovimientos();


};