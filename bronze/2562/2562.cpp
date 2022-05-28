#include <iostream>

using namespace std;

int main() {
	int t, idx = 0, max = 0;

	for (int i=0; i<9; i++) {
		scanf("%d", &t);

		if (t > max) {
			max = t;
			idx = i + 1;
		}

		max = max > t ? max : t;
	}

	printf("%d\n%d", max, idx);

	return 0;
}