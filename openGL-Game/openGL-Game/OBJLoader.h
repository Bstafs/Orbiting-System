#pragma once
/**
 *  Class Name:     ObjModelLoader
 *
 *  Version:        1.0
 *  Date:           March 28, 2015
 *
 *  Author:         Mohammad Zunayed Hassan
 *  Email:          ZunayedHassanBD@gmail.com
 *
 *  Last Updated:
 *
 *  Changes History:
 */

#ifndef OBJMODELLOADER_H
#define OBJMODELLOADER_H

#include <Windows.h> //Required for OpenGL on Windows 
#include <gl/GL.h> //OpenGL 
#include <gl/GLU.h> //OpenGL Utilities 
#include "GL\freeglut.h" //freeglut library
#include "GLUTCallbacks.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

#ifdef __APPLE__
#include <GLUT/gl.h>
#else
#include <GL/gl.h>
#endif

using namespace std;

class OBJLoader
{
public:

    OBJLoader(string filename);

    ~OBJLoader();

    void Draw();

private:
    string filename = "";

    vector<vector<float>*>* vertices = new vector<vector<float>*>;
    vector<vector<int>*>* faces = new vector<vector<int>*>;


    vector<string>* GetSplittedStrings(string text, char delimeter);


    float GetFloatFromString(string text);

    float* GetNormal(float* coord1, float* coord2, float* coord3);
};

#endif // OBJMODELLOADER_H