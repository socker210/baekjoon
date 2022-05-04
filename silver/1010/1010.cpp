#include <iostream>

#define LEFT 0
#define RIGHT 1

using namespace std;

int main() {
  int N;

  scanf("%d", &N);

  int n[N][2];

  for (int i=0; i<N; i++) scanf("%d %d", &n[i][LEFT], &n[i][RIGHT]);

  for (int i=0; i<N; i++) {
    int left = n[i][LEFT];
    int right = n[i][RIGHT];

    int dp[right + 1];

    dp[0] = 1;

    for (int j=1; j<=right; j++) {
      dp[j] = dp[j - 1] * j;
    }

    printf("%d\n", dp[right]);
  };

  return 0;
}
