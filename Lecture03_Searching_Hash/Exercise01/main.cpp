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
	cout << argc << endl;
	for (int i=1; i < argc; ++i) {
		cout << " " << argv[i] << " |";
	}
	cout << endl;
	for (int i=1; i < argc; ++i) {
		cout << "----|";
	}
	cout << endl;
	for (int i=1; i < argc; ++i) {
		istringstream ss(argv[i]);
		if(!(ss >> key)) {
			cout << " Error | ";
		} 
		cout << " " << h(key) << " | ";
	}
	cout << endl;
	return 0;
}
