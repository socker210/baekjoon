#include <iostream>

using namespace std;

int main() {
	int N;

	scanf("%d", &N);

	int n[N];

	for (int i=0; i<N; i++) scanf("%d", &n[i]);

	int dp[N];

	dp[0] = n[0];
	dp[1] = n[0] + n[1];

	for (int i=2; i<N; i++) {
		int a = n[i] + dp[i - 1] - n[i - 2];
		int b = n[i] + dp[i - 2];

		dp[i] = a > b ? n[i] + n[i - 1] + (i > 2 ? dp[i - 3] : 0) : b;
	}

	printf("%d", dp[N - 1]);

	return 0;
}
