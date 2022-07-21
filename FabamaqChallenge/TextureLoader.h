#pragma once
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

/// <summary>
/// A helper class that offers static functions that load and create textures for the various game objects
/// </summary>
class TextureLoader
{
public:
	/// <summary>
	/// Creates a texture from a file, specifically a .png file
	/// </summary>
	/// <param name="renderer">The primary game renderer</param>
	/// <param name="fileName">The path and name of the file</param>
	/// <returns>A pointer to the created texture</returns>
	static SDL_Texture* LoadTexture(SDL_Renderer* renderer,const char* fileName);

	/// <summary>
	/// Creates a texture based on a font and a string
	/// </summary>
	/// <param name="renderer">the primary game renderer</param>
	/// <param name="text">The text that is going to used to create the texture</param>
	/// <param name="textColor">The color of the texture</param>
	/// <param name="font">The font for the text</param>
	/// <returns>A pointer to the created texture</returns>
	static SDL_Texture* loadTTF(SDL_Renderer* renderer,std::string text, SDL_Color textColor, TTF_Font* font);

};

