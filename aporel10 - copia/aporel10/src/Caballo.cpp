#include "Caballo.h"
#include"Tablero.h"


std::string Caballo::getTipo()
{
    return "CABALLO";
}

std::string Caballo::getColor()
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

void Caballo::dibuja()
{

    std::string negro, blanco;

    glEnable(GL_TEXTURE_2D);

    switch (modo)
    {
    case(Tradicional):
    {
        blanco = "lib/imagenes/caballoblanco_tradicional.png";
        negro = "lib/imagenes/caballonegro_tradicional.png";
        break;
    }
    case(StarWars):
    {
        blanco = "lib/imagenes/caballoblanco_StarWars.png";
        negro = "lib/imagenes/caballonegro_StarWars.png";
        break;
    }
    case(Etsidi):
    {
        blanco = "lib/imagenes/caballoblanco_tradicional_ETSIDI.png";
        negro = "lib/imagenes/caballonegro_tradicional_ETSIDI.png";
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
bool Caballo::validar_mov(Vector2D* posfinal, Vector2D* posini, Tablero& tablero)
{
    
    if ((abs(posfinal->x - posini->x) == 2 && abs(posfinal->y - posini->y) == 1)|| (abs(posfinal->x - posini->x) == 1 && abs(posfinal->y - posini->y) == 2)) 
    {
        if (tablero.tab[posfinal->y][posfinal->x] == nullptr)//si no hay pieza
            return true;
        else if (tablero.tab[posfinal->y][posfinal->x]->get_Color() != tablero.tab[posini->y][posini->x]->get_Color())//si son del  mismo color
            return true;
        else {
            return false;
        }
    }
      

    else {
       /* std::cout << "movimiento no valido\n";*/
        return false;
    }
}
void Caballo::getTipoPieza()
{
    std::ofstream archivoSalida;
    archivoSalida.open("lib/ficheros/Partida.txt", std::ofstream::app);

    
    if (color == -1) {
        
        if (archivoSalida.is_open()) {
            archivoSalida << "Caballo blanco" << std::endl;

            archivoSalida.close();
        }
    }

    else {
       
        if (archivoSalida.is_open()) {
            archivoSalida << "Caballo negro" << std::endl;

            archivoSalida.close();
        }
    }
}