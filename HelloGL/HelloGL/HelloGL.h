#pragma once
#include <Windows.h> // required for opengl on windows
#include <gl/GL.h> // Opengl
#include <gl/GLU.h> // opengl utilities
#include "GL\freeglut.h" // freeglut library
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"
#define REFRESHRATE 16

class Cube;
class HelloGL
{
public:
	//constructor def
	HelloGL(int argc, char* argv[]);
	//destrcutor
	~HelloGL(void);
	void Display();
	//void DrawPolygon();
	//void DrawTriangle();
	//void DrawRectangle();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	//void DrawCube();
	//void DrawCubeArray();
	//void DrawIndexedCube();
	//void DrawIndexedCubeAlt();
	//void DrawCubeArrayAlt();

private:
	float rotation;
	Camera* camera;
	Cube* cube[];
	
/*	static Vertex vertices[];
	static Color colors[];
	static Vertex indexedVertices[];
	static Color indexedColors[];
	static GLushort indices[];*/
};




