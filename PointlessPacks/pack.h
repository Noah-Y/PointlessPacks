#pragma once
#include <SDL.h>

class pack
{
private:
	int cardNum;
	SDL_Rect pos, crop;
public:
	pack();
	~pack();
	void SetPos(int x, int y, int w, int h);
	void SetCrop(int x, int y, int w, int h);
	void SetCardNum(int num) { cardNum = num; }
};

