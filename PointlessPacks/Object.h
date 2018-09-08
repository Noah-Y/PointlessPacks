#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>

using namespace std;

class Object
{
private:
	SDL_Rect pos, crop; 
	SDL_Texture *texture;
public:
	Object();
	~Object();
	void SetPos(int x, int y, int w, int h);
	void SetCrop(int x, int y, int w, int h);
	void SetTexture(string filename, SDL_Renderer* renderer);
	SDL_Rect GetPos() const { return pos; }
	SDL_Rect GetCrop() const { return crop; }
	SDL_Texture *GetTexture() const { return texture; }
};

