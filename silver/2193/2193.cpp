#include <iostream>

using namespace std;

int pow(int base, int exp) {
  int res = 1;

  while(exp--) res *= base;

  return res;
}

int main() {
  int N;

  scanf("%d", &N);

  int digit = pow(2, N - 1);

  int dp[digit + 1];

  dp[0] = 0;
  dp[1] = 1;

  for (int i=2; i<=digit; i++) dp[i] = dp[i - 2] + dp[i - 1];

  printf("%d", dp[N]);

  return 0;
}
