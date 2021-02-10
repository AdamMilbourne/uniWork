#pragma once
class HelloGL;

namespace GLUTCallbacks
{
	void Init(HelloGL* gl);

	void Display();

	void Timer(int prefferedRefresh);

	void Keyboard(unsigned char key, int x, int y);
}