#pragma once
#include <utility>

using namespace std;

class Wall;



class GameObject
{
public:
	GameObject(int x, int y, char sym);
	~GameObject();
	virtual pair<int, int> GetPos();



	int Collide(GameObject* g);





	void SetPos(int y, int x);
	virtual int DoCollide() = 0;
protected:
	
	char _sym;
	int _pos_x;
	int _pos_y;
};
