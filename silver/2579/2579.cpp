#include <iostream>

using namespace std;

int main() {
	int N;

	scanf("%d", &N);

	int n[N + 1];

	n[0] = 0;

	for (int i=1; i<=N; i++) scanf("%d", &n[i]);

	int dp[N + 1];

	dp[0] = 0;
	dp[1] = n[1];
	dp[2] = n[1] + n[2];

	for (int i=3; i<=N; i++) {
		int a = n[i] + n[i - 1] + dp[i - 3];
		int b = n[i] + dp[i - 2];

		dp[i] = a > b ? a : b;
	}

	printf("%d", dp[N]);

	return 0;
}