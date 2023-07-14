#include <iostream>

using namespace std;

int N = 9, M = 9;

int main() {
	int n, m, t, answer = 0;

	for (int i=1; i<=N; i++)
		for (int j=1; j<=M; j++) {
			scanf("%d", &t);

			if (t >= answer) {
				answer = t;
				n = i;
				m = j;
			}
		}

	printf("%d\n%d %d", answer, n, m);

	return 0;
}