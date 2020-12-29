#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Map 
{
private: 
	/*coordinates*/
	int map_x, map_y;

	/*default and custom map coordinate for rover*/
	int map_default[2][2] = { {0, 1}, {1, 1} };
	vector<vector<int>> map_custom;
	
public:
	Map() : map_x{2}, map_y{2}
	{
		for (int i = 0; i < map_x; i++)
		{
			for (int j = 0; j < map_y; j++)
			{
				cout << "[" << map_default[i][j] << "]" << "  ";
			}

			cout << endl;
		}
	}

	Map(int x, int y) : map_x{x}, map_y{y}
	{
		for (int i = 0; i < map_x; i++)
		{
			vector<int>v1;

			for (int j = 0; j < map_y; j++)
			{
				v1.push_back(0);
			}

			map_custom.push_back(v1);
		}

		for (int i = 0; i < map_custom.size(); i++) {
			for (int j = 0; j < map_custom[i].size(); j++)
				cout << map_custom[i][j] << " ";
			cout << endl;
		}
	}

	void Get() 
	{
		for (int i = 0; i < map_custom.size(); i++) {
			for (int j = 0; j < map_custom[i].size(); j++)
				cout << map_custom[i][j] << " ";
			cout << endl;
		}
	}

	void Set(int *rover_position)
	{
		map_custom[rover_position[0]][rover_position[1]] = 1;
	}
};