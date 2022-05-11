#include <iostream>

using namespace std;

int main() {
  int N;

  scanf("%d", &N);

  long dp[N + 1];

  dp[0] = 0;
  dp[1] = 1;

  for (int i=2; i<=N; i++) dp[i] = dp[i - 2] + dp[i - 1];

  printf("%ld", dp[N]);

  return 0;
}
