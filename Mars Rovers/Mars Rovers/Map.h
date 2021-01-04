#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Map 
{
private: 
	//map coordinates
	int map_x, map_y;

	//default and custom maps coordinate for rover
	int map_default[2][2] = { {0, 0}, {0, 0} }; //TODO: change default map to char so is more consistent
	vector<vector<char>> map_custom;
	
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
			vector<char>v1;

			for (int j = 0; j < map_y; j++)
			{
				v1.push_back('0');
			}

			map_custom.push_back(v1);
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

	void Set(int *rover_position, char rover_rotation)
	{
		map_custom[rover_position[0]][rover_position[1]] = rover_rotation;
	}
};