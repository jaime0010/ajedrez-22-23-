#include "Reina.h"
#include "Tablero.h"

void Reina::dibuja()
{

    glEnable(GL_TEXTURE_2D);
    if (color == BLANCO)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("lib/imagenes/reinablanca.png").id);
    else glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("lib/imagenes/reinanegra.png").id);
    glDisable(GL_LIGHTING);
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 1); ; glVertex3f(-0.5, -0.5, 0.01f);
    glTexCoord2d(1, 1); ; glVertex3f(+0.5, -0.5, 0.01f);
    glTexCoord2d(1, 0);   glVertex3f(+0.5, +0.5, 0.01f);
    glTexCoord2d(0, 0); glVertex3f(-0.5, +0.5, 0.01f);
    //
    glEnd();
    //glEnable(GL_LIGHTING);
}
bool Reina::validar_mov(Vector2D* posfinal, Vector2D* posini, Tablero& tablero)
{



    //int no_valid = -1;
    //bool primer_mov = true;

    //Posición inicial de la reina
    


    //Movimiento de la reina a la derecha 
    if (posfinal->x > posini->x && posini->y == posfinal->y)
    {
        //Se recorren todas las casillas en el eje x, empezando por la posición inicial de la reina
        for (int i = posini->x; i < posfinal->x; i++)

            if (tablero.tab[posini->y][i] != nullptr) //Si en la casilla destino hay pieza 
            {
                //Si la reina encuentra una pieza en su trayectoria en el eje x se la come 
                if (i == posfinal->x)
                {
                    if (tablero.tab[posini->y][i]->getColor() == tablero.tab[posini->y][posfinal->x]->getColor()) return false; //si la pieza en la casilla destino es del mismo color 
                    else if (tablero.tab[posini->y][i]->getColor() != tablero.tab[posini->y][posfinal->x]->getColor())return true; //si la pieza en la casilla destino es de color distinto 
                }
                else return false;
            }
        return true;
    }

}

    //if ((posini->x == 4 && primer_mov == true)&&((posini->y == 7 || posini->y == 0)&&primer_mov == true))


    //int mueve_x = (posfinal->x == 4) ? 0 : 1; //mueve_x == 0 cuando es el primier movimiento en el eje x
    //int mueve_y = (posfinal->y == 7 || posfinal->y == 0) ? 0 : 1;

    ////Establece hacia donde se mueve la torre, 1=arriba o derecha; -1=abajo o izq
    //int dx = (posfinal->x > posini->x) ? 1 : ((mueve_x == 1) ? -1 : 0);
    //int dy = (posfinal->y > posini->y) ? 1 : ((mueve_y == 1) ? -1 : 0);
    ////Empieza en el origen
    //int x = posini->x;
    //int y = posini->y;

    /*
    //Recorre toda la trayectoria recta
    while (x != posfinal->x || y != posfinal->y) {
        //avanza a la siguiente casilla
        x += dx;
        y += dy;
        //Si la casilla que analiza no apunta a puntero nulo; hay pieza
        if (tablero.tab[y][x] != nullptr) {

            //Si la pieza en la trayectoria es en la casilla destino y es de otro color la come
            if (x == posfinal->x && y == posfinal->y && tablero.tab[posfinal->y][posfinal->x]->color != tablero.tab[posini->y][posini->x]->color)
                return true;

            else {
                // Hay una pieza en el camino
                no_valid = 1;
                return false;
            }
        }
    }
    if (no_valid != 1) {
        std::cout << "soy torre" << std::endl;
        if (posfinal->x != posini->x && posfinal->y != posini->y) { //Si no es en linea recta
            std::cout << "movimiento no valido\n";
            return false;   //Devuelve movimiento NO valido
        }
        else
            return true;    //Devuelve movimiento valido
    }

    std::cout << "soy reina" << std::endl;

    if ((abs(posfinal->x - posini->x) == abs(posfinal->y - posini->y)) || (posfinal->x == posini->x || posfinal->y == posini->y))  //Comprueba linea recta y diagonal
        return true;

    else {
        std::cout << "movimiento no valido\n";
        return false;
    }
}
/*
bool Reina::validar_mov(int x_dest, int y_dest, int x_orig, int y_orig)
{
    std::cout << "soy reina" << std::endl;
    
    if((abs(x_dest - x_orig) == abs(y_dest - y_orig))||(x_dest == x_orig || y_dest == y_orig))  //Comprueba linea recta y diagonal
        return true;
    
    else {
        std::cout << "movimiento no valido\n";
        return false;
    }
}
*/
    

    