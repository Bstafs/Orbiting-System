#include "SolarSystem.h"
#include <random>
#include <ctime>
#include <math.h>

#define PI 3.14

static GLfloat _rotation = 0.0;

void SolarSystem::drawOrbit(float r)
{
	glLineWidth(1.5); // Thickness of lines
	
	glBegin(GL_LINES); // Begin drawing lines
	
	for (int i = 0; i < 200; i++)
	{
		float A = (i * 2 * PI) / 100; // Area
		
		float x = r * cos(A); // X position
		
		float y = r * sin(A); // Y Position
		
		glVertex2f(x, y); // Place a point at the x and y position
	}
	glEnd();
}

