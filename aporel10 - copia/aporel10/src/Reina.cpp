#include "Reina.h"
#include"Tablero.h"
#include  <string>


std::string Reina::getTipo()
{
    return "REINA";
}

std::string Reina::getColor()
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

void Reina::dibuja()
{

    glEnable(GL_TEXTURE_2D);

    switch (modo)
    {
        case(Tradicional):
        {
            blanco = "lib/imagenes/reinablanca_tradicional.png";
            negro = "lib/imagenes/reinanegra_tradicional.png";
            break;
        }
        case(StarWars):
        {
            blanco = "lib/imagenes/reinablanca_StarWars.png";
            negro = "lib/imagenes/reinanegra_StarWars.png";
            break;
        }
        case(Etsidi):
        {
            blanco = "lib/imagenes/reinablanca_tradicional_ETSIDI.png";
            negro = "lib/imagenes/reinanegra_tradicional_ETSIDI.png";
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
    //glEnable(GL_LIGHTING);
}
bool Reina::validar_mov(Vector2D* posfinal, Vector2D* posini, Tablero& tablero)
{
   /* std::cout << "soy reina" << std::endl;*/
    int dx = (posfinal->x > posini->x) ? 1 : -1;
    int dy = (posfinal->y > posini->y) ? 1 : -1;
    if (posfinal->x == posini->x)dx = 0;
    if (posfinal->y == posini->y)dy = 0;
    
    if (abs(posfinal->x - posini->x) != abs(posfinal->y - posini->y)) {//si no es diagonal
        if (dx != 0 && dy != 0){//si no es recto
           /* std::cout << "movimiento no valido\n";*/
            return false;
        }
        
    }
    int x = posini->x;
    int y = posini->y;
    int full = 0;
    while (y != posfinal->y || x != posfinal->x)
    {
        x += dx;
        y += dy;
        if (tablero.tab[y][x])//si hay una pieza
            full++;
    }
    if (tablero.tab[posfinal->y][posfinal->x] != nullptr)//si en la ultima casiilla hay pieza
    {
        if (tablero.tab[posfinal->y][posfinal->x]->get_Color() != tablero.tab[posini->y][posini->x]->get_Color())
        {//si el objetivo es de otro color
            full--;
        }
    }

    if (full == 0)
        return true;
    else
        return false;
}
void Reina::getTipoPieza()
{
 

    std::ofstream archivoSalida;
    archivoSalida.open("lib/ficheros/Partida.txt", std::ofstream::app);

    if (color == -1) {
        
        if (archivoSalida.is_open()) {
            archivoSalida << "Reina Blanca" << std::endl;

            archivoSalida.close();
        }
    }

    else {
       
        if (archivoSalida.is_open()) {
            archivoSalida << "Reina negra" << std::endl;

            archivoSalida.close();
        }
    }
}