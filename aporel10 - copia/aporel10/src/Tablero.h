#pragma once

#include <iostream>
#include "freeglut.h"
#include "Peon.h"
#include "Rey.h"
#include "Reina.h"
#include "Torre.h"
#include "Alfil.h"
#include "Caballo.h"
#include"Vector2D.h"

#define filas 8
#define columnas 8



class Tablero
{
public:
	Vector2D* pos_origen, * pos_final, * origen;

	int coger = 1;	//se usará como una "maquina de estados para coger la posicion a la que nos queremos mover"
	//1 = esperando a casilla de destino; -1 = esperando a casilla de origen
	int turno = -1;	//-1=turno blancas; 1= turno negras
	int x_org = -1, y_org= -1 ; //esto antes era 100 100

	//EstiloModoJuego _modo;  ///NUEVO CAMBIO DUDOSO

	Pieza* tab[columnas][filas];	//Matriz de punteros a piezas
	
	Tablero(EstiloModoJuego modo);
	~Tablero();
	void dibuja();
	//void dibuja1();
	
	bool hay_pieza(int, int);
	void quien_soy(Pieza*);
	
	//void inicializa1();
	
	bool coger_posiciones(int, int, int, int);
	int comprobar_jaque(Pieza*[columnas][filas]);
	int comprobar_mate();
};