#pragma once
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

class TextureLoader
{
public:
	//Loads an PNG file to a texture
	static SDL_Texture* LoadTexture(SDL_Renderer* renderer,const char* fileName);

	//Creates image from font string
	static SDL_Texture* loadTTF(SDL_Renderer* renderer,std::string fontLocation, SDL_Color textColor, TTF_Font* font);

private:
	
};

