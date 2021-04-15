#pragma once
#include "Structures.h"
#include <fstream>
#include <iostream>

class SceneObject
{
protected:
	Mesh* _mesh;

public:
	SceneObject(Mesh* mesh);
	virtual ~SceneObject();

	virtual void Update();
	virtual void Draw();
};

