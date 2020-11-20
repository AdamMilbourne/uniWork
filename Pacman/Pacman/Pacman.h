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

//class def
class Pacman : public Game
{
private:
	Player* _pacman;

	
	//Input methods
	void Input(int elapsedTime, Input::KeyboardState* state);

	//Check methods
	void CheckPaused(Input::KeyboardState* state, Input::Keys pauseKey);
	void CheckViewportCollision();
	void CheckStart(Input::KeyboardState* state, Input::Keys startkey);

	//Update methods
	void UpdatePacman(int elapsedTime);
	void UpdateMunchie(int elapsedTime);

	//pacman direction animation data
	int _pacmanDirection;

	//pacman mouth animation
	int _pacmanFrame; 
	int _pacmanCurrentFrameTime;
	const int _cPacmanFrameTime;

	// Data to represent Pacman
	Vector2* _pacmanPosition;
	Rect* _pacmanSourceRect;
	Texture2D* _pacmanTexture;

	// Data to represent Munchie
	int _munchieframeCount;
	Rect* _munchieRect;
	Texture2D* _munchieBlueTexture;
	Texture2D* _munchieInvertedTexture;
	const int _cMunchieFrameTime;
	int _munchieFrame;
	int _munchieCurrentFrameTime;

	// Position for String
	Vector2* _stringPosition;

	//Constant data for Game Variables 
	const float _cPacmanSpeed;

	// Data for Menu
	Texture2D* _menuBackground;
	Rect* _menuRectangle;
	Vector2* _menuStringPosition; 
	bool _paused;
	bool _pKeyDown;

	//data for start menu
	Texture2D* _StartBackground;
	Rect* _StartRectangle;
	Vector2* _StartStringPosition;
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