#include "Character.h"
using namespace std;

Character::Character(int x, int y, char sym, int hp, int dmg, int m_hp) : GameObject(x, y, sym), _hp(hp), _damage(dmg), _max_hp(m_hp)
{
	_dir = N;
}

Character::~Character()
{

}

pair<int, int> Character::GetPos() {
	return GameObject::GetPos();
}

void Character::Move(Direction dir) {
	switch (dir)
	{
	case N:
		GameObject::SetPos(-1, 0);
		break;
	case S:
		GameObject::SetPos(1, 0);
		break;
	case W:
		GameObject::SetPos(0, -1);
		break;
	case E:
		GameObject::SetPos(0, 1);
		break;
	default:
		break;
	}
}

char Character::GetSym() { return _sym; }