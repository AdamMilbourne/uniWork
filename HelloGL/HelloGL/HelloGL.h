#pragma once
#include <Windows.h> // required for opengl on windows
#include <gl/GL.h> // Opengl
#include <gl/GLU.h> // opengl utilities
#include "GL\freeglut.h" // freeglut library
#include "GLUTCallbacks.h"
#define REFRESHRATE 16

class HelloGL
{
public:
	//constructor def
	HelloGL(int argc, char* argv[]);

	//destrcutor
	~HelloGL(void);

	void Display();

	void DrawPolygon();

	void DrawTriangle();

	void DrawRectangle();

	void Update();

private:
	float rotation;
};



