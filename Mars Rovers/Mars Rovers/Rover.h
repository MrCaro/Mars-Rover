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
	Rover(int x, int y, char r) : rover_x{x}, rover_y{y}, rover_rotation{r}
	{
		/*cout << "Rover x-axis position: " << rover_x << endl;
		cout << "Rover y-axis position: " << rover_y << endl;
		cout << "Rover facing: " << rover_rotation << endl;*/
	}

	int *SetPosition()
	{
		return position;
	}

	void UpdatePosition(char instructions[])
	{
		if (instructions[0] == 'M')
		{
			cout << "Moving rover" << endl;
		}

		else
		{
			UpdateRotation(instructions[0]);
		}
	}

	char SetRotation()
	{
		return rover_rotation;
	}

	char UpdateRotation(char rotation)
	{
		int rotate_rover = (rotation == 'L') ? -1 : 1;

		for (int i = 0; i < sizeof(rover_rotationOptions); i++)
		{
			if (rover_rotation == rover_rotationOptions[i])
			{
				i += (rotate_rover);
				rover_rotation = rover_rotationOptions[i];
				cout << "Rover is facing: " << rover_rotation << endl;
				break;
			}
		}

		return rover_rotation;
	}
};
