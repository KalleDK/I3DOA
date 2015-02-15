#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include "Room.hpp"
#include "Maze.hpp"
#include "Player.hpp"

using namespace std;

void wait() {
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void find_exit(Player* p) {
	char ch;
	if(p->lookLeft() != '*') { p->turnLeft(); p->location->print(); wait(); }
	while(p->lookForward() == '*') { p->turnRight(); p->location->print(); wait();}
	p->go(p->facing->direction);
	p->location->print();
	wait();
	if(p->isCompleted()) { cout << "We found the exit\n"; return; }
	find_exit(p);
}


int main(void) {
	Maze* m = new Maze("maze.txt");
	Player* p = m->p;
	find_exit(p);
	return 0;
}
