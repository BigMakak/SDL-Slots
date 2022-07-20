#include "TextObject.h"
#include "TextureLoader.h"

TextObject::TextObject(std::string text, int x, int y, int width, int height,SDL_Color color, TTF_Font* font, SDL_Renderer* renderer)
{
	gameRenderer = renderer;

	objTexture = TextureLoader::loadTTF(gameRenderer,text,color,font);

	xPos = x;
	yPos = y;
	objectWidth = width;
	objectHeight = height;
	textColor = color;
	textFont = font;

	destRect = { xPos, yPos, objectWidth, objectHeight };
}

void TextObject::Update()
{
	
}

void TextObject::Render()
{
	//Render to screen
	SDL_RenderCopy(gameRenderer, objTexture, NULL, &destRect);
}

void TextObject::ChangeText(std::string newText)
{
	//Destroy the old texture, so that the memory of the loaded texture is freed
	SDL_DestroyTexture(objTexture);
	//Load the texture with the new text
	objTexture = TextureLoader::loadTTF(gameRenderer,newText, textColor, textFont);
}