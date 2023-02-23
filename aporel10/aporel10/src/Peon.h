#pragma once
#include "Pieza.h"

using ETSIDI::Sprite;

class Peon :public Pieza
{

public:
		Peon(Color c) :Pieza(c, PEON) {};
		void dibuja();
		bool validarmovimientos();
		
};