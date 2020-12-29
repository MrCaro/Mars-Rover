#pragma once
#include <iostream>
#include "Map.h"

class Rover
{
private:
	/*position of rover in coordinates of map*/
	int rover_x, rover_y;
	int position[2] = { rover_x, rover_y };

	/*facing direction of rover*/
	char rover_rotation;
	char rover_rotationOptions[4] = { 'N', 'E', 'S', 'W' };


public:
	Rover(int x, int y, char rotation) : rover_x{x}, rover_y{y}, rover_rotation{rotation}
	{
		cout << "Rover x-axis position: " << rover_x << endl;
		cout << "Rover y-axis position: " << rover_y << endl;
		cout << "Rover facing: " << rover_rotation << endl;
	}

	int *SetPosition()
	{
		return position;
	}

	char SetRotation()
	{

	}
};
