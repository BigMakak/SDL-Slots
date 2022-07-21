#pragma once
#include <SDL.h>
//#include <SDL_image.h>
//#include <SDL_ttf.h>
#include <stdio.h>
#include "ObjectFactory.h"
#include "CasinoSlot.h"
#include "KeyboardEventHandler.h"

/// <summary>
/// Class that represents the base of the Game
/// This class works almost has a game engine
/// Takes care of loading all the assets, handling input, runnning the main Update loop, rendering all the objects into the window and cleaning all the objects created
/// </summary>
class Game
{
public:
	Game();

	~Game();

	//Function that initializes all the processes for the game to start, like the SDL subsystem 
	//Needs a X position and Y position for it's position on Screen
	//An int for width and height for the total size of the game screen
	//And a flag to see if the game window is going to occupy the fullscreen or not
	void init(const char* title,int xPosition, int yPosition,int width, int height, bool fullscreen);

	//Function that loads all the Assets for the game
	void loadAssets();

	//Function responsibale for handling all the input events that the game is listening to
	void handleEvents();

	//The Update function runs when the game starts and is where we put all our game logic
	void update();

	//Function that takes care of rendering all the assets of the game
	void render();

	//Cleans and deletes all the objects created and closes all the SDL subsystems
	void clean();

	//Checks for the current time it took to pass one frame, and delays the next frame if needed
	void limitFrameRate(bool isFrameStart);

	//Returns true if the game is running, and false if the game is not running
	bool running() { return isRunning; };

	

private:
	//Flag that represents if the Game is running or not
	bool isRunning = false;
	//The main game window
	SDL_Window* gWindow = nullptr;
	//An Casino Slot Object that holds all the Game logic and the various objects that populate the game
	CasinoSlot* casinoSlot = nullptr;
	//The font used in the game
	TTF_Font* gameFont = nullptr;
	//The main renderer for the game
	SDL_Renderer* renderer = nullptr;

	
#pragma region Variables for the FPS limit
	const int FPS = 80;

	const int frameDelay = 1000 / FPS;

	Uint32 frameStart = 0;

	int frameTime = 0;
#pragma endregion Variables for the FPS limit

};

