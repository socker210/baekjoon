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

    double res = 1;

    for (int j=0; j<r; j++) {
      res *= static_cast<double>(n - j) / static_cast<double>(r - j);
    }

    printf("%d\n", static_cast<int>(round(res)));
  };

  return 0;
}
