#pragma once
#include "curses.h"
#include "Map.h"
#include "GameObject.h"

class Game
{
public:
	Game(Map m);
	~Game();

	void GameLoop();
	void WindowRender();

	void HandleInput(chtype);

	
private:
	bool CanMove(map<pair<int, int>, GameObject*>::iterator it, map<pair<int, int>, GameObject*>::iterator end);
	Map _map;
	Knight* _hero;
	WINDOW* _main_window;
	int _max_x;
	int _max_y;
	WINDOW* _hud_window;
	WINDOW* _message_window;
};

