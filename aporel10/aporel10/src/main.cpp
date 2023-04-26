#include "freeglut.h"
#include<iostream>
//#include "Tablero.h"
#include "ETSIDI.h"
#include "Coordinador.h"
using namespace std;
//Tablero tab;
Coordinador coordinador;


//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void OnMouseClick(int button, int state, int x, int y); //LLamada para la gestion del raton
void resize(int width, int height); //LLamada para no maximizar pantalla

int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutMouseFunc(OnMouseClick);
	glutKeyboardFunc(OnKeyboardDown);

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}
void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(4.5, 0, 20,  // posicion del ojo
		4.5, 4.5, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el código de dibujo

	//tab.dibuja();
	coordinador.dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	coordinador.Tecla(key);
}

void OnTimer(int value)
{

}

void OnMouseClick(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//x e y son las casillas clickadas por el raton
		if (x > 252 && x <= 294)x = 1;
		if (x > 295 && x <= 337)x = 2;
		if (x > 338 && x <= 379)x = 3;
		if (x > 380 && x <= 419)x = 4;
		if (x > 420 && x <= 464)x = 5;
		if (x > 465 && x <= 504)x = 6;
		if (x > 505 && x <= 549)x = 7;
		if (x > 208 && x <= 251)x = 0;

		if (y < 449 && y >= 407)y = 1;
		if (y < 406 && y >= 366)y = 2;
		if (y < 365 && y >= 325)y = 3;
		if (y < 324 && y >= 285)y = 4;
		if (y < 284 && y >= 244)y = 5;
		if (y < 243 && y >= 207)y = 6;
		if (y < 206 && y >= 170)y = 7;
		if (y < 491 && y >= 450)y = 0;
		
		coordinador.mueve(coordinador.xorig, coordinador.yorig, x, y);

		/*if (tab.coger < 0) {                    //cogemos la posicion a la que nos queremos mover
			if (tab.coger_posiciones(tab.x_org, tab.y_org, x, y)) {
				tab.turno *= -1;	//Cambia de turno una vez validado el movimiento
				cout << "Turno = " << tab.turno << endl;
			}
			tab.coger *= -1;
		}

		if (x > 8 || y > 8) {
			std::cout << " CASILLA FUERA DE LIMITES " << std::endl;
			ETSIDI::playMusica("lib/sonidos/disparo.mp3");
			tab.coger = 1;
		}

		if (tab.hay_pieza(x, y)) {
			tab.coger *= -1;
			tab.x_org = x;
			tab.y_org = y;
		}



	}*/

	}

}

void resize(int width, int height)
{
}
