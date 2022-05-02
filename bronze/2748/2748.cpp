#include <iostream>

using namespace std;

long dp[91];

int main() {
  int N;

  scanf("%d", &N);

  dp[1] = 1;

  for (int i=2; i<=N; i++) dp[i] = dp[i - 1] + dp[i - 2];

  printf("%ld", dp[N]);

  return 0;
}