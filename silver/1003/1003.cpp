#include <iostream>

using namespace std;

int main() {
  int N;

  scanf("%d", &N);

  int n[N];

  for (int i=0; i<N; i++) scanf("%d", &n[i]);

  for (int i=0; i<N; i++) {
    int dp[n[i] + 1][2];

    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;

    for (int j=2; j<=n[i]; j++) {
      dp[j][0] = dp[j - 1][0] + dp[j - 2][0];
      dp[j][1] = dp[j - 1][1] + dp[j - 2][1];
    }

    printf("%d %d\n", dp[n[i]][0], dp[n[i]][1]);
  }

  return 0;
}
