#include "Keyboard.h"

bool Keyboard::ReadKeyPressed(unsigned char keycode)
{
	return keystates.test(keycode);
}

void Keyboard::SetKeyPressState(unsigned char keycode)
{
	keystates.set(keycode);
}