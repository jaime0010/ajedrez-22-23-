#pragma once
#include "Pieza.h"
#include<iostream>
class Reina :public Pieza
{

public:
	Reina(Color c) :Pieza(c, REINA) {};
	void dibuja();
	bool validar_mov(int, int, int, int);


};