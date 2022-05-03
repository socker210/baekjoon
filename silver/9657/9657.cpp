#include <iostream>

using namespace std;

bool dp[1000];

int main() {
  int N;

  scanf("%d", &N);

  dp[0] = true;
  dp[1] = false;
  dp[2] = true;
  dp[3] = true;

  for (int i=4; i<N; i++) {
    bool stone_1 = dp[i - 1];
    bool stone_3 = dp[i - 3];
    bool stone_4 = dp[i - 4];

    dp[i] = !stone_1 || !stone_3 || !stone_4;
  }

  printf("%s", dp[N - 1] ? "SK" : "CY");

  return 0;
}
