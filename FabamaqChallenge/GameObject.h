#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

/// <summary>
/// Class that represents an object inside the game
/// Each object has a X and Y position on screen and need to have an Update and Render implementation
/// </summary>
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
	//The texture that the game object will have
	SDL_Texture* objTexture = nullptr;
	//The game renderer
	SDL_Renderer* gameRenderer = nullptr;
	//The src and Destination Rect. Used for the rendering of the Game Object
	SDL_Rect srcRect, destRect;

};

