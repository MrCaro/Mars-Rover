#include <iostream>
#include "Map.h"
#include "Rover.h"

using namespace std;

int main()
{
	/*creating map with number of coordinates desired*/
	Map map(5, 5);
	cout << "Initializing map" << endl;
	
	/*placing rover in starting point*/
	Rover rover(1, 2, 'N');
	map.Set(rover.GetPosition(), rover.GetRotation());
	map.Get();

	cout << endl;

	/*updating position of rover*/
	string instructions = "LMLMLMLMM";
	rover.UpdatePosition(instructions);
	map.Set(rover.GetPosition(), rover.GetRotation());
	rover.GetPosition();
	map.Get();
}
