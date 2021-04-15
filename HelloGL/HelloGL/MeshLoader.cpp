#include "MeshLoader.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace MeshLoader
{
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadColours(ifstream& inFile, Mesh& mesh);
	void LoadIndices(ifstream& inFile, Mesh& mesh);
	void LoadCoordinates(ifstream& inFile, Mesh& mesh);

	void LoadVertices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.VertexCount;

		if (mesh.VertexCount > 0)
		{
			mesh.Vertices = new Vertex[mesh.VertexCount];

			for (int i = 0; i < mesh.VertexCount; i++)
			{
				inFile >> mesh.Vertices[i].x;
				inFile >> mesh.Vertices[i].y;
				inFile >> mesh.Vertices[i].z;
			}
		}
	}

	void LoadColours(ifstream& inFile, Mesh& mesh)
	{
		//TODO: LOAD COLOURS
		inFile >> mesh.ColorCount;

		
			mesh.Colors = new Color[mesh.ColorCount];

			for (int i = 0; i < mesh.ColorCount; i++)
			{
				inFile >> mesh.Colors[i].r;
				inFile >> mesh.Colors[i].g;
				inFile >> mesh.Colors[i].b;
			}
		
	}

	void LoadCoordinates(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.TexCoordCount;

		mesh.TexCoords = new TexCoord[mesh.TexCoordCount];

		for (int i = 0; i < mesh.TexCoordCount; i++)
		{
			inFile >> mesh.TexCoords[i].u;
			inFile >> mesh.TexCoords[i].v;
		}
	}

	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		//TODO: Load Indices
		inFile >> mesh.IndexCount;

		
			mesh.Indices = new GLushort[mesh.IndexCount];

			for (int i = 0; i < mesh.IndexCount; i++)
			{
				inFile >> mesh.Indices[i];
			}
		
	}

	Mesh* MeshLoader::Load(char* path)
	{
		Mesh* mesh = new Mesh();

		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())  
		{
			cerr  << "Can't open texture file " << path << endl;
			return nullptr;
		}

		LoadVertices(inFile, * mesh);
		LoadColours(inFile, * mesh);
		LoadIndices(inFile, * mesh);
		LoadCoordinates(inFile, *mesh);

		inFile.close();

		return mesh;
	}
}
