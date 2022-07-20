#include "Game.h"


Game::Game() 
{
	casinoSlot = new CasinoSlot();
}

Game::~Game()
{
	delete casinoSlot;
}

void Game::init(const char* title, int xPosition, int yPosition, int width, int height, bool fullscreen)
{
	int flags = 0;

	//Check if bool of fullscreen is true, and change the flags variable to fullscreen
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//Initialize the SDL and check if th return value is valid
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		printf("Subsystem has been initialised!\n");

		//Create the window with the corresponding parameters
		gWindow = SDL_CreateWindow(title, xPosition, yPosition, width, height, flags);

		if (gWindow)
		{
			printf("Game Window created\n");
		}
		else
		{
			printf("Error creating window: Error: %s\n", SDL_GetError());
			isRunning = false;
			return;
		}

		//Create the renderer with the index and the creation flag
		renderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

			printf("Renderer has been created!\n");
		}
		else
		{
			printf("Error creating renderer. Error %s\n", SDL_GetError());
			isRunning = false;
			return;
		}



		//Set the isRunning boolean to true, seing that everting was created
		isRunning = true;
	}

	if(TTF_Init() == -1) 
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		isRunning = false;
		return;
	}

	loadAssets();
}

/// <summary>
/// Function that loads all the assest for the game to run
/// It loads the font and the object Manager, the class that creates all objects inside the game
/// </summary>
void Game::loadAssets() 
{
	
	gameFont = TTF_OpenFont("Resources/Fonts/editundo.ttf", 50);

	casinoSlot->loadGameObjects(renderer,gameFont);

	printf("Assets are loaded!\n");


}

void Game::handleEvents() 
{
	KeyboardEventHandler::HandleInput(isRunning,*casinoSlot);
}

void Game::update() 
{
	//TODO: Add State Machine for the Game Loop using Timers
	counter++;

	casinoSlot->UpdateLoop();

}

void Game::render() 
{
	SDL_RenderClear(renderer);

	//Render text
	casinoSlot->renderGameObjects();
	
	SDL_RenderPresent(renderer);
}

void Game::limitFrameRate(bool isFrameStart) 
{
	if(isFrameStart) 
	{
		frameStart = SDL_GetTicks();
	}
	else
	{
		frameTime = SDL_GetTicks() - frameStart;

		if(frameDelay > frameTime) 
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
}

void Game::clean() 
{
	SDL_DestroyWindow(gWindow);

	SDL_DestroyRenderer(renderer);

	TTF_CloseFont(gameFont);

	SDL_Quit();

	TTF_Quit();

	gWindow = nullptr;

	renderer = nullptr;

	printf("The game has been cleaned!");
}

