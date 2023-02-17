#pragma once
#include "Pieza.h"
class peon :public Pieza
{
private:
		peon(Color c) :Pieza(c, PEON) {};
	public:
		TipoPieza* getTipoPieza()
		{
			return &pieza;
			
		}
		Color* getColor()
		{
			return &color;
			
		}
		

};