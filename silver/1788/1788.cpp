#include <iostream>

using namespace std;

int main() {
  int N;
  int sign;

  scanf("%d", &N);

  sign = N < 0 ? -1 : 1;
  N = N * sign;

  int dp[N + 1];

  dp[0] = 0;
  dp[1] = 1;

  for (int i=2; i<=N; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;

  printf("%d\n", dp[N] == 0 ? 0 : sign == 1 ? 1 : N % 2 == 0 ? -1 : 1);
  printf("%d", dp[N]);

  return 0;
}