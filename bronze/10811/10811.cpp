#include <iostream>

using namespace std;

int main() {
	int N, M;

	cin >> N >> M;

	int basket[N + 1];

	for (int i=1; i<=N; i++) basket[i] = i;

	while(M--) {
		int i, j, t;

		cin >> i >> j;

		for (;i < j;i++, j--) {
			t = basket[i];
			basket[i] = basket[j];
			basket[j] = t;
		}
	}

	for (int i=1; i<=N; i++) cout << basket[i] << ' ';

	return 0;
}