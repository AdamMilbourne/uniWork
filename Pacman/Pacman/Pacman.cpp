#include "Pacman.h"

#include <sstream>

#include <time.h>

//constructor
Pacman::Pacman(int argc, char* argv[]) : Game(argc, argv), _cPacmanSpeed(0.1f), _cPacmanFrameTime(250)
{
	srand(time(NULL));

	//munchie data
	for (int i = 0; i < MUNCHIECOUNT; i++)
	{
		_munchies[i] = new Enemy();
		_munchies[i]->CurrentFrameTime = 0;
		_munchies[i]->frameCount = rand() % 1;
		_munchies[i]->frameTime = rand() % 500 + 50;
	}

	//cherry data
	_Cherry = new Enemy();
	_Cherry->CurrentFrameTime = 0;
	_Cherry->frameCount = rand() % 1;
	_Cherry->frameTime = rand() % 500 + 50;

	Input::KeyboardState* keyboardState = Input::Keyboard::GetState();
	StartMenu(keyboardState, Input::Keys::SPACE);

	//initialise member variables
	_pacman = new Player();
	_pause = new Menu();
	_start = new Menu();

	//pacman speed data
	_pacman->speedMultiplier = 1.0f;

	//pacman direction data
	_pacman->direction = 0;

	//pacman mouth animation data
	_pacman->currentFrameTime = 0;
	_pacman->frame = 0;

	//pause data
	_paused = false;
	_pKeyDown = false;

	//start menu data
	_started = false;

	//random cherry data
	_cherryRandomize = false;
	_rKeyDown = false;

	//Initialise important Game aspects
	Graphics::Initialise(argc, argv, this, 1024, 768, false, 25, 25, "Pacman", 60);
	Input::Initialise();

	// Start the Game Loop - This calls Update and Draw in game loop
	Graphics::StartGameLoop();
}

void Pacman::StartMenu(Input::KeyboardState* state, Input::Keys startkey)
{
	//start menu button
	if (_started == false)
	{
		if (state->IsKeyDown(Input::Keys::SPACE))
		{
			_started = true;
		}
	}
}
//destructor method
Pacman::~Pacman()
{
	//pacman destructor
	delete _pacman->texture;
	delete _pacman->sourceRect;
	
	//clean up texture
	delete _munchies[0]->BlueTexture;


	for (int nCount = 0; nCount < MUNCHIECOUNT; nCount++)
	{
	delete _munchies[nCount]->BlueTexture;
	delete _munchies[nCount]->InvertedTexture;
	delete _munchies[nCount]->position;
	delete _munchies[nCount]->Rect;
	delete _munchies[nCount];
	}
	delete[] _munchies;
	//remaining clean up...

	//clean up texture
	delete _Cherry->BlueTexture;
		
	delete _Cherry->BlueTexture;
	delete _Cherry->InvertedTexture;
	delete _Cherry->position;
	delete _Cherry->Rect;
	delete _Cherry;
	//remaining clean up...

}

void Pacman::LoadContent()
{
	//munchie texture
	Texture2D* munchieTex = new Texture2D();
	munchieTex->Load("Textures/Munchie.png", false);

	for (int i = 0; i < MUNCHIECOUNT; i++)
	{
		_munchies[i]->BlueTexture = munchieTex;
	}

	//cherry Texture
	Texture2D* CherryTex = new Texture2D();
	CherryTex->Load("Textures/Cherry.png", false);
	_Cherry->BlueTexture = CherryTex;


	//set start parameters
	_start->Background = new Texture2D();
	_start->Background->Load("Textures/Transparency.png", false);
	_start->Rectangle = new Rect(0.0f, 0.0f, Graphics::GetViewportWidth(), Graphics::GetViewportHeight() / 2.0f);
	_start->StringPosition = new Vector2(Graphics::GetViewportWidth() / 2.0f, Graphics::GetViewportHeight() / 2.0f);

	//set menu parameters
	_pause->Background = new Texture2D();
	_pause->Background->Load("Textures/Transparency.png",false);
	_pause->Rectangle = new Rect(0.0f, 0.0f, Graphics::GetViewportWidth(), Graphics::GetViewportHeight() / 2.0f);
	_pause->StringPosition = new Vector2(Graphics::GetViewportWidth() / 2.0f, Graphics::GetViewportHeight() / 2.0f);

	// Load Pacman
	_pacman->texture = new Texture2D();
	_pacman->texture->Load("Textures/Pacman.tga", false);
	_pacman->position = new Vector2(350.0f, 350.0f);
	_pacman->sourceRect = new Rect(0.0f, 0.0f, 32, 32);

	//Load cherry 
	_Cherry->BlueTexture = new Texture2D();
	_Cherry->BlueTexture->Load("Textures/Cherry.png", false);
	_Cherry->InvertedTexture = new Texture2D();
	_Cherry->InvertedTexture->Load("Textures/CherryInverted.png", false);
	_Cherry->Rect = new Rect(100.0f, 450.0f, 34, 34);
	

	// Load Munchie
	for (int i = 0; i < MUNCHIECOUNT; i++)
	{
		_munchies[i]->BlueTexture = new Texture2D();
		_munchies[i]->BlueTexture->Load("Textures/Munchie.png", false);
		_munchies[i]->InvertedTexture = new Texture2D();
		_munchies[i]->InvertedTexture->Load("Textures/MunchieInverted.png", false);
		_munchies[i]->Rect = new Rect(100.0f, 450.0f, 12, 12);
		_munchies[i]->position = new Vector2((rand() % Graphics::GetViewportWidth()), (rand() % Graphics::GetViewportHeight()));
	}
	


	// Set string position
	_stringPosition = new Vector2(10.0f, 25.0f);
}

void Pacman::Update(int elapsedTime)
{
	// Gets the current state of the keyboard
	Input::KeyboardState* keyboardState = Input::Keyboard::GetState();
	Input::MouseState* mouseState = Input::Mouse::GetState();

	if (!_started)
	{
		//check start
		if (keyboardState->IsKeyDown(Input::Keys::SPACE))
		{
			_started = true;
		}
	}
	else
	{
		CheckPaused(keyboardState, Input::Keys::P);
		if (!_paused)
		{
			Input(elapsedTime, keyboardState, mouseState);
			UpdatePacman(elapsedTime);
			CheckViewportCollision();

			for (int i = 0; i < MUNCHIECOUNT; i++)
			{
				//munchie frame count continues
				_munchies[i]->frameCount++;
				UpdateMunchies(_munchies[i], elapsedTime);	
			}
		}
	}

	if (_cherryRandomize == true)
	{
		_Cherry->position = new Vector2((rand() % Graphics::GetViewportWidth()), (rand() % Graphics::GetViewportHeight()));
	}
}

void Pacman::Draw(int elapsedTime)
{

	// Allows us to easily create a string
	std::stringstream stream;
	stream << "Pacman X: " << _pacman->position->X << " Y: " << _pacman->position->Y;

	SpriteBatch::BeginDraw(); // Starts Drawing
	SpriteBatch::Draw(_pacman->texture, _pacman->position, _pacman->sourceRect); // Draws Pacman
	for (int i = 0; i < MUNCHIECOUNT; i++)
	{
		if (_munchies[i]->frameCount == 0)
		{
			// Draws Red Munchie
			SpriteBatch::Draw(_munchies[i]->InvertedTexture, _munchies[i]->Rect, nullptr, Vector2::Zero, 1.0f, 0.0f, Color::White, SpriteEffect::NONE);
			_munchies[i]->frameCount++;
		}
		else
		{
			// Draw Blue Munchie
			SpriteBatch::Draw(_munchies[i]->BlueTexture, _munchies[i]->Rect, nullptr, Vector2::Zero, 1.0f, 0.0f, Color::White, SpriteEffect::NONE);
			if (_munchies[i]->frameCount >= 60)
				_munchies[i]->frameCount = 0;
		}
	}

	if (_Cherry->frameCount == 0)
	{
		// Draws Red Munchie
		SpriteBatch::Draw(_Cherry->InvertedTexture, _Cherry->Rect, nullptr, Vector2::Zero, 1.0f, 0.0f, Color::White, SpriteEffect::NONE);
		_Cherry->frameCount++;
	}
	else
	{
		// Draw Blue Munchie
		SpriteBatch::Draw(_Cherry->BlueTexture, _Cherry->Rect, nullptr, Vector2::Zero, 1.0f, 0.0f, Color::White, SpriteEffect::NONE);
		if (_Cherry->frameCount >= 60)
			_Cherry->frameCount = 0;
	}
	
	// Draws String
	SpriteBatch::DrawString(stream.str().c_str(), _stringPosition, Color::Green);

	//draws start menu 
	if (!_started)
	{
		std::stringstream StartStream;
		StartStream << "Push Spacebar to Start";

		SpriteBatch::Draw(_start->Background, _start->Rectangle, nullptr);
		SpriteBatch::DrawString(StartStream.str().c_str(), _start->StringPosition, Color::Red);
	}

	//draws pause menu
	if (_paused)
	{
		std::stringstream menuStream;
		menuStream << "paused";

		SpriteBatch::Draw(_pause->Background, _pause->Rectangle, nullptr);
		SpriteBatch::DrawString(menuStream.str().c_str(), _pause->StringPosition, Color::Red);
			
	}

	SpriteBatch::EndDraw(); // Ends Drawing
}

void Pacman::Input(int elapsedTime, Input::KeyboardState* state, Input::MouseState* mouseState)
{	
	float pacmanSpeed = _cPacmanSpeed * elapsedTime * _pacman->speedMultiplier;


	//MOUSE INPUT
	//reposition cherry
	for (int i = 0; i < MUNCHIECOUNT; i++)
	{
		if (mouseState->LeftButton == Input::ButtonState::PRESSED)
		{
			_Cherry->position->X = mouseState->X;
			_Cherry->position->Y = mouseState->Y;
		}
	}


	//KEYBAORD INPUT
	//Speed Multiplier (shift)
	if (state->IsKeyDown(Input::Keys::LEFTSHIFT))
	{
		//apply multiplier
		_pacman->speedMultiplier = 2.0f;
	}
	else
	{
		//reset multiplier
		_pacman->speedMultiplier = 1.0f;
	}

	// Checks if right arrow key is pressed
	if (state->IsKeyDown(Input::Keys::D))
	{
		_pacman->position->X += pacmanSpeed; //Moves Pacman across X axis
		_pacman->direction = 0;
	}
	// Checks if A key is pressed
	else if (state->IsKeyDown(Input::Keys::A))
	{
		_pacman->position->X += -pacmanSpeed; //Moves Pacman across X axis
		_pacman->direction = 2;
	}
	// Checks if W key is pressed
	else if (state->IsKeyDown(Input::Keys::W))
	{
		_pacman->position->Y += -pacmanSpeed; //Moves Pacman across Y axis
		_pacman->direction = 3;
	}
	// Checks if S key is pressed
	else if (state->IsKeyDown(Input::Keys::S))
	{
		_pacman->position->Y += pacmanSpeed; //Moves Pacman across Y axis
		_pacman->direction = 1;
	}

	if (state->IsKeyDown(Input::Keys::R) && !_rKeyDown)
	{
		_rKeyDown = true;
		_cherryRandomize = true;
	}
	if (state->IsKeyUp(Input::Keys::R))
	{
		_rKeyDown = false;
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
	if (_pacman->position->X + _pacman->sourceRect->Width > Graphics::GetViewportWidth())//1024 is game width
	{
		//pacman hit right wall
		_pacman->position->X = 0 - _pacman->sourceRect->Width;
	}
	//check pacman is trying to dissappear
	if (_pacman->position->X + _pacman->sourceRect->Width < 0)//1024 is game width
	{
		//pacman hit Left wall
		_pacman->position->X = Graphics::GetViewportWidth() - _pacman->sourceRect->Width;
	}
	//check pacman is trying to dissappear
	if (_pacman->position->Y + _pacman->sourceRect->Height > Graphics::GetViewportHeight())//1024 is game width
	{
		//pacman hit Floor
		_pacman->position->Y = 0 - _pacman->sourceRect->Height;
	}
	//check pacman is trying to dissappear
	if (_pacman->position->Y + _pacman->sourceRect->Height < 0)//1024 is game width
	{
		//pacman hit Roof
		_pacman->position->Y = Graphics::GetViewportHeight() - _pacman->sourceRect->Height;
	}
}
void Pacman::UpdatePacman(int elapsedTime)
{
	//pacman frame count
	_pacman->currentFrameTime += elapsedTime;

	//mouth movement
	_pacman->sourceRect->X = _pacman->sourceRect->Width * _pacman->frame;

	//mouth movement
	_pacman->sourceRect->X = _pacman->sourceRect->Width * _pacman->frame;

	//changes direction of pacman
	_pacman->sourceRect->Y = _pacman->sourceRect->Height * _pacman->direction;

	if (_pacman->currentFrameTime > _cPacmanFrameTime)
	{
		_pacman->frame++;

		if (_pacman->frame >= 2)
			_pacman->frame = 0;

		_pacman->currentFrameTime = 0;
	}
}

void Pacman::UpdateMunchies(Enemy*, int elapsedTime)
{
	for (int i = 0; i < MUNCHIECOUNT; i++)
	{
		//munchie animation
		_munchies[i]->CurrentFrameTime += elapsedTime;
		_munchies[i]->Rect->X = _munchies[i]->Rect->Width * _munchies[i]->Frame;
	
		if (_munchies[i]->CurrentFrameTime > _munchies[i]->frameTime)
		{
			_munchies[i]->frameCount++;

			if (_munchies[i]->frameCount >= 2)
			_munchies[i]->frameCount = 0;

			_munchies[i]->CurrentFrameTime = 0;
		}
	}
}

void Pacman::UpdateCherries(Enemy*, int elapsedTime)
{
	//Cherry animation
	_Cherry->CurrentFrameTime += elapsedTime;
	_Cherry->Rect->X = _Cherry->Rect->Width * _Cherry->Frame;

	if (_Cherry->CurrentFrameTime > _Cherry->frameTime)
	{
		_Cherry->frameCount++;

		if (_Cherry->frameCount >= 2)
			_Cherry->frameCount = 0;

		_Cherry->CurrentFrameTime = 0;
	}
}