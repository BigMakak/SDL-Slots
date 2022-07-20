#include "KeyboardEventHandler.h"


void KeyboardEventHandler::HandleInput(bool &isRunning, CasinoSlot& casinoSlot)
{

	SDL_Event events;
	
	SDL_PollEvent(&events);

	switch (events.type)
	{

	case SDL_QUIT:
		isRunning = false;

	default:
		break;
	}

	if(events.type == SDL_KEYDOWN) 
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_SPACE:
			printf("Pressed the Space Button\n");
			casinoSlot.startGame();
			break;

		case SDLK_RSHIFT:
			printf("Pressed the Right Shift button\n");
			casinoSlot.modifyCreditsCounter(false);
			break;

		case SDLK_LSHIFT:
			printf("Pressed left shift\n");
			casinoSlot.modifyCreditsCounter(true);

			break;
		default:
			break;
		}
	}
}