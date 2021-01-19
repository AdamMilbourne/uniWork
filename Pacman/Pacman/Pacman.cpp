#include "Pacman.h"

#include <sstream>

#include <time.h>

#include <Windows.h>

//CONSTRUCTOR
Pacman::Pacman(int argc, char* argv[]) : Game(argc, argv), _cPacmanSpeed(0.1f), _cPacmanFrameTime(250)
{
	srand(time(NULL));


	//sound initialise
	CherryEat = new SoundEffect();
	Death = new SoundEffect();
	Waka = new SoundEffect();
	Theme = new SoundEffect();

	

	for (int i = 0; i < GHOSTCOUNT; i++)
	{
		//initialise ghosts
		_ghosts[i] = new MovingEnemy();
		_ghosts[i]->direction = 0;
		_ghosts[i]->speed = 0.1f;
	}

	//Munchie Data
	for (int i = 0; i < MUNCHIECOUNT; i++)
	{
		_munchies[i] = new Enemy();
		_munchies[i]->CurrentFrameTime = 0;
		_munchies[i]->Frame = 0;
		_munchies[i]->frameCount = 1;
		_munchies[i]->frameTime = 50 * 500;

	}

	//Cherry Data
	_Cherry = new Enemy();
	_Cherry->CurrentFrameTime = 0;
	_Cherry->Frame = 0;
	_Cherry->frameCount = 1;
	_Cherry->frameTime = 500;

	Input::KeyboardState* keyboardState = Input::Keyboard::GetState();
	StartMenu(keyboardState, Input::Keys::SPACE);

	//Initialise Member variables
	_pacman = new Player();
	_pause = new Menu();
	_start = new Menu();
	_gameOver = new Menu();

	//pacman data
	_pacman->speedMultiplier = 1.0f;
	_pacman->direction = 0;
	_pacman->currentFrameTime = 0;
	_pacman->frame = 0;
	_pacman->dead = false;

	//pause data
	_paused = false;
	_pKeyDown = false;

	//start menu data
	_started = false;

	//game over data
	_gameIsOver = false;
	_escapeKeyDown = false;

	//random cherry data
	_cherryRandomize = false;
	_rKeyDown = false;

	//Initialise important Game aspects
	Audio::Initialise();
	Graphics::Initialise(argc, argv, this, 1024, 768, false, 25, 25, "Pacman", 60);
	Input::Initialise();

	if (!Audio::IsInitialised())
	{
		std::cout << "Audio is initiialised" << std::endl;
	}

	// Start the Game Loop - This calls Update and Draw in game loop
	Graphics::StartGameLoop();

	

}


//START MENU DATA
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


//DESTRUCTOR METHOD
Pacman::~Pacman()
{
	//sound destructor
	delete Waka;
	delete Death;
	delete CherryEat;
	delete Theme;

	//pacman destructor
	delete _pacman->texture;
	delete _pacman->sourceRect;
	delete _pacman;

	//clean up texture
	delete _munchies[0]->Texture;


	for (int nCount = 0; nCount < MUNCHIECOUNT; nCount++)
	{
		delete _munchies[nCount]->Texture;
		delete _munchies[nCount]->position;
		delete _munchies[nCount]->Rect;
		delete _munchies[nCount];
	}
	delete[] _munchies;
	//remaining clean up...

	//clean up texture
	delete _Cherry->Texture;
	delete _Cherry->position;
	delete _Cherry->Rect;
	delete _Cherry;
	//remaining clean up...

	for (int i = 0; i < GHOSTCOUNT; i++)
	{
		//ghost destructor
		delete _ghosts[i]->texture;
		delete _ghosts[i]->position;
		delete _ghosts[i]->sourceRect;
		delete _ghosts[i];
	}

}


//LOAD ASSETS
void Pacman::LoadContent()
{
	//pop sound load
	Waka->Load("Sounds/Waka.wav");
	CherryEat->Load("Sounds/CherryEat.wav");
	Death->Load("Sounds/Death.wav");
	//Theme->Load("Sounds/Theme.wav");


	for (int i = 0; i < GHOSTCOUNT; i++)
	{
		//Load blue ghost
		_ghosts[i]->texture = new Texture2D();
		_ghosts[i]->texture->Load("Textures/GhostBlueSpriteSheet.png", false);
		_ghosts[i]->position = new Vector2((rand() % Graphics::GetViewportWidth()), (rand() % Graphics::GetViewportHeight()));
		_ghosts[i]->sourceRect = new Rect(0.0f, 0.0f, 20, 20);
	}

	//munchie texture
	Texture2D* munchieTex = new Texture2D();
	munchieTex->Load("Textures/Munchie SpriteSheet.png", false);
	for (int i = 0; i < MUNCHIECOUNT; i++)
	{
		_munchies[i]->Texture = munchieTex;
	}

	//cherry Texture
	Texture2D* CherryTex = new Texture2D();
	CherryTex->Load("Textures/CherrySpriteSheet.png", false);
	_Cherry->Texture = CherryTex;


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

	//set Game Over parameters
	_gameOver->Background = new Texture2D();
	_gameOver->Background->Load("Textures/Transparency.png", false);
	_gameOver->Rectangle = new Rect(0.0f, 0.0f, Graphics::GetViewportWidth(), Graphics::GetViewportHeight() / 2.0f);
	_gameOver->StringPosition = new Vector2(Graphics::GetViewportWidth() / 2.0f, Graphics::GetViewportHeight() / 2.0f);

	// Load Pacman
	_pacman->texture = new Texture2D();
	_pacman->texture->Load("Textures/Pacman.tga", false);
	_pacman->position = new Vector2(350.0f, 350.0f);
	_pacman->sourceRect = new Rect(0.0f, 0.0f, 32, 32);

	//Load cherry 
	_Cherry->Texture = CherryTex;
	_Cherry->position = new Vector2((rand() % Graphics::GetViewportWidth()), (rand() % Graphics::GetViewportHeight()));
	_Cherry->Rect = new Rect(0.0f, 0.0f, 32.0f, 32.0f);
	

	// Load Munchie
	for (int i = 0; i < MUNCHIECOUNT; i++)
	{
		
		_munchies[i]->Texture = munchieTex;
		_munchies[i]->position = new Vector2((rand() % Graphics::GetViewportWidth()), (rand() % Graphics::GetViewportHeight()));
		_munchies[i]->Rect = new Rect(0.0f, 0.0f, 12, 12);
	}
	

	// Set string position
	_stringPosition = new Vector2(10.0f, 25.0f);

	if (!Waka->IsLoaded())
	{
		std::cout << "_pop member sound effect has not loaded" << std::endl;
	}
	if (!Death->IsLoaded())
	{
		std::cout << "_pop member sound effect has not loaded" << std::endl;
	}
	if (!CherryEat->IsLoaded())
	{
		std::cout << "_pop member sound effect has not loaded" << std::endl;
	}
	if (!Theme->IsLoaded())
	{
		std::cout << "_pop member sound effect has not loaded" << std::endl;
	}
	Audio::Play(Theme);
}


//UPDATE (CONSTANTLY CHECKING)
void Pacman::Update(int elapsedTime)
{
	// Gets the current state of the keyboard
	Input::KeyboardState* keyboardState = Input::Keyboard::GetState();
	Input::MouseState* mouseState = Input::Mouse::GetState();


	//Start buttons
	if (!_started)
	{
		//check start
		if (keyboardState->IsKeyDown(Input::Keys::SPACE))
		{
			_started = true;
		}
	}

	//pause everything
	else
	{
		if (score < 55)
		{
			UpdateGameOver(keyboardState, Input::Keys::ESCAPE);
			if (!_gameIsOver)
			{
				CheckPaused(keyboardState, Input::Keys::P);
				if (!_paused)
				{
					CheckCherryCollision();
					CheckMunchieCollision();
					UpdateGameOver(keyboardState, Input::Keys::ESCAPE);
					CheckPaused(keyboardState, Input::Keys::P);
					Input(elapsedTime, keyboardState, mouseState);
					UpdatePacman(elapsedTime);
					for (int i = 0; i < GHOSTCOUNT; i++)
					{
						UpdateGhost(_ghosts[i], elapsedTime);
					}
					CheckGhostCollision();
					CheckViewportCollision();
					UpdateCherries(_Cherry, elapsedTime);
					for (int i = 0; i < MUNCHIECOUNT; i++)
					{
						//munchie frame count continues
						UpdateMunchies(_munchies[i], elapsedTime);
					}
				}
			}
		}
	}
	
	//randomise cherry position with r
	if (_cherryRandomize == true)
	{
		_Cherry->position = new Vector2((rand() % Graphics::GetViewportWidth()), (rand() % Graphics::GetViewportHeight()));
		_cherryRandomize = false;
	}
	
}


//DRAW FUNCTIONS
void Pacman::Draw(int elapsedTime)
{

	// Allows us to easily create a string
	std::stringstream stream;
	stream << "Pacman X: " << _pacman->position->X << " Y: " << _pacman->position->Y;

	SpriteBatch::BeginDraw(); // Starts Drawing

	for (int i = 0; i < GHOSTCOUNT; i++)
	{
		//draw ghosts 
		SpriteBatch::Draw(_ghosts[i]->texture, _ghosts[i]->position, _ghosts[i]->sourceRect);
	}

	// Draws Pacman
	if (!_pacman->dead)
	{
		SpriteBatch::Draw(_pacman->texture, _pacman->position, _pacman->sourceRect);
	}
	//draw Munchie array 

	for (int i = 0; i < MUNCHIECOUNT; i++)
	{
				
		// Draws Red Munchie
		SpriteBatch::Draw(_munchies[i]->Texture, _munchies[i]->position, _munchies[i]->Rect);
			
	}
		
	//draw cherry
	SpriteBatch::Draw(_Cherry->Texture, _Cherry->position, _Cherry->Rect);
			
	// Draws String
	//SpriteBatch::DrawString(stream.str().c_str(), _stringPosition, Color::Green); // this is the X Y values shown in game(currently not needed)

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

	if (_gameIsOver)
	{
		std::stringstream menuStream;
		menuStream << "Game Over\n Press ESCAPE to exit\n your score was: " << score << endl;

		SpriteBatch::Draw(_gameOver->Background, _gameOver->Rectangle, nullptr);
		SpriteBatch::DrawString(menuStream.str().c_str(), _gameOver->StringPosition, Color::Red);
	}

	if (score == 6)
	{
		std::stringstream menuStream;
		menuStream << "YOU WON";

		SpriteBatch::Draw(_gameOver->Background, _gameOver->Rectangle, nullptr);
		SpriteBatch::DrawString(menuStream.str().c_str(), _gameOver->StringPosition, Color::Red);
	}

	std::stringstream scorestream;
	scorestream << "Score:" << score;
	SpriteBatch::DrawString(scorestream.str().c_str(), _stringPosition, Color::Red);


	SpriteBatch::EndDraw(); // Ends Drawing
}



//CONTROLS INPUT 
void Pacman::Input(int elapsedTime, Input::KeyboardState* state, Input::MouseState* mouseState)
{	
	float pacmanSpeed = _cPacmanSpeed * elapsedTime * _pacman->speedMultiplier;
	

	//MOUSE INPUT
	//reposition cherry
		/*if (mouseState->LeftButton == Input::ButtonState::PRESSED)
		{
			_Cherry->position->X = mouseState->X;                      //THIS MOVED THE CHERRY POSITION TO MOUSE CLICK HOWEVER I DO NOT NEED THIS FOR THE FINISHED PRODUCT.
			_Cherry->position->Y = mouseState->Y;
		}*/
	


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

	// Checks if D key is pressed
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


//CHECK IF THE GAME IS PAUSED
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


//CHECK THE SCREEN VIEW FOR COLLISIONS
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


//UPDATE THE PACMAN ANIMATION
void Pacman::UpdatePacman(int elapsedTime)
{
	//pacman frame count
	_pacman->currentFrameTime += elapsedTime;

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


//UPDATE THE MUNCHIES ARRAY ANIMATION
void Pacman::UpdateMunchies(Enemy*, int elapsedTime)
{
	for (int i = 0; i < MUNCHIECOUNT; i++)
	{
		//munchie time elapsed
		_munchies[i]->CurrentFrameTime += elapsedTime;	
	
		if (_munchies[i]->CurrentFrameTime > _munchies[i]->frameTime)
		{
			_munchies[i]->frameCount++;

			if (_munchies[i]->frameCount >= 2)
			{
				_munchies[i]->frameCount = 0;
	
			}
			_munchies[i]->CurrentFrameTime = 0;
			_munchies[i]->Rect->X = _munchies[i]->Rect->Width * _munchies[i]->frameCount;
		}
	}
}


//UPDATE CHERRY ANIMATIONS
void Pacman::UpdateCherries(Enemy*, int elapsedTime)
{
	//cherry elapsed time
	_Cherry->CurrentFrameTime += elapsedTime;

	if (_Cherry->CurrentFrameTime > _Cherry->frameTime)
	{
		_Cherry->frameCount++;

		if (_Cherry->frameCount >= 2)
		{
			_Cherry->frameCount = 0;
		}
		_Cherry->CurrentFrameTime = 0;
		_Cherry->Rect->X = _Cherry->Rect->Width * _Cherry->frameCount;
	}
}

void Pacman::UpdateGhost(MovingEnemy* , int elapsedtime)
{
	for (int i = 0; i < GHOSTCOUNT; i++)
	{
		_ghosts[i]->sourceRect->X = _ghosts[i]->sourceRect->Height * _ghosts[i]->direction;

		if (_ghosts[i]->direction == 0)
		{
			_ghosts[i]->position->X += _ghosts[i]->speed * elapsedtime;
		}
		else if (_ghosts[i]->direction == 1)
		{
			_ghosts[i]->position->X -= _ghosts[i]->speed * elapsedtime;
		}
		if (_ghosts[i]->position->X + _ghosts[i]->sourceRect->Width >= Graphics::GetViewportWidth())
		{
			_ghosts[i]->direction = 1;
		}
		else if (_ghosts[i]->position->X <= 0)
		{
			_ghosts[i]->direction = 0;
		}
	}
}

void Pacman::CheckGhostCollision()
{
	//local Variables
	int i = 0;
	int bottom1 = _pacman->position->Y + _pacman->sourceRect->Height;
	int bottom2 = 0;
	int left1 = _pacman->position->X;
	int left2 = 0;
	int right1 = _pacman->position->X + _pacman->sourceRect->Height;
	int right2 = 0;
	int top1 = _pacman->position->Y;
	int top2 = 0;

	
	for (i = 0; i < GHOSTCOUNT; i++)
	{
		//populate variables with ghost data
		bottom2 =_ghosts[i]->position->Y + _ghosts[i]->sourceRect->Height;

		left2 = _ghosts[i]->position->X;

		right2 = _ghosts[i]->position->X + _ghosts[i]->sourceRect->Width;

		top2 = _ghosts[i]->position->Y;

		if ((bottom1 > top2) && (top1 < bottom2) && (right1 > left2) && (left1 < right2))
		{
			i = GHOSTCOUNT;
			Audio::Play(Death);
			_pacman->dead = true;
		}
	}
}

void Pacman::UpdateGameOver(Input::KeyboardState* state, Input::Keys restartKey)
{
	if (_pacman->dead == true)
	{
		_gameIsOver = true;
	}
	if (_gameIsOver == true)
	{
		if (state->IsKeyDown(Input::Keys::ESCAPE) && !_escapeKeyDown)
		{
			_escapeKeyDown = true;
			exit;
		}
		if (state->IsKeyUp(Input::Keys::ESCAPE))
		{
			_escapeKeyDown = false;
		}
	}
}

void Pacman::CheckMunchieCollision()
{
	//local Variables
	int i = 0;
	int bottom1 = _pacman->position->Y + _pacman->sourceRect->Height;
	int bottom2 = 0;
	int left1 = _pacman->position->X;
	int left2 = 0;
	int right1 = _pacman->position->X + _pacman->sourceRect->Height;
	int right2 = 0;
	int top1 = _pacman->position->Y;
	int top2 = 0;

	for (i = 0; i < MUNCHIECOUNT; i++)
	{
		//populate variables with ghost data
		bottom2 = _munchies[i]->position->Y + _munchies[i]->Rect->Height;

		left2 = _munchies[i]->position->X;

		right2 = _munchies[i]->position->X + _munchies[i]->Rect->Width;

		top2 = _munchies[i]->position->Y;

		if ((bottom1 > top2) && (top1 < bottom2) && (right1 > left2) && (left1 < right2))
		{
			_munchies[i]->position = new Vector2 (-100, -100);
			Audio::Play(Waka);
			score++;
		}
	}
}

void Pacman::CheckCherryCollision()
{
	//local Variables
	int i = 0;
	int bottom1 = _pacman->position->Y + _pacman->sourceRect->Height;
	int bottom2 = 0;
	int left1 = _pacman->position->X;
	int left2 = 0;
	int right1 = _pacman->position->X + _pacman->sourceRect->Height;
	int right2 = 0;
	int top1 = _pacman->position->Y;
	int top2 = 0;

	
		//populate variables with ghost data
		bottom2 = _Cherry->position->Y + _Cherry->Rect->Height;

		left2 = _Cherry->position->X;

		right2 = _Cherry->position->X + _Cherry->Rect->Width;

		top2 = _Cherry->position->Y;

		if ((bottom1 > top2) && (top1 < bottom2) && (right1 > left2) && (left1 < right2))
		{
			_Cherry->position = new Vector2(-100, -100);
			Audio::Play(CherryEat);
			for (int i = 0; i < 5; i++)
			{
				score++;
			}
		}
	
}