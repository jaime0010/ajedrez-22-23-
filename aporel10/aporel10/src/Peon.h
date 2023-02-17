#pragma once
#include "Pieza.h"
#include "freeglut.h"
class Peon :public Pieza
{
public:
		Peon(Color c) :Pieza(c, PEON) {};
		void dibuja();
		
};