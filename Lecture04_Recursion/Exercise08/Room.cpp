#include "Room.hpp"

using namespace std;

/* States
  '*' = Wall
  ' ' = Floor
  'E' = Exit
  'P' = Player
*/


Room::Room() : Room('w') {}

Room::Room(char state) {
	this->north = NULL;
	this->south = NULL;
	this->east = NULL;
	this->west = NULL;
	this->state = state;
}

char Room::getConnectedState(char direction) {
	char state = '*';
	switch(direction)
	{
	case 'n':
		if (north != NULL) { state = north->state; }
		break;
	case 's':
		if (south != NULL) { state = south->state; }
		break;
	case 'w':
		if (west != NULL) { state = west->state; }
		break;
	case 'e':
		if (east != NULL) { state = east->state; }
		break;
	default:
		state = '*';
		break;
	}
	return state;
}

void Room::addRoom(Room* &ptr, char state, bool newline) {
	if (ptr == NULL) {
		ptr = new Room(state);
		return;
	}
	if (newline) {
		while(ptr->west != NULL) {ptr = ptr->west;}
		ptr->south = new Room(state);
		ptr->south->north = ptr;
		ptr = ptr->south;
	} else {
		ptr->east = new Room(state);
		ptr->east->west = ptr;
		if ((ptr->north != NULL) && (ptr->north->east != NULL)) {
			ptr->east->north = ptr->north->east;
			ptr->north->east->south = ptr->east;
		}
		ptr = ptr->east;
	}
}

void Room::print() {
	Room* ptr = this;
	if (ptr == NULL) {cout << "No Room\n"; return;}
	while(ptr->west != NULL) {ptr = ptr->west;}
	while(ptr->north != NULL) {ptr = ptr->north;}
	while(ptr != NULL) {
		do {
			cout << ptr->state;
			if (ptr->east != NULL) {
				ptr = ptr->east;
				if (ptr->east == NULL) { cout << ptr->state; }
			}
		} while(ptr->east != NULL);
		cout << "\n";
		while(ptr->west != NULL) {ptr = ptr->west;}
		ptr = ptr->south;
	}
	cout << "\n";
}
