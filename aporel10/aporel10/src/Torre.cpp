#include "Torre.h"
#include"Tablero.h"

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
bool Torre::validar_mov(Vector2D* posfinal, Vector2D* posini, Tablero& tablero)
{
    int full = 0;
    for (int x = posini->x; x < abs(posfinal->x - posini->x); x++)
    {
        for (int y = posini->y; y < abs(posfinal->y - posini->y); y++)
        {
            if (tablero.tab[posini->y][posini->x])
                full++;
        }
    }
    if (full > 0)
        return false;
    std::cout << "soy torre" << std::endl;
    if (posfinal->x != posini->x && posfinal->y != posini->y) { //Si no es en linea recta
        std::cout << "movimiento no valido\n";
        return false;   //Devuelve movimiento NO valido
    }
    else
        return true;    //Devuelve movimiento valido
}
/*


bool Torre::validar_mov(int x_dest, int y_dest, int x_orig, int y_orig)
{
    std::cout << "soy torre" << std::endl;
    if (x_dest != x_orig && y_dest != y_orig) { //Si no es en linea recta
        std::cout << "movimiento no valido\n";
        return false;   //Devuelve movimiento NO valido
    }
    else
        return true;    //Devuelve movimiento valido
}

*/