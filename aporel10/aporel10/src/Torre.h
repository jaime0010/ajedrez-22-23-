#pragma once
#include "Pieza.h"
#include<iostream>
class Torre :public Pieza
{
public:
	Torre(Color c) :Pieza(c, TORRE) {};
	void dibuja();
	bool validar_mov(int, int);



};