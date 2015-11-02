#include "Drawer.h"
#include <GL/glut.h>
#include "CMY.h"
#include "Coordinate.h"


void Drawer::Start(unsigned int mode) {
	glBegin(mode);
}

void Drawer::SetColor(double c, double m, double y){
	glColor3f(c, m, y);
}

void Drawer::AddCoordinate(double x, double y, double z){
	glVertex3f(x, y, z);
}

void Drawer::End(){
	glEnd();
}

