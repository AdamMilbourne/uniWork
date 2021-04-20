#include "HelloGL.h"
#include "Cube.h"
#include "MeshLoader.h"
#include "Pyramid.h"
#include "SceneObject.h"
#include"Texture2D.h"


//CONSTRUCTOR 
HelloGL::HelloGL(int argc, char* argv[])
{
	//call functions to set up
	//call glut calls etc
	HelloGL::InitGL(argc, argv);
	//call function for object creation
	HelloGL::InitObjects();
	//call function for lighting
	HelloGL::InitLighting();

	//start main loop (always last)
	glutMainLoop();
}

void HelloGL::InitGL(int argc, char* argv[])
{
	//used for initialising all GL functions rather than crowding the constructor
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(100, 1, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glCullFace(GL_BACK);
}
void HelloGL::InitObjects()
{
	//used for initialising objects rather than crowding the constructor

	//call the txt file to be read by the meshloader function
	Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");

	//texture initialise 
	Texture2D* texture = new Texture2D();
	//load texture file (.raw)
	texture->Load((char*)"Penguins.raw", 512, 512);

	//for amount of cubes in array
	for (int i = 0; i < 500; i++)
	{
		//load object cube in random positions
		objects[i] = new Cube(cubeMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}

	camera = new Camera();
	//set camera to look at certain position. (never stops looking at that center position)
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	
}
void HelloGL::InitLighting()
{
	//set lighting position
	_lightPosition = new Vector4();
	_lightPosition->x = 0.0;
	_lightPosition->y = 0.0;
	_lightPosition->z = 1.0;
	_lightPosition->w = 0.0;

	//lighing effcts (colour)
	_lightData = new Lighting();
	_lightData->Ambient.x = 0.2;
	_lightData->Ambient.y = 0.2;
	_lightData->Ambient.z = 0.2;
	_lightData->Ambient.w = 1.0;
	_lightData->Diffuse.x = 0.8;
	_lightData->Diffuse.y = 0.8;
	_lightData->Diffuse.z = 0.8;
	_lightData->Diffuse.w = 1.0;
	_lightData->Specular.x = 0.2;
	_lightData->Specular.y = 0.2;
	_lightData->Specular.z = 0.2;
	_lightData->Specular.w = 1.0;
}

//DESCTRUCTOR
HelloGL::~HelloGL(void)
{
	//make space by deleting
	delete camera;

}
 
void HelloGL::Display()
{
	//clear display before drawing objects
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//draw for array of objects
	for (int i = 0; i < 500; i++)
	{
		objects[i]->Draw();
	}
	//text position
	Vector3 v = { -2.0f, 2.0f, -1.0f };
	//text color
	Color c = { 255.0f, 0.0f, 255.0f };
	//what text says and then display using color and position
	HelloGL::DrawString("Controls: W to circle up, S to circle Down, A to circle left, D to circle right", &v, &c);
	glFlush();
	glutSwapBuffers();

	
	
}

void HelloGL::Update()
{
	//load identity
	glLoadIdentity();
	//post display
	glutPostRedisplay();
	//look in direction of camera
	gluLookAt
	(
		camera->eye.x, camera->eye.y, camera->eye.z,
		camera->center.x, camera->center.y, camera->center.z,
		camera->up.x, camera->up.y, camera->up.z
	);
	//update for however many cubes are in array 
	for (int i = 0; i < 500; i++)
	{
		objects[i]->Update();
	}
	//set lighting effects
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));
	InitLighting();
}
//draw text to screen
void HelloGL::DrawString(const char* text, Vector3* position, Color* color) 
{
	glPushMatrix();
	//position text
	glTranslatef(position->x, position->y, position->z);
	glRasterPos2f(0.0f, 0.0f);
	//type of text
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text);

	glPopMatrix();
}

//keyboard function allows for input
void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	//allows camera to move left and right around the center
	if (key == 'D' || key == 'd')
		camera->eye.x += 1.0f;
	else if (key == 'A' || key == 'a')
		camera->eye.x -= 1.0f;

	//allows the camera to move up and down around the center
	if (key == 'W' || key == 'w')
		camera->eye.y += 1.0f;
	else if (key == 'S' || key == 's')
		camera->eye.y -= 1.0f ;
}