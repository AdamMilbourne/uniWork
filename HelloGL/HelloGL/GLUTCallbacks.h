#pragma once
class HelloGL;

namespace GLUTCallbacks
{
	void Init(HelloGL* gl);

	void Display();

	void Timer(int prefferedRefresh);
}