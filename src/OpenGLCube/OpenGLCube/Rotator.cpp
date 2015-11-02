#include "Rotator.h"
#include <GL/glut.h>

double Rotator::rotateX = 0;
double Rotator::rotateY = 0;
double Rotator::rotateMX = 0;
double Rotator::rotateMY = 0;

/**
	Rotates the object in the screen by 5 degrees

	@param key the key pressed on keyboard.
	@param x indicate the mouse in window relative
	coordinates when the key was pressed.
	@param y indicate the mouse in window relative
	coordinates when the key was pressed.
*/
void Rotator::CalculateKeyboardRotation(int key, int x, int y) {
	
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		Rotator::rotateY += 5;
		break;
	case GLUT_KEY_LEFT:
		Rotator::rotateY -= 5;
		break;
	case GLUT_KEY_UP:
		Rotator::rotateX += 5;
		break;
	case GLUT_KEY_DOWN:
		Rotator::rotateX -= 5;
		break;
	}

	glutPostRedisplay();
}

/**
	Rotates the object in the screen by 5 degrees

	@param x indicate the mouse in window relative
	coordinates when the key was pressed.
	@param y indicate the mouse in window relative
	coordinates when the key was pressed.
*/
void Rotator::CalculateMouseRotation(int x, int y) {

	if (x > Rotator::rotateMX) {
		Rotator::rotateX += 2;
		Rotator::rotateMX = x;
	}
	else if (x < Rotator::rotateMX) {
		Rotator::rotateX -= 2;
		Rotator::rotateMX = x;
	}
	if (y > Rotator::rotateMY) {
		Rotator::rotateY += 2;
		Rotator::rotateMY = y;
	}
	else if (y < Rotator::rotateMY) {
		Rotator::rotateY -= 2;
		Rotator::rotateMY = y;
	}
	glutPostRedisplay();
}

/*
	Executes the rotation based on x and y values.
*/
void Rotator::Rotate(){
	glRotatef(Rotator::rotateX, 1.0, 0.0, 0.0);
	glRotatef(Rotator::rotateY, 0.0, 1.0, 0.0);
}