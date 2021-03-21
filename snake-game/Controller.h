#pragma once
class Controller
{
protected:
	bool anyPressed = false;
	int pressedKey = 0;
public:
	virtual bool isKeyPressed(int key) = 0;
	virtual bool isSpacePressed() = 0;
	virtual bool isUpPressed() = 0;
	virtual bool isDownPressed() = 0;
	virtual bool isLeftPressed() = 0;
	virtual bool isRightPressed() = 0;

	bool isAnyPressed() { return anyPressed; }
	void setAnyPressed(bool anyPressed) { this->anyPressed = anyPressed; }
};

