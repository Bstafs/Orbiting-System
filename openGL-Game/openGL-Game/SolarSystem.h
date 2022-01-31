#pragma once
#include <Windows.h>
#include <gl/GL.h> //OpenGL 
#include <gl/GLU.h> //OpenGL Utilities 
#include "GL\freeglut.h" //freeglut library
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Texture2D.h"
#include "MeshLoader.h"
#include "SceneObject.h"
#include "Cube.h"

class Texture2D;


class SolarSystem
{

public:

	void drawOrbit(float r);

private:

	SceneObject* SceneObjects[9];

};

