#pragma once
class Pieza
{
protected:
	typedef enum { REY, PEON,ALFIL,REINA,CABALLO,TORRE } TipoPieza;
	typedef enum { BLANCO, NEGRO } Color;
  public:
	  TipoPieza pieza;// ya podemos acceder a cada tipo de las piezas
	  Color color;// ya podemos acceder al color de ellas, o blanco o negro
	  Pieza(Color c, TipoPieza p) :color(c), pieza(p) {};
	 virtual TipoPieza* getTipoPieza() = 0; //no se si devuelve el tipo pieza aqui o la propia pieza
	 virtual Color* getColor() = 0;//igual pasa con el color no se si el color lo devuelve la clase pieza o luego el peon
};