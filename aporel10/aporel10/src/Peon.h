#pragma once
#include "Pieza.h"
#include<iostream>
using ETSIDI::Sprite;

class Peon :public Pieza
{

public:
		Peon(Color c) :Pieza(c, PEON) {};
		void dibuja();
		bool validar_mov(int, int);
		
};