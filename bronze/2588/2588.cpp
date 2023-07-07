#include <iostream>

using namespace std;

int main() {
	int a, b, n;

	cin >> a >> b;

	n = a * b;

	for (int i=0; i<3; i++) {
		cout << a * (b % 10) << '\n';

		b = b / 10;
	}

	cout << n;

	return 0;
}


