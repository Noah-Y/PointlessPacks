#pragma once
#include "Object.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

using namespace std;

class card : public Object
{
private:
	int cardNum;
public:
	card();
	~card();
	void SetCardNum(int num) { cardNum = num; }
	void SetCardTexture(SDL_Renderer *renderer);
};

