#pragma once

#include "Character.h"

class Princes : public GameObject
{
public:
	Princes(int x, int y, char sym);
	~Princes();

	virtual int DoCollide();
	pair<int, int> GetPos() override;
private:

};

