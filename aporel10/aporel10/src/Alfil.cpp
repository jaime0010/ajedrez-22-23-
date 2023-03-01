#include "Alfil.h"


void Alfil::dibuja()
{

    glEnable(GL_TEXTURE_2D);
    if (color == BLANCO)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("lib/imagenes/alfilblanco.png").id);
    else glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("lib/imagenes/alfilnegro.png").id);
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

bool Alfil::validar_mov(int x_dest, int y_dest,int x_org,int y_org)
{
    std::cout << "soy alfil" << std::endl;
    if (abs(x_dest - x_org) == abs(y_dest - y_org)) {
        std::cout << "Movimiento valido del Alfil" << std::endl;
        return true;
    }
    return false;
}
