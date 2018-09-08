#include "game.h"

game::game()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	IMG_Init(IMG_INIT_PNG);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	window = SDL_CreateWindow("PointlessPacks", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, winW, winH, SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	srand(SDL_GetTicks());
	running = true;
	menuUse = true;

	//Pack Choosing
	menuPacks[0].SetPos(40, 320, 120, 160);
	menuPacks[1].SetPos(340, 320, 120, 160);
	menuPacks[2].SetPos(640, 320, 120, 160);
	menuPacks[0].SetCrop(0, 0, 700, 950);
	menuPacks[1].SetCrop(0, 0, 700, 950);
	menuPacks[2].SetCrop(0, 0, 700, 950);
	menuPacks[0].SetTexture("cheappack.png", renderer);
	menuPacks[1].SetTexture("normalpack.png", renderer);
	menuPacks[2].SetTexture("richpack.png", renderer);

	//Pack Opening
	normalpack.SetCardNum(10);
	richpack.SetCardNum(15);
	cheappack.SetTexture("cheappack.png", renderer);
	normalpack.SetTexture("normalpack.png", renderer);
	richpack.SetTexture("richpack.png", renderer);

	Loop();
}


game::~game()
{
	for (int num = 0; num < 3; num++)
	{
		menuPacks[num].~Object();
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_CloseAudio();
	IMG_Quit();
	SDL_Quit();
}

void game::Loop()
{
	while (running)
	{
		MenuLoop();
		OpeningPackLoop();
		EventHandler();
	}
}

void game::MenuLoop()
{
	while (menuUse)
	{
		//Events
		GetMousePos();
		while (SDL_PollEvent(&ev))
		{
			if (ev.type == SDL_QUIT)
			{
				running = false;
				menuUse = false;
				openingPack = false;
			}
			if (RectCollisionCheck(cursorPos, menuPacks[0].GetPos()) == true)
			{
				if (ev.type == SDL_MOUSEBUTTONDOWN)
				{
					if (ev.button.button == SDL_BUTTON_LEFT)
					{
						menuUse = false;
						cheappack.SetCards(renderer);
						cheappack.SetPos(212, 50, 375, 500);
						cheappack.SetCrop(0, 0, 700, 950);
						cheappack.Opened = 0;
						openingPack = true;
						packType = 1;
					}
				}
			}
			if (RectCollisionCheck(cursorPos, menuPacks[1].GetPos()) == true)
			{
				if (ev.type == SDL_MOUSEBUTTONDOWN)
				{
					if (ev.button.button == SDL_BUTTON_LEFT)
					{
						menuUse = false;
						normalpack.SetCards(renderer);
						normalpack.SetPos(212, 50, 375, 500);
						normalpack.SetCrop(0, 0, 700, 950);
						normalpack.Opened = 0;
						openingPack = true;
						packType = 2;
					}
				}
			}
			if (RectCollisionCheck(cursorPos, menuPacks[2].GetPos()) == true)
			{
				if (ev.type == SDL_MOUSEBUTTONDOWN)
				{
					if (ev.button.button == SDL_BUTTON_LEFT)
					{
						menuUse = false;
						richpack.SetCards(renderer);
						richpack.SetPos(212, 50, 375, 500);
						richpack.SetCrop(0, 0, 700, 950);
						richpack.Opened = 0;
						openingPack = true;
						packType = 3;
					}
				}
			}
		}
		//Render
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		for (int num = 0; num < 3; num++)
		{
			Draw(menuPacks[num]);
		}
		SDL_RenderPresent(renderer);
	}
}

void game::OpeningPackLoop()
{
	while (openingPack)
	{
		GetMousePos();
		while (SDL_PollEvent(&ev))
		{
			if (ev.type == SDL_QUIT)
			{
				running = false;
				menuUse = false;
				openingPack = false;
			}
			if (ev.type == SDL_MOUSEBUTTONDOWN)
			{
				if (ev.button.button == SDL_BUTTON_LEFT)
				{
					switch (packType)
					{
					case 1:
						cheappack.Opened++;
						break;
					case 2:
						normalpack.Opened++;
						break;
					case 3:
						richpack.Opened++;
						break;
					default:
						break;
					}
				}
			}
		}

		//Render
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		switch (packType)
		{
		case 1:
			for (int num = 0; num < 5; num++)
			{
				if (num < cheappack.Opened)
				{
					Draw(cheappack.cards[num]);
				}
			}
			if (cheappack.Opened < 1)
			{
				Draw(cheappack);
			}
			if (cheappack.Opened > 5)
			{
				openingPack = false;
				menuUse = true;
			}
			break;
		case 2:
			for (int num = 0; num < 10; num++)
			{
				if (num < normalpack.Opened)
				{
					Draw(normalpack.cards[num]);
				}
			}
			if (normalpack.Opened < 1)
			{
				Draw(normalpack);
			}
			if (normalpack.Opened > 10)
			{
				openingPack = false;
				menuUse = true;
			}
			break;
		case 3:
			for (int num = 0; num < 15; num++)
			{
				if (num < richpack.Opened)
				{
					Draw(richpack.cards[num]);
				}
			}
			if (richpack.Opened < 1)
			{
				Draw(richpack);
			}
			if (richpack.Opened > 15)
			{
				openingPack = false;
				menuUse = true;
			}
			break;
		default:
			break;
		}
		
		SDL_RenderPresent(renderer);
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


bool game::PointCol(int x, int y, SDL_Rect object)
{
	if (x > object.x && y > object.y && x < object.x + object.w && y < object.y + object.h)
	{
		return true;
	}
	return false;
}

bool game::RectCollisionCheck(SDL_Rect object1, SDL_Rect object2)
{
	if (PointCol(object1.x, object1.y, object2) == true ||
		PointCol(object1.x + object1.w, object1.y, object2) == true ||
		PointCol(object1.x, object1.y + object1.h, object2) == true ||
		PointCol(object1.x + object1.w, object1.y + object1.h, object2) == true)
	{
		return true;
	}
	return false;
}

bool game::CirCollisionCheck(SDL_Rect object1, SDL_Rect object2, int radius1, int radius2)
{
	if (radius1 == 0)
	{
		radius1 = object1.w / 2;
	}
	if (radius2 == 0)
	{
		radius2 = object2.w / 2;
	}
	float deltaX = (object1.x + (object1.w / 2)) - (object2.x + (object2.w / 2));
	float deltaY = (object1.y + (object1.h / 2)) - (object2.y + (object2.h / 2));
	float distance = (sqrt((deltaX*deltaX) + (deltaY*deltaY)));
	if (distance <= radius1 + radius2)
	{
		return true;
	}
	return false;
}

void game::GetMousePos()
{
	SDL_GetMouseState(&mousePos.x, &mousePos.y);
	cursorPos = { mousePos.x, mousePos.y, 10, 10 };
}


void game::Draw(Object object)
{
	SDL_Rect pos = object.GetPos();
	SDL_Rect crop = object.GetCrop();
	SDL_RenderCopy(renderer, object.GetTexture(), &crop, &pos);
}