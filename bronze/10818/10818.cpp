#include <iostream>

using namespace std;

int main() {
	int N, t, min = 1000000, max = -1000000;

	scanf("%d", &N);

	for (int i=0; i<N;i ++) {
		scanf("%d", &t);

		max = max > t ? max : t;
		min = min < t ? min : t;
	}

	printf("%d %d", min, max);
		
	return 0;
}