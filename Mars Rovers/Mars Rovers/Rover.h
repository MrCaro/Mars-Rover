#pragma once
#include <iostream>
#include "Map.h"

class Rover
{
private:
	/*position of rover in coordinates of map*/
	int rover_x, rover_y;
	int rover_position[2] = { rover_x, rover_y };

	/*facing direction of rover*/
	char rover_rotation;
	char rover_rotationOptions[4] = { 'N', 'E', 'S', 'W' };

public:
	Rover(int x, int y, char r) : rover_x{x}, rover_y{y}, rover_rotation{r}
	{
		//init my rover object
	}

	int *GetPosition()
	{
		return rover_position;
	}

	char GetRotation()
	{
		return rover_rotation;
	}

	void UpdatePosition(string instructions)
	{
		for (int i = 0; i < instructions.size() ; i++)
		{
			if (instructions[i] == 'M')
			{
				cout << "Moving rover" << endl;
			}

			else
			{
				RotateRover(instructions[i]);
			}
		}
	}

	int MoveRover()
	{
		return 0;
	}

	char RotateRover(char rotation)
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
				/*cout << "Rover is now facing: " << rover_rotation << endl;*/
				break;
			}
		}
		
		return rover_rotation;
	}
};
