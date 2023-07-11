#include <iostream>

using namespace std;

int main() {
	int N, M;

	cin >> N >> M;

	int basket[N];

	for (int i=0; i<N; i++) basket[i] = 0;

	while(M--) {
		int i, j, k;

		cin >> i >> j >> k;

		for (i= i -1; i<j; i++) basket[i] = k;
	}

	for (int i=0; i<N; i++) cout << basket[i] << ' ';
	
	return 0;
}