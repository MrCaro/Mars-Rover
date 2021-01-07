#pragma once
#include <iostream>
#include "Map.h"

class Rover
{
private:
	//position of rover in coordinates of map
	int rover_x, rover_y;
	int rover_position[2] = { rover_x, rover_y };

	//facing direction of rover
	char rover_rotation;
	char rover_rotationOptions[4] = { 'N', 'E', 'S', 'W' };

public:
	Rover(int x, int y, char r) : rover_x{x}, rover_y{y}, rover_rotation{r}
	{
		//init my rover object
	}

	int *GetPosition()
	{
		cout << "(" << rover_position[0] << ", " << rover_position[1] << ")" << endl;
		return rover_position;
	}

	char GetRotation()
	{
		return rover_rotation;
	}

	void SetPosition(string instructions)
	{
		for (int i = 0; i < instructions.size() ; i++)
		{
			if (instructions[i] == 'M')
			{
				if (rover_rotation == 'W' || rover_rotation == 'E')
				{
					rover_x += (rover_rotation == 'W') ? -1 : 1;
				}

				else
				{
					rover_y += (rover_rotation == 'S') ? -1 : 1;
				}
			}

			else
			{
				SetRotation(instructions[i]);
			}
		}

		rover_position[0] = rover_x;
		rover_position[1] = rover_y;
	} 

	char SetRotation(char rotation)
	{
		int rotate_rover = (rotation == 'L') ? -1 : 1;

		for (int i = 0; i < sizeof(rover_rotationOptions); i++)
		{
			if (rover_rotation == rover_rotationOptions[i])
			{
				i += (rotate_rover);
				//handling whenever turn is negative (N -> W) and greater than array size whenever (W -> N)
				i = (i < 0) ? (sizeof(rover_rotationOptions) - 1) : i;
				i = (i == sizeof(rover_rotationOptions)) ? 0 : i;

				rover_rotation = rover_rotationOptions[i];
				break;
			}
		}
		
		return rover_rotation;
	}
};
