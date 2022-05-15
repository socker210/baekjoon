#include <iostream>

using namespace std;

int main() {
	int N;

	scanf("%d", &N);

	int n[N];

	for (int i=0; i<N; i++) scanf("%d", &n[i]);

	int dp[N];
	int cnt = 0;

	dp[0] = n[0];
	dp[1] = dp[0] + n[1];

	cnt = dp[1] > dp[0] ? 1 : 0;

	for (int i=2; i<N; i++) {
		if (dp[i - 1] > dp[i - 2]) {
			dp[i] = n[i] + dp[i - 1];

			if (cnt == 2) {
				dp[i] -= dp[i - 2];

				cnt = 0;
			} else {
				cnt++;
			}
		} else {
			dp[i] = n[i] + dp[i - 2];
		}
	}

	printf("%d ", dp[N - 1]);

	return 0;
}
