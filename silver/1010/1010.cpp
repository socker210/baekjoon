#include <iostream>
#include <cmath>

#define IDX_N 0
#define IDX_R 1

using namespace std;

int main() {
  int N;

  scanf("%d", &N);

  int cases[N][2];

  for (int i=0; i<N; i++) scanf("%d %d", &cases[i][IDX_R], &cases[i][IDX_N]);

  for (int i=0; i<N; i++) {
    int r = cases[i][IDX_R];
    int n = cases[i][IDX_N];

    int res = 1;

    for (int j=0; j<r; j++) {
      res *= n - j;
      res /= j + 1;
    }

    printf("%d\n", res);
  };

  return 0;
}
