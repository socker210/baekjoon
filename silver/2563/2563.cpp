#include <iostream>

using namespace std;

int main() {
	int n, c = 0, square[101][101] = {0};

	scanf("%d", &n);

	for(int i=0; i<n; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		for (int i=x; i<x+10; i++)
			for (int j=y; j<y+10; j++) {
				if (square[i][j] != 1) {
					square[i][j] = 1;
					c++;
				}
			}
	}

	printf("%d", c);

	return 0;
}