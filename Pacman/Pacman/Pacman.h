#pragma once

// If Windows and not in Debug, this will run without a console window
// You can use this to output information when debugging using cout or cerr
#ifdef WIN32 
	#ifndef _DEBUG
		#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
	#endif
#endif

#define MUNCHIECOUNT 1
#define GHOSTCOUNT 4
// Just need to include main header file
#include "S2D/S2D.h"
#include "S2D/MathHelper.h"
#include <iostream>

// Reduces the amount of typing by including all classes in S2D namespace
using namespace S2D;
   
//structure def
struct Player
{
	float speedMultiplier;
	int currentFrameTime;
	int direction;
	int frame;
	Rect* sourceRect;
	Texture2D* texture;
	Vector2* position;
	bool dead;
};

//structure def
struct Enemy
{
	int frameCount;
	Rect* Rect;
	Texture2D* Texture;
	int Frame;
	int CurrentFrameTime;
	Vector2* position;
	int frameTime;
};

//structure def
struct Menu
{
	Texture2D* Background;
	Rect* Rectangle;
	Vector2* StringPosition;
};

//structure def
struct MovingEnemy
{
	Vector2* position;
	Texture2D* texture;
	Rect* sourceRect;
	int direction;
	float speed;
};


//class def
class Pacman : public Game
{
private:
	//sound effects
	SoundEffect* CherryEat;
	SoundEffect* Death;
	SoundEffect* Theme;
	SoundEffect* Waka;

	//player name
	Player* _pacman;

	//Enemy
	Enemy* _munchies[MUNCHIECOUNT];
	Enemy* _Cherry;

	//menu
	Menu* _pause;
	Menu* _start;
	Menu* _gameOver;

	//movingenemy
	MovingEnemy* _ghosts[GHOSTCOUNT];

	//audio method


	//Input methods
	void Input(int elapsedTime, Input::KeyboardState* state, Input::MouseState* mouseState);

	//Check methods
	void CheckPaused(Input::KeyboardState* state, Input::Keys pauseKey);
	void CheckViewportCollision();
	void StartMenu(Input::KeyboardState* state, Input::Keys startkey);
	void CheckGhostCollision();
	void CheckMunchieCollision();
	void CheckCherryCollision();

	//Update methods
	void UpdatePacman(int elapsedTime);
	void UpdateMunchies(Enemy*, int elapsedTime);
	void UpdateCherries(Enemy*, int elapsedTime);
	void UpdateGhost(MovingEnemy*, int elapsedtime);
	void UpdateGameOver(Input::KeyboardState* state, Input::Keys startkey);

	//pacman mouth animation
	const int _cPacmanFrameTime;

	// Position for String
	Vector2* _stringPosition;

	//Constant data for Game Variables 
	const float _cPacmanSpeed;
	
	//game over menu data
	bool _gameIsOver;
	bool _escapeKeyDown;

	// Data for Menu
	bool _paused;
	bool _pKeyDown;

	//data for start menu
	bool _started;

	//data for random cherries
	bool _cherryRandomize;
	bool _rKeyDown;

	//collision data
	bool collisionCheck;

	//score 
	int score;

public:
	/// <summary> Constructs the Pacman class. </summary>
	Pacman(int argc, char* argv[]);

	/// <summary> Destroys any data associated with Pacman class. </summary>
	virtual ~Pacman();

	/// <summary> All content should be loaded in this method. </summary>
	void virtual LoadContent();

	/// <summary> Called every frame - update game logic here. </summary>
	void virtual Update(int elapsedTime);

	/// <summary> Called every frame - draw game here. </summary>
	void virtual Draw(int elapsedTime);
};