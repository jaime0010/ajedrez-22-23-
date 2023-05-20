#pragma once

#include <iostream>
#include <fstream>
#include "freeglut.h"
#include "Pieza.h"
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

protected:
	Vector2D* pos_origen, * pos_final, * origen;
	int turno = -1;	//-1=turno blancas; 1= turno negras
	int x_org = -1, y_org = -1; //esto antes era 100 100
	int coger = 1;


public:

	Pieza* tab[columnas][filas];	//Matriz de punteros a piezas
	
	Tablero(EstiloModoJuego modo);
	~Tablero();
	void dibuja();

	
	bool hay_pieza(int, int);
	void quien_soy(Pieza*);
	
	bool coger_posiciones(int, int, int, int);
	int comprobar_jaque(Pieza*[columnas][filas]);
	int comprobar_mate();
	char convertirPosicion(int);

	//// Metodos getters para que esten en protegidos nuestras variables
	std::string print_turno();
	int get_turno();
	int get_coger();
	int get_x();
	int get_y();
	/// Metodos setters para dar valores
	void set_turno(int);
	void set_coger(int);
	void set_x(int);
	void set_y(int);


private:
	char numeroALetra[8];
};

