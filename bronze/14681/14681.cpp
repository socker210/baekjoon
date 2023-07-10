#include <iostream>

using namespace std;

int main() {
	int x, y;

	cin >> x >> y;

	cout << (x > 0 && y > 0 ? 1 : x < 0 && y > 0 ? 2 : x < 0 && y < 0 ? 3 : 4);

	return 0;
}