#pragma once
#include <Windows.h> // required for opengl on windows
#include <gl/GL.h> // Opengl
#include <gl/GLU.h> // opengl utilities
#include "GL\freeglut.h" // freeglut library
#include "Structures.h"
#include "SceneObject.h"
#include "fstream"
#include "iostream"
class Pyramid : public SceneObject
{
private:
	
	Vector3 _position;
	static int numVertices, numColors, numindices;

public:
	Pyramid(Mesh* mesh, float x, float y, float z);
	~Pyramid();

	virtual void Draw();
	virtual void Update();
};

