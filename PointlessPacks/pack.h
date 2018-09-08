#pragma once
#include <cstdlib>
#include "Object.h"
#include "card.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

using namespace std;

class pack : public Object
{
private:
	int cardAmount;
public:
	pack();
	~pack();
	void SetCardNum(int num) { cardAmount = num; }
	void SetCards(SDL_Renderer *renderer);
	card cards[15];
	int Opened = 0;
};

