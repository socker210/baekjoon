#include <iostream>

using namespace std;

int main() {
	int N[6] = {1, 1, 2, 2, 2, 8}, n;

	for (int i=0; i<6; i++) {
		cin >> n;

		cout << N[i] - n << ' ';
	}

	return 0;
}