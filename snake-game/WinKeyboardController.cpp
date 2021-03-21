#include "WinKeyboardController.h"

bool WinKeyboardController::isKeyPressed(int key)
{
	bool keyPressed = (GetAsyncKeyState(key) & 0x0001) != 0;
	if (keyPressed)
	{
		pressedKey = key;
		anyPressed = true;
	}
	else
	{
		anyPressed = false;
	}

	return keyPressed;
}

bool WinKeyboardController::isSpacePressed()
{
	return isKeyPressed(VK_SPACE);
}

bool WinKeyboardController::isUpPressed()
{
	return isKeyPressed(VK_UP);
}

bool WinKeyboardController::isDownPressed()
{
	return isKeyPressed(VK_DOWN);
}

bool WinKeyboardController::isLeftPressed()
{
	return isKeyPressed(VK_LEFT);
}

bool WinKeyboardController::isRightPressed()
{
	return isKeyPressed(VK_RIGHT);
}
