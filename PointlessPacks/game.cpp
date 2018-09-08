#include "game.h"



game::game()
{
	window = SDL_CreateWindow("PointlessPacks", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, winW, winH, SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	srand(SDL_GetTicks());
	running = true;
	Loop();
}


game::~game()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void game::Loop()
{
	while (running)
	{
		EventHandler();
	}
}

void game::EventHandler()
{
	while (SDL_PollEvent(&ev))
	{
		if (ev.type == SDL_QUIT)
		{
			running = false;
		}
	}
}