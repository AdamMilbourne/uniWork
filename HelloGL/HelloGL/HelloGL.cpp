#include "HelloGL.h"
/*Vertex HelloGL::vertices[] = { 1, 1, 1, -1, 1, 1, -1,-1, 1, // v0-v1-v2 (front)
-1,-1, 1, 1,-1, 1, 1, 1, 1, // v2-v3-v0
1, 1, 1, 1,-1, 1, 1,-1,-1, // v0-v3-v4 (right)
1,-1,-1, 1, 1,-1, 1, 1, 1, // v4-v5-v0
1, 1, 1, 1, 1,-1, -1, 1,-1, // v0-v5-v6 (top)
-1, 1,-1, -1, 1, 1, 1, 1, 1, // v6-v1-v0
-1, 1, 1, -1, 1,-1, -1,-1,-1, // v1-v6-v7 (left)
-1,-1,-1, -1,-1, 1, -1, 1, 1, // v7-v2-v1
-1,-1,-1, 1,-1,-1, 1,-1, 1, // v7-v4-v3 (bottom)
1,-1, 1, -1,-1, 1, -1,-1,-1, // v3-v2-v7
1,-1,-1, -1,-1,-1, -1, 1,-1, // v4-v7-v6 (back)
-1, 1,-1, 1, 1,-1, 1,-1,-1 }; // v6-v5-v4
Color HelloGL::colors[] = { 1, 1, 1, 1, 1, 0, 1, 0, 0, // v0-v1-v2 (front)
1, 0, 0, 1, 0, 1, 1, 1, 1, // v2-v3-v0
1, 1, 1, 1, 0, 1, 0, 0, 1, // v0-v3-v4 (right)
0, 0, 1, 0, 1, 1, 1, 1, 1, // v4-v5-v0
1, 1, 1, 0, 1, 1, 0, 1, 0, // v0-v5-v6 (top)
0, 1, 0, 1, 1, 0, 1, 1, 1, // v6-v1-v0			
1, 1, 0, 0, 1, 0, 0, 0, 0, // v1-v6-v7 (left)
0, 0, 0, 1, 0, 0, 1, 1, 0, // v7-v2-v1
0, 0, 0, 0, 0, 1, 1, 0, 1, // v7-v4-v3 (bottom)
1, 0, 1, 1, 0, 0, 0, 0, 0, // v3-v2-v7
0, 0, 1, 0, 0, 0, 0, 1, 0, // v4-v7-v6 (back)
0, 1, 0, 0, 1, 1, 0, 0, 1 }; // v6-v5-v4

Vertex HelloGL::indexedVertices[] = { 1, 1, 1, -1, 1, 1, // v0,v1,
-1,-1, 1, 1,-1, 1, // v2,v3
1,-1,-1, 1, 1,-1, // v4,v5
-1, 1,-1, -1,-1,-1 }; // v6,v7
Color HelloGL::indexedColors[] = { 1, 1, 1, 1, 1, 0, // v0,v1,
1, 0, 0, 1, 0, 1, // v2,v3
0, 0, 1, 0, 1, 1, // v4,v5
0, 1, 0, 0, 0, 0 }; //v6,v7
GLushort HelloGL::indices[] = { 0, 1, 2, 2, 3, 0, // front
0, 3, 4, 4, 5, 0, // right
0, 5, 6, 6, 1, 0, // top
1, 6, 7, 7, 2, 1, // left
7, 4, 3, 3, 2, 7, // bottom
4, 7, 6, 6, 5, 4 }; // back
*/

//CONSTRUCTOR 
HelloGL::HelloGL(int argc, char* argv[])
{
	camera = new Camera();
	//camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
	camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -5.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	for (int i = 0; i < 200; i++)
	{
		cube[i] = new Cube(((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f); 
	}
	//rotation = 0.0f;
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
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glutMainLoop();
}

//DESCTRUCTOR
HelloGL::~HelloGL(void)
{

}
 
void HelloGL::Display()
{
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i < 200; i++)
	{
		cube[i]->Draw();
	}
	//DrawIndexedCubeAlt();
	//DrawCubeArrayAlt();
	//DrawIndexedCube();
	//DrawCubeArray();
	//DrawCube();
	//glutWireCube(0.1);
	//DrawPolygon();
	//DrawTriangle();
	//DrawRectangle();
	glFlush();
	glutSwapBuffers();
}

void HelloGL::Update()
{
	
	glLoadIdentity();
	for (int i = 0; i < 200; i++)
	{
		cube[i]->Update();
	}
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

/*void HelloGL::DrawCubeArrayAlt()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glColorPointer(3, GL_FLOAT, 0, colors);

	glPushMatrix();
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void HelloGL::DrawIndexedCubeAlt()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, indexedVertices);
	glColorPointer(3, GL_FLOAT, 0, indexedColors);

	glPushMatrix();
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, indices);
	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void HelloGL::DrawIndexedCube()
{
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++)
	{
		glColor3f(indexedColors[indices[i]].r, indexedColors[indices[i]].g, indexedColors[indices[i]].b);
		glVertex3f(indexedVertices[indices[i]].x, indexedVertices[indices[i]].y, indexedVertices[indices[i]].z);
	}
	glEnd();

	glPopMatrix();

}

void HelloGL::DrawCubeArray()
{
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++)
	{  
		glColor3f(colors[i].r, colors[i].g, colors[i].b);
		glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
	}
	glEnd();

	glPopMatrix();
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
	//face v7-v2-v1
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	//face v7-v4-v3
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	//face v3-v2-v7
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	//face v4-v7-v6
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	// face v6-v5-v4
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);

	glEnd();
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
*/



void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd' || key == 'D')
	{
		//rotation += 0.5;
	}
}