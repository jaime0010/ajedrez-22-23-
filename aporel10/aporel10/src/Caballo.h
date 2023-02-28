#pragma once
#include "Pieza.h"

class Caballo :public Pieza
{
public:
	Caballo(Color c) :Pieza(c, CABALLO) {};
	void dibuja();
	bool validarmovimientos();
};