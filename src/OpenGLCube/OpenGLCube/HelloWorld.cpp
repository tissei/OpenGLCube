#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <GL/glut.h>
#include "CMY.h"
#define GL_GLEXT_PROTOTYPES

// Variáveis Globais
double rotate_y = 0;
double rotate_x = 0;
CMY red;

// Declarações de Funções
void display(){

}

void specialKeys(int key, int x, int y) {

	// Seta para direita - aumenta a rotação em 5 graus
	if (key == GLUT_KEY_RIGHT)
		rotate_y += 5;

	//  Seta para esquerda - diminui a rotação em 5 graus
	else if (key == GLUT_KEY_LEFT)
		rotate_y -= 5;

	else if (key == GLUT_KEY_UP)
		rotate_x += 5;

	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 5;

	// Requisitar atualização da tela
	glutPostRedisplay();

}

int main(int argc, char* argv[]){

	// Inicializa o GLUT e processa os parâmetros do usuário
	glutInit(&argc, argv);

	//  Requisita uma janela true color de buffer duplo com o Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);

	// Criar a janela
	glutCreateWindow("Super Cubo");

	// Habilite o teste de profundidade do Z-buffer
	glEnable(GL_DEPTH_TEST);

	// Funções callback
	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);

	// Passando o controle para os eventos GLUT
	glutMainLoop();

	// Voltar para o SO
	return 0;

}
