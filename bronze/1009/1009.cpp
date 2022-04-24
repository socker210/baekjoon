#include <iostream>

using namespace std;

int solve(int base, int exp) {
	int res = 1;

	while(exp--) {
		res = (res * base) % 10;
	};

	return res;
}

int main() {
	int c, a, b;

	scanf("%d", &c);

	for (int i=0; i<c; i++) {
		scanf("%d %d", &a, &b);

		int res = solve(a, b);

		cout << (res == 0 ? 10 : res) << endl;
	}

	return 0;
}
