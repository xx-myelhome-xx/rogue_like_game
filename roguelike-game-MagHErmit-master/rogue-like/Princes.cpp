#include "Princes.h"




int Princes::DoCollide() {
	return 2;
}

pair<int, int> Princes::GetPos() {
	return GameObject::GetPos();
}

Princes::Princes(int x, int y, char sym) : GameObject(x, y, sym)
{
}

Princes::~Princes()
{
}