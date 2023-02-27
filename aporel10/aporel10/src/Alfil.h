#pragma once
#include "Pieza.h"

class Alfil :public Pieza
{
public:

	Alfil(Color c) :Pieza(c, ALFIL) {};
	void dibuja();
	bool validarmovimientos();



};