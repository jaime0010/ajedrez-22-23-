#pragma once
#include "Pieza.h"

class Caballo :public Pieza
{
public:
	Caballo(Color c) :Pieza(c, PEON) {};
	void dibuja();
	bool validarmovimientos();
};