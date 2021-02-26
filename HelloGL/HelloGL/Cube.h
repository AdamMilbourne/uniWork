#pragma once
#include <Windows.h> // required for opengl on windows
#include <gl/GL.h> // Opengl
#include <gl/GLU.h> // opengl utilities
#include "GL\freeglut.h" // freeglut library
#include "Structures.h"

class Cube
{
private:
	static Vertex indexedVertices[];
	static Color indexedColors[];
	static GLushort indices[];
	GLfloat _rotation;
	Vector3 _position;

public:
	Cube(float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
};

