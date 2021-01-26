#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutCreateWindow("simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(16, GLUTCallbacks::Timer, 16);
	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	DrawPolygon();
	//DrawTriangle();
	glFlush();
}

void HelloGL::Update()
{
	glutPostRedisplay();
}

void HelloGL::DrawPolygon()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(2.0f, 0.5f, 1.0f, 0.0f); 
		glVertex2f(-0.5, 0.5); //top left
		glVertex2f(-0.5, 0.5); // top right
		glVertex2f(0.75, -0.5); // bot right
		glVertex2f(-0.75, -0.5); // bot left
		glEnd();
	}
}
/*void HelloGL::DrawTriangle()
{
		glColor4f(2.0f, 0.5f, 1.0f, 0.0f);
		glVertex2f(-0.75, 0.5); //top left
		glVertex2f(0.75, 0.5); // top right
		glVertex2f(0.75, -0.5); // bot right
		glVertex2f(-0.75, -0.5); // bot left
		glEnd();
}*/

HelloGL::~HelloGL(void)
{

}
