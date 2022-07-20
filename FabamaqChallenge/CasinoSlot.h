#pragma once
#include "ObjectFactory.h"


enum GameState 
{
	Stopped,
	Running,
	Paused
};


/// <summary>
/// Class that holds all the game logic
/// It will be in charge of changing the state of the game
/// </summary>
class CasinoSlot
{
public:
	//destructor that delete all objects created in this class
	~CasinoSlot();

	/// <summary>
	/// Loads all the Game objects using the the Object Factory class
	/// </summary>
	/// <param name="renderer">The main game renderer</param>
	/// <param name="textFont">The font that we want to use</param>
	void loadGameObjects(SDL_Renderer* renderer, TTF_Font* textFont);

	/// <summary>
	/// The function that start the slot rotation and State Machine
	/// </summary>
	void startGame();

	/// <summary>
	/// The main game loop function. 
	/// This function will have all the game code that needs to be runned inside the Update function
	/// </summary>
	void UpdateLoop();

	/// <summary>
	/// Renders all the game objects inside the CasinoSlot Game
	/// </summary>
	void renderGameObjects();

	/// <summary>
	/// Alters the value of the Play counter
	/// Used to create
	/// </summary>
	/// <param name="isCreditsIn"></param>
	void modifyCreditsCounter(bool isCreditsIn);


private:

	GameState currState = Stopped;

	int CreditsInCounter = 0;

	int CreditsOutCounter = 0;

	int PlaysCounter = 0;

	ObjectFactory* objectFactory;

};

