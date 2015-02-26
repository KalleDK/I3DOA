//void cubes(int n) {
//	for (int i = 1; i <= n; i++)
//		cout << i * i * i << ’’;
//	}
// }

#include <iostream>

using namespace std;

void cubes(int n) {
	if (n == 0)
		return;

	cubes(n-1);
	cout << n * n * n << ' ';
}

int main(void) {
	cubes(8);
}
