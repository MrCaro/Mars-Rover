#include <iostream>
#include "Map.h"
#include "Rover.h"

using namespace std;

int main()
{
	/*creating map with number of coordinates desired*/
	Map map(5, 5);
	cout << "Init empty map" << endl;
	map.Get();
	
	cout << endl;

	/*placing rover in starting point*/
	Rover rover(1, 2, 'E');
	map.Set(rover.SetPosition(), rover.SetRotation());
	map.Get();

	/*updating position of rover*/
	char array[] = { 'L' };
	rover.UpdatePosition(array);
	map.Set(rover.SetPosition(), rover.SetRotation());
	map.Get();
}
