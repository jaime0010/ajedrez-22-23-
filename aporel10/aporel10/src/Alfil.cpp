#include "Alfil.h"
#include"Tablero.h"

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

bool Alfil::validar_mov(Vector2D*posfinal, Vector2D*posini,Tablero &tablero)
{
    
    std::cout << "soy alfil" << std::endl;
    //Comprueba movimiento en diagonal
    if (abs(posfinal->x - posini->x) != abs(posfinal->y - posini->y)) {
        std::cout << "movimiento no valido\n";
        return false;
    }
    else
        return true;
        
}
/*
bool Alfil::validar_mov(int x_dest, int y_dest, int x_orig, int y_orig)
{
    
    std::cout << "soy alfil" << std::endl;
    //Comprueba movimiento en diagonal
    if (abs(x_dest - x_orig) != abs(y_dest - y_orig)) {
        std::cout << "movimiento no valido\n";
        return false;
    }
    else
        return true;
        
}
*/