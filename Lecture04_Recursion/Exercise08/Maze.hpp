#pragma once
#include <iostream>
#include <fstream>
#include "Room.hpp"
#include "Player.hpp"

class Maze {
public:
	Room* maze;
	Player* p;
	Room* exit_room;

	Maze(const char * file);
	void print();
	bool isCompleted();
};
