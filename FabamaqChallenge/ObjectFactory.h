#pragma once
#include <map>
#include <list>
#include <string>

#include "ImageObject.h"
#include "TextObject.h"
#include "AnimatedObject.h"


using namespace std;

/// <summary>
/// Enum that represent keys inside the TextUI map
/// </summary>
enum UIText
{
	In,
	Out,
	Plays
};

/// <summary>
/// Class that is in charge of creating and placing all the Game Objects inside the game window
/// </summary>
class ObjectFactory
{
public:

	ObjectFactory(SDL_Renderer* renderer, TTF_Font* textFont);

	/// <summary>
	/// Loads and creates all the objects inside the game window
	/// </summary>
	void LoadObjects();

	/// <summary>
	/// Animate all the game objects that are of type AnimatedGameObject
	/// </summary>
	/// <param name="isToAnimate"></param>
	void AnimateObjects(bool isToAnimate);

	/// <summary>
	/// Renders all the objects created
	/// </summary>
	void RenderObjects();

	/// <summary>
	/// Changes the text in the UI, depending on the UI text passed in the parameters
	/// </summary>
	/// <param name="uiEnum">The UI text value for the key in the map of Text GameObjects</param>
	/// <param name="newValue">The string to add to the Text Ui object</param>
	void ChangeUIText(UIText uiEnum, std::string newValue);

	/// <summary>
	/// Cleans and deletes all the Objects created
	/// </summary>
	void CleanObjects();


private:
	//Reference to the game font 
	TTF_Font* gameFont;

	//Default color for all the text used, in this case is black
	SDL_Color textColor = { 0, 0, 0 };

	//Reference to the renderer of the game
	SDL_Renderer* gameRenderer;

	//List of All the Game Objects inside the game, expect the Text objects that have values that change in run-time
	list<GameObject*> images;

	///Map that has all the Text UI that change in run-time
	map<UIText, TextObject*> TextUI;
};

