#pragma once
#include "Pieza.h"
#include "freeglut.h"
#include "ETSIDI.h"
using ETSIDI::Sprite;

class Peon :public Pieza
{

public:
		Peon(Color c) :Pieza(c, PEON) {};
		void dibuja();
		
};