
#include "Peon.h"

void Peon::dibuja()
{
    //ELEGIMOS COLOR DEL FONDO DE LA IMAGEN
    
 
	glEnable(GL_TEXTURE_2D);         
    if(color==BLANCO)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("lib/imagenes/peonblanco.png").id);
    else glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("lib/imagenes/peonnegro.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
    glTexCoord2d(0, 1); ; glVertex3f( - 0.5,  - 0.5, 0.01f);
    glTexCoord2d(1, 1); ; glVertex3f( + 0.5,  - 0.5, 0.01f);
    glTexCoord2d(1, 0);   glVertex3f( + 0.5,  + 0.5, 0.01f);
    glTexCoord2d(0, 0); glVertex3f(- 0.5,  + 0.5, 0.01f);
    //
    glEnd();
    //glEnable(GL_LIGHTING);
}

bool Peon::validar_mov(int x_dest, int y_dest, int x_orig, int y_orig)
{   //FALTA MOVIMIENTO EN DIAGONAL, CUANDO HAGAMOS "COMER"
    std::cout << "soy peon" << std::endl;
    if (abs(x_orig - x_dest) == 0) {
        if (color == -1 && (y_dest - y_orig == 1 || (y_dest - y_orig == 2) && (y_orig == 2)))  //movimiento recto de peones blancos
            return true;
        else
            if (color == 1 && (y_dest - y_orig == -1 || (y_dest - y_orig == -2) && (y_orig == 7)))  //movimiento recto de peones negros
                return true;
            else return false;
    }
    else {
        std::cout << "movimiento no valido\n";
        return false;
    }
}
