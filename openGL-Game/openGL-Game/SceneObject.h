#pragma once
#include "Structures.h"
#include "Texture2D.h"

class SceneObject
{

public:
	
	SceneObject(Mesh* mesh, Texture2D* texture);
	virtual ~SceneObject();

	virtual void Update();
	virtual void Draw();
protected:
	
	Mesh* _mesh;
	Texture2D* _texture;

private:


};
