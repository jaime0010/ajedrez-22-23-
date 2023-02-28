#pragma once
#include "Pieza.h"

class Reina :public Pieza
{

public:
	Reina(Color c) :Pieza(c, REINA) {};
	void dibuja();
	bool validarmovimientos();


};