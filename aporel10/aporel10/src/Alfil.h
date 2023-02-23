#pragma once
#include "Pieza.h"

class Alfil :public Pieza
{
public:

	Alfil(Color c) :Pieza(c, PEON) {};
	void dibuja();
	bool validarmovimientos();



};