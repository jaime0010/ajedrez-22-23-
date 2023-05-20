#pragma once
#include "Pieza.h"
#include<iostream>
class Torre :public Pieza
{
public:
	Torre(Color c,EstiloModoJuego modo) :Pieza(c, TORRE,modo) {};
	void dibuja();
	//bool validar_mov(int, int, int, int);
	bool validar_mov(Vector2D*, Vector2D*, Tablero&);
	void getTipoPieza();
	std::string getTipo();
	std::string getColor();
};