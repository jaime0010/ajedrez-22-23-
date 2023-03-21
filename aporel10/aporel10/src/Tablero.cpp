#include "Tablero.h"

Tablero::Tablero()
{

	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			tab[i][j] = nullptr;
		}
	}
	//peones
	for (int j = 0; j < columnas; j++)//EL VECTOR VA DE 0 A 7, POR ESO SE PONE 6 Y 1 EN LAS COORDENADAS
	{
		tab[1][j] = new Peon(Pieza::BLANCO);
		tab[6][j] = new Peon(Pieza::NEGRO);
	}
	//creacion de las demas piezas
	// caballo
	tab[0][1] = new Caballo(Pieza::BLANCO);
	tab[0][6] = new Caballo(Pieza::BLANCO);
	tab[7][1] = new Caballo(Pieza::NEGRO);
	tab[7][6] = new Caballo(Pieza::NEGRO);
	//reyes
	tab[0][3] = new Rey(Pieza::BLANCO);
	tab[7][3] = new Rey(Pieza::NEGRO);
	//reinas
	tab[0][4] = new Reina(Pieza::BLANCO);
	tab[7][4] = new Reina(Pieza::NEGRO);
	//torres
	tab[0][0] = new Torre(Pieza::BLANCO);
	tab[0][7] = new Torre(Pieza::BLANCO);
	tab[7][0] = new Torre(Pieza::NEGRO);
	tab[7][7] = new Torre(Pieza::NEGRO);
	//Alfiles
	tab[0][2] = new Alfil(Pieza::BLANCO);
	tab[0][5] = new Alfil(Pieza::BLANCO);
	tab[7][2] = new Alfil(Pieza::NEGRO);
	tab[7][5] = new Alfil(Pieza::NEGRO);

	pos_origen = new Vector2D(0, 0);
	pos_final = new Vector2D(0, 0);

}

Tablero::~Tablero()
{

	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			delete tab[i][j];
		}
	}
}

void Tablero::dibuja()
{

	for (int fila = 0; fila < filas; fila++)
	{
		for (int columna = 0; columna < columnas; columna++)
		{
			glDisable(GL_LIGHTING);
			if ((fila + columna) % 2 == 0) glColor3ub(100, 100, 100);
			else glColor3ub(255, 255, 255);
			glBegin(GL_POLYGON);
			glVertex3d(columna, fila, 0.0);
			glVertex3d(columna + 1.0, fila, 0.0);
			glVertex3d(columna + 1.0, fila + 1.0, 0.0);
			glVertex3d(columna, fila + 1.0, 0.0);
			glEnd();
			glEnable(GL_LIGHTING);
		}
	}
	for (int fila = 0; fila < filas; fila++)
	{
		for (int columna = 0; columna < columnas; columna++)
		{
			if ((fila + columna) % 2 == 0) glColor3ub(100, 100, 100);
			else glColor3ub(255, 255, 255);
			glPushMatrix();
			glTranslatef(columna + 0.5, fila + 0.5, 0);
			if (tab[fila][columna])tab[fila][columna]->dibuja();
			glPopMatrix();
		}
	}



}



bool Tablero::hay_pieza(int x, int y)
{
	if (tab[y][x]) {//se pone'-1' porque las piezas van de 0 a 7 y las coordenadas de 1 a 8
		quien_soy(tab[y][x]);
		return (true);
	}
	else {
		//std::cout << "origen:" << pos_origen->x << " , " << pos_origen->y << "\n destino " << pos_final->x << " , " << pos_final->y << " , " << std::endl;
		std::cout << "casilla libre " << std::endl;
		return false;
	}
}

void Tablero::quien_soy(Pieza* tab)
{
	std::cout << "soy de tipo " << tab->pieza << " y color " << tab->color << std::endl;
}

bool Tablero::coger_posiciones(int x_org, int y_org, int x_dest, int y_dest)
{
	pos_origen->x = x_org;
	pos_origen->y = y_org;

	pos_final->y = y_dest;
	pos_final->x = x_dest;

	if (x_org == x_dest && y_org == y_dest)
		return false;
	std::cout << "origen:" << pos_origen->x + 1 << " , " << pos_origen->y + 1 << "\n destino " << pos_final->x + 1 << " , " << pos_final->y + 1 << " , " << std::endl;
	if ((tab[y_org][x_org]->color == turno)/*Comprueba que la pieza seleccionada sea la que toca segun el turno*/
		&& (tab[y_org][x_org]->validar_mov(pos_final, pos_origen, *this)))
	{
		tab[y_dest][x_dest] = tab[y_org][x_org];	//actualizamos la matriz de piezas
		tab[y_org][x_org] = nullptr;						//eliminamos la anterior posicion de la matriz de piezas
		Tablero::coger = 1;
		return true;
	}
	return false;
}