#include "Rey.h"
#include"Tablero.h"

std::string Rey::getTipo()
{
    return "REY";
}

std::string Rey::getColor()
{
    switch (this->color)
    {
    case BLANCO:
        return "BLANCO";
        break;
    case NEGRO:
        return "NEGRO";
        break;
    default:
        return "NULL";
        break;
    }
}

void Rey::dibuja()
{

    std::string negro, blanco;

    glEnable(GL_TEXTURE_2D);


    switch (modo)
    {
    case(Tradicional):
    {
        blanco = "lib/imagenes/reyblanco_tradicional.png";
        negro = "lib/imagenes/reynegro_tradicional.png";
        break;
    }
    case(StarWars):
    {
        blanco = "lib/imagenes/reyblanco_StarWars.png";
        negro = "lib/imagenes/reynegro_StarWars.png";
        break;
    }
    case(Etsidi):
    {
        blanco = "lib/imagenes/reyblanco_tradicional_ETSIDI.png";
        negro = "lib/imagenes/reynegro_tradicional_ETSIDI.png";
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
bool Rey::validar_mov(Vector2D* posfinal, Vector2D* posini, Tablero& tablero)
{
   /* std::cout << "soy rey" << std::endl;*/
    if ((abs(posfinal->x - posini->x) < 2) && (abs(posfinal->y - posini->y) < 2))
    {
        if (tablero.tab[posfinal->y][posfinal->x] == nullptr)//si la casilla está vacía, no hay que comprobar color de pieza
            return true;
        else if (tablero.tab[posfinal->y][posfinal->x]->get_Color() != tablero.tab[posini->y][posini->x]->get_Color())
            return true;
        else
            return false;
    }
    else
        return false; 
}
void Rey::getTipoPieza()
{
    std::ofstream archivoSalida;
    archivoSalida.open("lib/ficheros/Partida.txt", std::ofstream::app);

    if (color == -1) {
        //std::cout << "blanco";
        if (archivoSalida.is_open()) {
            archivoSalida << "Rey blanco" << std::endl;

            archivoSalida.close();
        }
    }

    else {
        //std::cout << "negro";
        if (archivoSalida.is_open()) {
            archivoSalida << "Rey negro" << std::endl;

            archivoSalida.close();
        }
    }
}