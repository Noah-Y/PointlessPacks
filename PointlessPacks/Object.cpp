#include "Object.h"



Object::Object()
{

}

Object::~Object()
{
}

void Object::SetPos(int x, int y, int w, int h)
{
	pos.x = x;
	pos.y = y;
	pos.w = w;
	pos.h = h;
}

void Object::SetCrop(int x, int y, int w, int h)
{
	crop.x = x;
	crop.y = y;
	crop.w = w;
	crop.h = h;
}

void Object::SetTexture(string filename, SDL_Renderer* renderer)
{
	SDL_Surface *surface = IMG_Load(filename.c_str());
	texture = SDL_CreateTextureFromSurface(renderer, surface);
}
