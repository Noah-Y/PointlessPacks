#pragma once

#include <stdlib.h>
#include <math.h>
#include "pack.h"
#include "Object.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

using namespace std;

class game
{
private:
	//Base
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event ev;
	const int winH = 600;
	const int winW = 800;
	
	//Pos
	SDL_Point mousePos;
	SDL_Rect cursorPos;
	
	//Bools
	bool running = true;
	bool menuUse = true;
	bool openingPack = false;

	//Classes
	Object menuPacks[3];
	pack cheappack;
	pack normalpack;
	pack richpack;

	//Other
	int packType;

public:
	game();
	~game();
	void Loop();
	void MenuLoop();
	void OpeningPackLoop();
	void EventHandler();
	void GetMousePos();
	bool PointCol(int x, int y, SDL_Rect object);
	bool RectCollisionCheck(SDL_Rect object1, SDL_Rect object2);
	bool CirCollisionCheck(SDL_Rect object1, SDL_Rect object2, int radius1, int radius2);
	void Draw(Object object);
	void DrawPtr(Object *object);
};

