#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int a, b, ax, ay, bx, by;

	scanf("%d %d", &a, &b);

	ax = (a - 1) / 4;
	ay = (a - 1) % 4;
	bx = (b - 1) / 4;
	by = (b - 1) % 4;

	printf("%d", abs(ax - bx) + abs(ay - by));

	return 0;
}

