#include "Coordinador.h"

Coordinador::Coordinador()
{
	estado = INICIO;
	xorig = 0;
	yorig = 0;

}
Coordinador::~Coordinador()
{

}

void Coordinador::mueve(int x_org, int y_org, int x_dest, int y_dest)
{
	
		if (estado = JUEGO)
		{
			xorig = tab.x_org;
			yorig = tab.y_org;
			if (tab.coger < 0) {                    //cogemos la posicion a la que nos queremos mover
				if (tab.coger_posiciones(tab.x_org, tab.y_org, x_dest, y_dest)) {
					tab.turno *= -1;	//Cambia de turno una vez validado el movimiento
					std::cout << "Turno = " << tab.turno << std::endl;
				}
				tab.coger *= -1;
			}

			if (x_dest > 8 || y_dest > 8) {
				std::cout << " CASILLA FUERA DE LIMITES " << std::endl;
				ETSIDI::playMusica("lib/sonidos/disparo.mp3");
				tab.coger = 1;
			}

			if (tab.hay_pieza(x_dest, y_dest)) {
				tab.coger *= -1;
				tab.x_org = x_dest;
				tab.y_org = y_dest;
			}
		}
	
	

}

void Coordinador::dibuja()
{
	if (estado == INICIO) //Muestra la pantalla de inicio
	{


		MenuInicial.draw();

		gluLookAt(
			0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("lib/fuentes/Bitwise.ttf", 50);
		ETSIDI::printxy("AJEDREZ", -4, 20);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("lib/fuentes/Bitwise.ttf", 20);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -10, 15);
		ETSIDI::setTextColor(1, 200, 1);
		ETSIDI::setFont("lib/fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("Realizado por: Pablo Nunyez, Jaime Bustos, Felipe de Gracia, Victor Alcolea, Nikita Zhukov", -18, 5);
		ETSIDI::setTextColor(1, 1, 1);
			
	}
	else if (estado == JUEGO) //Duda: Por qué hace lo mismo en JUEGO que en EMPEZAR???
	{
		tab.dibuja();
	}

}

void Coordinador::teclaEspecial(unsigned char key)
{

}

void Coordinador::Tecla(unsigned char key)
{
	if (estado == INICIO)
	{
		if (key =='e')
		{
			estado = JUEGO;

		}
		
	}
	
}