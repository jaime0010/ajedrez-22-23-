#pragma once
#include "Juego.h"

class JuegoStarWars :public Juego {

public:

	JuegoStarWars();
	//~JuegoStarWars();

	void dibuja();
	int mueve(int, int);

};