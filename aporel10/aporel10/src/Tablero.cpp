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
	//peones
	for (int j = 0; j <columnas; j++)//EL VECTOR VA DE 0 A 7, POR ESO SE PONE 6 Y 1 EN LAS COORDENADAS
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
	tab[0][3] = new Rey (Pieza::BLANCO);
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



bool Tablero::hay_pieza(int x, int y)
{
	if (tab[y][x]) {
		quien_soy(tab[y][x]);	
		return (true);
	}
	else {
		std::cout << "casilla libre " << std::endl;
		return false;
	}
}

void Tablero::quien_soy(Pieza* tab)
{
	std::cout << "soy de tipo " << tab->pieza<<" y color "<<tab->color<<std::endl;
}

void Tablero::coger_posiciones(int x_org, int y_org, int x_dest, int y_dest)
{
	std::cout << "origen:"<<x_org+1 << " , " << y_org+1 << "\n destino " << x_dest+1 << " , " << y_dest+1 << " , " << std::endl;
	if (tab[y_org][x_org]->validar_mov(x_dest, y_dest, x_org, y_org))
	{
		tab[y_dest][x_dest] = tab[y_org][x_org];	//actualizamos la matriz de piezas
		tab[y_org][x_org] = nullptr;				//eliminamos la anterior posicion de la matriz de piezas
		Tablero::coger = 1;
	}
}
