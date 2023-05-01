#pragma once

#include"Tablero.h"
#include "Juego.h"

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
			
	Sprite Recuadro{ "lib/imagenes/Recuadro.png", 1.5, 7.5, 12, 2 };
	Sprite Mate_al_negro{ "lib/imagenes/MATE_NEGRO_DALL-E.png", 5, 5, 25, 20 };
	Sprite Mate_al_blanco{ "lib/imagenes/MATE_BLANCO_DALL-E.png", 5, 5, 25, 20 };

protected:
	//Tablero tab;
	Juego* juego;
	enum Estado { INICIO, JUEGO, MATE_AL_BLANCO, MATE_AL_NEGRO };
	Estado estado;
	//int xorig, yorig;
};