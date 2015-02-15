#include "Maze.hpp"

using namespace std;

Maze::Maze(const char * file) {
	ifstream ifs(file);
	if (ifs.is_open()) {
		char ch;
		bool newline = false;
		ch = ifs.get();
		while (ifs.good()) {
			if (ch == '\n') {
				newline = true;
			} else {
				maze->addRoom(maze, ch, newline);
				newline = false;
			}
			if (ch == 'P') {
				p = new Player; 
				p->location = maze; 
				maze->state = '^';
			}
			if (ch == 'F') {exit_room = maze;}
			ch = ifs.get();
		}
		p->exit_room = exit_room;
		maze->print();
	} else {
		cout << "Error opening file\n";
	}
}

void Maze::print() {
	maze->print();
}

bool Maze::isCompleted() {
	return ((exit_room->state == '^') || (exit_room->state == '>') || (exit_room->state == '<') || (exit_room->state == 'v'));
}
