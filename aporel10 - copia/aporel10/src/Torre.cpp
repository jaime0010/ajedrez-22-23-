#include "Torre.h"
#include"Tablero.h"
#include "Tablero.h"

std::string Torre::getTipo()
{
    return "TORRE";
}

std::string Torre::getColor()
{
    switch (this->color)
    {
    case BLANCO:
        return "BLANCA";
        break;
    case NEGRO:
        return "NEGRA";
        break;
    default:
        return "NULL";
        break;
    }
}

void Torre::dibuja()
{

    std::string negro, blanco;

    glEnable(GL_TEXTURE_2D);


    switch (modo)
    {
    case(Tradicional):
    {
        blanco = "lib/imagenes/torreblanca_tradicional.png";
        negro = "lib/imagenes/torrenegra_tradicional.png";
        break;
    }
    case(StarWars):
    {
        blanco = "lib/imagenes/torreblanca_StarWars.png";
        negro = "lib/imagenes/torrenegra_StarWars.png";
        break;
    }
    case(Etsidi):
    {
        blanco = "lib/imagenes/torreblanca_tradicional_ETSIDI.png";
        negro = "lib/imagenes/torrenegra_tradicional_ETSIDI.png";
        break;
    }
    }


    if (color == BLANCO)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(blanco.c_str()).id);
    else glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(negro.c_str()).id);
    glDisable(GL_LIGHTING);
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 1); ; glVertex3f(-0.5, -0.5, 0.01f);
    glTexCoord2d(1, 1); ; glVertex3f(+0.5, -0.5, 0.01f);
    glTexCoord2d(1, 0);   glVertex3f(+0.5, +0.5, 0.01f);
    glTexCoord2d(0, 0); glVertex3f(-0.5, +0.5, 0.01f);
    //
    glEnd();
    
}
bool Torre::validar_mov(Vector2D* posfinal, Vector2D* posini, Tablero& tablero)
{
    int dx = (posfinal->x > posini->x) ? 1 : -1;
    int dy = (posfinal->y > posini->y) ? 1 : -1;
    if (posfinal->x == posini->x)dx = 0;
    if (posfinal->y == posini->y)dy = 0;

    if (dx != 0 && dy != 0)//hay incrmento enlos dos ejes=mal
        return false;

    int x = posini->x;
    int y = posini->y;
    int full = 0;
    while (y!=posfinal->y || x!=posfinal->x)
    {
        x += dx;
        y += dy;
        if (tablero.tab[y][x])//si hay una pieza
            full++;
    }
    if (tablero.tab[posfinal->y][posfinal->x]!=nullptr)//si en la ultima casiilla hay pieza
    {
        if (tablero.tab[posfinal->y][posfinal->x]->color != tablero.tab[posini->y][posini->x]->color)
        {//si el objetivo es de otro color
            full--;
        }
    }
    
    if (full == 0)
        return true;
    else
        return false;
    
}
void Torre::getTipoPieza()
{
    std::ofstream archivoSalida;
    archivoSalida.open("lib/ficheros/Partida.txt", std::ofstream::app);

    if (color == -1) {
      
        if (archivoSalida.is_open()) {
            archivoSalida << "Torre blanca" << std::endl;

            archivoSalida.close();
        }
    }

    else {
        if (archivoSalida.is_open()) {
            archivoSalida << "Torre negra " << std::endl;

            archivoSalida.close();
        }
    }
}