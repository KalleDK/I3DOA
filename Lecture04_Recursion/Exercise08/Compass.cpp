#include "Compass.hpp"

Compass::Compass() {
	this->direction = 'n';
	Compass* south = new Compass('s');
	Compass* east = new Compass('e');
	Compass* west = new Compass('w');
	this->right = east;
	this->left = west;
	this->back = south;
	east->right = south;
	east->left = this;
	east->back = west;
	south->left = east;
	south->right = west;
	south->back = this;
	west->left = south;
	west->right = this;
	west->back = east;
}

Compass::Compass(char direction) {
	this->direction = direction;
}
