#include "Alfil.h"
#include"Tablero.h"

void Alfil::dibuja()
{

    std::string negro, blanco;

    glEnable(GL_TEXTURE_2D);

    switch (modo)
    {
    case(Tradicional):
    {
        blanco = "lib/imagenes/alfilblanco_tradicional.png";
        negro = "lib/imagenes/alfilnegro_tradicional.png";
        break;
    }
    case(StarWars):
    {
        blanco = "lib/imagenes/alfilblanco_StarWars.png";
        negro = "lib/imagenes/alfilnegro_StarWars.png";
        break;
    }
    case(Etsidi):
    {
        blanco = "lib/imagenes/alfilblanco_tradicional_ETSIDI.png";
        negro = "lib/imagenes/alfilnegro_tradicional_ETSIDI.png";
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

bool Alfil::validar_mov(Vector2D* posfinal, Vector2D* posini, Tablero& tablero)
{
    int no_valid = -1;

    //Establece hacia donde se mueve el alfil, 1=arriba o derecha; -1=abajo o izq
    int dx = (posfinal->x > posini->x) ? 1 : -1;
    int dy = (posfinal->y > posini->y) ? 1 : -1;
    //Empieza en el origen
    int x = posini->x;//no es necesario
    int y = posini->y;

    //Recorre toda la trayectoria diagonal
    while (x != posfinal->x && y != posfinal->y) {
        //avanza a la siguiente casilla
        x += dx;
        y += dy;

        //Si la casilla que analiza no apunta a puntero nulo; hay pieza
        if (tablero.tab[y][x] != nullptr) {

            //Si la pieza en la trayectoria es en la casilla destino y es de otro color la come
            if (x == posfinal->x && y == posfinal->y && tablero.tab[posfinal->y][posfinal->x]->color != tablero.tab[posini->y][posini->x]->color) {
                
                return true;
            }

            else {
                // Hay una pieza en el camino
                no_valid = 1;
                return false;
            }
        }
    }

    //Si no ha encontrado piezas, o puede comer, efectua el movimiento
    if (no_valid != 1)
        if (abs(posfinal->x - posini->x) != abs(posfinal->y - posini->y)) {
           /* std::cout << "movimiento no valido\n";*/
            return false;
        }
        else
            return true;

}

std::string Alfil::getTipo()
{
    return "ALFIL";
}

std::string Alfil::getColor()
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

void Alfil::getTipoPieza()
{
    std::ofstream archivoSalida;
    archivoSalida.open("lib/ficheros/Partida.txt", std::ofstream::app);

    if (color == -1) {
        //std::cout << "blanco";
        if (archivoSalida.is_open()) {
            archivoSalida << "Alfil blanco" << std::endl;

            archivoSalida.close();
        }
    }

    else {
        //std::cout << "negro";
        if (archivoSalida.is_open()) {
            archivoSalida << "Alfil negro" << std::endl;

            archivoSalida.close();
        }
    }
}