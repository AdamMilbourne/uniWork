#pragma once
#include <Windows.h> // required for opengl on windows
#include <gl/GL.h> // Opengl
#include <gl/GLU.h> // opengl utilities
#include "GL\freeglut.h" // freeglut library
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"
#include "MeshLoader.h"
#include "Pyramid.h"
#include <iostream>
#include <fstream>
#define REFRESHRATE 16

class Texture2D;
class Pyramid;
class Cube;
class HelloGL
{
public:
	//constructor def
	HelloGL(int argc, char* argv[]);
	//destrcutor
	~HelloGL(void);
	void Display();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	
	void InitObjects();
	void InitGL(int argc, char* argv[]);
	void InitLighting();
	

private:
	float rotation;
	Camera* camera;
	SceneObject* objects[1000];
	Vector4* _lightPosition;
	Lighting* _lightData;
	Input* CubeInput;
};




