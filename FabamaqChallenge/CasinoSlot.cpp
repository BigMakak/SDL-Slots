#include "CasinoSlot.h"

CasinoSlot::~CasinoSlot() 
{
	objectFactory->CleanObjects();

	delete objectFactory;
}

void CasinoSlot::loadGameObjects(SDL_Renderer* renderer, TTF_Font* textFont)
{
	objectFactory = new ObjectFactory(renderer,textFont);

	objectFactory->LoadObjects();
}

void CasinoSlot::startGame() 
{
	if(currState == Stopped && CreditsInCounter > 0) 
	{
		currState = Running;

		PlaysCounter++;

		objectFactory->TextUI.at(Plays)->ChangeText("Plays: " + to_string(PlaysCounter));

		objectFactory->AnimateObjects();
		return;
	}

	if(currState == Running) 
	{
		currState = Stopped;
		return;
	}
	
}

void CasinoSlot::UpdateLoop() 
{
	switch (currState)
	{
	case Running:
		//printf("Game is Running\n");
		break;


	default:
		break;
	}
}

void CasinoSlot::modifyCreditsCounter(bool isCreditsIn)
{
	if(isCreditsIn) 
	{
		CreditsInCounter++;
	}
	else
	{
		CreditsOutCounter += CreditsInCounter;

		objectFactory->TextUI.at(Out)->ChangeText("Credits Out: " + to_string(CreditsOutCounter));
		CreditsInCounter = 0;
	}

	objectFactory->TextUI.at(In)->ChangeText("Credits In: " + to_string(CreditsInCounter));
}

void CasinoSlot::renderGameObjects() 
{
	objectFactory->RenderObjects();
}
