#pragma once
#include <iostream>

class Room {
public:
	Room* north;
	Room* south;
	Room* east;
	Room* west;
	char state;

	Room();
	Room(char state);
	char getConnectedState(char direction);
	static void addRoom(Room* &ptr, char state, bool newline = false);
	void print();
};
