#include <iostream>

using namespace std;

int recursion(int* cnt, int n) {
  if (n == 0 || n == 1 || n == 2) {
    (*cnt)++;

    return n == 0 ? 0 : 1;
  }

  return recursion(cnt, n - 1) + recursion(cnt, n - 2);
}

int dp(int* cnt, int n) {
  int f[n + 1];

  f[0] = 0;
  f[1] = 1;
  f[2] = 1;

  for (int i=3; i<=n; i++) {
    (*cnt)++;
    
    f[i] = f[i - 1] + f[i - 2];
  }

  return f[n];
}

int main() {
  int N;
  int recursive_cnt = 0;
  int dp_cnt = 0;

  scanf("%d", &N);

  recursion(&recursive_cnt, N);
  dp(&dp_cnt, N);

  printf("%d %d", recursive_cnt, dp_cnt);

  return 0;
}
