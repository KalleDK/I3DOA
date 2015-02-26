//void cubes(int n) {
//	for (int i = 1; i <= n; i++)
//		cout << i * i * i << ’’;
//	}
// }

#include <iostream>
#include <string>

using namespace std;

bool isvalidChar(char c) {
	return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')) || ((c >= '0') && (c <= '9'));
}

bool _palidrome(string str, int fpos, int epos) {
	while ((fpos < epos) && (!isvalidChar(str[fpos]))) {
		++fpos;
	} 
	while ((fpos < epos) && (!isvalidChar(str[epos]))) {
		--epos;
	} 
	if (epos <= fpos) {
		return true;
	}
	if (str[fpos] == str[epos]) {
		return true && _palidrome(str, fpos+1, epos-1);
	} else {
		return false;
	}

}

bool palidrome(string str) {
	return	_palidrome(str, 0, str.length()-1);
}

int main(void) {
	cout << palidrome("KaololaK") << endl;
	cout << palidrome("KaollolaK") << endl;
	cout << palidrome("fl' affalf") << endl;
	cout << palidrome("flaf1falf") << endl;
}
