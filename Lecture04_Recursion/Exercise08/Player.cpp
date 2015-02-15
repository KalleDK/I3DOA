#include "Player.hpp"

using namespace std;

Player::Player() {
	facing = new Compass();
}

void Player::updateArrow() {
	switch(facing->direction)
	{
	case 'n':
		location->state = '^';
		break;
	case 's':
		location->state = 'v';
		break;
	case 'e':
		location->state = '>';
		break;
	case 'w':
		location->state = '<';
		break;
	default:
		break;
	}
}

void Player::turnLeft() {
	facing = facing->left;
	updateArrow();
}

void Player::turnRight() {
	facing = facing->right;
	updateArrow();
}

bool Player::go(char direction) {
	Room* newroom;
	switch(direction)
	{
	case 'n':
		newroom = location->north;
		break;
	case 's':
		newroom = location->south;
		break;
	case 'e':
		newroom = location->east;
		break;
	case 'w':
		newroom = location->west;
		break;
	default:
		newroom = location;
		break;
	}

	if (newroom != NULL && newroom->state != '*') {
		newroom->state = location->state;
		location->state = '0';
		location = newroom;
		return true;
	} else {
		cout << "Illegal move!\n";
		return false;
	}
}

char Player::look(char direction) {
	return location->getConnectedState(direction);
}
char Player::lookLeft() {
	return look(facing->left->direction);
}
char Player::lookRight() {
	return look(facing->right->direction);
}
char Player::lookForward() {
	return look(facing->direction);
}
char Player::lookBackward() {
	return look(facing->back->direction);
}

bool Player::isCompleted() {
	return ((exit_room->state == '^') || (exit_room->state == '>') || (exit_room->state == '<') || (exit_room->state == 'v'));
}
