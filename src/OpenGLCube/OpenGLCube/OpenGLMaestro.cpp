#include "OpenGLMaestro.h"
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <GL/glut.h>
#include "Rotator.h"
#include "CubeBuilder.h"

OpenGLMaestro::OpenGLMaestro(char* windowTitle, unsigned int displayMode) {
	this->windowTitle = windowTitle;
	this->displayMode = displayMode;
}

void OpenGLMaestro::DisplayCallback(){

	OpenGLMaestro::ClearScreen(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	OpenGLMaestro::Prepare(GL_POLYGON);

	Rotator::Rotate();

	CubeBuilder().BuildCube(0.5);

	OpenGLMaestro::Flush();
}

/**
	Initializes the example

	@param argc passed parameters.
	@param argv passed parameters
*/
void OpenGLMaestro::Init(int argc, char** argv){
	glutInit(&argc, argv);
	this->StartWindow();
	this->EnableCapability(GL_DEPTH_TEST);
	this->SetCallbacks();
	this->GlutStart();
}

/**
	Creates the example window
*/
void OpenGLMaestro::StartWindow() {
	glutInitDisplayMode(this->displayMode);
	glutCreateWindow(this->windowTitle);
}

/**
	Enable or disable server-side GL capabilities

	@param capability Specifies a symbolic constant 
	indicating a GL capability.
*/
void OpenGLMaestro::EnableCapability(unsigned int capability) {
	glEnable(capability);
}

/**
	Set the callback functions
*/
void OpenGLMaestro::SetCallbacks() {
	glutDisplayFunc(&OpenGLMaestro::DisplayCallback);
	glutSpecialFunc(&Rotator::CalculateKeyboardRotation);
	glutMotionFunc(&Rotator::CalculateMouseRotation);
}

/**
	Start the example
*/
void OpenGLMaestro::GlutStart() {
	glutMainLoop();
}

/**
	Clear buffers to preset values	

	@param mask Bitwise OR of masks that 
	indicate the buffers to be cleared.
*/
void OpenGLMaestro::ClearScreen(unsigned int mask) {
	glClear(mask);
}

/**
	Prepares the enviroment begin drawing

	@param mask Specifies the primitive 
	or primitives that will be created 
	from vertices presented between glBegin 
	and the subsequent glEnd.
*/
void OpenGLMaestro::Prepare(unsigned int mode) {
	glBegin(mode);
	glEnd();
	glLoadIdentity();
}

/**
	Flush the buffers on the current screen
*/
void OpenGLMaestro::Flush() {
	glFlush();
	glutSwapBuffers();
}