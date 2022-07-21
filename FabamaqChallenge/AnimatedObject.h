#pragma once
#include "GameObject.h"
#include <vector>

/// <summary>
/// Class that represents a Animated Game Object
/// This game object will load a sprite sheet, and those different tiles in the sprite sheet will be the different frames of animation
/// </summary>
class AnimatedObject : public GameObject
{

public:

	AnimatedObject(const char* fileName, int x, int y, int width, int height, int maxSpriteClip,int spriteSheetRows,SDL_Renderer* renderer);

	virtual void Update();

	virtual void Render();

	//Changes the flag IsAnimated. If it's true, the Game Object will start going throw it's animation frames
	void Animate(bool isToAnimate) { isAnimated = isToAnimate; };

private:
	
	//The rows of the loaded sprite sheet
	int spriteSheetRowsCount = 0;
	//Max number of clips/frames that are going to be loaded into the animation
	int maxSpriteClips = 0;
	//The current frame of the animation
	int frame = 0;
	//The tag that let's the Game Object animate
	bool isAnimated = false;
	//Current clip/frame Rect
	SDL_Rect* currClip = nullptr;
	//Vector with all the animation Sprite Clips
	std::vector<SDL_Rect> gSpriteClips;
	//Function that loads the sprite sheet, and fills the Sprite Clips
	void loadSpriteSheet(SDL_Texture* texture);
};

