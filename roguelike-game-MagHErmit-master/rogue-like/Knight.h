#pragma once

#include "Character.h"

class Knight : public Character
{
public:
	Knight(int x, int y, char sym, int hp = 0, int dmg = 0, int m_hp = 0);
	~Knight();

	pair<int, int> GetPos();

	void Move(Direction dir);
	

	//void Move(Direction dir, Map* m);
private:

};

