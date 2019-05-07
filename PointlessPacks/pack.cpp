#include "pack.h"

pack::pack()
{
	cardAmount = 5;
}


pack::~pack()
{
}

void pack::SetCards(SDL_Renderer *renderer)
{
	srand(SDL_GetTicks());
	for (int num = 0; num < cardAmount; num++)
	{
		int randNum = rand() % 15 + 1;
		card *cardClass = new card;
		cardClass->SetCardNum(randNum);
		cardClass->SetCardTexture(renderer);
		cardClass->SetPos( 250, 100, 300, 400 );
		cardClass->SetCrop(0, 0, 600, 800);
		cards[num] = *cardClass;
		free(cardClass);
		cardClass->~card();
	}
}