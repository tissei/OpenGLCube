#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <GL/glut.h>
#include "OpenGLMaestro.h"
#define GL_GLEXT_PROTOTYPES

int main(int argc, char* argv[]){

	OpenGLMaestro maestro = OpenGLMaestro("Super Cubo", GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);

	maestro.Init(argc, argv);

	// Voltar para o SO
	return 0;

}
