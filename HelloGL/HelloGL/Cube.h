#pragma once
#include <Windows.h> // required for opengl on windows
#include <gl/GL.h> // Opengl
#include <gl/GLU.h> // opengl utilities
#include "GL\freeglut.h" // freeglut library
#include "Structures.h"
#include "SceneObject.h"



class Texture2D;
class Cube : public SceneObject
{
protected:

private:
	GLfloat _rotationValue;
	GLfloat _rotation;
	Vector3 _position;
	static int numVertices, numindices;

	Material* _material;

	
public:
	Cube(Mesh* mesh,Texture2D* texture, float x, float y, float z);
	~Cube();

	virtual void Draw();
	virtual void Update();
	void MaterialFunc();
	

};

