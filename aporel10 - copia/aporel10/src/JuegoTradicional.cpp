#include "JuegoTradicional.h"


JuegoTradicional::JuegoTradicional()
{

	tab = new Tablero(Tradicional);
	std::cout << "\t-----------Bienvenid@s a Juego Tradicional----------\t" << std::endl;
}

void JuegoTradicional::dibuja()
{
	tab->dibuja();
	//tab.inicializa();
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("lib/imagenes/FondoChess.png").id);

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-15, -10, -1.5);
	glTexCoord2d(1, 1); glVertex3f(15, -10, -1.5);
	glTexCoord2d(1, 0); glVertex3f(15, 35, -1.5);
	glTexCoord2d(0, 0); glVertex3f(-15, 35, -1.5);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

}

int JuegoTradicional::mueve(int x_dest, int y_dest)
{
	/*xorig = tab.x_org;
	yorig = tab.y_org;*/
	if (x_dest == -1 || y_dest == -1) {
		std::cout << " CASILLA FUERA DE LIMITES " << std::endl;
		ETSIDI::playMusica("lib/sonidos/disparo.mp3"); //poner sonido de disparo en el modo de star wars
		//tab->coger = 1;
		tab->set_coger(1);

		return 0;
	}

	if (tab->get_coger() < 0) {  //cogemos la posicion a la que nos queremos mover
		if (tab->coger_posiciones(tab->get_x(), tab->get_y(), x_dest, y_dest)) {
			if (tab->comprobar_mate() == -1)
				return 1;
			else if (tab->comprobar_mate() == 1)
				return -1;

			if (tab->get_turno() < 0)
			{
				tab->set_turno(1);
				std::cout << "Turno => " << tab->print_turno() << std::endl;

			}
			else
			{
				tab->set_turno(-1);
				std::cout << "Turno => " << tab->print_turno() << std::endl;
			}

		}

		tab->set_coger(-1);
	}



	if (tab->hay_pieza(x_dest, y_dest)) {

		tab->set_coger(-1);
		tab->set_x(x_dest);
		tab->set_y(y_dest);
	}
	return 0;
}
