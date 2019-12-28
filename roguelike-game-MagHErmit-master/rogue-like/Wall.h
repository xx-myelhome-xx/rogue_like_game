#pragma once
#include "GameObject.h"

class Wall : public GameObject
{
public:
	Wall(int x, int y, char sym);
	~Wall();

	pair<int, int> GetPos() override;
	virtual int DoCollide();

private:

};

