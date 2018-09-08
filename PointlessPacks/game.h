#pragma once

#include <iostream>
#include <SDL.h>

using namespace std;

class game
{
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event ev;
	const int winH = 600;
	const int winW = 800;
	bool running = true;
public:
	game();
	~game();
	void Loop();
	void EventHandler();
};

