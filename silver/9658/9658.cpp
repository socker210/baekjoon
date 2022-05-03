#include <iostream>

using namespace std;

int dp[1000];

int main() {
	int N;

	scanf("%d", &N);

	dp[0] = false;
	dp[1] = true;
	dp[2] = false;
	dp[3] = true;

	for (int i=4; i<N; i++) {
		int stone_1 = dp[i - 1];
		int stone_3 = dp[i - 3];
		int stone_4 = dp[i - 4];

		dp[i] = !stone_1 || !stone_3 || !stone_4;
	}

	printf("%s", dp[N - 1] ? "SK" : "CY");

	return 0;
}
