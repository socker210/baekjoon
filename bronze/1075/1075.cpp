#include <iostream>

using namespace std;

int main() {
	int N, F;

	scanf("%d %d", &N, &F);

	int n = (N / 100) * 100;
	int N2 = N;
	
	while(true) {
		if (n % F == 0) {
			N2 = n;
			break;
		}

		n += 1;
	}

	printf("%02d", N2 % 100);

	return 0;
}
