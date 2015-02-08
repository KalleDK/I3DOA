#include<iostream>
#include <sstream>

using namespace std;

int h(int key) {
	key = ((key/10)+2) % 13;
	if (key < 0)
		key += 13;
	return key;
}

int main(int argc, char **argv) {
	int key;
	if (argc < 2) {
		return 1;
	}
	istringstream ss(argv[1]);
	if(!(ss >> key)) {
		return 2;
	}
	cout << h(key);
	return 0;
}
