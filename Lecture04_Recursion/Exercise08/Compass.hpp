#pragma once

class Compass {
public:
	char direction;
	Compass* left;
	Compass* right;
	Compass* back;
	Compass();
	Compass(char direction);
};
