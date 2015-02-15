#pragma once

#include<iostream>
#include "Room.hpp"
#include "Compass.hpp"

class Player {
public:
	Room* location;
	Room* exit_room;
	Compass* facing;
	bool go(char direction);
	char look(char direction);
	void turnLeft();
	void turnRight();
	char lookLeft();
	char lookRight();
	char lookForward();
	char lookBackward();
	void updateArrow();
	bool isCompleted();
	Player();
};
