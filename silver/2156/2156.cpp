#include <iostream>

using namespace std;

#define Max(a,b) (a>b?a:b)

int INPUT[10001];
int DP[10001];

int main() {
  int N;

  scanf("%d", &N);

  for (int i=1; i<=N; i++) {
    scanf("%d", &INPUT[i]);

    DP[i] = i < 3 ? INPUT[i - 1] + INPUT[i] : Max(Max(INPUT[i] + INPUT[i - 1] + DP[i - 3], INPUT[i] + DP[i - 2]), DP[i - 1]);
  }

  printf("%d", DP[N]);

  return 0;
}
