#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include <math.h>

class Pieza
{
  public:
	  //como le pasamos las coordenadas a piezas desde tablero, 1.creamos un objeto tablero o se lo pasamos como arguemnto de validarmovimientos.
	  typedef enum { REY=0, PEON, ALFIL, REINA, CABALLO, TORRE } TipoPieza;
	  typedef enum { BLANCO=0, NEGRO } Color;
	  TipoPieza pieza;// ya podemos acceder a cada tipo de las piezas
	  Color color;// ya podemos acceder al color de ellas, o blanco o negro
	 
	  Pieza(Color c, TipoPieza p) :color(c), pieza(p){};

	  virtual void dibuja()=0;

	  TipoPieza* getTipoPieza() { return &pieza; }; //no se si devuelve el tipo pieza aqui o la propia pieza
	  Color* getColor() { return &color; };//igual pasa con el color no se si el color lo devuelve la clase pieza o luego el peon
	  
	  virtual bool validar_mov(int, int,int,int)=0;
	  

	  
};