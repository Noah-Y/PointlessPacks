#include "card.h"



card::card()
{
}


card::~card()
{
}

void card::SetCardTexture(SDL_Renderer *renderer)
{
	switch (cardNum)
	{
	case 1:
		SetTexture("1card.png", renderer);
		break;
	case 2:
		SetTexture("2card.png", renderer);
		break;
	case 3:
		SetTexture("3card.png", renderer);
		break;
	case 4:
		SetTexture("4card.png", renderer);
		break;
	case 5:
		SetTexture("5card.png", renderer);
		break;
	case 6:
		SetTexture("6card.png", renderer);
		break;
	case 7:
		SetTexture("7card.png", renderer);
		break;
	case 8:
		SetTexture("8card.png", renderer);
		break;
	default:
		break;
	}
}