#include "OpenGLMaestro.h"
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <GL/glut.h>

OpenGLMaestro::OpenGLMaestro(char* windowTitle, unsigned int displayMode) {
	this->rotateX = 0;
	this->rotateY = 0;
	this->windowTitle = windowTitle;
	this->displayMode = displayMode;
}

void OpenGLMaestro::Display(){

	// Limpar a tela e o Z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Lado multicolorido - FRENTE
	glBegin(GL_POLYGON);

	// Os vértices serão adicionados na próxima etapa
	glEnd();

	// Reinicializar transformações
	glLoadIdentity();

	// Rotacionar quando o usuário mudar as variáveis rotate_x e rotate_y
	glRotatef(this->rotateX, 1.0, 0.0, 0.0);
	glRotatef(this->rotateY, 0.0, 1.0, 0.0);

	//Lado multicolorido - Frente
	glBegin(GL_POLYGON);
	glColor3f(0.09, 0.28, 0.89);

	glVertex3f(0.5, -0.5, -0.5);      // P1 é vermelho
	glVertex3f(0.5, 0.5, -0.5);      // P2 é verde
	glVertex3f(-0.5, 0.5, -0.5);      // P3 é azul
	glVertex3f(-0.5, -0.5, -0.5);      // P4 é roxo

	glEnd();

	// Lado branco - TRASEIRA
	glBegin(GL_POLYGON);
	glColor3f(0.14, 0.8, 0.74);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();

	// Lado roxo - DIREITA
	glBegin(GL_POLYGON);
	glColor3f(0.03, 0.8, 0.21);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();

	// Lado verde - ESQUERDA
	glBegin(GL_POLYGON);
	glColor3f(0.84, 0.32, 0.10);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	// Lado azul - TOPO
	glBegin(GL_POLYGON);
	glColor3f(0.87, 0.14, 0.39);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glEnd();

	// Lado vermelho - BASE
	glBegin(GL_POLYGON);
	glColor3f(0.87, 0.14, 0.39);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void OpenGLMaestro::Init(int argc, char** argv){

	// Inicializa o GLUT e processa os parâmetros do usuário
	glutInit(&argc, argv);

	//  Requisita uma janela true color de buffer duplo com o Z-buffer
	glutInitDisplayMode(this->displayMode);

	// Criar a janela
	glutCreateWindow(this->windowTitle);

	// Habilite o teste de profundidade do Z-buffer
	glEnable(GL_DEPTH_TEST);

	// Funções callback
	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);

	// Passando o controle para os eventos GLUT
	glutMainLoop();
}