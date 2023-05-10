#include "Coordinador.h"
#include "JuegoStarWars.h"
#include "JuegoTradicional.h"
#include "JuegoEtsidi.h"


Coordinador::Coordinador()
{
	estado = INICIO;
	juego = nullptr;

}
Coordinador::~Coordinador()
{

}



void Coordinador::seleccionaPosicion(int x_dest, int y_dest)
{
	

	if (estado == JUEGO)
	{
		switch (juego->mueve(x_dest, y_dest)) {

		case 1:
			estado = MATE_AL_BLANCO;
			break;

		case -1:
			estado = MATE_AL_NEGRO;
			break;

		default:
			break;

		}


	}


}

void Coordinador::dibuja()
{
	if (estado == INICIO) //Muestra la pantalla de inicio
	{

		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("lib/imagenes/MenuInicio.png").id);

		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-25, -5, -20);
		glTexCoord2d(1, 1); glVertex3f(28, -5, -20);
		glTexCoord2d(1, 0); glVertex3f(28, 27, -20);
		glTexCoord2d(0, 0); glVertex3f(-25, 27, -20);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		//Recuadro.draw();
		
		
		

		gluLookAt(
			0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("lib/fuentes/04B_20__.ttf", 30);
		ETSIDI::printxy("AJEDREZ", -17, 30);
		ETSIDI::setTextColor(0, 1, 0);
		ETSIDI::setFont("lib/fuentes/04B_20__.ttf", 10);
		ETSIDI::printxy("Modo Tradicional : Pulse T", -17, 25);
		ETSIDI::setTextColor(0, 1, 0);
		ETSIDI::setFont("lib/fuentes/04B_20__.ttf", 10);
		ETSIDI::printxy("Modo StarWars : Pulse S", -16, 18);
		ETSIDI::setTextColor(0, 1, 0);
		ETSIDI::setFont("lib/fuentes/04B_20__.ttf", 10);
		ETSIDI::printxy("Modo ETSIDI : Pulse E", -15, 12);
		ETSIDI::setTextColor(1, 200, 1);
		ETSIDI::setFont("lib/fuentes/04B_20__.ttf", 7);
		ETSIDI::printxy("Realizado por: Pablo Nuniez, Jaime Bustos, Felipe de Gracia, Nikita Zhukov, Victor Alcolea", -18, 5);
		ETSIDI::setTextColor(1, 1, 1);
			
	}
	else if (estado == JUEGO) 
	{
		juego->dibuja();
		
	}

	else if (estado == MATE_AL_BLANCO) {
		//std::cout << "\n\n\n\n" << tab.comprobar_mate() <<"\n\n\n\n";
			Mate_al_blanco.draw();

			gluLookAt(
				0, 7.5, 30, // posicion del ojo
				0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
				0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("lib/fuentes/Bitwise.ttf", 28);
			ETSIDI::printxy("FIN DE LA PARTIDA", -5, 30);
			ETSIDI::printxy("GANAN LAS NEGRAS", -5, 25);
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("lib/fuentes/Bitwise.ttf", 10);
			ETSIDI::printxy("PULSE LA TECLA -E- PARA COMPROBAR EL MATE", -5, 20);
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("lib/fuentes/Bitwise.ttf", 12);
			ETSIDI::printxy("Realizado por: Pablo Nuniez, Jaime Bustos, Felipe de Gracia, Victor Alcolea, Nikita Zhukov", -18, 5);
			ETSIDI::setTextColor(1, 0, 0);
	}
	else if (estado == MATE_AL_NEGRO) {
		//std::cout << "\n\n\n\n" << tab.comprobar_mate() << "\n\n\n\n";
		Mate_al_negro.draw();

		gluLookAt(
			0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("lib/fuentes/Bitwise.ttf", 28);
		ETSIDI::printxy("FIN DE LA PARTIDA", -5, 30);
		ETSIDI::printxy("GANAN LAS BLANCAS", -5, 25);
		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("lib/fuentes/Bitwise.ttf", 10);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA COMPROBAR EL MATE", -5, 20);
		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("lib/fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("Realizado por: Pablo Nuniez, Jaime Bustos, Nikita Zhukov, Felipe de Gracia,Victor Alcolea", -18, 5);
		ETSIDI::setTextColor(0, 0, 0);
	}

}

void Coordinador::teclaEspecial(unsigned char key)
{

}

void Coordinador::Tecla(unsigned char key)
{
	switch (estado)
	{
		case(INICIO):
			{
				switch (key)
				{
					case 't':
					case 'T':
						estado = JUEGO;
						juego = new JuegoTradicional();
					break;

					case 's':
					case 'S':
						estado = JUEGO;
						juego = new JuegoStarWars();
					break;

					case 'e':
					case 'E':
						estado = JUEGO;
						juego = new JuegoEtsidi();
						break;
				}
			}
		case(JUEGO):
			{
				switch (key)
				{
					case 'a':
					case 'A':
						estado = INICIO;
					break;
				}
			}
		case (MATE_AL_BLANCO):
			{	
				switch (key)
				{
					case 'e':
					case 'E':
						estado = INICIO;
					break;

				}
			}
		case (MATE_AL_NEGRO):
			{
				switch (key)
				{
					case 'e':
					case 'E':
						estado = INICIO;
						break;
				}
			}
	}

	
}