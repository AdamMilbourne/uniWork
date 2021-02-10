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
		int updateTime = glutGet(GLUT_ELAPSED_TIME);
		helloGL->Update();
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
		glutTimerFunc(prefferedRefresh - updateTime, GLUTCallbacks::Timer, prefferedRefresh);
	}

	void GLUTCallbacks::Keyboard(unsigned char key, int x, int y)
	{
		helloGL->Keyboard(key, x, y);
	}
}
