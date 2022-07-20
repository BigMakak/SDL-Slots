#pragma once
#include <map>
#include <list>
#include "ImageObject.h"
#include "TextObject.h"
#include "AnimatedObject.h"

using namespace std;

enum UIText
{
	In,
	Out,
	Plays
};

class ObjectFactory
{
public:

	ObjectFactory(SDL_Renderer* renderer, TTF_Font* textFont);

	map<UIText, TextObject*> TextUI;

	list<GameObject*> images;

	void LoadObjects();

	void AnimateObjects();

	void RenderObjects();

	void CleanObjects();


private:
	TTF_Font* gameFont;

	SDL_Color textColor = { 0, 0, 0 };

	SDL_Renderer* gameRenderer;
};

