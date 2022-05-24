#include <iostream>

using namespace std;

int DP[1000001];

int main() {
  int N;

  scanf("%d", &N);

  DP[0] = 1;
  DP[1] = 1;

  for (int i=2; i<=N; i++) {
    DP[i] = (DP[i - 1] + DP[i - 2]) % 15746;
  }

  printf("%d", DP[N]);

  return 0;
}
