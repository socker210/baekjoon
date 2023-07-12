#include <iostream>

using namespace std;

int main() {
	int n, i, start, end, sign = 1;

	cin >> n;

	i = 2 * n - 1;
	start = n - 1;
	end = n - 1;

	for (int j=0; j<i; j++) {
		for (int k=0; k<=end; k++) cout << (k >= start ? '*' : ' ');

		cout << '\n';

		if (j >= n - 1) sign = -1;

		start -= sign;
		end += sign;
	}

	return 0;
}