#include "HelloGL.h"
#include "Cube.h"
#include "MeshLoader.h"
#include "Pyramid.h"
#include "SceneObject.h"
#include"Texture2D.h"

//CONSTRUCTOR 
HelloGL::HelloGL(int argc, char* argv[])
{
	HelloGL::InitGL(argc, argv);
	HelloGL::InitObjects();
	HelloGL::InitLighting();
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
	rotation = 0.0f;
	//used for initialising objects rather than crowding the constructor
	Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");

	Texture2D* texture = new Texture2D();
	texture->Load((char*)"Penguins.raw", 512, 512);

	for (int i = 0; i < 1000; i++)
	{
		objects[i] = new Cube(cubeMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}

	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
}
void HelloGL::InitLighting()
{
	_lightPosition = new Vector4();
	_lightPosition->x = 0.0;
	_lightPosition->y = 0.0;
	_lightPosition->z = 1.0;
	_lightPosition->w = 0.0;

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
	delete camera;
}
 
void HelloGL::Display()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i < 1000; i++)
	{
		objects[i]->Draw();
	}
	glFlush();
	glutSwapBuffers();
}

void HelloGL::Update()
{

	glLoadIdentity();
	glutPostRedisplay();



	gluLookAt(
		camera->eye.x, camera->eye.y, camera->eye.z,
		camera->center.x, camera->center.y, camera->center.z,
		camera->up.x, camera->up.y, camera->up.z
	);

	rotation += 0.5;
	if (rotation >= 360.0f)
	{
		rotation = 0.0f;
	}
	for (int i = 0; i < 1000; i++)
	{
		objects[i]->Update();
	}
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));
	InitLighting();
}




void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd' || key == 'D')
	{
		rotation += 0.5;
	}
}