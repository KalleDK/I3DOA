//void cubes(int n) {
//	for (int i = 1; i <= n; i++)
//		cout << i * i * i << ’’;
//	}
// }

#include <algorithm>
#include <string>
#include <iostream>
#include <cctype>

bool _palidrome(std::string str, int fpos) {
	if (fpos >= (str.length()/2)) {
		return true;
	}
	if (str[fpos] == str[str.length()-1-fpos]) {
		return true && _palidrome(str, fpos+1);
	} else {
		return false;
	}

}

bool palidrome(std::string str) {
	str.erase(std::remove_if(str.begin(), str.end(), [](char ch){return !isalpha(ch);}), str.end());
	return	_palidrome(str, 0);
}

int main(void) {
	std::cout << palidrome("KaololaK") << std::endl;
	std::cout << palidrome("KaollolaK") << std::endl;
	std::cout << palidrome("fl' affalf") << std::endl;
	std::cout << palidrome("flaf1falf") << std::endl;
}
