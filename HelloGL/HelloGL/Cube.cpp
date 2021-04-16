#include "Cube.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Texture2D.h"
using namespace std;

int Cube::numVertices = 0;
int Cube::numColors = 0;
int Cube::numindices = 0;

//constructor
Cube::Cube(Mesh* mesh,Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;

	_texture = texture;
}

//destructor
Cube::~Cube()
{

}


void Cube::Update()
{
	
	_rotation += 1.0f;
	
}


void Cube::Draw()
{
	if (_mesh->Vertices != nullptr && _mesh->Colors != nullptr && _mesh->Indices != nullptr)
	{

		
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);

		glEnableClientState(GL_COLOR_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);

		glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
		glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT,  _mesh->Indices);
		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);

		glDisableClientState(GL_VERTEX_ARRAY);

		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		

	}

}