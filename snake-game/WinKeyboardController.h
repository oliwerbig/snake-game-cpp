#pragma once
#include "Controller.h"
#include <Windows.h>
class WinKeyboardController
	: public Controller
{
public:
	bool isKeyPressed(int key);
	bool isSpacePressed();
	bool isUpPressed();
	bool isDownPressed();
	bool isLeftPressed();
	bool isRightPressed();
};

