#pragma once
#include <SDL.h>
#include <stdio.h>
#include <string>


enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

class KeyGameSetup 
{
public:

	SDL_Window* window = NULL;

	SDL_Surface* gScreenSurface = NULL;

	SDL_Surface* gImageBMP = NULL;

	//The images that correspond to a keypress
	SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

	//Current displayed image
	SDL_Surface* gCurrentSurface = NULL;

	//Start the SDL and creates a window
	bool init(int width, int height);
	//Loads all the media necessary for the game to run
	bool loadAllMedia();
	//Free all the media created and closes the SDL 
	void close();

	//The main function loop of the game
	void startGame(int width, int height);

	//Loads individual image
	SDL_Surface* loadSurface(std::string path);

	
};