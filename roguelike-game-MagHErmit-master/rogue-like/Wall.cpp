#include "Wall.h"


Wall::Wall(int x, int y, char sym) : GameObject(x, y, sym)
{
}

Wall::~Wall()
{
}

pair<int, int> Wall::GetPos() {
	return GameObject::GetPos();
}

int Wall::DoCollide() {
	return -1;
}