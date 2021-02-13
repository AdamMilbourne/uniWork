#pragma once
#include <Windows.h> // required for opengl on windows
#include <gl/GL.h> // Opengl
#include <gl/GLU.h> // opengl utilities
#include "GL\freeglut.h" // freeglut library
#include "GLUTCallbacks.h"
#define REFRESHRATE 16
struct Vector3
{
	float x;
	float y;
	float z;
};

struct Camera
{
	Vector3 eye;
	Vector3 center;
	Vector3 up;
};

struct Color
{
	GLfloat r, g, b;
};

struct Vertex
{
	GLfloat x, y, z;
};


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

	void Keyboard(unsigned char key, int x, int y);

	void DrawCube();

	void DrawCubeArray();

	void DrawIndexedCube();

private:
	float rotation;
	Camera* camera;
	static Vertex vertices[];
	static Color colors[];
	static Vertex indexedVertices[];
	static Color indexedColors[];
	static GLushort indices[];
};




