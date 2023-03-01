#pragma once
#include "Pieza.h"
#include<iostream>
class Caballo :public Pieza
{
public:
	Caballo(Color c) :Pieza(c, CABALLO) {};
	void dibuja();
	bool validar_mov(int, int, int, int);
};