#pragma once
#include "CasinoSlot.h"
#include "ObjectFactory.h"
#include <stdio.h>

/// <summary>
/// Helper class that provides a static function to handle the input of the player
/// </summary>
class KeyboardEventHandler
{
public:
	/// <summary>
	/// Checks the poll of inputs of the player, and calls functions inside the game logic object
	/// Also stops the game engine main loop
	/// </summary>
	/// <param name="isRunning">An address to the boolean value of the Is Running in the Game class</param>
	/// <param name="casinoSlot">Address to the Casino slot Object</param>
	static void HandleInput(bool &isRunning, CasinoSlot& casinoSlot);
};

