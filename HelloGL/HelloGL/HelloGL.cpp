#include "HelloGL.h"

//constructor 
HelloGL::HelloGL(int argc, char* argv[])
{
	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	rotation = 0.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
}
 
void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutWireCube(0.1);
	//DrawPolygon();
	//DrawTriangle();
	//DrawRectangle();
	glFlush();
	glutSwapBuffers();
}

void HelloGL::Update()
{
	glLoadIdentity();
	gluLookAt(
	camera->eye.x, camera->eye.y, camera->eye.z,
	camera->center.x, camera->center.y, camera->center.z,
	camera->up.x, camera->up.y, camera->up.z
	);
	glutPostRedisplay();
	rotation += 0.5;
	if (rotation >= 360.0f)
	{
		rotation = 0.0f;
	}
	//Sleep(10);//REMOVED LATER
}

void HelloGL::DrawCube()
{
	glBegin(GL_TRIANGLES);
	//face v0-v1-v2
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	//face v2-v3-v0
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	// face v0-v3-v4
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	//fave v4-v5-v0
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	//face v0-v5-v6
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	//face v6-v1-v0
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	//face v1-v6-v7
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
}

void HelloGL::DrawPolygon()
{
	glPushMatrix();
	glTranslatef(0.5, -0.5, -5.0);
	glRotatef(rotation, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.5, -0.5, 0.0);
	glBegin(GL_POLYGON);
	{
		glColor4f(2.0f, 0.5f, 1.0f, 0.0f); 	

		glVertex2f(-0.8, 0.8); //top left
		glVertex2f(-0.25, 0.8); // top right
		glVertex2f(-0.25,0.3); // bot right
		glVertex2f(-0.8, 0.3); // bot left
		
		glEnd();
	}
	glPopMatrix();
}
void HelloGL::DrawTriangle()
{
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	{
		glColor4f(2.0f, 0.5f, 1.0f, 0.0f);

		glVertex2f(0.75, 0.75); //top left
		glVertex2f(0.75, 0.75); // top right
		glVertex2f(0.25, 0.75 ); // bot right
		glVertex2f(0.25, 0.25); // bot left
		glEnd();
	}
	glPopMatrix();
}

void HelloGL::DrawRectangle()
{
	glPushMatrix();
	glRotatef(rotation, 1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	{
		glColor4f(2.0f, 0.5f, 1.0f, 0.0f);

		glVertex2f(-0.75, -0.3); //top left
		glVertex2f(0.75, -0.3); // top right
		glVertex2f(0.75, -0.8); // bot right
		glVertex2f(-0.75, -0.8); // bot left
		glEnd();
	}
	glPopMatrix();
}

HelloGL::~HelloGL(void)
{

}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd' || key == 'D')
	{
		//rotation += 0.5;
	}
}