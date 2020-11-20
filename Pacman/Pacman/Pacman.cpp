#include "Pacman.h"

#include <sstream>

//constructor
Pacman::Pacman(int argc, char* argv[]) : Game(argc, argv), _cPacmanSpeed(0.1f), _cPacmanFrameTime(250), _cMunchieFrameTime(1000)
{
	//initialise member variables
	_pacman = new Player();

	//munchie data
	_munchieframeCount = 0;
	_munchieCurrentFrameTime = 0;
	_munchieFrame = 0;

	//pacman direction data
	_pacmanDirection = 0;

	//pacman mouth animation data
	_pacmanCurrentFrameTime = 0;
	_pacmanFrame = 0;

	//pause data
	_paused = false;
	_pKeyDown = false;

	//start menu data
	_started = false;

	//Initialise important Game aspects
	Graphics::Initialise(argc, argv, this, 1024, 768, false, 25, 25, "Pacman", 60);
	Input::Initialise();

	// Start the Game Loop - This calls Update and Draw in game loop
	Graphics::StartGameLoop();
}

Pacman::~Pacman()
{
	delete _pacmanTexture;
	delete _pacmanSourceRect;
	delete _munchieBlueTexture;
	delete _munchieInvertedTexture;
	delete _munchieRect;
}

void Pacman::LoadContent()
{
	//set start parameters
	_StartBackground = new Texture2D();
	_StartBackground->Load("Textures/Transparency.png", false);
	_StartRectangle = new Rect(0.0f, 0.0f, Graphics::GetViewportWidth(), Graphics::GetViewportHeight() / 2.0f);
	_StartStringPosition = new Vector2(Graphics::GetViewportWidth() / 2.0f, Graphics::GetViewportHeight() / 2.0f);


	//set menu parameters
	_menuBackground = new Texture2D();
	_menuBackground->Load("Textures/Transparency.png",false);
	_menuRectangle = new Rect(0.0f, 0.0f, Graphics::GetViewportWidth(), Graphics::GetViewportHeight() / 2.0f);
	_menuStringPosition = new Vector2(Graphics::GetViewportWidth() / 2.0f, Graphics::GetViewportHeight() / 2.0f);

	// Load Pacman
	_pacmanTexture = new Texture2D();
	_pacmanTexture->Load("Textures/Pacman.tga", false);
	_pacmanPosition = new Vector2(350.0f, 350.0f);
	_pacmanSourceRect = new Rect(0.0f, 0.0f, 32, 32);

	// Load Munchie
	_munchieBlueTexture = new Texture2D();
	_munchieBlueTexture->Load("Textures/Cherry.png", false);
	_munchieInvertedTexture = new Texture2D();
	_munchieInvertedTexture->Load("Textures/CherryInverted.png", false);
	_munchieRect = new Rect(100.0f, 450.0f, 32, 32);

	// Set string position
	_stringPosition = new Vector2(10.0f, 25.0f);
}

void Pacman::Update(int elapsedTime)
{
	// Gets the current state of the keyboard
	Input::KeyboardState* keyboardState = Input::Keyboard::GetState();

	//start menu button
	if (!_started)
	{
		if (keyboardState->IsKeyDown(Input::Keys::SPACE))
		{
			_started = true;
		}
	}
	else
	{
		CheckPaused(keyboardState, Input::Keys::P);
	}
		if (!_paused)
		{
			//munchie frame count continues
			_munchieframeCount++;
			Input(elapsedTime, keyboardState);
			UpdatePacman(elapsedTime);
			UpdateMunchie(elapsedTime);
			CheckViewportCollision();
		}
}

void Pacman::Draw(int elapsedTime)
{
	// Allows us to easily create a string
	std::stringstream stream;
	stream << "Pacman X: " << _pacmanPosition->X << " Y: " << _pacmanPosition->Y;

	SpriteBatch::BeginDraw(); // Starts Drawing
	SpriteBatch::Draw(_pacmanTexture, _pacmanPosition, _pacmanSourceRect); // Draws Pacman

	if (_munchieframeCount == 0)
	{
		// Draws Red Munchie
		SpriteBatch::Draw(_munchieInvertedTexture, _munchieRect, nullptr, Vector2::Zero, 1.0f, 0.0f, Color::White, SpriteEffect::NONE);
		_munchieframeCount++;
	}
	else
	{
		// Draw Blue Munchie
		SpriteBatch::Draw(_munchieBlueTexture, _munchieRect, nullptr, Vector2::Zero, 1.0f, 0.0f, Color::White, SpriteEffect::NONE);
		if (_munchieframeCount >= 60)
			_munchieframeCount = 0;
	}
	
	// Draws String
	SpriteBatch::DrawString(stream.str().c_str(), _stringPosition, Color::Green);
	if (_paused)
	{
		std::stringstream menuStream;
		menuStream << "paused";

		SpriteBatch::Draw(_menuBackground, _menuRectangle, nullptr); 
		SpriteBatch::DrawString(menuStream.str().c_str(), _menuStringPosition, Color::Red);
			
	}
	if (!_started)
	{
		std::stringstream StartStream;
		StartStream << "Push Spacebar to Start";

		SpriteBatch::Draw(_StartBackground, _StartRectangle, nullptr);
		SpriteBatch::DrawString(StartStream.str().c_str(), _StartStringPosition, Color::Red);
	}
	SpriteBatch::EndDraw(); // Ends Drawing
	
}

void Pacman::Input(int elapsedTime, Input::KeyboardState* state)
{
	// Checks if right arrow key is pressed
	if (state->IsKeyDown(Input::Keys::RIGHT))
	{
		_pacmanPosition->X += _cPacmanSpeed * elapsedTime; //Moves Pacman across X axis
		_pacmanDirection = 0;
	}
	// Checks if A key is pressed
	else if (state->IsKeyDown(Input::Keys::LEFT))
	{
		_pacmanPosition->X += -_cPacmanSpeed * elapsedTime; //Moves Pacman across X axis
		_pacmanDirection = 2;
	}
	// Checks if W key is pressed
	else if (state->IsKeyDown(Input::Keys::UP))
	{
		_pacmanPosition->Y += -_cPacmanSpeed * elapsedTime; //Moves Pacman across Y axis
		_pacmanDirection = 3;
	}
	// Checks if S key is pressed
	else if (state->IsKeyDown(Input::Keys::DOWN))
	{
		_pacmanPosition->Y += _cPacmanSpeed * elapsedTime; //Moves Pacman across Y axis
		_pacmanDirection = 1;
	}
}

void Pacman::CheckPaused(Input::KeyboardState* state, Input::Keys pauseKey)
{
	//pause button check
	if (state->IsKeyDown(Input::Keys::P) && !_pKeyDown)
	{
		_pKeyDown = true;
		_paused = !_paused;
	}
	//if p is not pressed the variable p pressed is false
	if (state->IsKeyUp(Input::Keys::P))
	{
		_pKeyDown = false;
	}
}
void Pacman::CheckViewportCollision()
{
	//check pacman is trying to dissappear
	if (_pacmanPosition->X + _pacmanSourceRect->Width > Graphics::GetViewportWidth())//1024 is game width
	{
		//pacman hit right wall
		_pacmanPosition->X = 0 - _pacmanSourceRect->Width;
	}
	//check pacman is trying to dissappear
	if (_pacmanPosition->X + _pacmanSourceRect->Width < 0)//1024 is game width
	{
		//pacman hit Left wall
		_pacmanPosition->X = Graphics::GetViewportWidth() - _pacmanSourceRect->Width;
	}
	//check pacman is trying to dissappear
	if (_pacmanPosition->Y + _pacmanSourceRect->Height > Graphics::GetViewportHeight())//1024 is game width
	{
		//pacman hit Floor
		_pacmanPosition->Y = 0 - _pacmanSourceRect->Height;
	}
	//check pacman is trying to dissappear
	if (_pacmanPosition->Y + _pacmanSourceRect->Height < 0)//1024 is game width
	{
		//pacman hit Roof
		_pacmanPosition->Y = Graphics::GetViewportHeight() - _pacmanSourceRect->Height;
	}
}
void Pacman::UpdatePacman(int elapsedTime)
{
	//pacman frame count
	_pacmanCurrentFrameTime += elapsedTime;

	//mouth movement
	_pacmanSourceRect->X = _pacmanSourceRect->Width * _pacmanFrame;

	//mouth movement
	_pacmanSourceRect->X = _pacmanSourceRect->Width * _pacmanFrame;

	//changes direction of pacman
	_pacmanSourceRect->Y = _pacmanSourceRect->Height * _pacmanDirection;

	if (_pacmanCurrentFrameTime > _cPacmanFrameTime)
	{
		_pacmanFrame++;

		if (_pacmanFrame >= 2)
			_pacmanFrame = 0;

		_pacmanCurrentFrameTime = 0;
	}
}

void Pacman::UpdateMunchie(int elapsedTime)
{
	//munchie animation
	_munchieCurrentFrameTime += elapsedTime;
	_munchieRect->X = _munchieRect->Width * _munchieFrame;

	if (_munchieCurrentFrameTime > _cMunchieFrameTime)
	{
		_munchieframeCount++;

		if (_munchieframeCount >= 2)
			_munchieframeCount = 0;

		_munchieCurrentFrameTime = 0;
	}

}

void Pacman::CheckStart(Input::KeyboardState* state, Input::Keys startkey)
{

}