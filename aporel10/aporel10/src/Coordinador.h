#pragma once

#include"Tablero.h"

class Coordinador
{
public:
	Coordinador();
	virtual ~Coordinador();

	void teclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void mueve(int, int, int, int);
	void dibuja();
	int xorig, yorig;

	Sprite MenuInicial{ "lib/imagenes/123.png", 4, 5, 23, 17 };
	//int inicio;

protected:
	Tablero tab;
	enum Estado { INICIO, JUEGO };
	Estado estado;
	//int xorig, yorig;
};