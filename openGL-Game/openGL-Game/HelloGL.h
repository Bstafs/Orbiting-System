#pragma once
#include <Windows.h> //Required for OpenGL on Windows 
#include <gl/GL.h> //OpenGL 
#include <gl/GLU.h> //OpenGL Utilities 
#include "GL\freeglut.h" //freeglut library
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"
#include "Pyramid.h"
#include <time.h>
#include "MeshLoader.h"
#include "Texture2D.h"
#include "SolarSystem.h"
#include <string>
#include "OBJLoader.h"

#define REFRESHRATE 16


class HelloGL
{
public:

	HelloGL(int argc, char* argv[]);
	~HelloGL(void);

	void Display();

	void Update();

	void Keyboard(unsigned char key, int x, int y);

	void InitObjects();
	void InitGL(int argc, char* argv[]);
    void InitLighting();
	void InitOBJModels();

	void DrawString(const char* text, Vector3* position, Color* color);

	void DrawOrbit();

private:

	Camera* camera;
	SceneObject* objects[11];
	SceneObject* sun[1];

	Cube* cube;

	Vector4* _lightPosition;
	Lighting* _lightData;

	SolarSystem* _solarSystem;

	GLfloat _rotation;

	Vector3 _position;

};

