#include <iostream>

using namespace std;

int f(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	return f(n - 1) + f(n - 2);
}

int main() {
	int N;

	scanf("%d", &N);

	printf("%d", f(N));

	return 0;
}