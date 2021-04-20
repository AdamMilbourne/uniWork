#include "Cube.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Texture2D.h"

using namespace std;

int Cube::numVertices = 0;
//int Cube::numColors = 0;
int Cube::numindices = 0;

//constructor
Cube::Cube(Mesh* mesh,Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture)
{
	//initialise positions
	_position.x = x;
	_position.y = y;
	_position.z = z;

	//initialise texture
	_texture = texture;

	//rotation initialised 
	_rotation = 0.0f;
	_rotationValue = ((rand() % 500) / 100.0f) - 2.5f;
}

//destructor
Cube::~Cube()
{

}



void Cube::Update()
{
	//update rotation
	_rotation += _rotationValue;
}

void Cube::MaterialFunc()
{
	//set up material
	_material = new Material();
	_material->Ambient.x = 0.8; _material->Ambient.y = 0.05; _material->Ambient.z = 0.05;
	_material->Ambient.w = 1.0;
	_material->Diffuse.x = 0.8; _material->Diffuse.y = 0.05; _material->Diffuse.z = 0.05;
	_material->Diffuse.w = 1.0;
	_material->Specular.x = 1.0; _material->Specular.y = 1.0; _material->Specular.z = 1.0;
	_material->Specular.w = 1.0;
	_material->shininess = 100.0f;

}



void Cube::Draw()
{
	if (_mesh->Vertices != nullptr,  _mesh->Indices != nullptr)
	{

		//enable arrays/texture
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnable(GL_NORMAL_ARRAY);

		//pointer to struct
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glNormalPointer(GL_FLOAT, 0, _mesh->Normals);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);

		//set up materials
		Cube::MaterialFunc();
		glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->Ambient.x));
		glMaterialf(GL_FRONT, GL_SHININESS, _material->shininess);

		glPushMatrix();
		//position. always translate before rotation
		glTranslatef(_position.x, _position.y, _position.z);

		//rotate
		glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
		glRotatef(_rotation * 2.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(_rotation / 2.0f, 0.0f, 0.0f, 1.0f);

		//draw the cubes
		glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT,  _mesh->Indices);
		glPopMatrix();

		//disable clients
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		

	}

}