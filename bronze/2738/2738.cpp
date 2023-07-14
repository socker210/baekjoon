#include <iostream>

using namespace std;

int main() {
	int N, M;

	scanf("%d %d", &N, &M);

	int matrix[N][M];

	for (int i=0; i<N * 2; i++) {
		for (int j=0; j<M; j++) {
			int n;

			scanf("%d", &n);

			if (i >= N) cout << matrix[i % N][j] + n << (j == M - 1 ? '\n' : ' ');
			else matrix[i][j] = n;
		}
	}

	return 0;
}