//void cubes(int n) {
//	for (int i = 1; i <= n; i++)
//		cout << i * i * i << ’’;
//	}
// }

#include <iostream>
#include <string>

using namespace std;

bool _palidrome(string str, int pos) {
	if ((str.length() - 2*pos) <= 1) {
		return true;
	}

	if (str[pos] == str[str.length()-pos-1]) {
		return true && _palidrome(str, pos+1);
	} else {
		return false;
	}

}

bool palidrome(string str) {
	return	_palidrome(str, 0);
}

int main(void) {
	cout << palidrome("KaololaK") << endl;
	cout << palidrome("KaollolaK") << endl;
	cout << palidrome("flaffalf") << endl;
	cout << palidrome("flaf1falf") << endl;
}
