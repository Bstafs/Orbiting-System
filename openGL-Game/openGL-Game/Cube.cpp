#include "Cube.h"
#include <iostream>
#include <fstream>
using namespace std;


Cube::Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z, float planetAngle, float anglePositionX, float anglePositionY, float anglePositionZ) : SceneObject(mesh, texture)
{


	_rotation = 360;

	_angle = planetAngle;

	_position.x = x;
	_position.y = y;
	_position.z = z; 

	_anglePosition.x = anglePositionX;
	_anglePosition.y = anglePositionY;
	_anglePosition.z = anglePositionZ;



}
Cube::~Cube()
{
	
}

void Cube::Draw()
{

	
	if (_mesh->Vertices != nullptr && _mesh->Normals != nullptr && _mesh->Indices != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glPushMatrix();

		glRotatef(_rotation - _angle, _anglePosition.x, _anglePosition.y, _anglePosition.z);
		
		glTranslatef(_position.x, -_position.y,-_position.z);

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glNormalPointer(GL_FLOAT, 0, _mesh->Normals);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);

		cubeMaterial();

	    glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->Ambient.x)); 
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->Diffuse.x));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->Specular.x));

		glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->Ambient.y));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->Diffuse.y));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->Specular.y));

		glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->Ambient.z));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->Diffuse.z));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->Specular.z));
		
		glMaterialf(GL_FRONT, GL_SHININESS, _material->Shininess);

		glPushMatrix();
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _mesh->Indices);
		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);

		glPopMatrix();

	}

}

void Cube::Update()
{
	rotateCubes();
}

void Cube::cubeMaterial()
{
	_material = new Material();
	_material->Ambient.x = 0.5; _material->Ambient.y = 0.05; _material->Ambient.z = 0.05;
	_material->Ambient.w = 1.0;
	_material->Diffuse.x = 0.8; _material->Diffuse.y = 0.05; _material->Diffuse.z = 0.05;
	_material->Diffuse.w = 1.0;
	_material->Specular.x = 1.0; _material->Specular.y = 1.0; _material->Specular.z = 1.0;
	_material->Specular.w = 1.0;
	_material->Shininess = 100.0f;

}

void Cube::rotateCubes(void)
{
	_rotation = _rotation + 2.0;
	if (_rotation > 360.0)
	{
		_rotation = _rotation - 360.0;
	}
	glutPostRedisplay();
}
