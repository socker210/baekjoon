#include <iostream>

using namespace std;

int main() {
	int N;

	scanf("%d", &N);

	int DP[N + 1];

	for (int i=0; i<=N; i++) DP[i] = 0;

	DP[2] = 1;
	DP[3] = 1;

	int t_idx[3];

	for (int i=4; i<=N; i++) {
		t_idx[0] = i - 1;
		t_idx[1] = i % 3 == 0 ? i / 3 : t_idx[0];
		t_idx[2] = i % 2 == 0 ? i / 2 : t_idx[0];

		int t = DP[t_idx[0]] < DP[t_idx[1]] ? t_idx[0] : t_idx[1];
		int idx = DP[t] < DP[t_idx[2]] ? t : t_idx[2];

		DP[i] = DP[idx] + 1;
	}

	printf("%d", DP[N]);
	
	return 0;
}