#pragma once
#include "Pieza.h"
#include<iostream>
class Alfil :public Pieza
{
public:

	Alfil(Color c) :Pieza(c, ALFIL) {};
	void dibuja();
	//bool validar_mov(int, int, int, int);

	bool validar_mov(Vector2D*, Vector2D*,Tablero&);

};