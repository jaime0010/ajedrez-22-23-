#pragma once
#include "Pieza.h"
#include<iostream>
class Reina :public Pieza
{

public:
	Reina(Color c,EstiloModoJuego _modo) :Pieza(c, REINA,_modo) {};
	void dibuja();
	//void dibuja1();
	//bool validar_mov(int, int, int, int);
	bool validar_mov(Vector2D*, Vector2D*, Tablero&);   

	std::string negro, blanco; //Color de la figura para los modos que contiene la dirección de acceso a la imagen


};