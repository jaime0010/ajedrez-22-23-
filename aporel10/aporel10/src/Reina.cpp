#include "Reina.h"

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
bool Reina::validar_mov(Vector2D* posfinal, Vector2D* posini,Tablero& tablero)
{
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