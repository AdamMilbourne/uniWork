#include "Texture2D.h"
using namespace std;

Texture2D::Texture2D()
{

}

Texture2D::~Texture2D()
{
	glDeleteTextures(1, &_ID);
}

bool Texture2D::Load(char* path, int width, int height)
{
	char* tempTextureData;
	int fileSize;
	ifstream inFile;
	_width = width;
	_height = height;

	inFile.open(path, ios::binary);

	if (!inFile.good())
	{
		cerr << "cant open texture file" << path << endl;
		return false;
	}

	inFile.seekg(0, ios::end); // seek to end of file
	fileSize = (int)inFile.tellg(); // get current position in file - the end, gives total file size
	tempTextureData = new char[fileSize]; // create new array to store data
	inFile.seekg(0, ios::beg); // seek to beginning of file
	inFile.read(tempTextureData, fileSize); // read all data in one go

	inFile.close(); // close file

	cout << path << "loaded" << endl;

	glGenTextures(1, &_ID); // get new Texture ID
	glBindTexture(GL_TEXTURE_2D, _ID); // bind the texture to ID
	glTexImage2D(GL_TEXTURE, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData);

	delete[] tempTextureData; // clear data - we dont need this any more
	return true;
}
