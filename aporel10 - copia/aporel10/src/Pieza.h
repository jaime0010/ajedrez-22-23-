#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "Vector2D.h"
#include<iostream>

enum EstiloModoJuego{Tradicional, StarWars,Etsidi};
class Tablero;



class Pieza
{
public:
	//como le pasamos las coordenadas a piezas desde tablero, 1.creamos un objeto tablero o se lo pasamos como arguemnto de validarmovimientos.
	typedef enum { REY = 0, PEON, ALFIL, REINA, CABALLO, TORRE } TipoPieza;
	typedef enum { BLANCO = -1, NEGRO = 1 } Color;
protected:
	TipoPieza pieza;// ya podemos acceder a cada tipo de las piezas
	Color color;// ya podemos acceder al color de ellas, o blanco o negro
	EstiloModoJuego modo;
public:

	Pieza(Color c, TipoPieza p, EstiloModoJuego _modo) :color(c), pieza(p),modo(_modo) {};

	virtual void dibuja() = 0;
	//virtual void dibuja1() = 0;
	virtual std::string getTipo() = 0;
	virtual std::string getColor() = 0;

	virtual void getTipoPieza() { }; //no se si devuelve el tipo pieza aqui o la propia pieza
	Color get_Color() { return color; };//igual pasa con el color no se si el color lo devuelve la clase pieza o luego el peon
	TipoPieza getPieza() { return pieza; }
	//virtual bool validar_mov(int, int, int, int)=0;
	virtual bool validar_mov(Vector2D*, Vector2D*, Tablero& tablero) = 0;



};