#pragma once
#include <queue>
#include <bitset>
#include <optional>

class Keyboard
{
public:
	bool ReadKeyPressed(unsigned char keycode);
	void SetKeyPressState(unsigned char keycode);

	static constexpr unsigned int nKeys = 256u;
	std::bitset<nKeys> keystates;
private:
	
	
};