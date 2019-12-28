#include <iostream>
#include <vector>
#include "Map.h"

#include "Factory.h"
using namespace std;
char path[] = "base_map.txt";

Factory fact;


Map::Map()
{

	ifstream in(path);
	for (size_t i = 0; !in.eof(); i++)
	{
		vector<char> tmp;
		char ch;
		in.get(ch);
		do
		{
			if(ch != '.')
				switch (ch)
				{
				case '@':
					_kn = new Knight(tmp.size(), i, '@');
					ch = '.';
					break;
				default:
					_g_obj.insert({ { tmp.size(), i }, fact.Create(ch, tmp.size(), i) });
					break;
				}
			tmp.push_back(ch);
			in.get(ch);
			
		} while (!in.eof() && ch != '\n');
		_map.push_back(tmp);
	}
}


pair<int, int> Map::GetSize() {
	return { _map[0].size(), _map.size() };
}

Knight* Map::RetKnight() {
	return _kn;
}

char Map::GetChar(int y, int x) {
	if (x < 0 || y < 0 || y > _map.size() - 1 || x > _map[y].size() - 1)
		return '%';
	return _map[y][x];
}

map<pair<int, int>, GameObject*>::iterator Map::IsBe(int x, int y) {
	return _g_obj.find({ x, y });
}

Map::~Map()
{
}