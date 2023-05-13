#pragma once

#include"Tablero.h"
#include "Juego.h"

enum Estado { INICIO, JUEGO, MATE_AL_BLANCO, MATE_AL_NEGRO };

class Coordinador
{
public:
	Coordinador();
	virtual ~Coordinador();

	void teclaEspecial(unsigned char key);
	void Tecla(unsigned char key);	
	void seleccionaPosicion(int, int);
	void dibuja();
	//int xorig, yorig;
			
	
	Sprite Mate_al_negro{ "lib/imagenes/MATE_NEGRO_DALL-E.png", 5, 5, 25, 20 };
	Sprite Mate_al_blanco{ "lib/imagenes/MATE_BLANCO_DALL-E.png", 5, 5, 25, 20 };

protected:
	//Tablero tab;
	Juego* juego;
	Estado estado;
	//int xorig, yorig;
};