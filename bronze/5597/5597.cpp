#include <iostream>

using namespace std;

int main() {
	int n[31] = {};

	for (int i=0; i<28; i++) {
		int num;

		cin >> num;

		n[num] = 1;
	}

	for (int i=1; i<=30; i++) {
		if (n[i] == 0) {
			cout << i << '\n';
		}
	}

	return 0;
}