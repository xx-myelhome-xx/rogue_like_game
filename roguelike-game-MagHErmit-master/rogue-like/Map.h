#pragma once
#include <fstream>
#include <vector>
#include <map>
#include "Wall.h"
#include "Knight.h"
#include "Princes.h"
using namespace std;

class Map
{
public:

	Map();
	~Map();

	pair<int, int> GetSize();

	char GetChar(int y, int x);
	Knight* RetKnight();

	map<pair<int, int>, GameObject*>::iterator IsBe(int x, int y);
	map<pair<int, int>, GameObject*>::iterator End() {
		return _g_obj.end();
	}

private:
	vector<vector<char>> _map;
	map<pair<int, int>, GameObject*> _g_obj;
	Knight* _kn;
};

