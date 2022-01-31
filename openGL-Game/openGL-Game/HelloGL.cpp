#include "HelloGL.h"
#include <iostream>
#include <string>
#include "OBJLoader.h"

using namespace std;

string filename = "OBJFiles\\rock.obj";
OBJLoader* rockModel = nullptr;

HelloGL::HelloGL(int argc, char* argv[])
{
	srand(time(NULL));

	_rotation = 0;

	InitGL(argc,argv);
	InitObjects();
	InitOBJModels();
	InitLighting();

	rockModel = new OBJLoader("OBJFiles/rock.obj");

	glutMainLoop();
}

HelloGL::~HelloGL(void)
{
	delete camera;
}

void HelloGL::InitGL(int argc, char* argv[])
{

	GLUTCallbacks::Init(this);

	// Window Settings
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(720, 680);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Obiting System");

	// Function initialisation
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	
	//Perspective initialisation
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(120, 1, 1, 1000);
	glMatrixMode(GL_MODELVIEW);

	// Texture initialisation
	glEnable(GL_TEXTURE_2D);

	//Z-Buffering initialisation
	glEnable(GL_DEPTH_TEST);

	//Culling initialisation
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//Lighting initialisation
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

}

void HelloGL::InitObjects()
{

	camera = new Camera();

	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 20.0f;
	//camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -5.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	// Load Meshes
	
	Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");
	
	Mesh* pyramidMesh = MeshLoader::Load((char*)"pyramid.txt");

	// Load Textures

	Texture2D* textureSu = new Texture2D();
	textureSu->Load((char*)"Textures/sun.raw", 512, 512);
	
	Texture2D* textureC = new Texture2D();
	textureC->Load((char*)"Textures/stars.raw", 512, 512);

	Texture2D* textureM = new Texture2D();
	textureM->Load((char*)"Textures/mercury.raw", 2048, 1024);

	Texture2D* textureV = new Texture2D();
	textureV->Load((char*)"Textures/venus.raw", 2048, 1024);

	Texture2D* textureE = new Texture2D();
	textureE->Load((char*)"Textures/earth.raw", 2048, 1024);

	Texture2D* textureMa = new Texture2D();
	textureMa->Load((char*)"Textures/mars.raw", 2048, 1024);

	Texture2D* textureJ = new Texture2D();
	textureJ->Load((char*)"Textures/jupiter.raw", 2048, 1024);

	Texture2D* textureS = new Texture2D();
	textureS->Load((char*)"Textures/saturn.raw", 2048, 1024);
	
	Texture2D* textureU = new Texture2D();
	textureU->Load((char*)"Textures/uranus.raw", 2048, 1024);
	
	Texture2D* textureN = new Texture2D();
	textureN->Load((char*)"Textures/neptune.raw", 2048, 1024);

	Texture2D* textureP = new Texture2D();
	textureP->Load((char*)"Textures/pluto.raw", 2048, 1024);
	
	Texture2D* texturePeng = new Texture2D();
	texturePeng->Load((char*)"Textures/penguins.raw", 512, 512);

	// Display Each Planet
	// Mesh, Texture, Xposition, Yposition, Zposition, angle, angleXposition, angleYposition, angleZposition

		objects[0] = new Cube(cubeMesh, textureM , 2.4, 0.0, 0.0, 20.0f, 0.0f, 0.0f,  1.0f);  // Mercury

		objects[1] = new Cube(cubeMesh, textureV,  4.8, 0.0, 0.0, 120.0f, 0.0f, 0.0f, 1.0f); // Venus
	
		objects[2] = new Cube(cubeMesh, textureE,  7.2, 0.0, 0.0, 70.0f, 0.0f, 0.0f,  1.0f); // Earth

		objects[3] = new Cube(cubeMesh, textureMa, 9.6, 0.0, 0.0, 200.0f, 0.0f, 0.0f, 1.0f); // Mars

		objects[4] = new Cube(cubeMesh, textureJ,  12.0, 0.0, 0.0, 80.0f, 0.0f, 0.0f, 1.0f); // Jupiter

		objects[5] = new Cube(cubeMesh, textureS,  14.4, 0.0, 0.0, 150.0f, 0.0f, 0.0f, 1.0f); // Saturn

		objects[6] = new Cube(cubeMesh, textureU,  16.8, 0.0, 0.0, 60.0f, 0.0f, 0.0f, 1.0f); // Uranus
		
		objects[7] = new Cube(cubeMesh, textureN,  19.2, 0.0, 0.0, 180.0f, 0.0f, 0.0f, 1.0f); // Neptune
	
		objects[8] = new Cube(cubeMesh, textureP,  21.6, 0.0, 0.0, 240.0f, 0.0f, 0.0f, 1.0f); // Pluto
	 
		sun[0] = new Cube(cubeMesh, texturePeng, 0.0, 0.0, 0.0, 220.0f, 1.0f, 1.0f, 0.5f); // The Sun


}

void HelloGL:: InitOBJModels()
{

}

void HelloGL::InitLighting()
{
	_lightPosition = new Vector4();
	_lightPosition->x = 1.0;
	_lightPosition->y = 0.0;
	_lightPosition->z = 0.0;
	_lightPosition->w = 0.0;

	_lightData = new Lighting();
	_lightData->Ambient.x = 1.0;
	_lightData->Ambient.y = 0.2;
	_lightData->Ambient.z = 0.2;
	_lightData->Ambient.w = 1.0;
	_lightData->Diffuse.x = 1.0;
	_lightData->Diffuse.y = 0.8;
	_lightData->Diffuse.z = 0.8;
	_lightData->Diffuse.w = 1.0;
	_lightData->Specular.x = 1.0;
	_lightData->Specular.y = 0.2;
	_lightData->Specular.z = 0.2;
	_lightData->Specular.w = 1.0;
}

void HelloGL::Display()
{
	
	    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clears the scene

		glTranslatef(0.0, 0.5, -0.0);
	
		  
				objects[0]->Draw();
				objects[1]->Draw();
				objects[2]->Draw();
				objects[3]->Draw();
				objects[4]->Draw();
				objects[5]->Draw();
				objects[6]->Draw();
				objects[7]->Draw();
				objects[8]->Draw();			
				
				//sun[0]->Draw();
	
		Vector3 v = { -30.0f, 30.0f,1.0f };
		Vector3 v2 = { -30.0f, 25.0f,1.0f };
		Color c = { 5.0f, 0.0f, 0.0f };
	
		DrawString("My Orbiting System", &v, &c);
		DrawString("Number of Planets: 9", &v2, &c);

		glPushMatrix();
		DrawOrbit();
		rockModel->Draw();
	
		glPopMatrix();
	
	
		glFlush(); //flushes the scene drawn to the graphics card
		glutSwapBuffers();

}

void HelloGL::Update()
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	
		objects[0]->Update();
		objects[1]->Update();
		objects[2]->Update();
		objects[3]->Update();
		objects[4]->Update();
		objects[5]->Update();
		objects[6]->Update();
		objects[7]->Update();
		objects[8]->Update();

		sun[0]->Update();

		Vector3 v = { -30.0f, 30.0f,1.0f };
		Vector3 v2 = { -30.0f, 25.0f,1.0f };
		Color c = { 5.0f, 0.0f, 0.0f };

		DrawString("My Solar System", &v, &c);
		DrawString("Number of Planets: 9", &v2, &c);
		DrawString("", &v2, &c);


	glutPostRedisplay();


	//glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.x));
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->Diffuse.y));
	//glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->Specular.z));

	//glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.y));
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->Diffuse.y));
	//glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->Specular.y));

	//glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.z));
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->Diffuse.z));
	//glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->Specular.z));
  
    //glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));
    //glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->y));
    //glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->z));

}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'w')
	{
		camera->eye.z = camera->eye.z - 1.0f;
	}
	else if (key == 's')
	{
		camera->eye.z = camera->eye.z + 1.0f;
	}
	else if (key == 'd')
	{
		camera->center.x = camera->center.x + 1.0f;
	}
	else if (key == 'a')
	{
		camera->center.x = camera->center.x - 1.0f;
	}
	else if (key == 'r')
	{
		camera->eye.y = camera->eye.y + 1.0f;
	}
	else if (key == 'f')
	{
		camera->eye.y = camera->eye.y - 1.0f;
	}
	else if (key == 'i')
	{
	  
	}

}

void HelloGL::DrawString(const char* text, Vector3* position, Color* color)
{
	glPushMatrix();

	glTranslatef(position->x, position->y, position->z);

	glRasterPos2f(0.0f, 0.0f);

	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text);

	glPopMatrix();
}

void HelloGL::DrawOrbit()
{
	//Draw Orbit - Radius of 2.4 between each ring

	_solarSystem->drawOrbit(2.4); // Draw Ring One
	_solarSystem->drawOrbit(4.8); // Draw Ring Two
	_solarSystem->drawOrbit(7.2); // Draw Ring Three
	_solarSystem->drawOrbit(9.6); // Draw Ring Four
	_solarSystem->drawOrbit(12.0); // Draw Ring Five
	_solarSystem->drawOrbit(14.4); // Draw Ring Six
	_solarSystem->drawOrbit(16.8); // Draw Ring Seven
	_solarSystem->drawOrbit(19.2); // Draw Ring Eight
	_solarSystem->drawOrbit(21.6); // Draw Ring Nine

}
