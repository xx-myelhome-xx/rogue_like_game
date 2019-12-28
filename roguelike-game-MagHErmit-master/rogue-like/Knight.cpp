#include "Knight.h"


Knight::Knight(int x, int y, char sym, int hp, int dmg, int m_hp) : Character(x, y, sym, hp, dmg, m_hp)
{
}

Knight::~Knight()
{
}

pair<int, int> Knight::GetPos() {
	return Character::GetPos();
}

void Knight::Move(Direction dir) {
	Character::Move(dir);
}