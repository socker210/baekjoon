#include <iostream>

using namespace std;

int main() {
	int a, b, c;

	cin >> a >> b >> c;

	if (a == b && b == c) {
		cout << 10000 + a * 1000;
	} else if (a == b || a == c || b == c) {
		cout << 1000 + (a == b || a == c ? a : b) * 100;
	} else {
		cout << (a > b ? (a > c ? a : c) : (b > c ? b : c)) * 100;
	}

	return 0;
}