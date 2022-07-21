#include "AnimatedObject.h"
#include "TextureLoader.h"
#include <stdlib.h>

AnimatedObject::AnimatedObject(const char* fileName, int x, int y, int width, int height, int SpriteClips, int ssRows,SDL_Renderer* renderer)
{
	//General assignment of all the internal variables
	gameRenderer = renderer;
	//Loads the texture 
	objTexture = TextureLoader::LoadTexture(gameRenderer, fileName);

	xPos = x;
	yPos = y;
	objectWidth = width;
	objectHeight = height;

	destRect = { xPos,yPos,objectWidth,objectHeight };

	maxSpriteClips = SpriteClips;
	spriteSheetRowsCount = ssRows;

	loadSpriteSheet(objTexture);	
}

void AnimatedObject::Update() 
{

}

void AnimatedObject::Render() 
{
	//Chose the next frame with a division of the current frame counter and the Max number of sprites
	currClip = &gSpriteClips[frame / maxSpriteClips];

	SDL_RenderCopy(gameRenderer, objTexture, currClip, &destRect);

	//If the isAnimated Tag is true, we start increasing the frame counter, so the curr clip changes value
	if(isAnimated) 
	{
		frame++;

		//If it reaches the max number, we reset the value of the frame counter
		if (frame / maxSpriteClips >= maxSpriteClips)
		{
			frame = 0;
		}
	}
}

void AnimatedObject::loadSpriteSheet(SDL_Texture* texture) 
{
	if(texture == nullptr) 
	{
		printf("Invalid Texture!");
		return;
	}

	//For loop to populate empty SDL_Rect into the vector
	//These values will been populated with values in the LoadSpriteSheet function
	for (size_t i = 0; i < maxSpriteClips; i++)
	{
		gSpriteClips.push_back({});
	}

	//This values are used to count for the next values of the sprites
	//One for the width, the height and the row
	//When the for loop reaches the max number of rows, we reset the value and increment the nextFrameHeightValue
	int nextFrameWidth = 0;
	int nextFrameHeight = 0;
	int spriteRow = 0;

	for(int i = 0; i < maxSpriteClips;i++) 
	{
		gSpriteClips[i].x = nextFrameWidth;
		gSpriteClips[i].y = nextFrameHeight;
		gSpriteClips[i].w = objectWidth;
		gSpriteClips[i].h = objectHeight;

		nextFrameWidth += objectWidth;

		spriteRow++;

		if(spriteRow >= spriteSheetRowsCount) 
		{
			nextFrameWidth = 0;
			nextFrameHeight += objectHeight;
			spriteRow = 0;
		}
	}
}