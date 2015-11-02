#include "CubeBuilder.h"
#include <GL/glut.h>
#include "CMY.h"
#include "Drawer.h"

void CubeBuilder::BuildCube(double size){
	
	CMY red = CMY(0, 0.7671, 0.7078);
	CMY blue = CMY(0.8238, 0.2467, 0);
	CMY yellow = CMY(0, 0.2069, 0.8879);
	CMY white = CMY(0, 0.0526, 0.1903);
	CMY green = CMY(0.8532, 0, 0.2890);

	Drawer drawer = Drawer();

	drawer.Start(GL_POLYGON);
	drawer.SetColor(red.c, red.m, red.y);
	drawer.AddCoordinate(size, -size, -size);
	drawer.AddCoordinate(size, size, -size);
	drawer.AddCoordinate(-size, size, -size);
	drawer.AddCoordinate(-size, -size, -size);
	drawer.End();

	drawer.Start(GL_POLYGON);
	drawer.SetColor(yellow.c, yellow.m, yellow.y);
	drawer.AddCoordinate(size, -size, size);
	drawer.AddCoordinate(size, size, size);
	drawer.AddCoordinate(-size, size, size);
	drawer.AddCoordinate(-size, -size, size);
	drawer.End();

	drawer.Start(GL_POLYGON);
	drawer.SetColor(white.c, white.m, white.y);
	drawer.AddCoordinate(size, -size, -size);
	drawer.AddCoordinate(size, size, -size);
	drawer.AddCoordinate(size, size, size);
	drawer.AddCoordinate(size, -size, size);
	drawer.End();

	drawer.Start(GL_POLYGON);
	drawer.SetColor(green.c, green.m, green.y);
	drawer.AddCoordinate(-size, -size, size);
	drawer.AddCoordinate(-size, size, size);
	drawer.AddCoordinate(-size, size, -size);
	drawer.AddCoordinate(-size, -size, -size);
	drawer.End();

	drawer.Start(GL_POLYGON);
	drawer.SetColor(blue.c, blue.m, blue.y);
	drawer.AddCoordinate(size, size, size);
	drawer.AddCoordinate(size, size, -size);
	drawer.AddCoordinate(-size, size, -size);
	drawer.AddCoordinate(-size, size, size);
	drawer.End();

	drawer.Start(GL_POLYGON);
	drawer.SetColor(blue.c, blue.m, blue.y);
	drawer.AddCoordinate(size, -size, -size);
	drawer.AddCoordinate(size, -size, size);
	drawer.AddCoordinate(-size, -size, size);
	drawer.AddCoordinate(-size, -size, -size);
	drawer.End();
}