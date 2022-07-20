#pragma once
#include "GameObject.h"
#include <vector>

class AnimatedObject : public GameObject
{

	

public:

	AnimatedObject(const char* fileName, int x, int y, int width, int height, int maxSpriteClip,int spriteSheetRows,SDL_Renderer* renderer);

	virtual void Update();

	virtual void Render();

	void Animate(bool isToAnimate) { isAnimated = isToAnimate; };

private:
	
	//Creating this hard coded values, because of the size of the sprite sheet
	int spriteSheetRowsCount = 0;

	int maxSpriteClips = 0;

	int frame = 0;

	bool isAnimated = false;

	SDL_Rect* currClip = nullptr;

	std::vector<SDL_Rect> gSpriteClips;

	void loadSpriteSheet(SDL_Texture* texture);
};

