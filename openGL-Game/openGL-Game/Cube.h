#pragma once
#include <vector>
#include "Structures.h"
#include "SceneObject.h"
#include "GLUTCallbacks.h"

class Cube : public SceneObject
{
public:

	Cube(Mesh* mesh, Texture2D* texture,float x, float y, float z, float planetAngle, float anglePositionX, float anglePositionY, float anglePositionZ);
	~Cube();

	void Draw();
	void Update();
	void cubeMaterial();
	void rotateCubes(void);
	void Keyboard(unsigned char key, int x, int y);

private:

	GLfloat _rotation;

	GLfloat _angle;

	Vector3 _anglePosition;

	Vector3 _position;

	Material* _material;

	
};

