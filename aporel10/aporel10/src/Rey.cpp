#include "Rey.h"
#include"Tablero.h"
void Rey::dibuja()
{

    glEnable(GL_TEXTURE_2D);
    if (color == BLANCO)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("lib/imagenes/reyblanco.png").id);
    else glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("lib/imagenes/reynegro.png").id);
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
bool Rey::validar_mov(Vector2D* posfinal, Vector2D* posini, Tablero& tablero)
{
    std::cout << "soy rey" << std::endl;
    if ((abs(posfinal->x - posini->x) < 2) && (abs(posfinal->y - posini->y) < 2))
    {
        if (tablero.tab[posfinal->y][posfinal->x] == nullptr)//si la casilla está vacía, no hay que comprobar color de pieza
            return true;
        else if (tablero.tab[posfinal->y][posfinal->x]->color != tablero.tab[posini->y][posini->x]->color)
            return true;
    }
    else
        return false; 
}
