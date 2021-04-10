#pragma once
#include <Windows.h> // required for opengl on windows
#include <gl/GL.h> // Opengl
#include <gl/GLU.h> // opengl utilities
#include "GL\freeglut.h" // freeglut library
#include "Structures.h"

class Cube
{
private:
	Mesh* _mesh;
	GLfloat _rotation;
	Vector3 _position;
	static int numVertices, numColors, numindices;

public:
	Cube(/*this is week 5a new*/Mesh* mesh/**/, float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
};

