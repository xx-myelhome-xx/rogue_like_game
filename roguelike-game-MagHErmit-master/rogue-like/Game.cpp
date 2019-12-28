#include "curses.h"
#include "Game.h"
using namespace std;


Game::Game(Map m) : _map(m) {
	_hero = _map.RetKnight();
	_main_window = newwin(0, 0, 0, 0);
	getmaxyx(_main_window, _max_y, _max_x);
	_max_y -= 5;
	_hud_window = subwin(_main_window, 5, _max_x, _max_y, 0);
	box(_hud_window, 0, 0);
	_message_window = subwin(_hud_window, 5, _max_x - 45, _max_y, 45);
	box(_message_window, 0, 0);

	WindowRender();

	touchwin(_main_window);
	refresh();
	wrefresh(_hud_window);
	wrefresh(_message_window);
}


void Game::WindowRender() {
	short p_x, p_y;

	p_x = _hero->GetPos().first; p_y = _hero->GetPos().second;
	int y_offset = p_y - (_max_y / 2), x_offset = p_x - (_max_x / 2);
	pair<int, int> size = _map.GetSize();

	/*if (is_termresized()) {
		resize_term(0, 0);
	}*/

	//print static elements of map

	for (int y = 0; y < _max_y && y < size.second; y++) {
		for (int x = 0; x < _max_x && x < size.first; x++) {
			char c = _map.GetChar(y_offset + y, x_offset + x);
			mvprintw(y, x, "%c", c);
		}
	}

	//print dynamic elements

	mvprintw(p_y - y_offset, p_x - x_offset, "%c", _hero->GetSym());


}

bool Game::CanMove(map<pair<int, int>, GameObject*>::iterator it, map<pair<int, int>, GameObject*>::iterator end) {
	if (it == end) return true;
	if (_hero->Collide(it->second) == -1) return false;
	if (_hero->Collide(it->second) == 2) {
		exit(0);
		return false;
	}
	return false;
}

void Game::HandleInput(chtype c) {
	switch (c) {
	case KEY_UP:
		if (CanMove(_map.IsBe(_hero->GetPos().first, _hero->GetPos().second - 1), _map.End())) {
			_hero->Move(N);
		}
		break;
	case KEY_DOWN:

		if (CanMove(_map.IsBe(_hero->GetPos().first, _hero->GetPos().second + 1), _map.End())) {
			_hero->Move(S);
		}
		break;
	case KEY_LEFT:

		if (CanMove(_map.IsBe(_hero->GetPos().first - 1, _hero->GetPos().second), _map.End())) {
			_hero->Move(W);
		}
		break;
	case KEY_RIGHT:

		if (CanMove(_map.IsBe(_hero->GetPos().first + 1, _hero->GetPos().second), _map.End())) {
			_hero->Move(E);
		}
		break;
	}
}

void Game::GameLoop() {
	while (true)
	{
		HandleInput(getch());
		WindowRender();
	}
}


Game::~Game() {}