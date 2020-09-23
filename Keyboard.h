#pragma once
#include <queue>
#include <bitset>
#include <optional>

class Keyboard
{
	friend class Window;
public:
	bool ReadKeyPressed(unsigned char keycode);
	void SetKeyPressState(unsigned char keycode);

private:
	std::bitset<256> keystates;
};