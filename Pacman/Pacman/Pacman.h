#pragma once

// If Windows and not in Debug, this will run without a console window
// You can use this to output information when debugging using cout or cerr
#ifdef WIN32 
	#ifndef _DEBUG
		#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
	#endif
#endif

// Just need to include main header file
#include "S2D/S2D.h"

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
};

//structure def
struct Collectible
{
	int frameCount;
	Rect* Rect;
	Texture2D* BlueTexture;
	Texture2D* InvertedTexture;
	int Frame;
	int CurrentFrameTime;
};

//structure def
struct Menu
{
	Texture2D* Background;
	Rect* Rectangle;
	Vector2* StringPosition;
};

//class def
class Pacman : public Game
{
private:
	//player name
	Player* _pacman;

	//collectibles
	Collectible* _munchie;

	//menu
	Menu* _pause;
	Menu* _start;

	//Input methods
	void Input(int elapsedTime, Input::KeyboardState* state);

	//Check methods
	void CheckPaused(Input::KeyboardState* state, Input::Keys pauseKey);
	void CheckViewportCollision();
	void StartMenu(Input::KeyboardState* state, Input::Keys startkey);

	//Update methods
	void UpdatePacman(int elapsedTime);
	void UpdateMunchie(int elapsedTime);

	//pacman mouth animation
	const int _cPacmanFrameTime;

	// Data to represent Munchie
	const int _cMunchieFrameTime;
	

	// Position for String
	Vector2* _stringPosition;

	//Constant data for Game Variables 
	const float _cPacmanSpeed;

	// Data for Menu
	bool _paused;
	bool _pKeyDown;

	//data for start menu
	bool _started;

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