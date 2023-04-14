
#include "Peon.h"
#include"Tablero.h"

void Peon::dibuja()
{
    //ELEGIMOS COLOR DEL FONDO DE LA IMAGEN


    glEnable(GL_TEXTURE_2D);
    if (color == BLANCO)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("lib/imagenes/peonblanco.png").id);
    else glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("lib/imagenes/peonnegro.png").id);
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


bool Peon::validar_mov(Vector2D* pos_final, Vector2D* pos_origen, Tablero& tablero)
    {
        int dx = (pos_final->x > pos_origen->x) ? 1 : -1;
        int dy = (pos_final->y > pos_origen->y) ? 1 : -1;

        int x = pos_origen->x;
        int y = pos_origen->y;

        //Movimiento de avance recto
        if (abs(pos_origen->x - pos_final->x) == 0) {
            //movimiento recto de peones blancos
            if (color == -1 && (pos_final->y - pos_origen->y == 1 || ((pos_final->y - pos_origen->y == 2) && (pos_origen->y == 1)))) {  
                while (y != pos_final->y) {
                    //avanza a la siguiente casilla
                    y += dy;

                    //Si la casilla que analiza no apunta a puntero nulo; hay pieza
                    if (tablero.tab[y][x] != nullptr)
                        return false;
                }
                return true;
            }
            //movimiento recto de peones negros
            else if (color == 1 && (pos_final->y - pos_origen->y == -1 || ((pos_final->y - pos_origen->y == -2) && (pos_origen->y == 6)))) {  
                while (y != pos_final->y) {
                    //avanza a la siguiente casilla
                    y += dy;

                    //Si la casilla que analiza no apunta a puntero nulo; hay pieza
                    if (tablero.tab[y][x] != nullptr)
                        return false;
                }
                return true;
            }
            else return false;
        }
        //Movimiento de comer diagonal
        else if (abs(pos_origen->x - pos_final->x) == 1 && abs(pos_origen->y - pos_final->y) == 1) {

            //Comprueba que si es blanca aumente "y", se mueve hacia arriba
            if (color == -1 && pos_final->y > pos_origen->y) {
                while (y != pos_final->y && x != pos_final->x) {
                    //avanza a la siguiente casilla
                    x += dx;
                    y += dy;
                    //Si la casilla que analiza apunta a puntero nulo no puede avanzar en diagonal
                    if (tablero.tab[y][x] == nullptr)
                        return false;
                    //Si hay pieza y no es del mismo color avanza
                    else if (tablero.tab[pos_final->y][pos_final->x]->color != tablero.tab[pos_origen->y][pos_origen->x]->color)
                        return true;
                    else return false;
                }
            }
            //Comprueba que si es negra disminuye "y"
            else if (color == 1 && pos_final->y < pos_origen->y) {
                while (y != pos_final->y && x != pos_final->x) {
                    //avanza a la siguiente casilla
                    x += dx;
                    y += dy;
                    //Si la casilla que analiza apunta a puntero nulo no puede avanzar en diagonal
                    if (tablero.tab[y][x] == nullptr)
                        return false;
                    //Si hay pieza y no es del mismo color avanza
                    else if (tablero.tab[pos_final->y][pos_final->x]->color != tablero.tab[pos_origen->y][pos_origen->x]->color)
                        return true;
                    else return false;
                }
            }
            else return false;
        }
        else return false;

    }