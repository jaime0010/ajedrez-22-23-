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

constexpr int filas = 8;
constexpr int columnas = 8;



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
	char convertirPosicion(int) const;

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

	//friend std::ostream& operator<<(std::ostream& o, const Tablero&);
	//std::ostream& print_coord(std::ostream& o = std::cout) const;

private:
	char numeroALetra[8];
};


//std::ostream& Tablero::print_coord(std::ostream& o) const 
//{
//	o << this->pos_origen->x << "-" << this-> << "======>" << this->convertirPosicion(this->pos_final->y) << "-" << this->pos_final->y;
//	return o;
//}

//
//std::ostream& operator<<(std::ostream &o, const Tablero& tab)
//{
//	return tab.print_coord(o);
//
//}

