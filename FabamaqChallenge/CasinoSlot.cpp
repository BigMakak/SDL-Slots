#include "CasinoSlot.h"

CasinoSlot::~CasinoSlot() 
{
	objectFactory->CleanObjects();

	delete objectFactory;

	delete timer;
}

void CasinoSlot::loadGameObjects(SDL_Renderer* renderer, TTF_Font* textFont)
{
	objectFactory = new ObjectFactory(renderer,textFont);

	timer = new Timer();

	objectFactory->LoadObjects();
}

void CasinoSlot::startGame() 
{
	//This represents a simple finite state machine that checks the current state of the game
	//Depending on the state of the game, we change the state of the game and change Text in the UI, animate objects and start Timers
	switch (currState)
	{
	case Stopped:

		//If there are at least 1 or more credits, the game can start running
		if(CreditsInCounter > 0) 
		{
			currState = Running;

			CreditsInCounter--;

			objectFactory->ChangeUIText(In, to_string(CreditsInCounter));

			objectFactory->AnimateObjects(true);

			timer->start();
		}

		break;

	case Running:

		currState = Paused;

		objectFactory->AnimateObjects(false);

		timer->pause();

		break;

	case Paused:

		currState = Running;

		objectFactory->AnimateObjects(true);

		timer->unpause();

		break;

	default:
		break;
	}

	
}

void CasinoSlot::UpdateLoop()
{
	//Checks if the timer of the game is bigger then the cooldown of the game loop. This time is in miliseconds
	if (timer->getTicks() > loopTime)
	{
		printf("Passed the 5 seconds");

		currState = Stopped;

		PlaysCounter++;

		objectFactory->ChangeUIText(Plays, to_string(PlaysCounter));

		objectFactory->AnimateObjects(false);

		timer->stop();
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
		//If not, we add all the credits to the credits out counter and update all the Text UI
		CreditsOutCounter += CreditsInCounter;

		objectFactory->ChangeUIText(Out, to_string(CreditsOutCounter));
		CreditsInCounter = 0;
	}

	objectFactory->ChangeUIText(In, to_string(CreditsInCounter));
}

void CasinoSlot::renderGameObjects() 
{
	objectFactory->RenderObjects();
}
