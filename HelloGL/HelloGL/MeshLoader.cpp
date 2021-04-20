#include "MeshLoader.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace MeshLoader
{
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadTexCoords(ifstream& inFile, Mesh& mesh);
	void LoadNormals(ifstream& inFile, Mesh& mesh);
	void LoadIndices(ifstream& inFile, Mesh& mesh);
	

	void LoadVertices(ifstream& inFile, Mesh& mesh)
	{
		//check file for vertex
		inFile >> mesh.VertexCount;

		if (mesh.VertexCount > 0)
		{
			//make new vertex array
			mesh.Vertices = new Vertex[mesh.VertexCount];

			for (int i = 0; i < mesh.VertexCount; i++)
			{
				//store vertex
				inFile >> mesh.Vertices[i].x;
				inFile >> mesh.Vertices[i].y;
				inFile >> mesh.Vertices[i].z;
			}
		}
	}

	void LoadTexCoords(ifstream& inFile, Mesh& mesh)
	{
		//check file for coord count 
		inFile >> mesh.TexCoordCount;
		//make coord array
		mesh.TexCoords = new TexCoord[mesh.TexCoordCount];

		for (int i = 0; i < mesh.TexCoordCount; i++)
		{
			//store coords
			inFile >> mesh.TexCoords[i].u;
			inFile >> mesh.TexCoords[i].v;
		}
	}

	void LoadNormals(ifstream& inFile, Mesh& mesh)
	{
		//check file for normal count
		inFile >> mesh.NormalCount;
		
			//create new normal array
			mesh.Normals = new Vector3[mesh.NormalCount];
			for (int i = 0; i < mesh.NormalCount; i++)
			{
				//store normal
				inFile >> mesh.Normals[i].x;
				inFile >> mesh.Normals[i].y;
				inFile >> mesh.Normals[i].z;
			}
		
		
	}

	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		//check file for index
		inFile >> mesh.IndexCount;

		//create index array
			mesh.Indices = new GLushort[mesh.IndexCount];

			for (int i = 0; i < mesh.IndexCount; i++)
			{
				//store indicies
				inFile >> mesh.Indices[i];
			}
		
	}

	Mesh* MeshLoader::Load(char* path)
	{
		//create new mesh
		Mesh* mesh = new Mesh();
		
		ifstream inFile;
		//open file
		inFile.open(path);
		//check if file is good
		if (!inFile.good())  
		{
			cerr  << "Can't open texture file " << path << endl;
			return nullptr;
		}
		//load functions for information
		LoadVertices(inFile, * mesh);
		LoadTexCoords(inFile, *mesh);
		LoadNormals(inFile, *mesh);
		LoadIndices(inFile, * mesh);
		
		//close file
		inFile.close();
		//return the mesh and info
		return mesh;
	}
}
