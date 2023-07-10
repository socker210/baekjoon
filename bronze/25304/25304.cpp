#include <iostream>

using namespace std;

int main() {
	int total, n, sum = 0;

	cin >> total >> n;

	while(n--) {
		int a, b;

		cin >> a >> b;

		sum += a * b;
	}

	cout << (sum == total ? "Yes" : "No");

	return 0;
}