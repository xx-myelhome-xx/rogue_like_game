#pragma once
#include <map>
#include "Princes.h"

using namespace std;





class aCreator
{
public:
	aCreator() {}
	virtual GameObject* Create(char sym, int x, int y) = 0;
	~aCreator() {}

private:

};


class CreatorPrinces : public aCreator
{
public:
	virtual GameObject* Create(char sym, int x, int y) {
		return new Princes(sym, x, y);
	}

private:
	 
};

class CreatorWall : public aCreator
{
public:
	virtual GameObject* Create(char sym, int x, int y) {
		return new Wall(sym, x, y);
	}

private:

};

class Factory
{
public:
	Factory();
	~Factory();
	GameObject* Create(char sym, int x, int y) {
		return fmap[sym]->Create(sym, x, y);
	}

private:
	map<char, aCreator*> fmap{
		make_pair('P', new CreatorPrinces()),
		make_pair('#', new CreatorWall())
	};
};


Factory::Factory()
{

}

Factory::~Factory()
{
}
