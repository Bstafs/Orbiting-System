#pragma once
#include <vector>
#include "Structures.h"
#include "SceneObject.h"

class Pyramid : public SceneObject
{
public:
	Pyramid(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~Pyramid();

	void Draw();
	void Update();
	void PyramidMaterial();




private:



	GLfloat _rotation;

	Vector3 _position;

	Material* _material;


};

