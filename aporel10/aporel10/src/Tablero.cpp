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
	if (tab[y - 1][x - 1]) {//se pone'-1' porque las piezas van de 0 a 7 y las coordenadas de 1 a 8
		quien_soy(tab[y - 1][x - 1]);	
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
	std::cout << "origen:"<<x_org << " , " << y_org << "\n destino " << x_dest << " , " << y_dest << " , " << std::endl;
	if ((tab[y_org - 1][x_org - 1]->color==turno)/*Comprueba que la pieza seleccionada sea la que toca segun el turno*/
		&& (tab[y_org - 1][x_org - 1]->validar_mov(x_dest, y_dest, x_org, y_org)))
	{
		tab[y_dest - 1][x_dest - 1] = tab[y_org - 1][x_org - 1];	//actualizamos la matriz de piezas
		tab[y_org - 1][x_org - 1] = nullptr;						//eliminamos la anterior posicion de la matriz de piezas
		Tablero::coger = 1;
	}
}
<<<<<<< Updated upstream
=======

void Tablero::trayectoria(Pieza* tabl, int x_org, int y_org, int x_dest, int y_dest) {
	int no_valid = 0;	//0=NO hay piezas en la trayectoria; 1=SI hay piezas en medio
	int tipo = quien_soy(tab[y_org][x_org]);
	
	switch (tipo) {
			std::cout << "ENTRO NE FUNCION22222";

		case 0:	// REY
		{
			coger_posiciones(x_org, y_org, x_dest, y_dest);
		}
		break;

		case 1:		//PEON
		{
			coger_posiciones(x_org, y_org, x_dest, y_dest);
		}
			break;
		case 2:		//ALFIL
		{
			//Establece hacia donde se mueve el alfil, 1=arriba o derecha; -1=abajo o izq
			int dx = (x_dest > x_org) ? 1 : -1;
			int dy = (y_dest > y_org) ? 1 : -1;
			//Empieza en el origen
			int x = x_org ;
			int y = y_org ;

			//Recorre toda la trayectoria diagonal
			while (x != x_dest && y != y_dest) {
				//avanza a la siguiente casilla
				x += dx;
				y += dy;
				//Si los tipos de pieza de las casillas son 0-5; hay pieza, no_valid = 1
				if (quien_soy(tab[y][x]) < 6 && quien_soy(tab[y][x]) >= 0) {
					// Hay una pieza en el camino
					no_valid = 1;
				}
			}
			//Si no ha encontrado piezas, efectua el movimiento
			if(no_valid!=1)
				coger_posiciones(x_org, y_org, x_dest, y_dest);

		}
			break;
		case 3:		//REINA
			coger_posiciones(x_org, y_org, x_dest, y_dest);
			break;
		case 4:		//CABALLO
		{
			
			coger_posiciones(x_org, y_org, x_dest, y_dest);
		}
			break;
		case 5:		//TORRE

			// Hacia donde se mueve la torre
			int dx = (x_dest - x_org > 0) ? 1 : -1; //si la torre se mueve hacía arriba 1 => else -1
			int dy = (y_dest - y_org > 0) ? 1 : -1; //si la torre se mueve hacía dcha 1 => else -1

			//Empieza en el origen
			int x = x_org;
			int y = y_org;

			if (abs(x_dest - x_org) == 0) // si x_dest-x_orig es distinto de 0 => desplazamiento en eje y
			{
				if (dy == 1) // Movimiento torre hacia arriba 
				{
					while (y != y_dest)
					{
						y += dy; //se suma para avanzar hacia la dcha
						if (quien_soy(tab[y][x]) < 6 && quien_soy(tab[y][x]) >= 0)
						{
							// Hay una pieza en el camino
							no_valid = 1;
						}
					}
				}
				else // Movimiento torre hacia abajo
				{
					while (y != y_dest)
					{
						y += dy; // se resta para avanzar hacia la izq
						if (quien_soy(tab[y][x]) < 6 && quien_soy(tab[y][x]) >= 0)
						{
							no_valid = 1;
						}
					}
				}
			}
			else // Desplazaiento en el eje x
			{
				if (dx == 1) // Movimiento de la torre hacia dcha
				{
					while (x != x_dest)
					{
						x += dx;
						if (quien_soy(tab[y][x]) < 6 && quien_soy(tab[y][x]) >= 0)
						{
							no_valid = 1;
						}
					}
				}
				else // Movimiento de torre hacía izq
				{
					while (x != x_dest)
					{
						x += dx;
						if (quien_soy(tab[y][x]) < 6 && quien_soy(tab[y][x]) >= 0)
						{
							no_valid = 1;
						}
					}
				}
			}

			//Si no ha encontrado piezas, efectua el movimiento
			if (no_valid != 1)
				coger_posiciones(x_org, y_org, x_dest, y_dest);

		


			break;
	}		
}
>>>>>>> Stashed changes
