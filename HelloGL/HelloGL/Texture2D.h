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
class Texture2D
{
private:
	GLuint _ID;
	int _width, _height;
public:
	Texture2D();
	~Texture2D();

	bool Load(char* path, int width, int height);

	GLuint GetID() const { return _ID; }
	int GetWidth() const { return _width; }
	int GetHeight() const { return _height; }
};

