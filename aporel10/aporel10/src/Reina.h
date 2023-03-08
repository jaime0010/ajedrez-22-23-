#pragma once
#include "Pieza.h"
#include<iostream>
class Reina :public Pieza
{

public:
	Reina(Color c) :Pieza(c, REINA) {};
	void dibuja();
	//bool validar_mov(int, int, int, int);
	bool validar_mov(Vector2D*, Vector2D*);

};