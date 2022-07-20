#pragma once
#include "CasinoSlot.h"
#include "ObjectFactory.h"
#include <stdio.h>

class KeyboardEventHandler
{
public:
	static void HandleInput(bool &isRunning, CasinoSlot& casinoSlot);
};

