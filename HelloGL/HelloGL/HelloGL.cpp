#include "HelloGL.h"

//constructor 
HelloGL::HelloGL(int argc, char* argv[])
{
	rotation = 0.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutCreateWindow("simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	DrawPolygon();
	DrawTriangle();
	DrawRectangle();
	glFlush();
}

void HelloGL::Update()
{
	glutPostRedisplay();
	rotation += 0.5;
	if (rotation >= 360.0f)
	{
		rotation = 0.0f;
	}
}

void HelloGL::DrawPolygon()
{
	glPushMatrix();
	//glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON);
	{
		glColor4f(2.0f, 0.5f, 1.0f, 0.0f); 	

		glVertex2f(-0.37, 0.25); //top left
		glVertex2f(0.37, 0.25); // top right
		glVertex2f(0.37, -0.25); // bot right
		glVertex2f(-0.37, -0.25); // bot left
		
		glEnd();
	}
	glPopMatrix();
}
void HelloGL::DrawTriangle()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(2.0f, 0.5f, 1.0f, 0.0f);

		glVertex2f(-0.25, 0.25); //top left
		glVertex2f(-0.25, 0.25); // top right
		glVertex2f(0.37, -0.25); // bot right
		glVertex2f(-0.37, -0.25); // bot left
		glEnd();
	}
}

void HelloGL::DrawRectangle()
{

	glBegin(GL_POLYGON);
	{
		glColor4f(2.0f, 0.5f, 1.0f, 0.0f);

		glVertex2f(-0.75, 0.25); //top left
		glVertex2f(0.75, 0.25); // top right
		glVertex2f(0.75, -0.25); // bot right
		glVertex2f(-0.75, -0.25); // bot left
		glEnd();
	}
}

HelloGL::~HelloGL(void)
{

}
