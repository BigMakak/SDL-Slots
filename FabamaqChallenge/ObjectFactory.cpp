#include "ObjectFactory.h"
#include <typeinfo>


ObjectFactory::ObjectFactory(SDL_Renderer* renderer, TTF_Font* font)
{
	gameFont = font;
    gameRenderer = renderer;
}

void ObjectFactory::LoadObjects()
{
    //Add all the text to the game, that can be altered by pressing the inputs
    //They are separeted by 20 pxls 
    TextUI.insert({ In, new TextObject("Credits In: ", 10, 20, 150, 50, textColor, gameFont,gameRenderer) });

    TextUI.insert({ Out, new TextObject("Credits Out: ", 590, 20, 150, 50, textColor, gameFont,gameRenderer) });

    TextUI.insert({ Plays, new TextObject("Plays: ", 200, 450, 150, 50, textColor, gameFont,gameRenderer) });

    //The Slot image for the game
    images.push_back(new ImageObject("Resources/Images/slots.png", 150, 150, 500, 350, gameRenderer));

    //Controll indications for the player
    images.push_back(new ImageObject("Resources/Images/PressSpace.png", 200, 500, 400, 50, gameRenderer));

    images.push_back(new ImageObject("Resources/Images/RightShift.png", 590, 75, 200, 50, gameRenderer));

    images.push_back(new ImageObject("Resources/Images/LeftShift.png", 10, 75, 200, 50, gameRenderer));

    //Animated Objects
    images.push_back(new AnimatedObject("Resources/Images/SS64.png", 220, 300, 64, 64, 50,15, gameRenderer));

    images.push_back(new AnimatedObject("Resources/Images/SS64.png", 370, 300, 64, 64, 50, 15, gameRenderer));

    images.push_back(new AnimatedObject("Resources/Images/SS64.png", 510, 300, 64, 64, 50, 15, gameRenderer));

}

void ObjectFactory::AnimateObjects(bool isAnimate) 
{
    for (auto const& image : images)
    {
        AnimatedObject* animatedObj = dynamic_cast<AnimatedObject*>(image);

        if(animatedObj != nullptr) 
        {
            //printf("Inside the animated Object");

            animatedObj->Animate(isAnimate);
        }
    }
}

void ObjectFactory::ChangeUIText(UIText uiText,std::string stringValue) 
{
    TextUI.at(uiText)->ChangeText(stringValue);
}

void ObjectFactory::RenderObjects()
{
    for (auto const& ui : TextUI)
    {
        ui.second->Render();
    }

    for(auto const& image : images) 
    {
        image->Render();
    }
}

void ObjectFactory::CleanObjects()
{
    for (auto const& ui : TextUI)
    {
        delete ui.second;
    }

    for(auto const& image : images) 
    {
        delete image;
    }

    TextUI.clear();

    images.clear();
}