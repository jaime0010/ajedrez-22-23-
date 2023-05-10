#include "Tablero.h"

Tablero::Tablero(EstiloModoJuego modo)
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
		tab[1][j] = new Peon(Pieza::BLANCO, modo); // modificar el resto
		tab[6][j] = new Peon(Pieza::NEGRO, modo);
	}
	//creacion de las demas piezas
	 //caballo

	tab[0][1] = new Caballo(Pieza::BLANCO,modo);
	tab[0][6] = new Caballo(Pieza::BLANCO,modo);
	tab[7][1] = new Caballo(Pieza::NEGRO,modo);
	tab[7][6] = new Caballo(Pieza::NEGRO,modo);
	//reyes
	tab[0][4] = new Rey(Pieza::BLANCO,modo);
	tab[7][4] = new Rey(Pieza::NEGRO,modo);
	//reinas
	tab[0][3] = new Reina(Pieza::BLANCO,modo);
	tab[7][3] = new Reina(Pieza::NEGRO,modo);
	//torres
	tab[0][0] = new Torre(Pieza::BLANCO,modo);
	tab[0][7] = new Torre(Pieza::BLANCO,modo);
	tab[7][0] = new Torre(Pieza::NEGRO,modo);
	tab[7][7] = new Torre(Pieza::NEGRO,modo);
	//Alfiles
	tab[0][2] = new Alfil(Pieza::BLANCO,modo);
	tab[0][5] = new Alfil(Pieza::BLANCO,modo);
	tab[7][2] = new Alfil(Pieza::NEGRO,modo);
	tab[7][5] = new Alfil(Pieza::NEGRO,modo);

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
	Vector2D origen(0, 0);
	origen.x = x_org;
	origen.y = y_org;
	for (int fila = 0; fila < filas; fila++)
	{
		for (int columna = 0; columna < columnas; columna++)
		{
				glDisable(GL_LIGHTING);
				if ((fila + columna) % 2 == 0) glColor3ub(245, 203, 138);
				else glColor3ub(70, 41, 5);
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
			Vector2D fn(0, 0);
			fn.x = columna;
			fn.y = fila;
			//Colorea la casilla seleccionada
			if (columna == x_org && fila == y_org && tab[y_org][x_org]->color==turno) {
				//Colorea las casillas disponibles
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						Vector2D fin(0,0);
						fin.x = i;
						fin.y = j;
						if (tab[y_org][x_org]->validar_mov(&fin, &origen, *this)) {
							glDisable(GL_LIGHTING);
							glColor3ub(0, 255, 0);
							glBegin(GL_POLYGON);
							glVertex3d(fin.x, fin.y, 0.001);
							glColor3ub(150, 255, 0);
							glVertex3d(fin.x + 1.0, fin.y, 0.001);
							glColor3ub(0, 50, 150);
							glVertex3d(fin.x + 1.0, fin.y + 1.0, 0.001);
							glColor3ub(30, 0, 100);
							glVertex3d(fin.x, fin.y + 1.0, 0.001);
							glEnd();
							glEnable(GL_LIGHTING);


							continue;
						}
						else continue;
					}
				}
				glDisable(GL_LIGHTING);
				glColor3ub(255, 0, 0);
				glBegin(GL_POLYGON);
				glVertex3d(columna, fila, 0.001);
				glVertex3d(columna + 1.0, fila, 0.001);
				glVertex3d(columna + 1.0, fila + 1.0, 0.001);
				glVertex3d(columna, fila + 1.0, 0.001);
				glEnd();
				glEnable(GL_LIGHTING);

			}
			else if (tab[origen.y][origen.x] != nullptr && tab[origen.y][origen.x]->validar_mov(&fn, &origen, *this)  && tab[origen.y][origen.x]->color == turno) glColor3ub(0, 0, 255);
			else if ((fila + columna) % 2 == 0) glColor3ub(245, 203, 138);
			else glColor3ub(70, 41, 5);;
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

	//Si no hay jaque, comprobamos posibles movimientos siempre que no se genere un jaque
	if ((tab[y_org][x_org]->color == turno)/*Comprueba que la pieza seleccionada sea la que toca segun el turno*/
		&& (tab[y_org][x_org]->validar_mov(pos_final, pos_origen, *this))&& comprobar_jaque(tab)==0)
	{

		//Se crea otra matriz de piezas y se copia el contenido de tab, para "simular" el movimiento
		Pieza* copia[columnas][filas];
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				copia[j][i] = tab[j][i];
		}

		//Se simula el movimiento
		tab[y_dest][x_dest] = tab[y_org][x_org];
		tab[y_org][x_org] = nullptr;

		//Si despues del movimiento hay jaque, devuelve el tablero a su posicion original y devuelve  false
		if (turno==comprobar_jaque(tab)) {
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
					tab[j][i] = copia[j][i];
			}
			return false;
		}
		//Si no hay jaque efectua el movimiento
		else {
			Tablero::coger = 1;
			if (comprobar_mate()==1)
				std::cout << "JAQUE MATE, FIN DE LA PARTIDA ganan blancas\n\n\n\n\n";
			if (comprobar_mate() == -1)
				std::cout << "JAQUE MATE, FIN DE LA PARTIDA ganan negras\n\n\n\n\n";
			return true;
		}
	}
	//Si ya hay jaque limitamos los posibles movimientos a los cuales sacarian al rey de jaque
	else if ((tab[y_org][x_org]->color == turno) && (tab[y_org][x_org]->validar_mov(pos_final, pos_origen, *this)) 
		&& comprobar_jaque(tab) != 0) {

		//Se crea otra matriz de piezas y se copia el contenido de tab, para "simular" el movimiento
		Pieza* copia[columnas][filas];
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				copia[j][i] = tab[j][i];
		}
		
		//Se simula el movimiento
		tab[y_dest][x_dest] = tab[y_org][x_org];
		tab[y_org][x_org] = nullptr;

		//Si despues del movimiento sigue el jaque, devuelve el tablero a su posicion original y devuelve  false
		if (comprobar_jaque(tab)!=0) {
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
					tab[j][i] = copia[j][i];
			}
			return false;
		}
		//Si no sigue en jaque efectua el movimiento
		else {
			Tablero::coger = 1;
			return true;
		}
	}

	return false;
}

int Tablero::comprobar_jaque(Pieza *ta[columnas][filas])
{
	int i, j,yn=0,yb=0,xn=0,xb=0;
	Vector2D reyb(0,0);
	Vector2D reyn(0,0);
	Vector2D origen(0, 0);
	
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
			if (ta[i][j] != nullptr) {
				if (ta[i][j]->pieza == 0)//es un rey
				{
					if (ta[i][j]->color == -1) {//rey blanco
						xb = j;
						yb = i;
						std::cout << "rey blanco en x:" << xb + 1 << " y:" << yb + 1 << std::endl;
					}
					else {//rey negro es color 1
						xn = j;
						yn = i;
						std::cout << "rey negro en x:" << xn + 1 << " y:" << yn + 1 << std::endl;
					}
				}
			}		
	}
	
	reyb.x = xb;
	reyb.y = yb;

	reyn.x = xn;
	reyn.y = yn;
	//ya tenemos las coordenadas,ahora se comprueba el jaque para el rey blanco
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (ta[i][j] != nullptr) {//si hay pieza
				if (ta[i][j]->color == 1)//la pieza es negra
				{
					origen.x = j;
					origen.y = i;
					if (ta[origen.y][origen.x]->validar_mov(&reyb, &origen, *this)) {//si alguna pieza negra puede llegar al reyb
						std::cout << "jaque al blanco señores";
						return -1;
					}
					else continue;
				}
			}
		}
	}

	//Lo mismo para el rey negro
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (ta[i][j] != nullptr) {//si hay pieza
				if (ta[i][j]->color == -1)//la pieza es blanca
				{
					origen.x = j;
					origen.y = i;
					if (ta[origen.y][origen.x]->validar_mov(&reyn, &origen, *this)) {//si alguna pieza negra puede llegar al reyb
						std::cout << "jaque al negro señores";
						return 1;
					}
					else continue;
				}
			}
		}
	}
	return 0;
}

//Funcion que simula todos los posibles movimientos de las piezas que estan en jaque y devuelve true si ninguno de estos movimientos saca al rey de jaque
int Tablero::comprobar_mate() {

	Vector2D pos_final(0, 0);
	Vector2D pos_inicial(0, 0);
	Pieza* copia[columnas][filas];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			copia[j][i] = tab[j][i];
	}
	//Recorre tab buscando piezas cuyo color == turno
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++) {
			pos_inicial.x = i;
			pos_inicial.y = j;
			if (tab[j][i] != nullptr && tab[j][i]->color != turno) {
				//Recorre tab buscando casillas validas
				for (int k = 0; k < 8; k++)
				{
					for (int l = 0; l < 8; l++) {
						pos_final.x = k;
						pos_final.y = l;
						//Si se puede mover se cambian las coord. y se comprueba si sigue habiendo jaque
						if (tab[j][i] != nullptr && tab[j][i]->validar_mov(&pos_final, &pos_inicial, *this)) {
							tab[pos_final.y][pos_final.x] = tab[pos_inicial.y][pos_inicial.x];
							tab[pos_inicial.y][pos_inicial.x] = nullptr;
							//Si ya no hay jaque devuelve el tablero a su posicion inicial y devuelve false (no hay mate)
							if (comprobar_jaque(tab) == 0) {
								for (int i = 0; i < 8; i++)
								{
									for (int j = 0; j < 8; j++)
										tab[j][i] = copia[j][i];
								}
								return 0;
							}
							//Si sigue habiendo jaque devuelve las piezas a las coord iniciales y continua buscando movimientos posibles
							else {
								for (int i = 0; i < 8; i++)
								{
									for (int j = 0; j < 8; j++)
										tab[j][i] = copia[j][i];
								}
							}
						}
					}
				}
			}
			else continue;

		}
	}
	if (comprobar_jaque(tab)==1)
	return 1;
	else if (comprobar_jaque(tab) == -1)
		return -1;

}

int Tablero::get_turno()
{
	return turno;
}

int Tablero::get_coger()
{
	return coger;
	
}

int Tablero::get_x()
{
	return x_org;
}

int Tablero::get_y()
{	
	return y_org;
}

void Tablero::set_turno(int t)
{
	turno = t;

}

void Tablero::set_coger(int c)
{
	coger = c;
}

void Tablero::set_x(int x)
{
	x_org = x;
}

void Tablero::set_y(int y)
{
	y_org = y;
}
	

