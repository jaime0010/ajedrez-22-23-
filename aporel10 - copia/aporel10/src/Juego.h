#pragma once

#include "Tablero.h"

class Juego {
public:
	
	Juego();
	~Juego();
	virtual void dibuja()=0;
	virtual int mueve(int, int) = 0;
	//void inicializa();
	
protected:
	Tablero* tab;

};