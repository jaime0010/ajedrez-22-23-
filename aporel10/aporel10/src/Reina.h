#pragma once
#include "Pieza.h"

class Reina :public Pieza
{

public:
	Reina(Color c) :Pieza(c, PEON) {};
	void dibuja();
	bool validarmovimientos();


};