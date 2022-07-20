#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class  GameObject
{

public:

	virtual void Update() = 0;

	virtual void Render() = 0;

protected:

	//This values hold the X and Y position of the game object on the screen
	int xPos = 0;
	int yPos = 0;

	//This will hold the values of width and height for the texture
	int objectWidth = 0;
	int objectHeight = 0;

	SDL_Texture* objTexture = nullptr;

	SDL_Renderer* gameRenderer = nullptr;

	SDL_Rect srcRect, destRect;

};

