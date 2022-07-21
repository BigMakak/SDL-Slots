#include "Game.h"

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


int main(int argc, char* args[])
{
	//Place where we run our game engine functions step by step
	Game* game = new Game();

	//First we start all the subsystems with the init function, like the SDL and TTF 
	game->init("Game Start",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,false);

	//Then if all went well, we start the main while loop
	while(game->running()) 
	{
		//Then we call all the functions in order of importance 
		game->limitFrameRate(true);

		game->handleEvents();

		game->update();

		game->render();

		game->limitFrameRate(false);
	}
	
	//And at the end we clean all the objects and stop and the subsystems
	game->clean();

	delete game;

	return 0;
}


