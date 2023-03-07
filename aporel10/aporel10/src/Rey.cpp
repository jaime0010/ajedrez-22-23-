#include "Rey.h"

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
bool Rey::validar_mov(Vector2D*, Vector2D*)
{
    std::cout << "soy rey" << std::endl;
    return false;
}
/*
bool Rey::validar_mov(int, int, int, int)
{
    std::cout << "soy rey" << std::endl;
    return false;
}
*/