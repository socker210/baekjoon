#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	freopen("examples.txt", "r", stdin);

	float a, b;

	cin >> a >> b;

	if (a - (a * b) / 100 >= 100) cout << 0;
	else cout << 1;

	return 0;
}