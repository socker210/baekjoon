#include <iostream>

using namespace std;

long DP[101];

int main() {
  int N;

  scanf("%d", &N);

  DP[1] = 1;
  DP[2] = 1;
  DP[3] = 1;
  DP[4] = 2;
  DP[5] = 2;

  for (int i=0; i<N; i++) {
    int n;

    scanf("%d", &n);

    for (int j=6; j<=n; j++) DP[j] = DP[j - 5] + DP[j - 1];

    printf("%ld\n", DP[n]);
  }

  return 0;
}