#include "GLUTCallbacks.h"
#include "HelloGL.h"

//namespace implementation 
namespace GLUTCallbacks
{
	namespace
	{
		//initialise to a null pointer before we do anything 
		HelloGL* helloGL = nullptr;
	}

	void Init(HelloGL* gl)
	{
		helloGL = gl;
	}

	void Display()
	{
		if (helloGL != nullptr)
		{
			helloGL->Display();
		}
	}

	void GLUTCallbacks::Timer(int prefferedRefresh)
	{
		helloGL->Update();
	}
}
