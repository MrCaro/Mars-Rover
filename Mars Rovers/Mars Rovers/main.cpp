#include <iostream>
#include "Map.h"
#include "Rover.h"

using namespace std;

int main()
{
	cout << "Creating map 5x5" << endl;
	Map map(5, 5);

	cout << endl;

	cout << "Accessing map" << endl;
	map.Get();
	
	cout << endl;

	Rover rover(1, 2, 'N');
	map.Set(rover.SetPosition());

	map.Get();
}
