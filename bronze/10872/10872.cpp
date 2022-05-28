#include <iostream>

using namespace std;

long f(int n) {
	if (n <= 1) return 1;

	return f(n - 1) * n;
}

int main() {
	int N;

	scanf("%d", &N);

	printf("%ld", f(N));

  return 0;
}