#pragma once
#include "GameObject.h"
#include <string>

/// <summary>
/// An Game Object that represents text that appears in Game
/// </summary>
class TextObject : public virtual GameObject
{
public:
	TextObject(std::string text, int x, int y, int width, int height,SDL_Color color, TTF_Font* font,SDL_Renderer* renderer);

	virtual void Update();

	virtual void Render();

	/// <summary>
	/// Function that changes the text inside the object at run-time
	/// Destroys the old texture, and creates a new one
	/// </summary>
	/// <param name="newText">The text that is going to be added to the texture</param>
	void ChangeText(std::string newText);

private:
	//Default color for the text
	SDL_Color textColor = {0,0,0};
	//String that is assigned in the creation of this object
	std::string defaultText = "";

	TTF_Font* textFont;
};

