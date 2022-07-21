#pragma once
#include "GameObject.h"

/// <summary>
/// Class that represents an Game Object that is a simple Image(like a .png,.bmp etc)
/// </summary>
class ImageObject : public GameObject
{
public:

	ImageObject(const char* fileName, int x, int y, int width, int height, SDL_Renderer* renderer);

	virtual void Update();

	virtual void Render();

};

