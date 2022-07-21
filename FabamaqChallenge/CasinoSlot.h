#pragma once
#include "ObjectFactory.h"
#include "Timer.h"

/// <summary>
/// Enum of the different states of the Game
/// </summary>
enum GameState 
{
	Stopped,
	Running,
	Paused
};


/// <summary>
/// Class that holds all the game logic
/// It will be in charge of changing the state of the game
/// 
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
	/// Modifies the values of the Credits In and Credits out variables
	/// </summary>
	/// <param name="isCreditsIn">If the player wants to add more credits</param>
	void modifyCreditsCounter(bool isCreditsIn);


private:

	//The state of the game in run-time. Default value is stopped
	GameState currState = Stopped;

	//The number of credits in the game
	int CreditsInCounter = 0;
	//Number of Credits that the player got out
	int CreditsOutCounter = 0;
	//Number of plays that ended
	int PlaysCounter = 0;

	//The max time in miliseconds that the loop is going to run
	int loopTime = 5000;

	//Objects that the Casino Slots needs to work properly
	//The Factory of Game Objects that populate the game window
	ObjectFactory* objectFactory = nullptr;
	//Timer for counting the time that the game loop is running
	Timer* timer = nullptr;

};

