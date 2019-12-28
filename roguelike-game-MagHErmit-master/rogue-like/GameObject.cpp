#include "GameObject.h"
#include "Wall.h"




GameObject::GameObject(int x, int y,  char sym) : _pos_x(x), _pos_y(y) , _sym(sym)
{
}

GameObject::~GameObject()
{
}

pair<int, int> GameObject::GetPos() {
	return { _pos_x, _pos_y };
}

void GameObject::SetPos(int y, int x) {
	if (_pos_x + x < 0 || _pos_y + y < 0) return;
	_pos_x += x; _pos_y += y;
}

int GameObject::Collide(GameObject* g) {
	return g->DoCollide();
}

