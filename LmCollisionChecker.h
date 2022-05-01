#pragma once

class LmCollisionChecker
{
public:
	bool CheckCollision(LmCharacter& _char, LmHome& _home)
	{
		return RectCollision(&_char.GetRect(),_home.GetRect());
	}

private:
	bool RectCollision(RECT _rt1, RECT _rt2)
	{
		if((_rt1.right<_rt2.left)&&(_rt1.top<_rt2.bottom))
			return true;
		if((_rt2.right<_rt1.left)&&(_rt2.top<_rt1.bottom))
			return true;

		return false;
	}
};