#pragma once
#include "Pieza.h"

class Torre :public Pieza
{
public:
	Torre(Color c) :Pieza(c, TORRE) {};
	void dibuja();
	bool validarmovimientos();



};