#include <iostream>

using namespace std;

int main() {
	int n;

	cin >> n;

	int N[n], num, cnt = 0;

	for (int i=0; i<n; i++) {
		int t;

		cin >> t;

		N[i] = t;
	}

	cin >> num;

	for (int i=0; i<n;i ++) {
		if (N[i] == num) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}
