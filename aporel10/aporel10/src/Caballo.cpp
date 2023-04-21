#include "Caballo.h"
#include"Tablero.h"

void Caballo::dibuja()
{

    glEnable(GL_TEXTURE_2D);
    if (color == BLANCO)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("lib/imagenes/caballoblanco.png").id);
    else glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("lib/imagenes/caballonegro.png").id);
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
bool Caballo::validar_mov(Vector2D* posfinal, Vector2D* posini, Tablero& tablero)
{
   /* std::cout << "soy caballo" << std::endl;*/

    //Comprueba movimiento en "L"
    
    if ((abs(posfinal->x - posini->x) == 2 && abs(posfinal->y - posini->y) == 1)|| (abs(posfinal->x - posini->x) == 1 && abs(posfinal->y - posini->y) == 2)) 
    {
        if (tablero.tab[posfinal->y][posfinal->x] == nullptr)//si no hay pieza
            return true;
        else if (tablero.tab[posfinal->y][posfinal->x]->color != tablero.tab[posini->y][posini->x]->color)//si son del  mismo color
            return true;
        else {
           /* std::cout << "movimiento no valido\n";*/
            return false;
        }
    }
      

    else {
       /* std::cout << "movimiento no valido\n";*/
        return false;
    }
}
