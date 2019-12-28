#pragma once
#include "Globals.h"
#include "GameObject.h"

using namespace std;

class Character : public GameObject
{
public:
	Character(int x, int y, char sym, int hp, int dmg, int m_hp);
	~Character();

	virtual void Move(Direction dir);

	virtual pair<int, int> GetPos() override;

	virtual int DoCollide() { return 0; }
	/*int GetHp();
	int GetDamage();*/
	char GetSym();

protected:
	Direction _dir;
	int _hp;
	int _damage;
	int _max_hp;
};

