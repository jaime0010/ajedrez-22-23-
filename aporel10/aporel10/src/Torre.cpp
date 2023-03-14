#include "Torre.h"
#include "Tablero.h"

void Torre::dibuja()
{

    glEnable(GL_TEXTURE_2D);
    if (color == BLANCO)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("lib/imagenes/torreblanca.png").id);
    else glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("lib/imagenes/torrenegra.png").id);
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
bool Torre::validar_mov(Vector2D*posfinal, Vector2D*posini,Tablero& tablero)
{
    int no_valid = -1;
    //Establece si se mueve la torre, 
    int mueve_x = (posfinal->x == posini->x) ? 0 : 1;
    int mueve_y = (posfinal->y == posini->y) ? 0 : 1;

    //Establece hacia donde se mueve la torre, 1=arriba o derecha; -1=abajo o izq
    int dx = (posfinal->x > posini->x) ? 1 : ((mueve_x == 1) ? -1 : 0);
    int dy = (posfinal->y > posini->y) ? 1 : ((mueve_y == 1) ? -1 : 0);
    //Empieza en el origen
    int x = posini->x;
    int y = posini->y;

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
}