#include "Tablero.h"

Tablero::Tablero()
{
	for (int i = 0; i< filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			tab[i][j]=nullptr;
		}
	}
	for (int j = 0; j <columnas; j++)//EL VECTOR VA DE 0 A 7, POR ESO SE PONE 6 Y 1 EN LAS COORDENADAS
	{
		tab[1][j] = new Peon(Pieza::BLANCO);
		tab[6][j] = new Peon(Pieza::NEGRO);
	}
	

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
			glTranslatef(columna+0.5, fila+0.5, 0);
			if(tab[fila][columna])tab[fila][columna]->dibuja();
			glPopMatrix();
		}
	}
	
	
	
}

void Tablero::get_cor(int x, int y)
{
	std::cout<< "X:" << x <<" Y:" <<y << std::endl;
}
