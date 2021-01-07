#include <iostream>
#include <string>
#include <vector>
#include "Map.h"
#include "Rover.h"

using namespace std;

int main()
{
	/*creating map with number of coordinates desired*/
	Map map(5, 5);
	cout << "Initializing map" << endl;
	
	/*placing rover in starting point*/
	Rover rover(3, 3, 'E');
	map.Set(rover.GetPosition(), rover.GetRotation());

	cout << endl;

	/*updating position of rover*/
	string instructions = "MMRMMRMRRM";
	rover.SetPosition(instructions);
	map.Set(rover.GetPosition(), rover.GetRotation());

	string line;
	vector<string> input;
	int i = 0;

	while (getline(cin, line))
	{
		if (line == "S")
		{
			break;
		}

		input.push_back(line);
	}

	cout << input[0];
	system("pause");
}
